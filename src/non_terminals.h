#ifndef _NON_TERMINALS_H_
#define _NON_TERMINALS_H_

#include "symbol.h"
#include "error.h"
#include <vector>

class Non_terminals 
{
	
	Errors errors;
	std::vector<Symbol> symbols;
	size_t get_index(const Symbol & symbol) const;
	
public:
	
	Non_terminals(const std::vector<std::string> & vect);
	Non_terminals();
	
	void check_for_internal_errors();
	void check_for_intersection_errors( const Non_terminals & other);
	bool contains(const Symbol & symbol) const;
	
	std::vector<Symbol> get_symbols();
	
};

#endif //_NON_TERMINALS_H_