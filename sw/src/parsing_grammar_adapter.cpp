#include "parsing_grammar_adapter.h"

Parsing_grammar_adapter::Parsing_grammar_adapter(const Grammar & _grammar)
{
	const Rules rules = _grammar.rules;
	for (size_t i=0; i<rules.size(); i++)
	{
		std::string key = rules[i].right1
			+ RULE_MAP_SEPARATOR + rules[i].right2;
		rule_map[key].push_back(rules[i].left);
	}
}

bool Parsing_grammar_adapter::has_rule(
	const std::string & r1, const std::string & r2) const
{
	std::string key = r1+ RULE_MAP_SEPARATOR + r2;
	if ( rule_map.find(key) == rule_map.end())
		return false;
	else
		return true;
}

std::vector<std::string> Parsing_grammar_adapter::get_rule_head(
	const std::string & r1, const std::string & r2) const
{
	std::string key = r1+ RULE_MAP_SEPARATOR + r2;
	return rule_map.at(key);
}
