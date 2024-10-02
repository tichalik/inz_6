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
	bool ok_result = compare(expected, result, "rules");
	
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


void TST_mod_from_http::test_rules_from_http()
{
	
	Rules expected_rules;
	
	Rule expected_rule1;
	expected_rule1.LHS = "a";
	expected_rule1.RHS[0] = "a";
	expected_rule1.RHS[1] = "a";
	
	Rule expected_rule2;
	expected_rule2.LHS = "b";
	expected_rule2.RHS[0] = "b";
	expected_rule2.RHS[1] = "b";
	
	Rule expected_rule3;
	expected_rule3.LHS = "c";
	expected_rule3.RHS[0] = "c";
	expected_rule3.RHS[1] = "c";
	
	Rule expected_rule4;
	expected_rule4.LHS = "d";
	expected_rule4.RHS[0] = "d";
	expected_rule4.RHS[1] = "d";
	
	
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
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " apparently problematic rules" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Rules rules;
		
		Rule r1;
		r1.LHS = "exp";
		r1.RHS[0] = "exp1";
		r1.RHS[1] = "exp";
		rules.push_back(r1);
		
		Rule r2;
		r2.LHS = "exp";
		r2.RHS[0] = "exp2";
		r2.RHS[1] = ")";
		rules.push_back(r2);
		
		Rule r3;
		r3.LHS = "exp";
		r3.RHS[0] = "exp2";
		r3.RHS[1] = ")";
		rules.push_back(r3);
		
		Rule r4;
		r4.LHS = "exp1";
		r4.RHS[0] = "exp";
		r4.RHS[1] = "+";
		rules.push_back(r4);
		
		Rule r5;
		r5.LHS = "exp1";
		r5.RHS[0] = "exp";
		r5.RHS[1] = "-";
		rules.push_back(r5);
		
		Rule r6;
		r6.LHS = "exp1";
		r6.RHS[0] = "exp";
		r6.RHS[1] = "/";
		rules.push_back(r6);
		
		Rule r7;
		r7.LHS = "exp1";
		r7.RHS[0] = "exp";
		r7.RHS[1] = "*";
		rules.push_back(r7);
		
		Rule r8;
		r8.LHS = "exp2";
		r8.RHS[0] = "(";
		r8.RHS[1] = "exp";
		rules.push_back(r8);
		
		
		
		_test_rules_from_http(
			"exp -> exp1 exp \n"
			"exp -> exp2 )\n"
			"exp -> exp2 )\n"
			"exp1 -> exp  +\n"
			"exp1 -> exp  -\n"
			"exp1 -> exp  /\n"
			"exp1 -> exp  *\n"
			"exp2 -> ( exp\n",
			rules,
			no_errors
		);
		
	}
	
	
	
}