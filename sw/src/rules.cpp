#include "rules.h"

std::string Rule::to_string() const 
{
	return "<" + left.to_string() 
		+ "> -> <" + right1.to_string()  + "> <" + right2.to_string()  +">";
}


void Rule::check_symbol_errors(
	Symbol &s,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{
	if (!terminals.contains(s) && !nonterminals.contains(s))
	{
		s.errors.push_back(UNKNOWN_SYMBOL);
	}
}

void Rule::check_errors(
	const Non_terminals& terminals,
	const Non_terminals& nonterminals)
{
	
	check_symbol_errors(left, terminals, nonterminals);
	check_symbol_errors(right1, terminals, nonterminals);
	check_symbol_errors(right2, terminals, nonterminals);
	
	if (terminals.contains(left))
	{
		this->errors.push_back(TERMINAL_AS_LHS);
	}
	
}

bool Rule::has_errors()
{
	return this->errors.size()!=0
		|| left.has_errors()
		|| right1.has_errors()
		|| right2.has_errors();
}

//--------------------------RuleSSSSSSS---------------------------

void Rules::check_errors(
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	)
{
	for (size_t i=0; i<this->size(); i++)
	{
		this->at(i).check_errors(terminals, nonterminals);
	}
}
bool Rules::has_errors()
{
	bool errors = false;
	
	for (size_t i=0; i<this->size(); i++)
	{
		errors |= this->at(i).has_errors();
	}
	
	return errors;
}