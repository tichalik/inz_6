#include "tst_http_grammar_adapter.h"

void TST_http_grammar_adapter::_test_rules_from_http(
	const std::string & str_terminals,
	const std::string & str_nonterminals,
	const std::string & str_head,
	const std::string & str_rules
)
{
	std::cout << "------inputs-----" << std::endl
		<< "\tterminals: <" << str_terminals << ">" << std::endl
		<< "\tnonterminals: <" << str_nonterminals << ">" << std::endl
		<< "\thead: <" << str_head << ">" << std::endl
		<< "\trules: <" << str_rules << ">" << std::endl
		<< "-----------------" << std::endl;
		
	Http_grammar_adapter http_grammar_adapter(
		str_terminals,
		str_nonterminals, 
		str_head,
		str_rules
	);
		
	//obtaining the grammar
	Grammar grammar = http_grammar_adapter.get_grammar();
	grammar.check_errors();
	
	//obtaining the terminals/nonterminals
	Rules rules = grammar.get_rules();
	
	std::cout << "rules lenght : " << rules.size() << std::endl;
	std::cout << "rules get_errors() : " << errors2str(rules.get_errors()) << std::endl;
	std::cout << "rules has_errors : " << rules.has_errors() << std::endl;
	
	for (size_t i=0; i<rules.size();i++)
	{
		std::cout << "------rule " << i << "----------" << std::endl;
		Rule rule = rules[i];
		
		std::cout << std::endl;
		std::cout << "\trule.left.symbol : <" << rule.left.symbol << ">" << std::endl;
		std::cout << "\trule.left.errors : <" << errors2str(rule.left.errors) << ">" << std::endl;
		std::cout << "\trule.left.get_errors : <" << errors2str(rule.left.get_errors()) << ">" << std::endl;
		std::cout << "\trule.left has_errors : " << rule.left.has_errors() << std::endl;
		
		std::cout << std::endl;
		std::cout << "\trule.right1.symbol : <" << rule.right1.symbol << ">" << std::endl;
		std::cout << "\trule.right1.errors : <" << errors2str(rule.right1.errors) << ">" << std::endl;
		std::cout << "\trule.right1.get_errors : <" << errors2str(rule.right1.get_errors()) << ">" << std::endl;
		std::cout << "\trule.right1 has_errors : " << rule.right1.has_errors() << std::endl;
		
		std::cout << std::endl;
		std::cout << "\trule.right2.symbol : <" << rule.right2.symbol << ">" << std::endl;
		std::cout << "\trule.right2.errors : <" << errors2str(rule.right2.errors) << ">" << std::endl;
		std::cout << "\trule.right2.get_errors : <" << errors2str(rule.right2.get_errors()) << ">" << std::endl;
		std::cout << "\trule.right2 has_errors : " << rule.right2.has_errors() << std::endl;
		
		
		std::cout << std::endl;
		std::cout << "\trule.errors : <" << errors2str(rule.errors) << ">" << std::endl;
		std::cout << "\trule.get_errors : <" << errors2str(rule.get_errors()) << ">" << std::endl;
		std::cout << "\trule has_errors : " << rule.has_errors() << std::endl;
		
	}
}

void TST_http_grammar_adapter::test_rules_from_http()
{
	//head as unknown symbol 
	//head in terminals
		
	std::cout << "===============================================================" << std::endl;
	std::cout << " normal single rule " << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_rules_from_http("a" , "A", "A", "A -> a a");

	
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " normal single rule -- multiple characters for symbol " << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa");
	
	// newlines
	if (1)
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal single rule -- leading newlines (empty) " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "\n\nAASDFA -> asasfa asasfa");
		
		
			
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal single rule -- trailing newlines (empty) " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa\n\n");
		
		
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal single rule -- newlines (filled with whitespace) " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "\n    \n\t  AASDFA -> asasfa asasfa\n    \n \t    ");
		
	}
	
	// whitespaces
	if (1)
	{
	
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal single rule -- leading whitespace " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "     \t  AASDFA -> asasfa asasfa");
		
		
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal single rule -- trailing whitespace " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa      ");
		
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal single rule -- whitespace between RHS " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa           asasfa");
		
		
			
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal single rule -- whitespace after the arraow " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA ->         asasfa asasfa");
		
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal single rule -- whitespace before the arraow " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA           -> asasfa asasfa");
	
	}
		
	//multiple rules
	if (1)
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal multiple rules " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa b c" , "AASDFA", "AASDFA", 
			"AASDFA -> asasfa asasfa\n"
			"AASDFA -> b asasfa\n"
			"AASDFA -> c b"
		);
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal multiple rules with newlines between (empty)" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa b c" , "AASDFA", "AASDFA", 
			"\n"
			"AASDFA -> asasfa asasfa\n"
			"\n"
			"\n"
			"AASDFA -> b asasfa\n"
			"\n"
			"AASDFA -> c b"
			"\n"
		);
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal multiple rules with newlines between (whitespace filled)" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa b c" , "AASDFA", "AASDFA", 
			"\n"
			"AASDFA -> asasfa asasfa\n"
			"      \n"
			" \t\t     \n"
			"AASDFA -> b asasfa\n"
			"           \n"
			"AASDFA -> c b"
			"\t\t \t \n"
		);
		
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal multiple rules with errors" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("a b c" , "A", "A", 
			"\n"
			"A ->  A\n"
			"a -> b \n"
			"A -> G b"
		);
	}

	//wrong structure
	if (1)
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " no LHS " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", " -> asasfa asasfa");
	
	
	
		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple LHS (2) " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", " AASDFA AASDFA -> asasfa asasfa");
	
	
		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple LHS (3) " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", " AASDFA AASDFA AASDFA -> asasfa asasfa");
	
	
	
		std::cout << "===============================================================" << std::endl;
		std::cout << " no RHS " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA ->     ");
			
		std::cout << "===============================================================" << std::endl;
		std::cout << " single RHS " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa ");
			
			
		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple RHS (3)" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa asasfa");
		
			
		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple RHS (4)" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa asasfa asasfa");


		
		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple arrows" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> -> asasfa asasfa");


		
		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple arrows" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa -> asasfa");


		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple arrows" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa ->");


	
	}	
	
	//non/terminals-related errors 
	if (1)
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " unknown symbols " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("" , "", "", "AASDFA -> asasfa asasfa");
	
		std::cout << "===============================================================" << std::endl;
		std::cout << " LSH in terminals " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("a" , "A", "A", "a -> a a");
	
	
	}
	
	// multiple errors
	if (1)
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " unknown symbols + multiple arrows " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("" , "", "", "AASDFA -> asasfa -> asasfa");
	
		std::cout << "===============================================================" << std::endl;
		std::cout << " LSH in terminals + too much RHS + unknown symbol in rhs" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("a" , "A", "A", "a -> b a a");
	
		std::cout << "===============================================================" << std::endl;
		std::cout << " LSH in terminals + too much LHS + unknown symbol in LHS and RHS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_rules_from_http("a" , "A", "A", "a b -> b a a");
	
	
	}
}