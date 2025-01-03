#ifndef RULES_H
#define RULES_H

#include <map>

#include "utils.h"
#include "symbol.h"

/**
 * \brief class representing rules of a context-free grammar
 *
 * Rules are implemented as a specialization of std::map. 
 * The key is the LHS of the rules, the value is a list of RHS of these rules; 
 * rules:
 \verbatim
	 	<A> ::= b | c d   
	 	<B> ::= b 
	 	<B> ::= e
 \endverbatim
 * are represented as:
 \verbatim
	  rules["<A>"] = {{"b"},{"c","d"}}
	  rules["<B>"] = {{"b"},{"e"}}
 \endverbatim
 */
struct Rules: public std::map<Symbol, std::vector<Symbols> > 
{
	/// operator [] overwritten, if no key is present, returns {}
	std::vector<Symbols> get_rules(const Symbol& LHS) const;
};

#endif // RULES_H
