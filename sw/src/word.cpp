#include "word.h"


std::vector<Symbol> Word::get_symbols() const
{
	return this->symbols;
}

Errors Word::get_errors() const
{
	Errors res;
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
