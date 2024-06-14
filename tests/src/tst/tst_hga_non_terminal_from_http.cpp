#include "tst_http_grammar_adapter.h"


void TST_http_grammar_adapter::test_terminals_and_nonterminals(
	const std::string & str_terminals,
	const std::string & str_nonterminals
)
{
	//simulated http input
	std::string http_input = "a b w c w d";
	
	//http adapter -- filling head and rules with dummies
	Http_grammar_adapter http_grammar_adapter(
		str_terminals, str_nonterminals, http_input, http_input);
		
	//obtaining the grammar
	Grammar grammar = http_grammar_adapter.get_grammar();
	grammar.check_errors();
	
	//obtaining the terminals/nonterminals
	Non_terminals terminals = grammar.get_terminals();
	Non_terminals nonterminals = grammar.get_nonterminals();
	
	
	std::cout << "input terminals: <" << str_terminals << ">" << std::endl;
	std::cout << "input nonterminals: <" << str_nonterminals << ">" << std::endl;
	
	std::cout << "------------------terminals------------------------" << std::endl;
	show_non_terminals(terminals);
	std::cout << "---------------nonterminals------------------------" << std::endl;
	show_non_terminals(nonterminals);
	
}


void TST_http_grammar_adapter::test_non_terminal_from_http()
{
	std::cout << "===============================================================" << std::endl;
	std::cout << " check if repeating symbols in one set are caught" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	test_terminals_and_nonterminals( "a b c d a", "A B C D");
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " check if intersecting symbols are caught" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	test_terminals_and_nonterminals( "a b c d", "a B C D");
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " check if repeating and intersecting symbols are caught" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	test_terminals_and_nonterminals( "a b c d a", "a B C D a");
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " check if blank lines are ok" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	test_terminals_and_nonterminals( "a b \n\n\n\n d ", "A \nB\n C\n D");
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " check if spaces are ok" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	test_terminals_and_nonterminals( "a b      c      d            ", "            A \nB    C D");
	
	
	// THIS IS A TEST FOR THE HTTP_GRAMMAR_ADAPTER ITSELF
	// std::cout << "===============================================================" << std::endl;
	// std::cout << " check if empty fields are caught" << std::endl;
	// std::cout << "===============================================================" << std::endl;
	
	// test_terminals_and_nonterminals( "", "A B C D");

	
}