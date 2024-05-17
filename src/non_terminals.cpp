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
