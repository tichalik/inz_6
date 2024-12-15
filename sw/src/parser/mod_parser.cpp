#include "mod_parser.h"

Mod_parser::Mod_parser(
	const Grammar & _grammar,
	const Word & input,
	SPPF & _sppf
):
	sppf(_sppf),
	grammar(_grammar)
{
	//create the state sets
	this->states.reserve(input.size()+1);
	for (size_t i=0; i<input.size() + 1; i++)
	{
		this->states.emplace_back(&state_compare);
	}

	//create leaf SPPF nodes
	this->sppf.leaves.resize(input.size());
	for (size_t i=0; i<input.size(); i++)
	{
		this->sppf.leaves[i].tag = input[i];
	}

	//add the first states
	{ 
		const std::vector<Symbols> RHSs = grammar.rules.get_rules(grammar.head);
		for (size_t j=0; j<RHSs.size(); j++)
		{ 
			this->sppf.nodes.emplace_back();
			this->sppf.nodes.back().tag = grammar.head;
			
			this->states[0].insert({
				grammar.head, 	//LHS
				RHSs[j], 		//RHS
				0, 				//pos
				0,				//origin
				&sppf.nodes.back(),		//sppf_node
				this->states[0].size()	//pos_in_set
			});
		}
	}
	
	//main loop 
	size_t i=0;
	for (; i<input.size(); i++)
	{
		int j = 0;
		for (State_set::iterator state = this->states[i].begin(); 
			state != this->states[i].end(); state++)
		{
			std::cout << i << "." << (j++)  <<std::endl;
			if (state->pos != state->RHS.size())
			{
				if (state->RHS[state->pos] == input[i])
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
	for (State_set::iterator state = this->states[i].begin(); 
		state != this->states[i].end(); state++)
	{
		if (state->pos != state->RHS.size())
		{
			this->predict(*state, i);
		}
		else
		{
			this->complete(*state, i);
		}
	} 
	
	//find the results
	for (State_set::iterator state = this->states[i].begin(); 
		state != this->states[i].end(); state++)
	{
		if (state->origin == 0 && state->LHS == grammar.head &&
			state->pos == state->RHS.size())
		{
			this->sppf.roots.push_back(state->sppf_node);
		}
	}

}

void Mod_parser::predict(const State & state, size_t i)
{
	const std::vector<Symbols> RHSs = 
		grammar.rules.get_rules(state.RHS[state.pos]);
	for (size_t j=0; j<RHSs.size(); j++)
	{
		State _state;
		_state.LHS = state.RHS[state.pos];
		_state.RHS = RHSs[j];
		_state.pos = 0;
		_state.origin = i;
		_state.pos_in_set = -1;
		if (this->states[i].find(_state) == this->states[i].end())
		{
			this->sppf.nodes.emplace_back();
			this->sppf.nodes.back().tag = _state.LHS;
			_state.sppf_node = & this->sppf.nodes.back();
			_state.pos_in_set = this->states[i].size();
			this->states[i].insert(_state);
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
	_state.pos_in_set = -1;
	if (this->states[i+1].find(_state) == this->states[i+1].end())
	{
		if (_state.sppf_node->alts.size() == 0)
		{
			_state.sppf_node->alts.emplace_back();
			_state.sppf_node->alts.back().push_back(&(this->sppf.leaves[i]));
		}
		else
		{
			for (size_t alt_id=0; alt_id<_state.sppf_node->alts.size(); alt_id++)
			{
				_state.sppf_node->alts[alt_id].push_back(&(this->sppf.leaves[i]));
			}
		}
		_state.pos_in_set = this->states[i+1].size();
		this->states[i+1].insert(_state);
	}
}

void Mod_parser::complete(const State & state, size_t i)
{
	for (State_set::iterator source = this->states[state.origin].begin();
		source != this->states[state.origin].end(); source++)
 	{
		if (source->pos < source->RHS.size() 
			&& source->RHS[source->pos] == state.LHS)
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
			_state.pos_in_set = -1;
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
			
			State_set::iterator pos = this->states[i].find(_state) ;
			if (pos == this->states[i].end())
			{
				_state.pos_in_set = this->states[i].size();
				this->states[i].insert(_state);
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


bool state_compare(
	const State& s1,
	const State& s2
)
{
	//A is equal to B iff !A<B && !B<A
	//there are two purposes for this function
	//1. to check if an item is in the set
	//		-> then the pos_in_set = -1
	//2. to place it in the queue

	#define CHECK(X)\
		if (s1.X != s2.X)\
		{\
			bool tmp = s1.X < s2.X;\
			std::cout << s1.pos_in_set << " " << s2.pos_in_set << " " #X " " << tmp << std::endl;\
			std::cout << "---------------" << std::endl;\
			return tmp;\
		}

	if (s1.pos_in_set == -1 || s2.pos_in_set == -1)
	{
		//we want ot check if the elements are identical
		// we do it like comparing strings
		CHECK(LHS);
		CHECK(RHS);
		CHECK(pos);
		CHECK(origin);

		//if reached this point, all fields were the same 
		// two items are the same if none of them is greater than the other 
	
		std::cout << s1.pos_in_set << " " << s2.pos_in_set << " "  << false  << std::endl;
		return false;
	}
	else 
	{
		//we want to put it in the queue
		//so we order by the pos_in_set
		return s1.pos_in_set < s2.pos_in_set;
	}
	#undef CHECK
}
