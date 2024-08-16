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

//ok, we have 2 structures for linking extra data to a symbol
//we could just make a separate data type with those
//the problem is that it would create muhc memory overhead as most symbols probably wont have this extra data
//	therefore we could use polymorphism to fix that!
//	have a normal symbol and a replaced symbol inheriting from it 
//	then symbol would have methods for accessing the fields of Replaced_symbol returning constant values
//		the only problem is that it would require pointers and dynamic memory allocation 
//		which is slower?
//		and messier
//		so for now lets stick to this i guess
//			however std::vector also does a heckton of dynamic memory management??
//		


struct Cycle_warnings_index
{
	size_t RHS_pos;
	Cycle_warnings cycle_warnings;
};
typedef std::vector<Cycle_warnings_index> Cycle_warnings_indexes;


struct Replaced_symbols_index
{
	size_t RHS_pos;
	Symbols symbols;
};
typedef std::vector<Replaced_symbols_index> Replaced_symbols_indexes;

struct Chomsky_rule
{
	Symbol LHS;
	Symbols RHS;
	
	Replaced_symbols_indexes replaced_symbols_indexes;
	Cycle_warnings_indexes cycle_warnings_indexes;
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