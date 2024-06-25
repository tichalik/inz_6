#include "tst_mod_check_errors.h"



void TST_mod_check_errors::_test_non_terminals_errors(
	const Non_terminals& input,
	const Non_terminals & other,
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
	mod_check_errors.non_terminals_check_errors(
		"", //skipping source
		input, 
		other
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


void TST_mod_check_errors::test_non_terminals_errors()
{
	Non_terminals other;
	other.insert("a");
	other.insert("b");
	other.insert("c");
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal case -- all ok" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Non_terminals input;
		input.insert("A");
		input.insert("B");
		input.insert("C");
		input.insert("D");
		
		Errors expected_errors;
		
		_test_non_terminals_errors(
			input, 
			other,
			expected_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " check if intersecting symbols are caught" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Non_terminals input;
		input.insert("a");
		input.insert("B");
		input.insert("C");
		input.insert("D");
		
		Errors expected_errors;
		
		Error error1;
		error1.type = IN_BOTH_TERMINALS_AND_NONTERMINALS;
		error1.source = "symbol <a>:";
		expected_errors.push_back(error1);
		
		_test_non_terminals_errors(
			input, 
			other,
			expected_errors
		);
	}
}