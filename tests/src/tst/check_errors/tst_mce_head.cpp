#include "tst_mod_check_errors.h"


void TST_mod_check_errors::_test_head_errors(
	const Head & head,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals,
	const Errors & expected_errors
)
{
	//create the class whose method will be tested
	Grammar grammar;
	Word word;
	Mod_check_errors mod_check_errors(grammar, word);
	
	//mod_check_errors performed error checking on empty grammar and word
	//leaving results in mod_check_errors.errors. The results are ignored
	mod_check_errors.errors.clear();
	
	//perform error checking
	mod_check_errors.head_check_errors(
		"", //skipping source
		head, 
		terminals, 
		nonterminals
	);
	
	//check if obtained errors are identical to expected 
	bool ok = compare_errors(expected_errors, mod_check_errors.errors);
	if (ok == true)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
	
}


void TST_mod_check_errors::test_head_errors()
{
	Non_terminals terminals;
	terminals.insert("a");
	terminals.insert("b");
	terminals.insert("c");
	
	Non_terminals nonterminals;
	nonterminals.insert("A");
	nonterminals.insert("B");
	nonterminals.insert("C");
	

	Error head_not_in_nonterminals;
	head_not_in_nonterminals.type = HEAD_NOT_IN_NONTERMINALS;
	head_not_in_nonterminals.source = "";


	Error unknown_head;
	unknown_head.type = UNKNOWN_SYMBOL;
	unknown_head.source = "";
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal head " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Head head = "A";
		
		Errors expected_errors;
		
		_test_head_errors(
			head,
			terminals, 
			nonterminals, 
			expected_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " head in terminals " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Head head = "a";
		
		Errors expected_errors;
		
		expected_errors.push_back(head_not_in_nonterminals);
		
		_test_head_errors(
			head,
			terminals, 
			nonterminals, 
			expected_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " completely unknown head " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Head head = "q";
		
		Errors expected_errors;
		
		expected_errors.push_back(head_not_in_nonterminals);
		expected_errors.push_back(unknown_head);
		
		_test_head_errors(
			head,
			terminals, 
			nonterminals, 
			expected_errors
		);
	}
}