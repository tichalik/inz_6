#ifndef HEAD_H
#define HEAD_H

#include <string>

#include "utils.h"
#include "errorable.h"
#include "symbol.h"
#include "non_terminals.h"

struct Head: public Errorable
{
	Symbol symbol;
	
	Head() {}
	Head(const std::string & _head);
	
	Errors get_errors() const;
	
	
	std::string to_string() const;
};



#endif // HEAD_H
