#include "head.h"

Head::Head(const std::string & _head)
{
	symbol.symbol = _head;}
	

std::string Head::to_string() const
{
	return this->symbol.symbol;
}
