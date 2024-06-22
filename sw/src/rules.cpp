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
	if (!terminals.contains(s) && !nonterminals.contains(s) && s.symbol != "")
	{
		s.add_error(UNKNOWN_SYMBOL);
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
		this->add_error(TERMINAL_AS_LHS);
	}
	
}

bool Rule::has_errors()
{
	return this->errors.size()!=0
		|| left.has_errors()
		|| right1.has_errors()
		|| right2.has_errors();
}


Errors Rule::get_errors() const
{
	Errors res;
	res.insert(res.end(), this->errors.begin(), this->errors.end());
	
	Errors left_errors = this->left.get_errors();
	Errors right1_errors = this->right1.get_errors();
	Errors right2_errors = this->right2.get_errors();
	
	res.insert(res.end(), left_errors.begin(), left_errors.end());
	res.insert(res.end(), right1_errors.begin(), right1_errors.end());
	res.insert(res.end(), right2_errors.begin(), right2_errors.end());
	
	for (size_t i=0; i<res.size(); i++)
	{
		res[i].source.push_back("rule "+this->to_string());
	}
	
	
	return res;
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


Errors Rules::get_errors() const
{
	Errors res;
	
	for (size_t i=0; i<this->size(); i++)
	{
		Errors tmp = this->at(i).get_errors();
		res.insert(res.end(), tmp.begin(), tmp.end());		
	}
	
	return res;
}