#include "symbol.h"


bool Symbol::has_errors() const
{
	return this->errors.size() != 0;
}


Errors Symbol::get_errors() const
{
	return this->errors;
}