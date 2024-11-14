#include "mod_parser.h"

Mod_parser::Mod_parser(
	const Grammar & grammar,
	const Word & input
):
	parsing_grammar_adapter(grammar),
	states(input.size()+1)
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


SPPF Mod_parser::get_SPPF() const
{
	return this->sppf;
}
