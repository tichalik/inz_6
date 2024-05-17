#include "http_grammar_adapter.h"

Http_grammar_adapter::Http_grammar_adapter(
	const std::string & http_nonterminals)
{
	// nonterminals_from_http(http_nonterminals);
	std::vector<std::string> str_nonterminals = vector_from_str(http_nonterminals);
	Non_terminals _nonterminals(str_nonterminals);
	this->nonterminals = _nonterminals;
}

std::string Http_grammar_adapter::nonterminals_to_http() const
{
	std::vector<Symbol> symbols = nonterminals.get_symbols();
	
	std::string res;
	for (size_t i; i< symbols.size(); i++)
	{
		res += symbols[i].symbol + " ";
	}
	
	res = res.substr(0, res.size()-1);
	
	return res ;
}



std::vector<std::string> Http_grammar_adapter::vector_from_str(const std::string & input)
{
	std::vector<std::string> output;
	std::stringstream ss;
	ss << input;
	
	std::string s; 
	while (ss >> s)
	{
		output.push_back(s);
	}

	return output;
}
