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
		
		Chomsky_rule cr;
		cr.LHS = r.LHS;
		cr.RHS = r.RHS;
		res.rules.push_back(cr);
	}
	
	return res;
}

void Chomskify::break_rules()
{
	Chomsky_rules res_rules;
	
	for (size_t i=0; i<res_grammar.rules.size(); i++)
	{
		Chomsky_rule r = res_grammar.rules[i];
		
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
				Chomsky_rule cr;
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
				
				Chomsky_rule cr;
				cr.LHS = old_symbol;
				cr.RHS.push_back(r.RHS[pos]);
				cr.RHS.push_back(new_symbol);
				
				res_rules.push_back(cr);
				
				pos++;
			}
			
			//the last rule contains last added symbol as LHS and the 2 last items of original RHS
			{
		
				Chomsky_rule cr;
				cr.LHS = new_symbol;
				cr.RHS.push_back(r.RHS[pos]);
				cr.RHS.push_back(r.RHS[pos+1]);
				
				res_rules.push_back(cr);
			}
		}
	}
	
	this->res_grammar.rules = res_rules;
}

std::vector<Symbols> Chomskify::get_path(
	Symbol head, 
	Symbols current_path,
	Chain_trees chain_trees
)
{
	std::vector<Symbols> res;
	current_path.push_back(head);
	
	if (chain_trees[head].exit == true)
	{
		res.push_back(current_path);
	}
	
	for (size_t i=0; i<chain_trees[head].symbols.size(); i++)
	{
		std::vector<Symbols> children = get_path(
			chain_trees[head].symbols[i], 
			current_path, 
			chain_trees
		);
		res.insert(res.end(), children.begin(), children.end());
	}
	
	return res;
}



Chomsky_rules Chomskify::replace_chain_in_rule(
	const Chomsky_rule& rule,
	const size_t& RHS_pos,
	Chain_trees chain_trees
)
{
	Chomsky_rules res;
	
	if (chain_trees.contains(rule.RHS[RHS_pos]))
	{
		std::vector<Symbols> replaced_symbolss = get_path(
			rule.RHS[RHS_pos], {}, chain_trees);
		for (size_t i=0; i<replaced_symbolss.size(); i++)
		{
			Chomsky_rule new_rule = rule;
			Symbol last_symbol = replaced_symbolss[i][replaced_symbolss.size()-1];
			new_rule.RHS[RHS_pos] = last_symbol;
			
			Replaced_symbols_index replaced_symbols_index;
			replaced_symbols_index.RHS_pos = RHS_pos;
			replaced_symbols_index.symbols = replaced_symbolss[i];
			new_rule.replaced_symbols_indexes.push_back(replaced_symbols_index);
			
			// Cycle_warnings_index cycle_warnings_index;
			// cycle_warnings_index.RHS_pos = RHS_pos;
			// cycle_warnings_index.cycle_warnings = replaced_symbolss[i].cycle_warnings;
			// new_rule.cycle_warnings_indexes.push_back(cycle_warnings_index);
			
			//if there are no more symbols to possibly replace
			if (RHS_pos == rule.RHS.size()-1)
			{
				res.push_back(new_rule);
			}
			//if more symbols can be replaced
			else
			{
				Chomsky_rules tmp = replace_chain_in_rule(
					new_rule,
					RHS_pos+1,
					chain_trees
				);
				res.insert(res.end(), tmp.begin(), tmp.end()); 
			}
		}
	}
	
	return res;
}
	


void Chomskify::remove_chains()
{
	Chomsky_rules res_rules;
	
	Chain_trees chain_trees;
	
	//create trees of chain dependencies 
	for (size_t i=0; i<res_grammar.rules.size(); i++)
	{
		const Chomsky_rule& rule = res_grammar.rules[i];
		if (rule.RHS.size() == 1)
		{
			//save the rule
			chain_trees[rule.LHS].symbols.push_back(rule.RHS[0]);
			//also save the RHS
			chain_trees[rule.RHS[0]].exit = false;
		}
	}
	
	//check which symbols are the exits
	//an exit symbol is either terminal or a nonterminal which is a head of a rule
	// with RHS.size() > 1
	for (auto i = chain_trees.begin(); i!= chain_trees.end(); i++)
	{
		if (res_grammar.terminals.contains(i->first))
		{
			i->second.exit = true;			
		}
		else
		{
			for (size_t j=0; j<res_grammar.rules.size(); j++)
			{
				const Chomsky_rule& rule = res_grammar.rules[j];
				if (rule.RHS.size() != 1 && rule.LHS == i->first)
				{
					i->second.exit = true;
				}
			}
		}
	}
	
	//replace chains in rules 
	for (size_t i=0; i<res_grammar.rules.size(); i++)
	{
		const Chomsky_rule& rule = res_grammar.rules[i];
		if (rule.RHS.size() != 1)
		{
			Chomsky_rules tmp = replace_chain_in_rule(rule, 0, chain_trees );
			res_rules.insert(res_rules.end(), tmp.begin(), tmp.end());
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
	remove_chains();
}

Chomsky_grammar Chomskify::get_grammar()
{
	return res_grammar;
}