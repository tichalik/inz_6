#include "http_grammar_adapter.h"

Http_grammar_adapter::Http_grammar_adapter(
	const std::string & http_terminals,
	const std::string & http_nonterminals,
	const std::string & http_head,
	const std::string & http_rules)
{
	terminals_from_http(http_terminals);
	nonterminals_from_http(http_nonterminals);
	head_from_http(http_head);
	rules_from_http(http_rules);
}

Http_grammar_adapter::Http_grammar_adapter( const Grammar & _grammar):
	grammar(_grammar)
{
	
}

Grammar Http_grammar_adapter::get_grammar() const
{
	return this->grammar;
}


void Http_grammar_adapter::nonterminals_from_http(const std::string & param)
{	
	std::vector<std::string> str_nonterminals = Utils::vector_from_str(param);
	if (str_nonterminals.size() == 0)
	{
		Error_desc error;
		error.error = EMPTY_FIELD;
		error.description = "empty nonterminals";
		this->errors.push_back(error);
	}
	else 
	{
		Non_terminals nonterminals(str_nonterminals);
		this->grammar.set_nonterminals(nonterminals);
	}
}

void Http_grammar_adapter::terminals_from_http(const std::string & param)
{
	std::vector<std::string> str_terminals = Utils::vector_from_str(param);
	if (str_terminals.size() == 0)
	{
		Error_desc error;
		error.error = EMPTY_FIELD;
		error.description = "empty terminals";
		this->errors.push_back(error);
	}
	else 
	{
		Non_terminals terminals(str_terminals);
		this->grammar.set_terminals(terminals);
	}
}

void Http_grammar_adapter::head_from_http(const std::string & param)
{
	std::vector<Head> head = Utils::vector_from_str(param);
	if (head.size() == 0)
	{
		Error_desc error;
		error.error = EMPTY_FIELD;
		error.description = "empty head";
		this->errors.push_back(error);
	}
	else if (head.size() >1)
	{
		Error_desc error;
		error.error = MULTIPLE_HEADS;
		error.description = "";
		this->errors.push_back(error);
	}
	else 
	{
		this->grammar.set_head(head[0]);
	}
}

void Http_grammar_adapter::rules_from_http(const std::string & param)
{
	std::vector<Rule> _tules;
	
	std::stringstream ss;
	ss << param;

	std::string line;
	while(std::getline(ss, line))
	{
		std::string tmp;
		Rule r; 
		std::stringstream sss; 
		sss << line;
		sss >> r.left.symbol >> tmp >> r.right1.symbol >> r.right2.symbol;
		_tules.push_back(r);
	}
	
	this->grammar.set_rules(_tules);
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
	for (size_t i=0; i< symbols.size(); i++)
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
	for (size_t i=0; i< symbols.size(); i++)
	{
		res += symbols[i].symbol + " ";
	}
	
	res = res.substr(0, res.size()-1);
	
	return res ;
}

std::string Http_grammar_adapter::head_to_http() const
{
	return this->grammar.get_head();
}

std::string Http_grammar_adapter::rules_to_http() const
{
	std::string res; 
	
	Rules rules = this->grammar.get_rules();
	
	for (size_t i=0; i< rules.size(); i++)
	{
		res += rule_to_http(rules[i]) + "\n";
	}
	res = res.substr(0, res.size()-1);
	
	return res;
}
