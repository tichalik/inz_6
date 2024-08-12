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
	
	
	bool ok = compare_chomsky_grammar(expected_grammar, chomskify.get_grammar());
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
	
	bool ok = compare_chomsky_grammar(expected_grammar, chomskify.get_grammar());
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