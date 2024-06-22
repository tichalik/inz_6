#ifndef _SYMBOL_H_
#define _SYMBOL_H_


#include <string>
struct Symbol
{
	std::string symbol;
	
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