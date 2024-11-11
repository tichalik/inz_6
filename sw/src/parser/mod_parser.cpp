#include "mod_parser.h"

Mod_parser::Mod_parser(
	const Grammar & grammar,
	const Word & input
):
	parsing_grammar_adapter(grammar),
	states(input.size()+1),
	leaves(input.size())
{
	//create leaf SPPF nodes
	for (size_t i=0; i<input.size(); i++)
	{
		this->leaves[i].tag = input[i];
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
			back.sppf.tag = grammar.head;
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
			this->res.push_back(&(state->sppf));
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
		_state.sppf.tag = _state.rule.LHS;
		if (this->find_in_set(_state, i) == this->states[i].end())
		{
			this->states[i].push_back(_state);
		}
	}

}

void Mod_parser::scan(const State & state, size_t i)
{
	State _state(state); //is this a deep copy of SPPF? is it necessary
	_state.pos++;
	if (this->find_in_set(_state, i+1) == this->states[i+1].end())
	{
		if (_state.sppf.alts.size() == 0)
		{
			_state.sppf.alts.emplace_back();
			_state.sppf.alts.back().push_back(&(this->leaves[i]));
		}
		else
		{
			for (size_t i=0; i<_state.sppf.alts.size(); i++)
			{
				_state.sppf.alts[i].push_back(&(this->leaves[i]));
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
			State _state(*source); //is this a deep copy of SPPF? is it necessary
			_state.pos++;
			if (_state.sppf.alts.size() == 0)
			{
				_state.sppf.alts.emplace_back();
				_state.sppf.alts.back().push_back(&state.sppf);
			}
			else
			{
				for (size_t k=0; k<_state.sppf.alts.size(); k++)
				{
					_state.sppf.alts[k].push_back(&state.sppf);
				}
			}
			
			std::list<State>::iterator pos = this->find_in_set(_state, i) ;
			if (pos == this->states[i].end())
			{
				this->states[i].push_back(_state);
			}
			else
			{ 
				pos->sppf.alts.insert(
					pos->sppf.alts.end(),
					_state.sppf.alts.begin(),
					_state.sppf.alts.end()
				);
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


PTrees Mod_parser::get_parse_trees() const
{
	return this->parse_trees;
}
