#include "grammar.h"

std::string Rule::to_string() const 
{
	return "<" + left.to_string() 
		+ "> -> <" + right1.to_string()  + "> <" + right2.to_string()  +">";
}


Non_terminals Grammar::get_nonterminals() const {return nonterminals;}
Non_terminals Grammar::get_terminals() const {return terminals;}
Head Grammar::get_head() const {return head;}
Rules Grammar::get_rules() const {return rules;}


void Grammar::set_nonterminals(const Non_terminals & _nonterminals)
{
	nonterminals = _nonterminals;
}


void Grammar::set_terminals(const Non_terminals & _terminals)
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


void Grammar::check_errors()
{
	terminals.check_for_internal_errors();
	nonterminals.check_for_internal_errors();
	
	terminals.check_for_intersection_errors(nonterminals);
	nonterminals.check_for_intersection_errors(terminals);
	
	// if (terminals.contains(head))
	// {
		// errors.push_back(HEAD_IN_TERMINALS);
	// }
	// if (!nonterminals.contains(head))
	// {
		// errors.push_back(HEAD_NOT_IN_NONTERMINALS);
	// }
}

bool Grammar::has_errors()
{
	return this->errors.size() != 0 
		|| this->nonterminals.has_errors()
		|| this->terminals.has_errors();
}