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
		
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " unknown symbol" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
			
		{
			Error error;
			error.type = UNKNOWN_SYMBOL;
			error.source = "rules: rule start  !: symbol: !: ";
			errors.push_back(error);
		}


		{
			Error error;
			error.type = EMPTY_RULES;
			error.source = "";
			errors.push_back(error);
		}

		Rules rules;
		
		_test_rules_from_http(
			"\n !",
			rules,
			errors
		);
		
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty rules -- completely empty" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors empty_rules_errors;
		Error empty_rules_error;
		empty_rules_error.type = EMPTY_RULES;
		empty_rules_error.source = "";
		empty_rules_errors.push_back(empty_rules_error);
		
		Rules empty_rules;
		
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
	
		Errors empty_rules_errors;
		Error empty_rules_error;
		empty_rules_error.type = EMPTY_RULES;
		empty_rules_error.source = "";
		empty_rules_errors.push_back(empty_rules_error);
		
		Rules empty_rules;
	
		
		_test_rules_from_http(
			"\n\n        \n\t  \n",
			empty_rules,
			empty_rules_errors
		);
		
	}
	

		
	Rule rule1;
	{
		rule1.LHS = "<a>";
		rule1.RHS.push_back("b");
	}

	Rule rule2;
	{
		rule2.LHS = "<a>";
		rule2.RHS.push_back("c");
		rule2.RHS.push_back("d");
		rule2.RHS.push_back("e");
	}

	Rule rule3;
	{
		rule3.LHS = "<e>";
		rule3.RHS.push_back("<f>");
		rule3.RHS.push_back("<g>");
		rule3.RHS.push_back("<h>");
	}


	Rule rule4;
	{
		rule4.LHS = "<e>";
		rule4.RHS.push_back("<i>");
	}

	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rules, no initial LB, no final LB" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;

		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.push_back(rule4);
		
		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e> ::= <f> <g> <h> | <i>",
			rules,
			errors
		);
		
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal rules, initial LB, final LB" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;

		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.push_back(rule4);
		
		_test_rules_from_http(
			"\n\n\n <a> ::= b | c d e\n"
			" <e> ::= <f> <g> <h> | <i> \n\n\n",
			rules,
			errors
		);
		
	}

	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " TERMINAL_AS_LHS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
	
		{
			Error error;
			error.type = TERMINAL_AS_LHS;
			error.source = "rules: rule start  e: symbol: e: ";
			errors.push_back(error);
		}


		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		
		_test_rules_from_http(
			"\n\n\n <a> ::= b | c d e\n"
			" e ::= <f> <g> <h> | <i> \n\n\n",
			rules,
			errors
		);
		
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " STRAY OR in INIT " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{
			Error error;
			error.type = STRAY_OR;
			error.source = "rules: rule start  |: symbol: |: ";
			errors.push_back(error);
		}



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		
		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" |<e> ::= <f> <g> <h> | <i> ",
			rules,
			errors
		);
		
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " STRAY SEP in INIT " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{
			Error error;
			error.type = MISSING_LHS;
			error.source = "rules: rule start  ::=: symbol: ::=: ";
			errors.push_back(error);
		}



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		
		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" ::=<e> ::= <f> <g> <h> | <i> ",
			rules,
			errors
		);
		
	}

	{ 
		std::cout << "===============================================================" << std::endl;
		std::cout << " TOO_MANY_LHS " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{
			Error error;
			error.type = TOO_MANY_LHS;
			error.source = "rules: rule start  <e><A>: symbol: <A>: ";
			errors.push_back(error);
		}



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.back().RHS.clear();
		
		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e><A> ::= <f> <g> <h> | <i> ",
			rules,
			errors
		);
		
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " STRAY OR in HEAD_FOUND " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{
			Error error;
			error.type = STRAY_OR;
			error.source = "rules: rule start  <e>|: symbol: |: ";
			errors.push_back(error);
		}



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.back().RHS.clear();
		
		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e>| ::= <f> <g> <h> | <i> ",
			rules,
			errors
		);
		
	}
		{ 
		std::cout << "===============================================================" << std::endl;
		std::cout << " TOO_MANY_LHS " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{
			Error error;
			error.type = TOO_MANY_LHS;
			error.source = "rules: rule start  <e><A>: symbol: <A>: ";
			errors.push_back(error);
		}



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.back().RHS.clear();
		
		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e><A> ::= <f> <g> <h> | <i> ",
			rules,
			errors
		);
		
	}

	 {
		std::cout << "===============================================================" << std::endl;
		std::cout << " STRAY OR in SEP_FOUND " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{ 
			Error error;
			error.type = STRAY_OR;
			error.source = "rules: rule start  <e> ::= |: symbol: |: ";
			errors.push_back(error);
		}



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.back().RHS.clear();
		
		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e> ::= |<f> <g> <h> | <i> ",
			rules,
			errors
		);
		
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " STRAY LB in SEP_FOUND " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{
			Error error;
			error.type = MISSING_RHS;
			error.source = "rules: rule start  <e> ::=\n: symbol: \n: ";
			errors.push_back(error);
		} 



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.back().RHS.clear();
		
		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e> ::=\n <f> <g> <h> | <i> ",
			rules,
			errors
		);
		
	} 
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " STRAY SEP in SEPD_FOUND " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{
			Error error;
			error.type = STRAY_SEP;
			error.source = "rules: rule start  <e> ::=::=: symbol: ::=: ";
			errors.push_back(error);
		} 



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.back().RHS.clear();
		
		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e> ::=::= <f> <g> <h> | <i> ",
			rules,
			errors
		);
		
	} 

		 {
		std::cout << "===============================================================" << std::endl;
		std::cout << " STRAY OR in SEP_FOUND " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{ 
			Error error;
			error.type = STRAY_OR;
			error.source = "rules: rule start  <e> ::= |: symbol: |: ";
			errors.push_back(error);
		}



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.back().RHS.clear();
		
		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e> ::= |<f> <g> <h> | <i> ",
			rules,
			errors
		);
		
	}

	 {
		std::cout << "===============================================================" << std::endl;
		std::cout << " STRAY LB in ALT_FOUND " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{
			Error error;
			error.type = STRAY_LB;
			error.source = "rules: rule start  <e> ::= <f> <g> <h> |\n: symbol: \n: ";
			errors.push_back(error);
		}  



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.push_back(rule4);
		rules.back().RHS.clear();

		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e> ::= <f> <g> <h> |\n <i> ",
			rules,
			errors
		);
		
	} 
	 {
		std::cout << "===============================================================" << std::endl;
		std::cout << " STRAY SEP in ALT_FOUND " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		
		{
			Error error;
			error.type = STRAY_SEP;
			error.source = "rules: rule start  <e> ::= <f> <g> <h> |::=: symbol: ::=: ";
			errors.push_back(error);
		}  



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.push_back(rule4);
		rules.back().RHS.clear();


		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e> ::= <f> <g> <h> |::= <i> ",
			rules,
			errors
		);
		
	} 
	 { 
		std::cout << "===============================================================" << std::endl;
		std::cout << " STRAY OR in ALT_FOUND " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Errors errors;
		 
		{ 
			Error error;
			error.type = STRAY_OR;
			error.source = "rules: rule start  <e> ::= <f> <g> <h> ||: symbol: |: ";
			errors.push_back(error);
		}  



		Rules rules;
		rules.push_back(rule1);
		rules.push_back(rule2);
		rules.push_back(rule3);
		rules.push_back(rule4);
		rules.back().RHS.clear();


		_test_rules_from_http(
			" <a> ::= b | c d e\n"
			" <e> ::= <f> <g> <h> || <i> ",
			rules,
			errors
		);
		
	} 
}
