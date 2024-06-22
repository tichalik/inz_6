#include "word.h"

bool Word::has_errors() const
{
	bool errors = false;
	for (size_t i=0; i<this->symbols.size(); i++)
	{
		errors |= this->symbols[i].has_errors();
	}
	return errors || this->errors.size() != 0;
}

std::vector<Symbol> Word::get_symbols() const
{
	return this->symbols;
}

void Word::check_errors(
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{
	for (size_t i=0; i<this->symbols.size(); i++)
	{
		if (!terminals.contains(this->symbols[i])
			&& !nonterminals.contains(this->symbols[i]))
		{
			this->symbols[i].add_error(UNKNOWN_SYMBOL);			
		}
		
		if (nonterminals.contains(this->symbols[i]))
		{
			this->symbols[i].add_error(SYMBOL_IN_NONTERMINALS);			
		}
		
	}
}

Errors Word::get_errors() const
{
	Errors ;
	res.insert(res.end(), this->errors.begin(), this->errors.end());
	
	for (size_t i=0; i<this->symbols.size(); i++)
	{
		Errors tmp = this->symbols[i].get_errors();
		res.insert(res.end(), tmp.begin(), tmp.end());		
	}
	
	for (size_t i=0; i<res.size(); i++)
	{
		res[i].source.push_back("input");
	}
	
	return res;
}