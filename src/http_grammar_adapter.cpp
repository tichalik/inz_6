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

Grammar Http_grammar_adapter::get_grammar()
{
	return this->grammar;
}


void Http_grammar_adapter::nonterminals_from_http(const std::string & param)
{	
	Nonterminals nonterminals = Utils::vector_from_str(param);
	this->grammar.set_nonterminals(nonterminals);
}

void Http_grammar_adapter::terminals_from_http(const std::string & param)
{
	Terminals terminals = Utils::vector_from_str(param);
	this->grammar.set_terminals(terminals);
}

void Http_grammar_adapter::head_from_http(const std::string & param)
{
	std::vector<Head> head = Utils::vector_from_str(param);
	this->grammar.set_head(head[0]);
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
		sss >> r.left >> tmp >> r.right1 >> r.right2;
		_tules.push_back(r);
	}
	
	this->grammar.set_rules(_tules);
}


std::string Http_grammar_adapter::nonterminals_to_http()
{
	return Utils::vector2str(this->grammar.get_nonterminals(), " ");
}

std::string Http_grammar_adapter::terminals_to_http()
{
	return Utils::vector2str(this->grammar.get_terminals(), " ");
}

std::string Http_grammar_adapter::head_to_http()
{
	return this->grammar.get_head();
}

std::string Http_grammar_adapter::rules_to_http()
{
	std::string res; 
	
	Rules rules = this->grammar.get_rules();
	
	for (size_t i=0; i< rules.size(); i++)
	{
		res += rules[i].to_http() +"\n";
	}
	res = res.substr(0, res.size()-1);
	
	return res;
}
