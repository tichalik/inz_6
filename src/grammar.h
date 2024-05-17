#ifndef GRAMMAR
#define GRAMMAR

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "utils.h"
#include "error.h"
#include "symbol.h"
#include "non_terminals.h"


/** 
 * \brief grammar in Chomsky's normal form
 */
class Grammar
{
	
	Non_terminals nonterminals;

	public:
	
	
    /** 
	 * \brief getter
	 */
	Non_terminals get_nonterminals() const;
	
    /** 
	 * \brief setter
	 */
	void set_nonterminals(const Non_terminals & _nonterminals);
    

};



#endif // GRAMMAR
