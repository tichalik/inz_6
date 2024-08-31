#include "tst_mod_parser.h"


void TST_mod_parser::_test_break_rules(
	const Grammar & input_grammar,
	const Chomsky_grammar expected_grammar
)
{
	Grammar dummy;
	Chomskify chomskify(dummy);
	
	chomskify.res_grammar = chomskify.init_res_grammar(input_grammar);
	chomskify.break_rules();
	
	
	bool ok = compare(expected_grammar, chomskify.get_grammar(), "grammar");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
}


void TST_mod_parser::test_break_rules()
{
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " rule A -> b c" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Grammar input_grammar;
		input_grammar.terminals.insert("b");
		input_grammar.terminals.insert("c");
		input_grammar.nonterminals.insert("A");
		input_grammar.head  = "A";
		
		Rule rule;
		rule.LHS = "A";
		rule.RHS.push_back("b");
		rule.RHS.push_back("c");
		
		input_grammar.rules.push_back(rule);
		
		Chomsky_grammar expected_grammar;
		expected_grammar.terminals.insert("b");
		expected_grammar.terminals.insert("c");
		expected_grammar.nonterminals.insert("A");
		expected_grammar.head = "A";
		
		Chomsky_rule crule;
		crule.LHS = "A";
		crule.RHS.push_back("b");
		crule.RHS.push_back("c");
		
		
		expected_grammar.rules.push_back(crule);
		
		_test_break_rules(
			input_grammar,
			expected_grammar
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " rule A -> b c d" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Grammar input_grammar;
		input_grammar.terminals.insert("b");
		input_grammar.terminals.insert("c");
		input_grammar.terminals.insert("d");
		input_grammar.nonterminals.insert("A");
		input_grammar.head  = "A";
		
		Rule rule;
		rule.LHS = "A";
		rule.RHS.push_back("b");
		rule.RHS.push_back("c");
		rule.RHS.push_back("d");
		
		input_grammar.rules.push_back(rule);
		
		Chomsky_grammar expected_grammar;
		expected_grammar.terminals.insert("b");
		expected_grammar.terminals.insert("c");
		expected_grammar.terminals.insert("d");
		expected_grammar.nonterminals.insert("A");
		expected_grammar.head = "A";
		
		expected_grammar.added_nonterminals.insert("0");
		
		{
			Chomsky_rule crule;
			crule.LHS = "A";
			crule.RHS.push_back("b");
			crule.RHS.push_back("0");
			
			
			expected_grammar.rules.push_back(crule);
		}
		
		{
			Chomsky_rule crule;
			crule.LHS = "0";
			crule.RHS.push_back("c");
			crule.RHS.push_back("d");
			
			
			expected_grammar.rules.push_back(crule);
		}
		
		
		_test_break_rules(
			input_grammar,
			expected_grammar
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " rule A -> b c d e" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Grammar input_grammar;
		input_grammar.terminals.insert("b");
		input_grammar.terminals.insert("c");
		input_grammar.terminals.insert("d");
		input_grammar.terminals.insert("e");
		input_grammar.nonterminals.insert("A");
		input_grammar.head  = "A";
		
		Rule rule;
		rule.LHS = "A";
		rule.RHS.push_back("b");
		rule.RHS.push_back("c");
		rule.RHS.push_back("d");
		rule.RHS.push_back("e");
		
		input_grammar.rules.push_back(rule);
		
		Chomsky_grammar expected_grammar;
		expected_grammar.terminals.insert("b");
		expected_grammar.terminals.insert("c");
		expected_grammar.terminals.insert("d");
		expected_grammar.terminals.insert("e");
		expected_grammar.nonterminals.insert("A");
		expected_grammar.head = "A";
		
		expected_grammar.added_nonterminals.insert("0");
		expected_grammar.added_nonterminals.insert("1");
		
		{
			Chomsky_rule crule;
			crule.LHS = "A";
			crule.RHS.push_back("b");
			crule.RHS.push_back("0");
			
			
			expected_grammar.rules.push_back(crule);
		}
		
		{
			Chomsky_rule crule;
			crule.LHS = "0";
			crule.RHS.push_back("c");
			crule.RHS.push_back("1");
			
			
			expected_grammar.rules.push_back(crule);
		}
		
		{
			Chomsky_rule crule;
			crule.LHS = "1";
			crule.RHS.push_back("d");
			crule.RHS.push_back("e");
			
			
			expected_grammar.rules.push_back(crule);
		}
		
		
		_test_break_rules(
			input_grammar,
			expected_grammar
		);
	}
}


void TST_mod_parser::_test_create_new_symbol(
	const Grammar & input_grammar,
	const Chomsky_grammar expected_grammar,
	const int NO_NEW_SYMBOLS
)
{
	
	Chomskify chomskify(input_grammar);
	
	for (int i=0; i<NO_NEW_SYMBOLS; i++)
	{
		chomskify.create_new_symbol();
	}
	
	bool ok = compare(expected_grammar, chomskify.get_grammar(), "grammar");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
}
	

void TST_mod_parser::test_create_new_symbol()
{
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " terminals: [], nonterminals: [], 3 new symbols " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Grammar input_grammar;
		
		Chomsky_grammar expected_grammar;
		expected_grammar.added_nonterminals.insert("0");
		expected_grammar.added_nonterminals.insert("1");
		expected_grammar.added_nonterminals.insert("2");
		
		_test_create_new_symbol(
			input_grammar,
			expected_grammar,
			3
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " terminals: [1], nonterminals: [3], 3 new symbols " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Grammar input_grammar;
		input_grammar.terminals.insert("1");
		input_grammar.nonterminals.insert("3");
		
		Chomsky_grammar expected_grammar;
		expected_grammar.terminals.insert("1");
		expected_grammar.nonterminals.insert("3");
		
		expected_grammar.added_nonterminals.insert("0");
		expected_grammar.added_nonterminals.insert("2");
		expected_grammar.added_nonterminals.insert("4");
		
		_test_create_new_symbol(
			input_grammar,
			expected_grammar,
			3
		);
	}
}


void TST_mod_parser::_test_remove_chains(
	const Chomsky_grammar & input_grammar,
	const Chomsky_grammar & expected_grammar
)
{
	Grammar dummy;
	Chomskify chomskify(dummy);
	
	chomskify.res_grammar = input_grammar;
	chomskify.remove_chains();
	
	
	bool ok = compare(expected_grammar, chomskify.get_grammar(), "grammar");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}

}


