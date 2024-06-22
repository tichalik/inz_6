#ifndef HEAD_H
#define HEAD_H

#include <string>

#include "utils.h"
#include "symbol.h"
#include "non_terminals.h"

struct Head
{
	Symbol symbol;
	
	Head() {}
	Head(const std::string & _head);
	
	std::string to_string() const;
};



#endif // HEAD_H
