#include "tester.h"

void save_file(const std::string &filename, const std::string &content)
{
	std::ofstream file(filename);
	if (file)
	{
		file << content;
		file.close();
	}
	else
	{
		std::cout << "cannot open file <<" << filename << ">>" << std::endl;
	}
}

std::string word2str(const Word &w)
{
    std::string res;
    for (size_t i=0; i<w.size(); i++)
        res += w[i].symbol + " ";
    return res;
}

void Tester::test_html_response()
{
	Html_response response;
	
	save_file("html_resp_tests/empty.html", response.get_response());
	
	
	response.fill_response(RESP_FIELDS::HEAD,"TESTING");
	save_file("html_resp_tests/head_filled.html", response.get_response());
	
	response.fill_response(RESP_FIELDS::TERMINALS,"TESTING");
	save_file("html_resp_tests/terminals_filled.html", response.get_response());
	
	response.fill_response(RESP_FIELDS::NONTERMINALS,"TESTING");
	save_file("html_resp_tests/nonterminals_filled.html", response.get_response());
	
	response.fill_response(RESP_FIELDS::RULES,"TESTING");
	save_file("html_resp_tests/rules_filled.html", response.get_response());
	
	response.fill_response(RESP_FIELDS::INPUT,"TESTING");
	save_file("html_resp_tests/input_filled.html", response.get_response());
	
	response.reset();
	save_file("html_resp_tests/reset.html", response.get_response());
	
}

std::string error2str(const EN_ERROR_TYPE &error)
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

std::string errors2str(Errors errors)
{
	std::string res;
    for (size_t i=0; i<errors.size(); i++)
        res += error2str(errors[i])+ " ";
    return res;
}

void show_non_terminals(const Non_terminals & nt)
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

void test_terminals_and_nonterminals(
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

void Tester::test_non_terminal_from_http()
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

void Tester::test_non_terminal_to_http()
{
	//simulated http input
	std::string http_input = "a b w c w d";
	
	//http adapter -- filling head and rules with dummies
	Http_grammar_adapter http_grammar_adapter(
		http_input, http_input,http_input, http_input);
		
	std::cout << http_grammar_adapter.nonterminals_to_http() << std::endl;
}

void Tester::test_infix_chomsky_grammar()
{

	// Grammar infix_chomsky_grammar;
	// Terminals terminals = {"A","+","-","*","/", "(",")"};
	// Nonterminals nonterminals = {"exp","exp1","exp2"};
	// Head head = "exp";

	// Rules rules = {
		// {"exp","exp1", "exp" },
		// {"exp","exp2", ")" },
		// {"exp","exp2", ")" }, // adding ambiguity

		// {"exp1","exp", "+" },
		// {"exp1","exp", "-" },
		// {"exp1","exp", "*" },
		// {"exp1","exp", "/" },

		// {"exp2","(", "exp" },
		// {"exp3","(", "exp" }  // adding ambiguity
	// };

	// infix_chomsky_grammar.set_terminals(terminals);
	// infix_chomsky_grammar.set_nonterminals(nonterminals);
	// infix_chomsky_grammar.set_head(head);
	// infix_chomsky_grammar.set_rules(rules);

	// std::vector<Word> words = {
		// {"exp", "+", "exp"},
		// {"(", "exp", "-", "exp", ")"},
		// {"exp", "*", "(", "exp", "-", "exp", ")"},
		// {"exp", "+", "exp", "*", "(", "exp", "-", "exp", ")"},
	// };

    // Parser p;
	// for (size_t i=0; i<words.size(); i++)
	// {
		// std::cout
			// << "-------------------------------------------------------" << std::endl
			// << word2str(words[i]) << std::endl
			// << "-------------------------------------------------------" << std::endl;


		// PTrees trees = p.parse(words[i], infix_chomsky_grammar);
		// for (size_t i=0; i<trees.size(); i++)
		// {
            // std::cout << trees[i].to_string() << std::endl;
		// }

	// }
}


std::string error_descs2str(std::vector<Error_desc> errors)
{
	std::string res;
	for (size_t i=0; i<errors.size(); i++)
	{
		res += "(" + error2str(errors[i].error) + ", " + errors[i].description + ") ";
	}
	return res;
}


void Tester::test_http_grammar_adapter_errors()
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

void Tester::test_head_from_http()
{
	//head as unknown symbol 
	//head in terminals
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