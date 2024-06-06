#ifndef _NON_TERMINALS_H_
#define _NON_TERMINALS_H_

#include "symbol.h"
#include "error.h"
#include <vector>


/** 
 * \brief set of symbols used either as terminals or nonterminals
 */
class Non_terminals 
{
	
	Errors errors;
	
	
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
	
public:

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
	 * \brief check if symbols repeat
	 *
	 * Repeating symbols are marked with proper error message
	 */
	void check_for_internal_errors();
	
	/** 
	 * \brief check if there are symbols common to this object and the parameter
	 *
	 * common symbols are marked with proper error message. Applies only to this 
	 * object.
	 */
	void check_for_intersection_errors( const Non_terminals & other);
	
	/** 
	 * \brief whether a symbol of given `symbol` field is present in the container
	 */
	bool contains(const Symbol & symbol) const;
	
	
	/** 
	 * \brief getter for the internal container
	 *
	 * stupid but necessary for creating html representation in `Http_grammar_adapter`
	 */
	std::vector<Symbol> get_symbols() const;
	
	bool has_errors();
	
};

#endif //_NON_TERMINALS_H_