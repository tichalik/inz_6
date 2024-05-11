#include "grammar.h"

std::string Rule::to_string() const 
{
	return "<" + left.to_string() 
		+ "> -> <" + right1.to_string()  + "> <" + right2.to_string()  +">";
}


Nonterminals Grammar::get_nonterminals() const {return nonterminals;}
Terminals Grammar::get_terminals() const {return terminals;}
Head Grammar::get_head() const {return head;}
Rules Grammar::get_rules() const {return rules;}


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
}

std::string Grammar::to_string() const
{
	std::string res;
	
	res += "TERMINALS\n";
	res += "<" + Utils::vector2str(terminals, "> <") + ">\n";
	res += "NONTERMINALS\n";
	res += "<" + Utils::vector2str(nonterminals, "> <") + ">\n";
	res += "HEAD\n";
	res += "<" + head + ">\n";
	
	std::string str_rules;
	for (size_t i=0; i<rules.size(); i++)
	{
		str_rules += rules[i].to_string() + "\n";
	}
	
	res += "RULES\n";
	res += str_rules + "\n";
	
	return res;
}
