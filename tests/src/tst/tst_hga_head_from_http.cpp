#include "tst_http_grammar_adapter.h"


void TST_http_grammar_adapter::test_head_from_http()
{
	{	
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal head " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			"a b c d" , "A B C D", "A", "");
			
		//obtaining the grammar
		Grammar grammar = http_grammar_adapter.get_grammar();
		grammar.check_errors();
		
		//obtaining the terminals/nonterminals
		Head head = grammar.get_head();
		Non_terminals nonterminals = grammar.get_nonterminals();
		
		std::cout << "head symbol.symbol: <" << head.symbol.symbol << ">" << std::endl;
		
		std::cout << "head symbol.errors: <" << errors2str(head.symbol.errors)<< ">" << std::endl;
		std::cout << "head symbol.has_errors(): <" << head.symbol.has_errors()<< ">" << std::endl;
		
		std::cout << "head errors: <" << errors2str(head.errors)<< ">" << std::endl;
		std::cout << "head has_errors(): <" << head.has_errors()<< ">" << std::endl;
	}
	
	{	
		std::cout << "===============================================================" << std::endl;
		std::cout << " head in terminals " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			"a b c d" , "", "a", "");
			
		//obtaining the grammar
		Grammar grammar = http_grammar_adapter.get_grammar();
		grammar.check_errors();
		
		//obtaining the terminals/nonterminals
		Head head = grammar.get_head();
		Non_terminals nonterminals = grammar.get_nonterminals();
		
		std::cout << "head symbol.symbol: <" << head.symbol.symbol << ">" << std::endl;
		
		std::cout << "head symbol.errors: <" << errors2str(head.symbol.errors)<< ">" << std::endl;
		std::cout << "head symbol.has_errors(): <" << head.symbol.has_errors()<< ">" << std::endl;
		
		std::cout << "head errors: <" << errors2str(head.errors)<< ">" << std::endl;
		std::cout << "head has_errors(): <" << head.has_errors()<< ">" << std::endl;
	}
	
	{	
		std::cout << "===============================================================" << std::endl;
		std::cout << " completely unknown head " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			"a b c d" , "", "whatevevr", "");
			
		//obtaining the grammar
		Grammar grammar = http_grammar_adapter.get_grammar();
		grammar.check_errors();
		
		//obtaining the terminals/nonterminals
		Head head = grammar.get_head();
		Non_terminals nonterminals = grammar.get_nonterminals();
		
		std::cout << "head symbol.symbol: <" << head.symbol.symbol << ">" << std::endl;
		
		std::cout << "head symbol.errors: <" << errors2str(head.symbol.errors)<< ">" << std::endl;
		std::cout << "head symbol.has_errors(): <" << head.symbol.has_errors()<< ">" << std::endl;
		
		std::cout << "head errors: <" << errors2str(head.errors)<< ">" << std::endl;
		std::cout << "head has_errors(): <" << head.has_errors()<< ">" << std::endl;
	}
	
}