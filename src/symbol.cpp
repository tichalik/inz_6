#include "symbol.h"


bool Symbol::has_errors()
{
	return this->errors.size() != 0;
}