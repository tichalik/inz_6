#include "chomskify.h"

Symbol Chomskify::create_new_symbol()
{
	Symbol res = Utils::int_to_string(next_new_symbol);
	next_new_symbol++;
	while( res_grammar.nonterminals.contains(res)
		|| res_grammar.added_nonterminals.contains(res)
		|| res_grammar.terminals.contains(res))
	{	
		res = Utils::int_to_string(next_new_symbol);
		next_new_symbol++;
	}
	
	res_grammar.added_nonterminals.insert(res);
	
	return res;
}

Chomsky_grammar Chomskify::init_res_grammar(
	const Grammar& input_grammar
) const
{
	Chomsky_grammar res;
	
	res.nonterminals = input_grammar.nonterminals;
	res.terminals = input_grammar.terminals;
	res.head = input_grammar.head;
	
	
	for (size_t i=0; i<input_grammar.rules.size(); i++)
	{
		Rule r = input_grammar.rules[i];
		
		Rule cr;
		cr.LHS = r.LHS;
		cr.RHS = r.RHS;
		res.rules.push_back(cr);
	}
	
	return res;
}

void Chomskify::break_rules()
{
	Rules res_rules;
	
	for (size_t i=0; i<res_grammar.rules.size(); i++)
	{
		Rule r = res_grammar.rules[i];
		
		//do nothing on rules which cannot be broken
		if (r.RHS.size() <= 2)
		{
			res_rules.push_back(r);
		}
		//break other rules
		else 
		{ 
			Symbol new_symbol = create_new_symbol();
			Symbol old_symbol;
			
			//the first rule contains the original LHS and the fist item of RHS
			{
				Rule cr;
				cr.LHS = r.LHS;
				cr.RHS.push_back(r.RHS[0]);
				cr.RHS.push_back(new_symbol);
				
				res_rules.push_back(cr);
			}
			
			int pos = 1;
			
			while(pos < r.RHS.size()-2)
			{
		
				old_symbol = new_symbol;
				new_symbol = create_new_symbol();
				
				Rule cr;
				cr.LHS = old_symbol;
				cr.RHS.push_back(r.RHS[pos]);
				cr.RHS.push_back(new_symbol);
				
				res_rules.push_back(cr);
				
				pos++;
			}
			
			//the last rule contains last added symbol as LHS and the 2 last items of original RHS
			{
		
				Rule cr;
				cr.LHS = new_symbol;
				cr.RHS.push_back(r.RHS[pos]);
				cr.RHS.push_back(r.RHS[pos+1]);
				
				res_rules.push_back(cr);
			}
		}
	}
	
	this->res_grammar.rules = res_rules;
}


Chomskify::Chomskify(
	const Grammar& input_grammar
):
	next_new_symbol(0),
	res_grammar(init_res_grammar(input_grammar))
{
	break_rules();
}

Chomsky_grammar Chomskify::get_grammar() const
{
	return res_grammar;
}

Errors Chomskify::get_errors() const
{
	return errors; 
}
