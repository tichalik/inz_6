#include "tst_mod_from_http.h"

void TST_mod_from_http::_test_non_terminals_from_http(
	const std::string & str_input,
	const bool is_nonterminals,
	const Non_terminals & expected,
	const Errors & expected_errors
)
{
	//create the class whose method will be tested
	//initialize it with all empty strings
	Mod_from_http mod_from_http(
		"",
		"",
		"",
		"",
		""
	);

	
	//mod_from_http extracted Grammar and Word from empty strings 
	//leaving errors in mod_check_errors.errors. Thes results are ignored
	mod_from_http.errors.clean();
	
	//perform the conversion
	Non_terminals result = mod_from_http.non_terminals_from_http(str_input, is_nonterminals);
	
	//check if the result is identical to expected
	bool ok_result = compare_non_terminals(expected, result)
	
	//check if obtained errors are identical to expected 
	bool ok_errors = compare_errors(expected_errors, mod_check_errors.errors);
	if (ok_errors && ok_result)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
	
}


void TST_mod_from_http::test_non_terminal_from_http()
{
	Errors no_errors;
	
	Errors empty_nonterminals;

	Error error1;
	error1.type = EMPTY_NONTERMINALS;
	error1.source = "";
	empty_nonterminals.push_back(error1);
	
	Errors empty_terminals;

	Error error2;
	error2.type = EMPTY_TERMINALS;
	error2.source = "";
	empty_terminals.push_back(error2);
	
	Non_terminals expected_non_terminals;
	expected_non_terminals.push_back("a");
	expected_non_terminals.push_back("b");
	expected_non_terminals.push_back("c");
	expected_non_terminals.push_back("d");
	
	Non_terminals empty_non_terminals;
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << "normal non_terminals -- single space separation " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_non_terminals_from_http(
			"a b c d",
			false, 
			expected_non_terminals,
			no_errors
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << "normal non_terminals -- leading whitespace " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_non_terminals_from_http(
			"         \t \n\na b c d",
			false, 
			expected_non_terminals,
			no_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << "normal non_terminals -- trailing whitespace " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_non_terminals_from_http(
			"a b c d\n\n\t      \t\n",
			false, 
			expected_non_terminals,
			no_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << "normal non_terminals -- whitespace in between" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_non_terminals_from_http(
			"a\nb\tc \n\n     \t\t d            ", "            A \nB    C D",
			false, 
			expected_non_terminals,
			no_errors
		);
	}
	
	
	{
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty nonterminals -- completely empty " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_non_terminals_from_http(
			"",
			true, 
			empty_non_terminals,
			empty_nonterminals
		);
	}
	
	{
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty nonterminals -- whitespace " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_non_terminals_from_http(
			"\n\n            \t\t \n\n\t\n     \n",
			true, 
			empty_non_terminals,
			empty_nonterminals
		);
	}
	
	{
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty terminals -- completely empty " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_non_terminals_from_http(
			"",
			false, 
			empty_non_terminals,
			empty_terminals
		);
	}
	
	{
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty terminals -- whitespace " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_non_terminals_from_http(
			"\n\n            \t\t \n\n\t\n     \n",
			false, 
			empty_non_terminals,
			empty_terminals
		);
	}
}