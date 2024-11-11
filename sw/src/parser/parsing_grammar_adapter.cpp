#include "parsing_grammar_adapter.h"

Parsing_grammar_adapter::Parsing_grammar_adapter(const Grammar & _grammar)
{
	for (size_t i=0; i<_grammar.rules.size(); i++)
	{
		rule_map[_grammar.rules[i].LHS].push_back(_grammar.rules[i].RHS);
	}
}

std::vector<Symbols> Parsing_grammar_adapter::get_RHS(const Symbol & LHS) const
{
	if (rule_map.find(LHS) != rule_map.end())
	{
		return rule_map.at(LHS);
	}
	else 
	{
		return std::vector<Symbols>();
	}
}
