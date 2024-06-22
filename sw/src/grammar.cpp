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



	
Errors Grammar::get_errors() const
{
	Errors res;
	res.insert(res.end(), this->errors.begin(), this->errors.end());
	
	Errors terminals_errors = this->terminals.get_errors();
	Errors nonterminals_errors = this->nonterminals.get_errors();
	Errors head_errors = this->head.get_errors();
	Errors rules_errors = this->rules.get_errors();
	
	for (size_t i=0; i<terminals_errors.size(); i++)
	{
		terminals_errors[i].source.push_back("terminals");
	}
	
	for (size_t i=0; i<nonterminals_errors.size(); i++)
	{
		nonterminals_errors[i].source.push_back("nonterminals");
	}
	
	for (size_t i=0; i<head_errors.size(); i++)
	{
		head_errors[i].source.push_back("head");
	}
	
	for (size_t i=0; i<rules_errors.size(); i++)
	{
		rules_errors[i].source.push_back("rules");
	}
	
	res.insert(res.end(), terminals_errors.begin(), terminals_errors.end());
	res.insert(res.end(), nonterminals_errors.begin(), nonterminals_errors.end());
	res.insert(res.end(), head_errors.begin(), head_errors.end());
	res.insert(res.end(), rules_errors.begin(), rules_errors.end());
	
	return res;
}