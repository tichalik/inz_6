#ifndef GRAMMAR
#define GRAMMAR

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "utils.h"
#include "symbol.h"
#include "non_terminals.h"
#include "head.h"
#include "rules.h"

/** 
 * \brief grammar in Chomsky's normal form
 */
struct Grammar
{
	
	Non_terminals nonterminals;
	Non_terminals terminals;
	Head head;
	Rules rules;

	
	Grammar() {}
	
	/** 
	 * \brief get grammar's printf friendly description
	 */
	std::string to_string() const;
};



#endif // GRAMMAR
