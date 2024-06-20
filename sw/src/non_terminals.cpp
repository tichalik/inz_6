#include "non_terminals.h"

Non_terminals::Non_terminals(const std::vector<std::string> & vect)
{
	for (size_t i = 0; i<vect.size(); i++)
	{
		Symbol s;
		s.symbol = vect[i];
		this->symbols.push_back(s);
	}
}
Non_terminals::Non_terminals()
{

}

std::vector<Symbol> Non_terminals::get_symbols() const
{
	return this->symbols;
}

void Non_terminals::check_for_internal_errors()
{
	for (size_t i=0; i<symbols.size(); i++)
	{
		//possible optimization?? 
		// for (size_t j=i; j<symbols.size(); j++)
			
		for (size_t j=0; j<symbols.size(); j++)
		{
			//OPTIMIZE!! ADD ERROR TO BOTH SYMBOLS, SKIP OTHER FROM 
			// ITERATION
			if (i != j && symbols[i].symbol == symbols[j].symbol)
			{
				symbols[i].add_error(REPEATING_SYMBOL);
				break;
			}
		}
	}
}

void Non_terminals::check_for_intersection_errors(const Non_terminals & other)
{
	for (size_t i=0; i<this->symbols.size(); i++)
	{
		if (other.contains(this->symbols[i]))
		{
			this->symbols[i].add_error(IN_BOTH_TERMINALS_AND_NONTERMINALS);			
		}
	}
}

bool Non_terminals::contains(const Symbol & symbol) const
{
	bool res = false;
	for (size_t i=0; i<this->symbols.size() && res == false; i++)
	{
		if (symbol.symbol == this->symbols[i].symbol)
		{
			res = true;
		}
	}
	return res;
}

bool Non_terminals::has_errors() const
{
	bool errors = false;
	for (size_t i=0; i<this->symbols.size(); i++)
	{
		errors |= this->symbols[i].has_errors();
	}
	return errors || this->errors.size() != 0;
}


Errors Non_terminals::get_errors() const
{
	Errors res;
	res.insert(res.end(), this->errors.begin(), this->errors.end());
	
	for (size_t i=0; i<this->symbols.size(); i++)
	{
		Errors tmp = this->symbols[i].get_errors();
		res.insert(res.end(), tmp.begin(), tmp.end());		
	}
	
	return res;
}