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
 * \brief formal grammar, analogous to its formal description
 *
 * Grammar may contain errors.
 */
struct Grammar
{
	/// set of nonterminals
	Non_terminals nonterminals;
	/// set of terminals
	Non_terminals terminals;
	/// head of the grammar
	Head head;
	/// rules of the grammar
	Rules rules;
};



#endif // GRAMMAR
