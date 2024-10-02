#ifndef CHOMSKY_GRAMMAR_H_
#define CHOMSKY_GRAMMAR_H_

#include "non_terminals.h"
#include "symbol.h"
#include "head.h"
#include "rules.h"

struct Chomsky_grammar 
{
	Non_terminals terminals;
	Non_terminals nonterminals;
	
	Non_terminals added_nonterminals;
	
	Head head;
	Rules rules;
};


#endif // CHOMSKY_GRAMMAR_H_