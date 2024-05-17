#include "http_grammar_adapter.h"

Http_grammar_adapter::Http_grammar_adapter(
	const std::string & http_nonterminals)
{
	nonterminals_from_http(http_nonterminals);
}


void Http_grammar_adapter::nonterminals_from_http(const std::string & param)
{	
	std::vector<std::string> str_nonterminals = Utils::vector_from_str(param);
	Non_terminals nonterminals(str_nonterminals);
	this->grammar.set_nonterminals(nonterminals);
}

std::string Http_grammar_adapter::nonterminals_to_http() const
{
	Non_terminals nonterminals = grammar.get_nonterminals();
	std::vector<Symbol> symbols = nonterminals.get_symbols();
	
	std::string res;
	for (size_t i; i< symbols.size(); i++)
	{
		res += symbols[i].symbol + " ";
	}
	
	res = res.substr(0, res.size()-1);
	
	return res ;
}
