#ifndef RULES_H
#define RULES_H

#include <vector>


#include "utils.h"
#include "errorable.h"
#include "symbol.h"
#include "non_terminals.h"

/** 
 * \brief representation of grammatical rule in form 
 *	left -> right1 right 2
 */
struct Rule: public Errorable
{
    Symbol left;
    Symbol right1, right2;
	
	std::string to_string() const;
	
	void check_symbol_errors(
		Symbol &s,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	void check_errors(
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	bool has_errors();
};

class Rules: public std::vector<Rule>
{
	public:
	
	void check_errors(
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	bool has_errors();
};


#endif // RULES_H
