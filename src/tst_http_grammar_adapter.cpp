#include "tst_http_grammar_adapter.h"


std::string TST_http_grammar_adapter::error2str(const EN_ERROR_TYPE &error)
{
	std::string res;
	switch (error)
	{
		case EMPTY_FIELD:
			res="EMPTY_FIELD";
			break;
		case UNKNOWN_SYMBOL:
			res="UNKNOWN_SYMBOL";
			break;
		case REPEATING_SYMBOL:
			res="REPEATING_SYMBOL";
			break;
		case IN_BOTH_TERMINALS_AND_NONTERMINALS:
			res="IN_BOTH_TERMINALS_AND_NONTERMINALS";
			break;
		case MISSING_LHS:
			res="MISSING_LHS";
			break;
		case TOO_MANY_LHS:
			res="TOO_MANY_LHS";
			break;
		case TOO_FEW_RHS:
			res="TOO_FEW_RHS";
			break;
		case TOO_MANY_RHS:
			res="TOO_MANY_RHS";
			break;
		case MISSING_ARROW:
			res="MISSING_ARROW";
			break;
		case MULTIPLE_ARROWS:
			res="MULTIPLE_ARROWS";
			break;
		case TERMINAL_AS_LHS:
			res="TERMINAL_AS_LHS";
			break;
		case HEAD_NOT_IN_NONTERMINALS:
			res="HEAD_NOT_IN_NONTERMINALS";
			break;
		case MULTIPLE_HEADS:
			res="MULTIPLE_HEADS";
			break;
		default:
			break;
	}
	
	return res;
}

std::string TST_http_grammar_adapter::errors2str(Errors errors)
{
	std::string res;
    for (size_t i=0; i<errors.size(); i++)
        res += error2str(errors[i])+ " ";
    return res;
}

void TST_http_grammar_adapter::show_non_terminals(const Non_terminals & nt)
{
	std::cout << "symbols: [<symbol>\\terrors\\thas_errors()]" << std::endl;
	std::vector<Symbol> symbols = nt.get_symbols();
	for (size_t i=0; i<symbols.size(); i++)
	{
		std::cout << "<" << symbols[i].symbol << ">"
			<< "\t" << errors2str(symbols[i].errors) 
			<< "\t" << symbols[i].has_errors() << std::endl;
	}
	std::cout << "errors: " << std::endl << errors2str(nt.errors) << std::endl; 
	std::cout << "has_errors(): " << std::endl << nt.has_errors() << std::endl; 
}

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

std::string TST_http_grammar_adapter::error_descs2str(std::vector<Error_desc> errors)
{
	std::string res;
	for (size_t i=0; i<errors.size(); i++)
	{
		res += "(" + error2str(errors[i].error) + ", " + errors[i].description + ") ";
	}
	return res;
}


void TST_http_grammar_adapter::test_http_grammar_adapter_errors()
{
	std::string str_ok_terminals = "a b c d";
	std::string str_ok_nonterminals = "A B C D";
	std::string str_ok_head = "A";
	std::string str_ok_rules = 
		"A -> B b\n"
		"B -> A C\n"
		"C -> a D\n"
		"D -> c d\n";
		
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " reference -- all fields filled" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			str_ok_terminals,
			str_ok_nonterminals,
			str_ok_head,
			str_ok_rules
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty terminals" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			"",
			str_ok_nonterminals,
			str_ok_head,
			str_ok_rules
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty nonterminals" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			str_ok_terminals,
			"",
			str_ok_head,
			str_ok_rules
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty head" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			str_ok_terminals,
			str_ok_nonterminals,
			"",
			str_ok_rules
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty rules" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			str_ok_terminals,
			str_ok_nonterminals,
			str_ok_head,
			""
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty everything" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			"",
			"",
			"",
			""
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
		
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " double head " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			str_ok_terminals,
			str_ok_nonterminals,
			"A A A",
			str_ok_rules
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	
}

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
	std::cout << "rules has_errors : " << rules.has_errors() << std::endl;
	
	for (size_t i=0; i<rules.size();i++)
	{
		std::cout << "------rule " << i << "----------" << std::endl;
		Rule rule = rules[i];
		
		std::cout << std::endl;
		std::cout << "\trule.left.symbol : <" << rule.left.symbol << ">" << std::endl;
		std::cout << "\trule.left.errors : <" << errors2str(rule.left.errors) << ">" << std::endl;
		std::cout << "\trule.left has_errors : " << rule.left.has_errors() << std::endl;
		
		std::cout << std::endl;
		std::cout << "\trule.right1.symbol : <" << rule.right1.symbol << ">" << std::endl;
		std::cout << "\trule.right1.errors : <" << errors2str(rule.right1.errors) << ">" << std::endl;
		std::cout << "\trule.right1 has_errors : " << rule.right1.has_errors() << std::endl;
		
		std::cout << std::endl;
		std::cout << "\trule.right2.symbol : <" << rule.right2.symbol << ">" << std::endl;
		std::cout << "\trule.right2.errors : <" << errors2str(rule.right2.errors) << ">" << std::endl;
		std::cout << "\trule.right2 has_errors : " << rule.right2.has_errors() << std::endl;
		
		
		std::cout << std::endl;
		std::cout << "\trule.errors : <" << errors2str(rule.errors) << ">" << std::endl;
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
	if (0)
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
	if (0)
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
	if (0)
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
	
	// //non/terminals-related errors 
	// if (true)
	// {
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " " << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_rules_from_http("asasfa" , "AASDFA", "AASDFA", "AASDFA -> asasfa asasfa");
	
	// }
}