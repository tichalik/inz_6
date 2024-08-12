#ifndef COMPARES_H_
#define COMPARES_H_

#include <iostream>

#include "to_string.h"


#include "non_terminals.h"
#include "word.h"
#include "error.h"
#include "grammar.h"
#include "ptree.h"

#include "chomsky_grammar.h"
#include "parsing_grammar_adapter.h"
#include "ptable.h"

bool compare_error(
	const Error & expected,
	const Error & real
);

bool compare_errors(
	const Errors & expected,
	const Errors & real
);

bool compare_non_terminals(
	const Non_terminals & expected,
	const Non_terminals & real
);

bool compare_head(
	const Head & expected,
	const Head & real
);


bool compare_rule(
	const Rule & expected,
	const Rule & real
);
bool compare_rules(
	const Rules & expected,
	const Rules & real
);
bool compare_word(
	const Word & expected,
	const Word & real
);
	

bool compare_ptable(
	const PTable & expected,
	const PTable & real
) ;
bool compare_ptable_entry(
	const PTable_entry & expected,
	const PTable_entry & real
) ;
bool compare_ptable_reference(
	const PTable_reference & expected,
	const PTable_reference & real
) ;

bool compare_ptrees(
	const PTrees & expected,
	const PTrees & real
) ;
bool compare_ptree(
	const PTree & expected,
	const PTree & real
) ;
bool compare_pnode(
	const PNode & expected,
	const PNode & real
) ;

bool compare_chomsky_grammar(
	const Chomsky_grammar & expected,
	const Chomsky_grammar & real
) ;

bool compare_chomsky_rule(
	const Chomsky_rule & expected,
	const Chomsky_rule & real
) ;

bool compare_chomsky_rules(
	const Chomsky_rules & expected,
	const Chomsky_rules & real
) ;

bool compare_cycle_warnigs(
	const Cycle_warning & expected,
	const Cycle_warning & real
) ;

	
#endif
