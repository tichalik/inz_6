#include "tst_http_grammar_adapter.h"

void TST_http_grammar_adapter::_test_head_from_http(
	const std::string & str_terminals,
	const std::string & str_nonterminals,
	const std::string & str_head
)
{
	std::cout << "------inputs-----" << std::endl
		<< "\tterminals: <" << str_terminals << ">" << std::endl
		<< "\tnonterminals: <" << str_nonterminals << ">" << std::endl
		<< "\thead: <" << str_head << ">" << std::endl
		<< "-----------------" << std::endl;
	
	Http_grammar_adapter http_grammar_adapter(
		str_terminals,
		str_nonterminals,
		str_head,
		""
	);
		
	//obtaining the grammar
	Grammar grammar = http_grammar_adapter.get_grammar();
	grammar.check_errors();
	
	//obtaining the head
	Head head = grammar.get_head();
	
	std::cout << "head symbol.symbol: <" << head.symbol.symbol << ">" << std::endl;
	
	std::cout << "head symbol.errors: <" << errors2str(head.symbol.errors)<< ">" << std::endl;
	std::cout << "head symbol.get_errors(): <" << errors2str(head.symbol.get_errors())<< ">" << std::endl;
	std::cout << "head symbol.has_errors(): <" << head.symbol.has_errors()<< ">" << std::endl;
	
	std::cout << "head errors: <" << errors2str(head.errors)<< ">" << std::endl;
	std::cout << "head has_errors(): <" << head.has_errors()<< ">" << std::endl;
	std::cout << "head get_errors(): <" << errors2str(head.get_errors())<< ">" << std::endl;
}

void TST_http_grammar_adapter::test_head_from_http()
{
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " normal head " << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_head_from_http(
		"a b c d" , "A B C D", "A");
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " head in terminals " << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_head_from_http(
		"a b c d" , "", "a");

	std::cout << "===============================================================" << std::endl;
	std::cout << " completely unknown head " << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_head_from_http(
		"a b c d" , "", "whatevevr");
	
}
