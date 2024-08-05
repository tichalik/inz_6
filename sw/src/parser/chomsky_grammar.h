#ifndef CHOMSKY_GRAMMAR_H_
#define CHOMSKY_GRAMMAR_H_

#include "non_terminals.h"
#include "symbol.h"
#include "head.h"
#include "rules.h"

/**
 * \brief information that a rule can be extented indefinitely into a cycle 
 *
 * stores references to the replaced_symbols fields in Chomsky_rule
 *
 * e.g. when the grammar has rules
 *	A->B
 *	B->C
 *	C->A
 * then the replaced symbols will be a vector [A B C] and it will contain warning 
 *	origin_pos = 2;
 *	target_pos = 1;
 *
 */
struct Cycle_warning
{
	///
	size_t origin_pos;
	///
	size_t target_pos;
};
typedef std::vector<Cycle_warning> Cycle_warnings;

struct Chomsky_rule
{
	Symbol LHS;
	Symbols RHS;
	
	Symbols replaced_symbols;
	Cycle_warnings cycle_warnings;
};
typedef std::vector<Chomsky_rule> Chomsky_rules;

struct Chomsky_grammar 
{
	Non_terminals terminals;
	Non_terminals nonterminals;
	
	Non_terminals added_nonterminals;
	
	Head head;
	Chomsky_rules rules;
};


#endif // CHOMSKY_GRAMMAR_H_