#include "mod_parser.h"

Mod_parser::Mod_parser(
	const Grammar & grammar,
	const Word & input,
	SPPF & _sppf
):
	parsing_grammar_adapter(grammar),
	states(input.size()+1),
	sppf(_sppf)
{ 
	//create leaf SPPF nodes
	this->sppf.leaves.resize(input.size());
	for (size_t i=0; i<input.size(); i++)
	{
		this->sppf.leaves[i].tag = input[i];
	}

	//add the first states
	{ 
		const std::vector<Symbols> RHSs = parsing_grammar_adapter.get_RHS(grammar.head);
		for (size_t j=0; j<RHSs.size(); j++)
		{ 
			this->states[0].emplace_back();
			State & back = this->states[0].back();
			back.rule.LHS = grammar.head;
			back.rule.RHS = RHSs[j];
			back.pos = 0;
			back.origin= 0;
			this->sppf.nodes.emplace_back();
			this->sppf.nodes.back().tag = grammar.head;
			back.sppf_node = & this->sppf.nodes.back();
		}
	}

	//main loop 
	size_t i=0;
	for (; i<input.size(); i++)
	{
		for (std::list<State>::iterator state = this->states[i].begin(); 
			state != this->states[i].end(); state++)
		{
			if (state->pos != state->rule.RHS.size())
			{
				if (state->rule.RHS[state->pos] == input[i])
				{
					this->scan(*state, i);
				}
				else
				{
					this->predict(*state, i);
				}
			}
			else
			{
				this->complete(*state, i);
			}
		}

	}

	//process last set
	for (std::list<State>::iterator state = this->states[i].begin();
		state != this->states[i].end(); state++)
	{
		if (state->pos != state->rule.RHS.size())
		{
			this->predict(*state, i);
		}
		else
		{
			this->complete(*state, i);
		}
	} 
	
	//find the results
	for (std::list<State>::iterator state = this->states[i].begin();
		state != this->states[i].end(); state++)
	{
		if (state->origin == 0 && state->rule.LHS == grammar.head &&
			state->pos == state->rule.RHS.size())
		{
			this->sppf.roots.push_back(state->sppf_node);
		}
	}

	this->process_sppf();
}

void Mod_parser::predict(const State & state, size_t i)
{
	const std::vector<Symbols> RHSs = 
		parsing_grammar_adapter.get_RHS(state.rule.RHS[state.pos]);
	for (size_t j=0; j<RHSs.size(); j++)
	{
		State _state;
		_state.rule.LHS = state.rule.RHS[state.pos];
		_state.rule.RHS = RHSs[j];
		_state.pos = 0;
		_state.origin = i;
		if (this->find_in_set(_state, i) == this->states[i].end())
		{
			this->sppf.nodes.emplace_back();
			this->sppf.nodes.back().tag = _state.rule.LHS;
			_state.sppf_node = & this->sppf.nodes.back();
			this->states[i].push_back(_state);
		}
	}

}

void Mod_parser::scan(const State & state, size_t i)
{
	State _state(state); 
	// is the deep copy here necessary?
	// for the SPPF, probably no
	// there is only one way to scan from one state to another
	// (so also no need for checking if the state is already present?)
	// anyway, making a deep copy of SPPF, to keep the 1 state = 1 sppf node relation
	this->sppf.nodes.push_back(SPPF_node(*state.sppf_node));
	_state.sppf_node = & this->sppf.nodes.back();
	_state.pos++;
	if (this->find_in_set(_state, i+1) == this->states[i+1].end())
	{
		if (_state.sppf_node->alts.size() == 0)
		{
			_state.sppf_node->alts.emplace_back();
			_state.sppf_node->alts.back().push_back(&(this->sppf.leaves[i]));
		}
		else
		{
			for (size_t i=0; i<_state.sppf_node->alts.size(); i++)
			{
				_state.sppf_node->alts[i].push_back(&(this->sppf.leaves[i]));
			}
		}
		this->states[i+1].push_back(_state);
	}
}

