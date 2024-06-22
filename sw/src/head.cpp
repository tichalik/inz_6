#include "head.h"

Head::Head(const std::string & _head)
{
	symbol.symbol = _head;}
	

std::string Head::to_string() const
{
	return this->symbol.symbol;
}

Errors Head::get_errors() const
{
	Errors res;
	res.insert(res.end(), this->errors.begin(), this->errors.end());
	
	Errors tmp = this->symbol.get_errors();
	res.insert(res.end(), tmp.begin(), tmp.end());		

	return res;
}