void TST_mod_parser::test_remove_chains()
{
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " (no chains, broken rule):" << std::endl;
	std::cout << " A-> B 1" << std::endl;
	std::cout << " 1-> C D" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.terminals.insert("B");
		input_grammar.terminals.insert("C");
		input_grammar.terminals.insert("D");
		input_grammar.nonterminals.insert("A");
		input_grammar.added_nonterminals.insert("1");
		input_grammar.head  = "A";
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("B");
			rule.RHS.push_back("1");
			
			input_grammar.rules.push_back(rule);
		}
		
		{
			Chomsky_rule rule;
			rule.LHS = "1";
			rule.RHS.push_back("C");
			rule.RHS.push_back("D");
			
			input_grammar.rules.push_back(rule);
		}
		
		Chomsky_grammar expected_grammar = input_grammar;
		
		_test_remove_chains(
			input_grammar,
			expected_grammar
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " (single rue chain):" << std::endl;
	std::cout << " A-> b C" << std::endl;
	std::cout << " C -> D" << std::endl;
	std::cout << " D -> e" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.terminals.insert("b");
		input_grammar.terminals.insert("e");
		input_grammar.nonterminals.insert("A");
		input_grammar.nonterminals.insert("C");
		input_grammar.nonterminals.insert("D");
		input_grammar.head  = "A";
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("b");
			rule.RHS.push_back("C");
			
			input_grammar.rules.push_back(rule);
		}
		
		{
			Chomsky_rule rule;
			rule.LHS = "C";
			rule.RHS.push_back("D");
			
			input_grammar.rules.push_back(rule);
		}
		
		{
			Chomsky_rule rule;
			rule.LHS = "D";
			rule.RHS.push_back("e");
			
			input_grammar.rules.push_back(rule);
		}
		
		Chomsky_grammar expected_grammar = input_grammar;
		expected_grammar.rules.clear();
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("b");
			rule.RHS.push_back("c");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("C");
				replaced_symbol_index.symbols.push_back("D");
				
				rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_grammar.rules.push_back(rule);
		}
		
		_test_remove_chains(
			input_grammar,
			expected_grammar
		);
	}
}


