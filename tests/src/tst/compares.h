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
#include "chomskify.h"
#include "chomskify.h"

#define COMPARE_DECLARATION(TYPE)\
	bool compare(\
		const TYPE & expected,\
		const TYPE & real,\
		const std::string & message\
	);

COMPARE_DECLARATION(std::string);
COMPARE_DECLARATION(EN_ERROR_TYPE);
COMPARE_DECLARATION(bool);
COMPARE_DECLARATION(size_t);

COMPARE_DECLARATION(Symbols);
COMPARE_DECLARATION(std::vector<Symbols>);
COMPARE_DECLARATION(Errors);
COMPARE_DECLARATION(Rules);
COMPARE_DECLARATION(PTrees);

COMPARE_DECLARATION(Token);
COMPARE_DECLARATION(Tokens);
COMPARE_DECLARATION(rule_tokentype);


COMPARE_DECLARATION(Error);
COMPARE_DECLARATION(Non_terminals);
COMPARE_DECLARATION(Rule);
COMPARE_DECLARATION(PTable);
COMPARE_DECLARATION(PTable_entry);
COMPARE_DECLARATION(PTable_reference);
COMPARE_DECLARATION(PTable_references);
COMPARE_DECLARATION(PTree);
COMPARE_DECLARATION(PNode);
COMPARE_DECLARATION(Chomsky_grammar);


COMPARE_DECLARATION(PTable_entries);
COMPARE_DECLARATION(PNodes);	

#undef COMPARE_DECLARATION

#endif
