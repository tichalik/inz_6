#include "tst_mod_from_http.h"

void TST_mod_from_http::_test_rule_from_http(
	const std::string & str_input,
	const bool expected_ok,
	const Rule & expected,
	const Errors & expected_errors
)
{
//	//create the class whose method will be tested
//	//initialize it with all empty strings
//	Mod_from_http mod_from_http(
//		"",
//		"",
//		"",
//		"",
//		""
//	);
//
//	
//	//mod_from_http extracted Grammar and Word from empty strings 
//	//leaving errors in mod_from_http.errors. Thes results are ignored
//	mod_from_http.errors.clear();
//	
//	bool ok;
//	
//	//perform the conversion
//	Rule result = mod_from_http.rule_from_http(str_input, ok);
//	
//	if (ok != expected_ok)
//	{
//		std::cout << "wrong ok " << std::endl;
//	}
//	
//	bool ok_result = true;
//	//check if the result is identical to expected
//	// but when there are errors, the rule does not matter
//	if (expected_ok == true)
//	{
//		ok_result = compare(expected, result, "rule");
//	}
//	
//	//check if obtained errors are identical to expected 
//	bool ok_errors = compare(expected_errors, mod_from_http.errors, "errors");
//	if (ok_errors && ok_result && ok == expected_ok)
//	{
//		std::cout << "OK" << std::endl;
//	}
//	else
//	{
//		std::cout << __FILE__ << "\tFAIL" << std::endl;
//	}
//	
}


void TST_mod_from_http::test_rule_from_http()
{
		
	Rule expected_rule;
	expected_rule.LHS = "a";
	expected_rule.RHS.push_back("a");
	expected_rule.RHS.push_back("a");
	
	
	Errors no_errors;
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rule <a -> a a> " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rule_from_http(
			"a -> a a",
			true,
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
			true,
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
			true,
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
			true,
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
			true,
			expected_rule,
			no_errors
		);
		
	}
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " evil rule <- -> < >> " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
			
		Rule expected_rule2;
		expected_rule2.LHS = "-";
		expected_rule2.RHS.push_back("<");
		expected_rule2.RHS.push_back(">");
		
		
		_test_rule_from_http(
			"- -> < >",
			true,
			expected_rule2,
			no_errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " evil rule <->aa -> a->a aa->> " << std::endl;
		std::cout << "===============================================================" << std::endl;
					
		Rule expected_rule3;
		expected_rule3.LHS = "->aa";
		expected_rule3.RHS.push_back("a->a");
		expected_rule3.RHS.push_back("aa->");

		
		_test_rule_from_http(
			"->aa -> a->a aa->",
			true,
			expected_rule3,
			no_errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " evil rule <a-a -> -aa> a-a>> " << std::endl;
		std::cout << "===============================================================" << std::endl;
						
		Rule expected_rule4;
		expected_rule4.LHS = "a-a";
		expected_rule4.RHS.push_back("-aa>");
		expected_rule4.RHS.push_back("a-a>");
		
		
		_test_rule_from_http(
			"a-a -> -aa> a-a>",
			true,
			expected_rule4,
			no_errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " apparently problematic rule <exp -> exp1 exp >" << std::endl;
		std::cout << "===============================================================" << std::endl;
						
		Rule expected_rule4;
		expected_rule4.LHS = "exp";
		expected_rule4.RHS.push_back("exp1");
		expected_rule4.RHS.push_back("exp");
		
		
		_test_rule_from_http(
			"exp -> exp1 exp ",
			true,
			expected_rule4,
			no_errors
		);
		
	}
	
	Rule dummy_rule;

	//wrong structure
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " no LHS " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		std::string str_rule = " -> a b";
		
		Error error;
		error.type = MISSING_LHS;
		error.source = "rule " + str_rule + ": ";
		
		Errors expected_errors;
		expected_errors.push_back(error);
		
		
		_test_rule_from_http(
			str_rule,
			false,
			dummy_rule,
			expected_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple LHS (2) " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		std::string str_rule = " AASDFA AASDFA -> asasfa asasfa";
		
		Error error;
		error.type = TOO_MANY_LHS;
		error.source = "rule " + str_rule + ": ";
		
		Errors expected_errors;
		expected_errors.push_back(error);
		
		
		_test_rule_from_http(
			str_rule,
			false,
			dummy_rule,
			expected_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " no RHS " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		std::string str_rule = " AASDFA -> ";
		
		Error error;
		error.type = MISSING_RHS;
		error.source = "rule " + str_rule + ": ";
		
		Errors expected_errors;
		expected_errors.push_back(error);
		
		
		_test_rule_from_http(
			str_rule,
			false,
			dummy_rule,
			expected_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple arrows" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		std::string str_rule = " AASDFA -> -> asasfa asasfa";
		
		Error error;
		error.type = MULTIPLE_ARROWS;
		error.source = "rule " + str_rule + ": ";
		
		Errors expected_errors;
		expected_errors.push_back(error);
		
		
		_test_rule_from_http(
			str_rule,
			false,
			dummy_rule,
			expected_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple arrows" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		std::string str_rule = " AASDFA -> asasfa -> A asasfa";
		
		Error error;
		error.type = MULTIPLE_ARROWS;
		error.source = "rule " + str_rule + ": ";
		
		Errors expected_errors;
		expected_errors.push_back(error);
		
		
		_test_rule_from_http(
			str_rule,
			false,
			dummy_rule,
			expected_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " no arrow" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		std::string str_rule = " AASDFA AASDFA asasfa asasfa";
		
		Error error;
		error.type = MISSING_ARROW;
		error.source = "rule " + str_rule + ": ";
		
		Errors expected_errors;
		expected_errors.push_back(error);
		
		
		_test_rule_from_http(
			str_rule,
			false,
			dummy_rule,
			expected_errors
		);
	}
	
	// {
		
		// std::cout << "===============================================================" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> -> asasfa asasfa");

	// }
	// {
		
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple arrows" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa -> asasfa");

	// }
	// {

		// std::cout << "===============================================================" << std::endl;
		// std::cout << " multiple arrows" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rule_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa ->");

	// }	
	
}
