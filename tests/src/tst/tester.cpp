#include "tester.h"


void Tester::test_non_terminal_to_http()
{
	//simulated http input
	std::string http_input = "a b w c w d";
	
	//http adapter -- filling head and rules with dummies
	Http_grammar_adapter http_grammar_adapter(
		http_input, http_input,http_input, http_input);
		
	std::cout << http_grammar_adapter.nonterminals_to_http() << std::endl;
}


std::string word2str(const Word &w)
{
    std::string res;
    for (size_t i=0; i<w.size(); i++)
        res += w[i].symbol + " ";
    return res;
}
