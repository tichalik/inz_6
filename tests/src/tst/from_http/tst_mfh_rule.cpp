#include "tst_mod_from_http.h"

void TST_mod_from_http::_test_rule_from_http(
	const std::string & str_input,
	const Rule & expected,
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
	Rule result = mod_from_http.rule_from_http(str_input);
	
	//check if the result is identical to expected
	bool ok_result = compare_rule(expected, result);
	
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


void TST_mod_from_http::test_rule_from_http()
{
		
	Rule expected_rule;
	expected_rule.left = "a";
	expected_rule.right1 = "a";
	expected_rule.right2 = "a";
	
	
	Errors no_errors;
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rule <a -> a a> " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rule_from_http(
			"a -> a a",
			expected_rule,
			no_errors
		);
		
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rule <a -> a a>, tabs as separators " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rule_from_http(
			"a\t->\ta\ta",
			expected_rule,
			no_errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rule <a -> a a> with leading whitespaces" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rule_from_http(
			"   \t\t a -> a a",
			expected_rule,
			no_errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rule <a -> a a> with trailing whitespaces" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rule_from_http(
			"a -> a a\t     \t",
			expected_rule,
			no_errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rule <a -> a a> with whitespaces inbetween" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rule_from_http(
			"a     ->\t\t    \ta       a",
			expected_rule,
			no_errors
		);
		
	}
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " evil rule <- -> < >> " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
			
		Rule expected_rule2;
		expected_rule2.left = "-";
		expected_rule2.right1 = "<";
		expected_rule2.right2 = ">";
		
		
		_test_rule_from_http(
			"- -> < >",
			expected_rule2,
			no_errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " evil rule <->aa -> a->a aa->> " << std::endl;
		std::cout << "===============================================================" << std::endl;
					
		Rule expected_rule3;
		expected_rule3.left = "->aa";
		expected_rule3.right1 = "a->a";
		expected_rule3.right2 = "aa->";

		
		_test_rule_from_http(
			"->aa -> a->a aa->",
			expected_rule3,
			no_errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " evil rule <a-a -> -aa> > " << std::endl;
		std::cout << "===============================================================" << std::endl;
						
		Rule expected_rule4;
		expected_rule4.left = "a-a";
		expected_rule4.right1 = "-aa>";
		expected_rule4.right2 = "a-a>";
		
		
		_test_rule_from_http(
			"->aa -> a->a aa->",
			expected_rule4,
			no_errors
		);
		
	}
	

	// //wrong structure
	// if (1)
	// {
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " no LHS " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", " -> asasfa asasfa");
	
	
	
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple LHS (2) " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", " AASDFA AASDFA -> asasfa asasfa");
	
	
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple LHS (3) " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", " AASDFA AASDFA AASDFA -> asasfa asasfa");
	
	
	
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " no RHS " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA ->     ");
			
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " single RHS " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa ");
			
			
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple RHS (3)" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa asasfa");
		
			
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple RHS (4)" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa asasfa asasfa");


		
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple arrows" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> -> asasfa asasfa");


		
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple arrows" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa -> asasfa");


		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple arrows" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa ->");


	
	// }	
	
}