#ifndef _NON_TERMINALS_H_
#define _NON_TERMINALS_H_

#include "symbol.h"
#include "error.h"
#include <vector>
#include <sstream>


/** 
 * \brief set of symbols used either as terminals or nonterminals
 */
class Non_terminals 
{
	
public:
	
	/** 
	 * \brief collection of symbols
	 *
	 * for now it is a vector to keep algorithms for error detection simple.
	 */
	std::vector<Symbol> symbols;
	
	
	

	/** 
	 * \brief construct the symbols from given strings
	 */
	Non_terminals(const std::vector<std::string> & vect);
	
	/** 
	 * \brief default constructor
	 *
	 * necessary as the `Grammar` object is constructed without specifying its 
	 * fields beforehand.
	 */
	Non_terminals();
	
	
	/** 
	 * \brief getter for the internal container
	 *
	 * stupid but necessary for creating html representation in `Http_grammar_adapter`
	 */
	std::vector<Symbol> get_symbols() const;
	
};

#endif //_NON_TERMINALS_H_