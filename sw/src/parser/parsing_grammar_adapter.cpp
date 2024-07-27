#include "parsing_grammar_adapter.h"



void Parsing_grammar_adapter::update_map(const Chomsky_rules & rules)
{
	for (size_t i=0; i<rules.size(); i++)
	{
		std::string key = rules[i].RHS1
			+ RULE_MAP_SEPARATOR + rules[i].RHS2;
		rule_map[key].push_back(rules[i].LHS);
	}
}

Parsing_grammar_adapter::Parsing_grammar_adapter(const Chomsky_grammar & _grammar)
{
	update_map(_grammar.orig_rules);
	update_map(_grammar.added_rules);
}

bool Parsing_grammar_adapter::has_rule(
	const Symbol & r1, const Symbol & r2) const
{
	std::string key = r1+ RULE_MAP_SEPARATOR + r2;
	if ( rule_map.find(key) == rule_map.end())
		return false;
	else
		return true;
}

std::vector<std::string> Parsing_grammar_adapter::get_rule_head(
	const Symbol & r1, const Symbol & r2) const
{
	std::string key = r1+ RULE_MAP_SEPARATOR + r2;
	return rule_map.at(key);
}
