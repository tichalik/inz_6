#include "tst_mod_from_http.h"

void TST_mod_from_http::_test_terminals_from_http(
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
	bool ok_result = compare(expected, result, "nonterminals") ;
	
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


void TST_mod_from_http::test_terminals_from_http()
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
	expected_non_terminals.insert("a");
	expected_non_terminals.insert("b");
	expected_non_terminals.insert("c");
	expected_non_terminals.insert("d");
	
	Non_terminals empty_non_terminals;
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << "normal non_terminals -- single space separation " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_terminals_from_http(
			"a b c d",
			expected_non_terminals,
			no_errors
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << "normal non_terminals -- leading whitespace " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_terminals_from_http(
			"         \t \n\na b c d",
			expected_non_terminals,
			no_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << "normal non_terminals -- trailing whitespace " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_terminals_from_http(
			"a b c d\n\n\t      \t\n",
			expected_non_terminals,
			no_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << "normal non_terminals -- whitespace in between" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_terminals_from_http(
			"a\nb\tc \n\n     \t\t d           \n\n ", 
			expected_non_terminals,
			no_errors
		);
	}
	
	
	{
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty nonterminals -- completely empty " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_terminals_from_http(
			"",
			empty_non_terminals,
			empty_terminals
		);
	}
	
	{
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty nonterminals -- whitespace " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_terminals_from_http(
			"\n\n            \t\t \n\n\t\n     \n",
			empty_non_terminals,
			empty_terminals
		);
	}
	
	{
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty terminals -- completely empty " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_terminals_from_http(
			"",
			empty_non_terminals,
			empty_terminals
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " check if repeating symbols in one set are caught" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors expected_errors;
		
		Error error1;
		error1.type = REPEATING_SYMBOL;
		error1.source = "terminals: symbol <b>:";
		expected_errors.push_back(error1);
		
		_test_terminals_from_http(
			"a b c d b",
			expected_non_terminals,
			expected_errors
		);
	}
	
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << "special character non_terminals " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Non_terminals special_non_terminals;
		special_non_terminals.insert("!");
		special_non_terminals.insert("@");
		special_non_terminals.insert("#");
		special_non_terminals.insert("$");
		special_non_terminals.insert("%");
		special_non_terminals.insert("^");
		special_non_terminals.insert("&");
		special_non_terminals.insert("*");
		special_non_terminals.insert("(");
		special_non_terminals.insert(")");
		special_non_terminals.insert("[");
		special_non_terminals.insert("]");
		special_non_terminals.insert("{");
		special_non_terminals.insert("}");
		special_non_terminals.insert(".");
		special_non_terminals.insert(",");
		special_non_terminals.insert(":");
		special_non_terminals.insert(";");
		special_non_terminals.insert("\"");
		special_non_terminals.insert("\\");
		special_non_terminals.insert("'");
		special_non_terminals.insert("<");
		special_non_terminals.insert(">");
		special_non_terminals.insert("/");
		special_non_terminals.insert("?");
		special_non_terminals.insert("|");
		special_non_terminals.insert("_");
		special_non_terminals.insert("-");
		special_non_terminals.insert("+");
		special_non_terminals.insert("=");
		
		_test_terminals_from_http(
			"! @ # $ % ^ & * ( ) [ ] { } . , : ; \" \\ ' < > / ? | _ - + =",
			special_non_terminals,
			no_errors
		);
	}
}
