#include "http_grammar_adapter.h"

Http_grammar_adapter::Http_grammar_adapter(
	const std::string & http_terminals,
	const std::string & http_nonterminals,
	const std::string & http_head,
	const std::string & http_rules)
{
	terminals_from_http(http_terminals);
	nonterminals_from_http(http_nonterminals);
}


void Http_grammar_adapter::nonterminals_from_http(const std::string & param)
{	
	std::vector<std::string> str_nonterminals = Utils::vector_from_str(param);
	Non_terminals nonterminals(str_nonterminals);
	this->grammar.set_nonterminals(nonterminals);
}

void Http_grammar_adapter::terminals_from_http(const std::string & param)
{
	std::vector<std::string> str_terminals = Utils::vector_from_str(param);
	Non_terminals terminals(str_terminals);
	this->grammar.set_terminals(terminals);
}


std::string Http_grammar_adapter::rule_to_http(const Rule & rule) const 
{
	return rule.left.to_http() + " -> " 
		+ rule.right1.to_http() + " " + rule.right2.to_http();
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

std::string Http_grammar_adapter::terminals_to_http() const
{
	Non_terminals terminals = grammar.get_terminals();
	std::vector<Symbol> symbols = terminals.get_symbols();
	
	std::string res;
	for (size_t i; i< symbols.size(); i++)
	{
		res += symbols[i].symbol + " ";
	}
	
	res = res.substr(0, res.size()-1);
	
	return res ;
}
