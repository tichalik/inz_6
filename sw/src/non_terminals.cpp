#include "non_terminals.h"

Non_terminals::Non_terminals(const std::vector<std::string> & vect):
	symbols(vect)
{
	
}
Non_terminals::Non_terminals()
{

}


bool Non_terminals::contains(const Symbol & symbol) const
{
	bool res = false;
	for (size_t i=0; i<this->symbols.size() && res == false; i++)
	{
		if (symbol == this->symbols[i])
		{
			res = true;
		}
	}
	return res;
}
