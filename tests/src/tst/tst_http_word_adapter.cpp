#include "tst_http_word_adapter.h"

void TST_http_word_adapter::_test(
	const std::string & str_input,
	const Grammar & grammar
)
{
	std::cout << "------inputs-----" << std::endl
		<< "\tstr_input: <" << str_input << ">" << std::endl;
	
	std::cout << "\tgrammar.nonterminals:" << std::endl;
	show_non_terminals(grammar.nonterminals);
	std::cout << "\tgrammar.terminals:" << std::endl;
	show_non_terminals(grammar.terminals);
	
	std::cout << "-----------------" << std::endl;
		
	Http_word_adapter http_word_adapter(
		str_input
	);
		
	//obtaining the word
	Word input = http_word_adapter.get_word();
	input.check_errors(
		grammar.terminals,
		grammar.nonterminals
	);
	
	//results 
	std::cout << " input: " << std::endl;
	show_word(input);
	
	std::cout << "http_word_adapter.errors:" << errors2str(http_word_adapter.errors) << std::endl;
	std::cout << "http_word_adapter.has_errors:" << http_word_adapter.has_errors() << std::endl;
}


void TST_http_word_adapter::test()
{
	Grammar grammar;
	
	Symbol term1, term2, nterm1, nterm2;
	
	term1.symbol = "term1";
	term2.symbol = "term2";
	nterm1.symbol = "nterm1";
	nterm2.symbol = "nterm2";
	
	grammar.terminals.symbols.push_back(term1);
	grammar.terminals.symbols.push_back(term2);
	grammar.nonterminals.symbols.push_back(nterm1);
	grammar.nonterminals.symbols.push_back(nterm2);
	
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " reference -- all ok" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test( "term1 term2 term1", grammar);
	
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " whitespaces " << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test( "\nterm1    term2    \t   \nterm1\n", grammar);
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " empty field --completely empty" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test( "", grammar);
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " empty field -- whitespaces" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test( "         \t \n\n\t       ", grammar);
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " unknown symbols " << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test( "bad_symbol bad_symbol bad_symbol bad_symbol ", grammar);
	
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " nonterminals  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test( "nterm1 nterm2 nterm1", grammar);
	
	
}