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
		this->states[0] = std::vector<State>(RHSs.size());
		for (size_t j=0; j<RHSs.size(); j++)
		{ 
			this->states[0][j].rule.LHS = grammar.head;
			this->states[0][j].rule.RHS = RHSs[j];
			this->states[0][j].pos = 0;
			this->states[0][j].origin= 0;
			this->states[0][j].sppf.tag = grammar.head;
		}
	}

	//main loop 
	size_t i=0;
	for (; i<input.size(); i++)
	{
		size_t j = 0;
		while (j < this->states[i].size())
		{
			State& state = this->states[i][j];
			if (state.pos != state.rule.RHS.size())
			{
				if (state.rule.RHS[state.pos] == input[i])
				{
					this->scan(state, i);
				}
				else
				{
					this->predict(state, i);
				}
			}
			else
			{
				this->complete(state, i);
			}

			j++;
		}

	}

	//process last set
	{
		size_t j = 0;
		while (j < this->states[i].size())
		{
			State& state = this->states[i][j];
			if (state.pos != state.rule.RHS.size())
			{
				this->predict(state, i);
			}
			else
			{
				this->complete(state, i);
			}

			j++;
		} 
	}
	
	//find the results
	for (size_t j=0; j<this->states[i].size(); j++)
	{
		State & state = this->states[i][j];
		if (state.origin == 0 && state.rule.LHS == grammar.head &&
			state.pos == state.rule.RHS.size())
		{
			this->res.push_back(&state.sppf);
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
		if (this->find_in_set(_state, i) == -1)
		{
			this->states[i].push_back(_state);
		}
	}

}

void Mod_parser::scan(const State & state, size_t i)
{
	State _state(state); //is this a deep copy of SPPF? is it necessary
	_state.pos++;
	if (this->find_in_set(_state, i+1) == -1)
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
	for (size_t j=0; j<this->states[state.origin].size(); j++)
	{
		State & source = this->states[state.origin][j];

		if (source.pos < source.rule.RHS.size() 
			&& source.rule.RHS[source.pos] == state.rule.LHS)
		{
			State _state(source); //is this a deep copy of SPPF? is it necessary
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
			
			size_t pos = this->find_in_set(_state, i) ;
			if (pos == -1)
			{
				this->states[i].push_back(_state);
			}
			else
			{
				this->states[i][pos].sppf.alts.insert(
					this->states[i][pos].sppf.alts.end(),
					_state.sppf.alts.begin(),
					_state.sppf.alts.end()
				);
			}
			
		}
	}
}

size_t Mod_parser::find_in_set(const State & state, size_t i) const
{
	size_t res = -1;
	for( size_t j = 0; j<this->states[i].size() && res == -1; j++)
	{
		if (
			this->states[i][j].rule.LHS == state.rule.LHS &&
			this->states[i][j].rule.RHS == state.rule.RHS &&
			this->states[i][j].pos == state.pos &&
			this->states[i][j].origin == state.origin 
			)
		{
			res = j;
		}
	}
	return res;
}


PTrees Mod_parser::get_parse_trees() const
{
	return this->parse_trees;
}
