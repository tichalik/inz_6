#include "tst_mod_parser.h"



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



