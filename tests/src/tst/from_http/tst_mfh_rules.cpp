#include "tst_mod_from_http.h"

void TST_mod_from_http::_test_rules_from_http(
	const std::string & str_input,
	const Rules & expected,
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
	Rules result = mod_from_http.rules_from_http(str_input);
	
	//check if the result is identical to expected
	bool ok_result = compare_rules(expected, result);
	
	//check if obtained errors are identical to expected 
	bool ok_errors = compare_errors(expected_errors, mod_from_http.errors);
	if (ok_errors && ok_result)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
	
}


void TST_mod_from_http::test_rules_from_http()
{
	
	Rules expected_rules;
	
	Rule expected_rule1;
	expected_rule1.left = "a";
	expected_rule1.right1 = "a";
	expected_rule1.right2 = "a";
	
	Rule expected_rule2;
	expected_rule2.left = "b";
	expected_rule2.right1 = "b";
	expected_rule2.right2 = "b";
	
	Rule expected_rule3;
	expected_rule3.left = "c";
	expected_rule3.right1 = "c";
	expected_rule3.right2 = "c";
	
	Rule expected_rule4;
	expected_rule4.left = "d";
	expected_rule4.right1 = "d";
	expected_rule4.right2 = "d";
	
	
	expected_rules.push_back(expected_rule1);
	expected_rules.push_back(expected_rule2);
	expected_rules.push_back(expected_rule3);
	expected_rules.push_back(expected_rule4);
	
	Errors no_errors;
	
	Errors empty_rules_errors;
	Error empty_rules_error;
	empty_rules_error.type = EMPTY_RULES;
	empty_rules_error.source = "";
	empty_rules_errors.push_back(empty_rules_error);
	
	Rules empty_rules;
	
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rules " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http(
			"a -> a a\n"
			"b -> b b\n"
			"c -> c c\n"
			"d -> d d",
			expected_rules,
			no_errors
		);
		
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rules -- leading whitespace before rules" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http(
			"\n\n        \n\t  \n"
			"a -> a a\n"
			"b -> b b\n"
			"c -> c c\n"
			"d -> d d",
			expected_rules,
			no_errors
		);
		
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rules -- trailing whitespace after rules" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http(
			"a -> a a\n"
			"b -> b b\n"
			"c -> c c\n"
			"d -> d d\n"
			"\n\n\n\t     \t\n ",
			expected_rules,
			no_errors
		);
		
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rules -- whitespace between rules" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http(
			"\n\n        \n\t  \n"
			"a -> a a\n"
			"\n\n        \n\t  \n"
			"b -> b b\n"
			"\n\n        \n\t  \n"
			"c -> c c\n"
			"d -> d d",
			expected_rules,
			no_errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty rules -- completely empty" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http(
			"",
			empty_rules,
			empty_rules_errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty rules -- whitespaces " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http(
			"\n\n        \n\t  \n",
			empty_rules,
			empty_rules_errors
		);
		
	}
	
	
	
}