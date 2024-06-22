#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include "errorable.h"

#include <string>
struct Symbol: public Errorable
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
	
	Errors get_errors() const;
	
};


#endif //_SYMBOL_H_