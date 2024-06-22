#include "symbol.h"

Errors Symbol::get_errors() const
{
	Errors res = this->errors;
	for (size_t i=0; i<res.size(); i++)
	{
		res[i].source.push_back("symbol <"+this->symbol+">");
	}
	
	return res;
}