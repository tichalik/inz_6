#include "chomskify.h"

Symbol Chomskify::create_new_symbol()
{
	Symbol res = Utils::int_to_string(next_new_symbol);
	next_new_symbol++;
	while( res_grammar.orig_nonterminals.contains(res)
		|| res_grammar.added_nonterminals.contains(res)
		|| res_grammar.orig_terminals.contains(res))
	{	
		res = Utils::int_to_string(next_new_symbol);
		next_new_symbol++;
	}
	
	res_grammar.added_nonterminals.insert(res);
	
	return res;
}

Chomskify::Chomskify(
	const Grammar& input_grammar
):
	next_new_symbol(0)
{
	res_grammar.orig_nonterminals = input_grammar.nonterminals;
	res_grammar.orig_terminals = input_grammar.terminals;
	res_grammar.head = input_grammar.head;
	
	for (size_t i=0; i<input_grammar.rules.size(); i++)
	{
		Rule r = input_grammar.rules[i];
		if (r.RHS.size() == 2)
		{
			Chomsky_rule cr;
			cr.LHS = r.LHS;
			cr.RHS1 = r.RHS[0];
			cr.RHS2 = r.RHS[1];
			cr.source_rules_ids.push_back(i);
			
			res_grammar.orig_rules.push_back(cr);
		}
		else 
		{ 
			Symbol new_symbol = create_new_symbol();
			Symbol old_symbol;
			
			//the first rule contains the original LHS and the fist item of RHS
			{
				Chomsky_rule cr;
				cr.LHS = r.LHS;
				cr.RHS1 = r.RHS[0];
				cr.RHS2 = new_symbol;
				cr.source_rules_ids.push_back(i);
				
				res_grammar.added_rules.push_back(cr);
			}
			
			int pos = 1;
			
			while(pos < r.RHS.size()-2)
			{
		
				old_symbol = new_symbol;
				new_symbol = create_new_symbol();
				
				Chomsky_rule cr;
				cr.LHS = old_symbol;
				cr.RHS1 = r.RHS[pos];
				cr.RHS2 = new_symbol;
				cr.source_rules_ids.push_back(i);
				
				res_grammar.added_rules.push_back(cr);
				
				pos++;
			}
			
			//the last rule contains last added symbol as LHS and the 2 last items of original RHS
			{
		
				Chomsky_rule cr;
				cr.LHS = new_symbol;
				cr.RHS1 = r.RHS[pos];
				cr.RHS2 = r.RHS[pos+1];
				cr.source_rules_ids.push_back(i);
				
				res_grammar.added_rules.push_back(cr);
			}
		}
	}
}

Chomsky_grammar Chomskify::get_grammar()
{
	return res_grammar;
}