#include "chomskify.h"

Symbol Chomskify::get_new_symbol()
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
		Chomsky_rule cr;
		cr.LHS = r.left;
		cr.RHS1 = r.right1;
		cr.RHS2 = r.right2;
		cr.source_rules_ids.push_back(i);
		
		res_grammar.orig_rules.push_back(cr);
	}
}

Chomsky_grammar Chomskify::get_grammar()
{
	return res_grammar;
}