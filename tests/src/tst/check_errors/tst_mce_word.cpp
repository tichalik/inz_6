#include "tst_mod_check_errors.h"


void TST_mod_check_errors::_test_word_errors(
	const Word & word,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals,
	const Errors & expected_errors
)
{
	//create the class whose method will be tested
	Grammar grammar;
	Word _word;
	Mod_check_errors mod_check_errors(grammar, _word);
	
	//mod_check_errors performed error checking on empty grammar and word
	//leaving results in mod_check_errors.errors. The results are ignored
	mod_check_errors.errors.clear();
	
	//perform error checking
	mod_check_errors.word_check_errors(
		"", //skipping source
		word, 
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


void TST_mod_check_errors::test_word_errors()
{
	Non_terminals terminals;
	terminals.insert("a");
	terminals.insert("b");
	terminals.insert("c");
	
	Non_terminals nonterminals;
	nonterminals.insert("A");
	nonterminals.insert("B");
	nonterminals.insert("C");
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " reference -- all ok" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Word word;
		word.push_back("a");
		word.push_back("b");
		word.push_back("a");
		word.push_back("c");
		word.push_back("c");
		
		Errors expected_errors;
		
		_test_word_errors( 
			word,
			terminals,
			nonterminals,
			expected_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " unknown symbols " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Word word;
		word.push_back("a");
		word.push_back("b");
		word.push_back("z");
		word.push_back("c");
		word.push_back("q");
		
		Errors expected_errors;
		
		Error error1;
		error1.type = UNKNOWN_SYMBOL;
		error1.source = " symbol <z>:";
		expected_errors.push_back(error1);
		
		Error error2;
		error2.type = UNKNOWN_SYMBOL;
		error2.source = " symbol <q>:";
		expected_errors.push_back(error2);
		
		_test_word_errors( 
			word,
			terminals,
			nonterminals,
			expected_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " nonterminals  " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Word word;
		word.push_back("a");
		word.push_back("b");
		word.push_back("A");
		word.push_back("c");
		word.push_back("B");
		
		Errors expected_errors;
		
		Error error1;
		error1.type = SYMBOL_IN_NONTERMINALS;
		error1.source = " symbol <A>:";
		expected_errors.push_back(error1);
		
		Error error2;
		error2.type = SYMBOL_IN_NONTERMINALS;
		error2.source = " symbol <B>:";
		expected_errors.push_back(error2);
		
		_test_word_errors( 
			word,
			terminals,
			nonterminals,
			expected_errors
		);
	}
	
}