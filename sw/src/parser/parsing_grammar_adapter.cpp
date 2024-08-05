#include "parsing_grammar_adapter.h"

Parsing_grammar_adapter::Parsing_grammar_adapter(const Chomsky_grammar & _grammar)
{
	for (size_t i=0; i<_grammar.rules.size(); i++)
	{
		std::string key = _grammar.rules[i].RHS[0]
			+ RULE_MAP_SEPARATOR + _grammar.rules[i].RHS[1];
		rule_map[key].push_back(_grammar.rules[i].LHS);
	}
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
