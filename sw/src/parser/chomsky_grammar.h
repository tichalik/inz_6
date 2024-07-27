#ifndef CHOMSKY_GRAMMAR_H_
#define CHOMSKY_GRAMMAR_H_

#include "non_terminals.h"
#include "symbol.h"
#include "head.h"
#include "rules.h"

struct Chomsky_rule
{
	Symbol LHS, RHS1, RHS2;
	
	std::vector<size_t> source_rules_ids;
};
typedef std::vector<Chomsky_rule> Chomsky_rules;

struct Chomsky_grammar 
{
	Non_terminals orig_terminals;
	
	Non_terminals orig_nonterminals;
	Non_terminals added_nonterminals;
	
	Head head;
	
	Chomsky_rules orig_rules;
	Chomsky_rules added_rules;
};


#endif // CHOMSKY_GRAMMAR_H_