void Mod_parser::complete(State & state, size_t i)
{
	for (std::list<State>::iterator source = this->states[state.origin].begin();
		source != this->states[state.origin].end(); source++)
 	{
		if (source->pos < source->rule.RHS.size() 
			&& source->rule.RHS[source->pos] == state.rule.LHS)
 		{
			State _state(*source); 
			// is the deep copy here necessary?
			// for the SPPF, probably no
			// there is only one way to scan from one state to another
			// (so also no need for checking if the state is already present?)
			// anyway, making a deep copy of SPPF, to keep the 1 state = 1 sppf node relation
			this->sppf.nodes.push_back(SPPF_node(*source->sppf_node));
			_state.sppf_node = & this->sppf.nodes.back();
			_state.pos++;
			if (_state.sppf_node->alts.size() == 0)
			{
				_state.sppf_node->alts.emplace_back();
				_state.sppf_node->alts.back().push_back(state.sppf_node);
			}
			else
			{
				for (size_t k=0; k<_state.sppf_node->alts.size(); k++)
				{
					_state.sppf_node->alts[k].push_back(state.sppf_node);
				}
			}
			
			std::list<State>::iterator pos = this->find_in_set(_state, i) ;
			if (pos == this->states[i].end())
			{
				this->states[i].push_back(_state);
			}
			else
			{ 
				pos->sppf_node->alts.insert(
					pos->sppf_node->alts.end(),
					_state.sppf_node->alts.begin(),
					_state.sppf_node->alts.end()
				);
				// in the end the node is not used anywhere
				// so we remove it
				this->sppf.nodes.pop_back();
			}
			
		}
	}
} 

std::list<State>::iterator Mod_parser::find_in_set(const State & state, size_t i) 
{
	std::list<State>::iterator res = this->states[i].begin();
	for(; res != this->states[i].end(); res++)
	{
		if (
			res->rule.LHS == state.rule.LHS &&
			res->rule.RHS == state.rule.RHS &&
			res->pos == state.pos &&
			res->origin == state.origin 
			)
		{
			break;
		} 
	}
	return res;
}

std::vector<std::vector<PNode*>> Mod_parser::combine2(
	std::vector<std::vector<PNode*>> & list, 
	SPPF_node* sppf_node
)
{
	std::vector<std::vector<PNode*>> results;
	results.reserve(list.size() * sppf_node->pnodes.size());

	for (size_t i=0; i<list.size(); i++)
	{
		for (size_t j=0; j<sppf_node->pnodes.size(); j++)
		{
			results.push_back(list[i]);
			results.back().push_back(&sppf_node->pnodes[j]);
		}
	}

	return results;
}

std::vector<std::vector<PNode*>> Mod_parser::all_combinations(
	const std::vector<SPPF_node *> & sppf_children
)
{

	std::vector<std::vector<PNode*>> result;

	//first child
	for (size_t i=0; i<sppf_children[0]->pnodes.size(); i++)
	{
		result.emplace_back();
		result.back().push_back(&sppf_children[0]->pnodes[i]);
	}

	for (size_t i=1; i<sppf_children.size(); i++)
	{
		this->combine2(result, sppf_children[i]);
	}

	return result;
}

void Mod_parser::process_sppf()
{
	//order sppf nodes -- breadth first search 
	std::list<SPPF_node*> ordered_sppf;
    
	ordered_sppf.insert(ordered_sppf.begin(), sppf.roots.begin(), sppf.roots.end());
	
	for ( std::list<SPPF_node*>::iterator i = ordered_sppf.begin();
		i != ordered_sppf.end(); i++)
	{
		for (std::vector<SPPF_node*> & alt: (*i)->alts)
		{
			for (SPPF_node * node: alt)
			{
				if (node->visited == false)
				{
					ordered_sppf.push_back(node);
					node->visited = true;
				}
			}
		}
	}

	//starting from the leaves, create pnodes for each sppf node

	//for each SPPF_node 
	for ( std::list<SPPF_node*>::reverse_iterator i = ordered_sppf.rbegin();
		i != ordered_sppf.rend(); i++)
	{
		for (const std::vector<SPPF_node*> & alt: (*i)->alts)
		{
			std::vector<std::vector<PNode*>> children_combinations = 
				all_combinations(alt);
			
			for (size_t j=0; j<children_combinations.size(); j++)
			{
				(*i)->pnodes.emplace_back();
				(*i)->pnodes.back().tag = (*i)->tag;
				(*i)->pnodes.back().children = children_combinations[j];
			}
		}
	}
	
	//insert root's pnodes into sppf.res_pnodes
	for (size_t i=0; i<sppf.roots.size(); i++)
	{
		for (size_t j=0; j<sppf.roots[i]->pnodes.size(); j++)
		{
			this->sppf.res_pnodes.push_back(&sppf.roots[i]->pnodes[j]);
		}
	}
}