void TST_mod_parser::_test_replace_chain_in_rule(
	const Chomsky_rule & input_rule,
	Chain_trees& chain_trees, 
	const Chomsky_rules & expected_rule
)
{
	Grammar dummy;
	Chomskify chomskify(dummy);
	
	Chomsky_rules res_rule = chomskify.replace_chain_in_rule(
		input_rule,
		0,
		chain_trees
	);
	
	
	bool ok = compare(expected_rule, res_rule, "rule");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}

}


void TST_mod_parser::test_replace_chain_in_rule()
{
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " nothing to replace:" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Chain_trees chain_trees;
		
		Chomsky_rule input_rule;
		input_rule.LHS = "A";
		input_rule.RHS.push_back("B");
		input_rule.RHS.push_back("C");
		
		
		Chomsky_rules expected_rules;
		expected_rules.push_back(input_rule);
		
		_test_replace_chain_in_rule(
			input_rule,
			chain_trees,
			expected_rules
		);
	}
	
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " first symbol to replace with a single symbol:" << std::endl;
	std::cout << " rules:" << std::endl;
	std::cout << " A -> B C" << std::endl;
	std::cout << " B -> b" << std::endl;
	std::cout << " terminals: b, C" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Chain_trees chain_trees;
		
		chain_trees["B"].symbols.push_back("b");
		chain_trees["B"].exit = false;
		chain_trees["b"].exit = true;
		
		Chomsky_rule input_rule;
		input_rule.LHS = "A";
		input_rule.RHS.push_back("B");
		input_rule.RHS.push_back("C");
		
		
		
		Chomsky_rules expected_rules;
		
		{
			Chomsky_rule expected_rule;
			expected_rule.LHS = "A";
			expected_rule.RHS.push_back("b");
			expected_rule.RHS.push_back("C");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 0;
				replaced_symbol_index.symbols.push_back("B");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_rules.push_back(expected_rule);
		}
		
		_test_replace_chain_in_rule(
			input_rule,
			chain_trees,
			expected_rules
		);
	}
	
	
}


void TST_mod_parser::_test_get_path(
	const Symbol & head,
	Chain_trees & chain_trees,
	const std::vector<Symbols> & expected_symbols_vect
)
{
	Grammar dummy;
	Chomskify chomskify(dummy);
	
	Symbols current_path;
	std::vector<Symbols> real_symbols_vect = 
		chomskify.get_path( head, current_path, chain_trees);
	
	bool ok = compare(expected_symbols_vect, real_symbols_vect, "path");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}

}


