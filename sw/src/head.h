#ifndef HEAD_H
#define HEAD_H

#include <string>

#include "utils.h"
#include "errorable.h"
#include "symbol.h"
#include "non_terminals.h"

class Head: public Errorable
{
	Symbol symbol;
	
	public:
	Head() {}
	Head(const std::string & _head);
	
	void check_errors(
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	bool has_errors() const;
	
	Errors get_errors() const;
	
	
	std::string to_string() const;
};



#endif // HEAD_H
