#ifndef _NON_TERMINALS_H_
#define _NON_TERMINALS_H_

#include "symbol.h"
#include <vector>


/** 
 * \brief set of symbols used either as terminals or nonterminals
 */
struct Non_terminals
{
	
	/** 
	 * \brief collection of symbols
	 *
	 * for now it is a vector to keep algorithms for error detection simple.
	 */
	std::vector<Symbol> symbols;
	
	
	/** 
	 * \brief get position of first symbol with matching `symbol` field
	 *
	 * Only the symbol fields are matched. If no symbol is found, returns size 
	 * of the symbol collection. 
	 */
	size_t get_index(const Symbol & symbol) const;
	

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
	 * \brief whether a symbol of given `symbol` field is present in the container
	 */
	bool contains(const Symbol & symbol) const;
	
	
};

#endif //_NON_TERMINALS_H_