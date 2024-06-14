#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include "error.h"
#include <string>
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
	
	
	bool has_errors() const;
};


#endif //_SYMBOL_H_