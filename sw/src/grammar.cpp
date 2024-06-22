#include "grammar.h"


std::string Grammar::to_string() const
{
	std::string res;
	
	res += "TERMINALS\n";
	// res += "<" + Utils::vector2str(terminals, "> <") + ">\n";
	res += "NONTERMINALS\n";
	// res += "<" + Utils::vector2str(nonterminals, "> <") + ">\n";
	res += "HEAD\n";
	res += "<" + head.to_string() + ">\n";
	
	std::string str_rules;
	for (size_t i=0; i<rules.size(); i++)
	{
		str_rules += rules[i].to_string() + "\n";
	}
	
	res += "RULES\n";
	res += str_rules + "\n";
	
	return res;
}