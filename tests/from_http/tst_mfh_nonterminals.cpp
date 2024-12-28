#include "tst_mod_from_http.h"

void TST_mod_from_http::_test_nonterminals_from_http(
	const std::string & str_input,
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
	//leaving errors in mod_from_http.errors. Thes results are ignored
	mod_from_http.errors.clear();
	
	//perform the conversion
	Non_terminals result = mod_from_http.nonterminals_from_http(str_input);
	
	//check if the result is identical to expected
	bool ok_result = compare(expected, result, "nonterminals");
	
	//check if obtained errors are identical to expected 
	bool ok_errors = compare(expected_errors, mod_from_http.errors, "errors");
	if (ok_errors && ok_result)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
	
}


void TST_mod_from_http::test_nonterminals_from_http()
{
	{
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " check everything" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Non_terminals expected_nonterminals;
		expected_nonterminals.insert("<ok>");
		expected_nonterminals.insert("<ok2>");

		Errors expected_errors;

		{
			Error error;
			error.type = TERM_IN_NTERMS;
			error.source = "nonterminals: symbol bad: ";

			expected_errors.push_back(error);
		}
		{
			Error error;
			error.type = UNKNOWN_SYMBOL;
			error.source = "nonterminals: symbol !: ";

			expected_errors.push_back(error);
		}
		{
			Error error;
			error.type = UNKNOWN_SYMBOL;
			error.source = "nonterminals: symbol ::=: ";

			expected_errors.push_back(error);
		}
		{
			Error error;
			error.type = UNKNOWN_SYMBOL;
			error.source = "nonterminals: symbol |: ";

			expected_errors.push_back(error);
		}
		
		_test_nonterminals_from_http(
			"<ok> bad ! ::= |  \n <ok2>",
			expected_nonterminals,
			expected_errors
		);
	}
	
	
	{
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty nonterminals -- whitespace " << std::endl;
		std::cout << "===============================================================" << std::endl;
	
		Non_terminals expected_nonterminals;
		Errors expected_errors;
		
		{
			Error error;
			error.type = EMPTY_NONTERMINALS;
			error.source = "";

			expected_errors.push_back(error);

		}
		_test_nonterminals_from_http(
			"\n\n            \t\t \n\n\t\n     \n",
			expected_nonterminals,
			expected_errors	
		);
	}
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " check if repeating symbols in one set are caught" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Non_terminals expected_nonterminals;
		expected_nonterminals.insert("<ok>");

		Errors expected_errors;

		{
			Error error;
			error.type = REPEATING_SYMBOL;
			error.source = "nonterminals: symbol <ok>: ";

			expected_errors.push_back(error);
		}

		_test_nonterminals_from_http(
			"<ok> <ok>",
			expected_nonterminals,
			expected_errors
		);
	}
	
	
	
}
