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
		case REPEATING_SYMBOL:
			res = "REPEATING_SYMBOL";
			break;
		case IN_BOTH_TERMINALS_AND_NONTERMINALS:
			res = "IN_BOTH_TERMINALS_AND_NONTERMINALS";
			break;
		// case MALFORMED_RULE:
			// res = "MALFORMED_RULE";
			// break;
		case UNKNOWN_SYMBOL:
			res = "UNKNOWN_SYMBOL";
			break;
		// case NON_CHOMSKY_RULE:
			// res = "NON_CHOMSKY_RULE";
			// break;
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
	std::vector<Symbol> symbols = nt.get_symbols();
	for (size_t i=0; i<symbols.size(); i++)
	{
		std::cout << "<" << symbols[i].symbol << ">"
			<< "\t" << errors2str(symbols[i].errors) << std::endl;
	}
}

void Tester::test_non_terminal_from_http()
{
	//simulated http input
	std::string http_input = "a b w c w d";
	
	//http adapter -- filling head and rules with dummies
	Http_grammar_adapter http_grammar_adapter(
		http_input, http_input,http_input, http_input);
		
	//obtaining the grammar
	Grammar grammar = http_grammar_adapter.get_grammar();
	
	//obtaining the terminals/nonterminals
	Non_terminals terminals = grammar.get_terminals();
	Non_terminals nonterminals = grammar.get_nonterminals();
	
	show_non_terminals(terminals);
	show_non_terminals(nonterminals);
	
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
