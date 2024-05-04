#include "grammar.h"


bool Grammar::has_rule(const Symbol & r1, const Symbol & r2) const
{
	std::string key = r1 + RULE_MAP_SEPARATOR + r2;
	if ( rule_map.find(key) == rule_map.end())
		return false;
	else
		return true;
}

std::vector<Symbol> Grammar::get_rule_head(const Symbol & r1, const Symbol & r2) const
{
	std::string key = r1 + RULE_MAP_SEPARATOR + r2;
	return rule_map.at(key);
}



Nonterminals Grammar::get_nonterminals() {return nonterminals;}
Terminals Grammar::get_terminals() {return terminals;}
Head Grammar::get_head() {return head;}
Rules Grammar::get_rules() {return rules;}


void Grammar::set_nonterminals(const Nonterminals & _nonterminals)
{
	nonterminals = _nonterminals;
}


void Grammar::set_terminals(const Terminals & _terminals)
{
	terminals = _terminals;
}


void Grammar::set_head(const Head & _head)
{
	head = _head;
}


void Grammar::set_rules(const Rules & _rules)
{
	rules = _rules;

	for (size_t i=0; i<rules.size(); i++)
	{
		std::string key = rules[i].right1 + RULE_MAP_SEPARATOR + rules[i].right2;
		rule_map[key].push_back(rules[i].left);
	}
}

void Grammar::nonterminals_from_http(const std::string & param)
{

}
void Grammar::terminals_from_http(const std::string & param)
{

}
void Grammar::head_from_http(const std::string & param)
{

}
void Grammar::rules_from_http(const std::string & param)
{

}

std::string Grammar::nonterminals_to_http()
{

}
std::string Grammar::terminals_to_http()
{

}
std::string Grammar::head_to_http()
{

}
std::string Grammar::rules_to_http()
{

}
