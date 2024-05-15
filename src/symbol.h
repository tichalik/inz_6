#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include "error.h"
#include <string>

// typedef std::string Symbol;

struct Symbol
{
	std::string symbol;
	Errors errors;
	
	inline std::string to_string() const
	{
		return symbol;
	}
	inline std::string to_http() const
	{
		return symbol;
	}
};


#endif //_SYMBOL_H_