void TST_mod_parser::test_get_path()
{
	std::cout << "===============================================================" << std::endl;
	std::cout << " A[B C[D}}" << std::endl;
	std::cout << " exits: B D" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Symbol head = "A";
		
		Chain_trees chain_trees;
		
		chain_trees["A"].symbols.push_back("B");
		chain_trees["A"].symbols.push_back("C");
		
		chain_trees["C"].symbols.push_back("D");
		
		chain_trees["B"].exit = true;
		chain_trees["D"].exit = true;

		
		std::vector<Symbols> expected_symbols_vect;
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("B");
			expected_symbols_vect.push_back(tmp);
		}
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			expected_symbols_vect.push_back(tmp);
		}
		
		_test_get_path(
			head,
			chain_trees,
			expected_symbols_vect
		);
		
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " A[B C[D}}" << std::endl;
	std::cout << " exits: C" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Symbol head = "A";
		
		Chain_trees chain_trees;
		
		chain_trees["A"].symbols.push_back("B");
		chain_trees["A"].symbols.push_back("C");
		
		chain_trees["C"].symbols.push_back("D");
		
		chain_trees["C"].exit = true;

		
		std::vector<Symbols> expected_symbols_vect;
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			expected_symbols_vect.push_back(tmp);
		}
		
		_test_get_path(
			head,
			chain_trees,
			expected_symbols_vect
		);
		
	}

	std::cout << "===============================================================" << std::endl;
	std::cout << "     A     " << std::endl;
	std::cout << "    / \\   " << std::endl;
	std::cout << "   B   C   " << std::endl;
	std::cout << "    \\ /   " << std::endl;
	std::cout << "     D     " << std::endl;
	std::cout << "    / \\   " << std::endl;
	std::cout << "   E   F   " << std::endl;
	std::cout << "    \\ /   " << std::endl;
	std::cout << "     G     " << std::endl;
	std::cout << " exits: A B F G     " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Symbol head = "A";
		
		Chain_trees chain_trees;
		
		chain_trees["A"].symbols.push_back("B");
		chain_trees["A"].symbols.push_back("C");
		
		chain_trees["B"].symbols.push_back("D");
		chain_trees["C"].symbols.push_back("D");
		
		chain_trees["D"].symbols.push_back("E");
		chain_trees["D"].symbols.push_back("F");
		
		chain_trees["E"].symbols.push_back("G");
		chain_trees["F"].symbols.push_back("G");
		
		chain_trees["A"].exit = true;
		chain_trees["B"].exit = true;
		chain_trees["F"].exit = true;
		chain_trees["G"].exit = true;
		
		
		std::vector<Symbols> expected_symbols_vect;
		
		{
			Symbols tmp;
			tmp.push_back("A");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("B");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("B");
			tmp.push_back("D");
			tmp.push_back("E");
			tmp.push_back("G");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("B");
			tmp.push_back("D");
			tmp.push_back("F");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("B");
			tmp.push_back("D");
			tmp.push_back("F");
			tmp.push_back("G");
			expected_symbols_vect.push_back(tmp);
		}
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			tmp.push_back("E");
			tmp.push_back("G");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			tmp.push_back("F");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			tmp.push_back("F");
			tmp.push_back("G");
			expected_symbols_vect.push_back(tmp);
		}
		
		_test_get_path(
			head,
			chain_trees,
			expected_symbols_vect
		);
		
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "    A         " << std::endl;
	std::cout << "    |\\       " << std::endl;
	std::cout << "    | C       " << std::endl;
	std::cout << "    |/ \\     " << std::endl;
	std::cout << "    D   F     " << std::endl;
	std::cout << "     \\ /     " << std::endl;
	std::cout << "      E       " << std::endl;
	std::cout << "  exits: C D F E " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Symbol head = "A";
		
		Chain_trees chain_trees;
		
		chain_trees["A"].symbols.push_back("D");
		chain_trees["A"].symbols.push_back("C");
		
		chain_trees["C"].symbols.push_back("D");
		chain_trees["C"].symbols.push_back("F");
		
		chain_trees["D"].symbols.push_back("E");
		chain_trees["F"].symbols.push_back("E");
	
		chain_trees["C"].exit = true;
		chain_trees["D"].exit = true;
		chain_trees["F"].exit = true;
		chain_trees["E"].exit = true;

		
		
		std::vector<Symbols> expected_symbols_vect;
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("D");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("D");
			tmp.push_back("E");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			tmp.push_back("E");
			expected_symbols_vect.push_back(tmp);
		}
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("F");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("F");
			tmp.push_back("E");
			expected_symbols_vect.push_back(tmp);
		}
		
		_test_get_path(
			head,
			chain_trees,
			expected_symbols_vect
		);
		
	}
}