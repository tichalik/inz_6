#ifndef RULES_H
#define RULES_H

#include <vector>


#include "utils.h"
#include "symbol.h"
#include "non_terminals.h"

/** 
 * \brief representation of grammatical rule in form 
 *	left -> right1 right 2
 */
struct Rule
{
    Symbol left;
    Symbol right1, right2;
	
	std::string to_string() const;
	
};

struct Rules: public std::vector<Rule>
{
	
	
};


#endif // RULES_H
