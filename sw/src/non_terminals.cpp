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
