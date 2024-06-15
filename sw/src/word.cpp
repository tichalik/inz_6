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