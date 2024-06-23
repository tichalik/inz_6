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
	expected_rule2.left = "-";
	expected_rule2.right1 = "<";
	expected_rule2.right2 = ">";
	
	Rule expected_rule3;
	expected_rule3.left = "->aa";
	expected_rule3.right1 = "a->a";
	expected_rule3.right2 = "aa->";
	
	Rule expected_rule4;
	expected_rule4.left = "a-a";
	expected_rule4.right1 = "-aa>";
	expected_rule4.right2 = "a-a>";
	
	expected_rules.push_back(expected_rule1);
	expected_rules.push_back(expected_rule2);
	expected_rules.push_back(expected_rule3);
	expected_rules.push_back(expected_rule4);
	
	Errors no_errors;
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rules " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http(
			"a -> a a\n"
			"- -> < >\n"
			"->aa -> a->a aa->\n"
			"a-a -> -aa> a-a>",
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
			"- -> < >\n"
			"->aa -> a->a aa->\n"
			"a-a -> -aa> a-a>",
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
			"- -> < >\n"
			"->aa -> a->a aa->\n"
			"a-a -> -aa> a-a>\n"
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
			"a -> a a\n"
			"\n\n        \n\t  \n"
			"- -> < >\n"
			"->aa -> a->a aa->\n"
			"\n\n        \n\t  \n"
			"a-a -> -aa> a-a>",
			expected_rules,
			no_errors
		);
		
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rules -- whitespace inside rule" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http(
			"a     ->        a a     \n"
			"\t-\t->\t< \t>\t\n"
			"    ->aa     -> a->a aa->\t\t\n"
			"    a-a -> -aa>\t \ta-a>",
			expected_rules,
			no_errors
		);
		
	}
	
	
	

	// //wrong structure
	// if (1)
	// {
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " no LHS " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", " -> asasfa asasfa");
	
	
	
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple LHS (2) " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", " AASDFA AASDFA -> asasfa asasfa");
	
	
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple LHS (3) " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", " AASDFA AASDFA AASDFA -> asasfa asasfa");
	
	
	
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " no RHS " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA ->     ");
			
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " single RHS " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa ");
			
			
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple RHS (3)" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa asasfa");
		
			
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple RHS (4)" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa asasfa asasfa");


		
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple arrows" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> -> asasfa asasfa");


		
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple arrows" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa -> asasfa");


		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple arrows" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa ->");


	
	// }	
	
}