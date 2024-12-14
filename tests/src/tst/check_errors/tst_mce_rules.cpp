#include "tst_mod_check_errors.h"


void TST_mod_check_errors::_test_rules_errors(
	const Rules & rules,
	const Non_terminals& terminals,
	const Non_terminals& nonterminals,
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
	mod_check_errors.rules_check_errors(
		"", //skipping source
		rules, 
		terminals, 
		nonterminals
	);
	
	//check if obtained errors are identical to expected 
	bool ok = compare(expected_errors, mod_check_errors.errors, "errors");
	if (ok == true)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
	
}


void TST_mod_check_errors::test_rules_errors()
{
	Non_terminals terminals;
	terminals.insert("a");
	terminals.insert("b");
	terminals.insert("c");
	
	Non_terminals nonterminals;
	nonterminals.insert("A");
	nonterminals.insert("B");
	nonterminals.insert("C");
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " normal rule -- all nonterminals" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Rules rules;
		rules["A"] = {{"B","C"}};
		
		Errors expected_errors;
		
		_test_rules_errors(
			rules, 
			terminals,
			nonterminals,
			expected_errors
		);
	}
	std::cout << "===============================================================" << std::endl;
	std::cout << " normal rule -- RHS all terminals" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Rules rules;
		rules["A"] = {{"b","c"}};
		
		Errors expected_errors;
		
		_test_rules_errors(
			rules, 
			terminals,
			nonterminals,
			expected_errors
		);
	}
	std::cout << "===============================================================" << std::endl;
	std::cout << " normal rule -- RHS1 as terminal" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Rules rules;
		rules["A"] = {{"b","C"}};
		
		Errors expected_errors;
		
		_test_rules_errors(
			rules, 
			terminals,
			nonterminals,
			expected_errors
		);
	}
	std::cout << "===============================================================" << std::endl;
	std::cout << " normal rule -- RHS2 as terminal" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Rules rules;
		rules["A"] = {{"B","c"}};
		
		Errors expected_errors;
		
		_test_rules_errors(
			rules, 
			terminals,
			nonterminals,
			expected_errors
		);
	}
	std::cout << "===============================================================" << std::endl;
	std::cout << " LSH in terminals " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Rules rules;
		rules["a"] = {{"b","c"}};
		
		Errors expected_errors;
		
		Error error1;
		error1.type = TERMINAL_AS_LHS;
		error1.source = " rule <a -> b c >: symbol <a>:";
		expected_errors.push_back(error1);
		
		
		_test_rules_errors(
			rules, 
			terminals,
			nonterminals,
			expected_errors
		);
	}
	std::cout << "===============================================================" << std::endl;
	std::cout << " unknown symbols " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Rules rules;
		rules["x"] = {{"y","z"}};
		
		Errors expected_errors;
		
		Error error1;
		error1.type = UNKNOWN_SYMBOL;
		error1.source = " rule <x -> y z >: symbol <x>:";
		expected_errors.push_back(error1);
		
		Error error2;
		error2.type = UNKNOWN_SYMBOL;
		error2.source = " rule <x -> y z >: symbol <y>:";
		expected_errors.push_back(error2);
		
		Error error3;
		error3.type = UNKNOWN_SYMBOL;
		error3.source = " rule <x -> y z >: symbol <z>:";
		expected_errors.push_back(error3);
		
		
		_test_rules_errors(
			rules, 
			terminals,
			nonterminals,
			expected_errors
		);
	}
	
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " unknown symbols -- many char symbols " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Rules rules;
		rules["xxx"] = {{"yyy","zzz"}};
		
		Errors expected_errors;
		
		Error error1;
		error1.type = UNKNOWN_SYMBOL;
		error1.source = " rule <xxx -> yyy zzz >: symbol <xxx>:";
		expected_errors.push_back(error1);
		
		Error error2;
		error2.type = UNKNOWN_SYMBOL;
		error2.source = " rule <xxx -> yyy zzz >: symbol <yyy>:";
		expected_errors.push_back(error2);
		
		Error error3;
		error3.type = UNKNOWN_SYMBOL;
		error3.source = " rule <xxx -> yyy zzz >: symbol <zzz>:";
		expected_errors.push_back(error3);
		
		
		_test_rules_errors(
			rules, 
			terminals,
			nonterminals,
			expected_errors
		);
	}
	
	
}
