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
    Symbol LHS;
    Symbols RHS;
	
	std::string to_string() const
	{
		std::string res = LHS + " -> ";
		for (size_t i=0; i<RHS.size(); i++)
		{
			res += RHS[i] + " ";
		}
		return res;
	}
	
};

struct Rules: public std::vector<Rule>
{
	
	
};


#endif // RULES_H
