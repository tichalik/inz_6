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
