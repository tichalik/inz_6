#ifndef HEAD_H
#define HEAD_H

#include <string>

#include "utils.h"
#include "error.h"
#include "symbol.h"
#include "non_terminals.h"

class Head
{
	Symbol symbol;
	Errors errors;
	
	public:
	Head() {}
	Head(const std::string & _head);
	
	void check_errors(
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	bool has_errors() const;
	
	std::string to_string() const;
};



#endif // HEAD_H
