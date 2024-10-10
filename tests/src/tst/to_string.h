#ifndef TO_STRING_H_
#define TO_STRING_H_

#include <string>
#include <iostream>
#include <sstream>


#include "non_terminals.h"
#include "word.h"
#include "error.h"
#include "grammar.h"
#include "ptree.h"

#include "chomsky_grammar.h"
#include "parsing_grammar_adapter.h"
#include "ptable.h"
#include "chomskify.h"

#include "vnode.h"

#define STR_DECLARATION(TYPE)\
	std::string str(\
		const TYPE & i,\
		const std::string & tabs\
	);

STR_DECLARATION(std::string);
STR_DECLARATION(EN_ERROR_TYPE);
STR_DECLARATION(bool);
STR_DECLARATION(size_t);

STR_DECLARATION(Symbols);
STR_DECLARATION(std::vector<Symbols>);
STR_DECLARATION(Errors);
STR_DECLARATION(Rules);
STR_DECLARATION(PTrees);


STR_DECLARATION(Error);
STR_DECLARATION(Non_terminals);
STR_DECLARATION(Rule);
STR_DECLARATION(PTable);
STR_DECLARATION(PTable_entry);
STR_DECLARATION(PTable_reference);
STR_DECLARATION(PTable_references);
STR_DECLARATION(PTree);
STR_DECLARATION(PNode);
STR_DECLARATION(Chomsky_grammar);


STR_DECLARATION(PTable_entries);
STR_DECLARATION(PNodes);

STR_DECLARATION(VNodes);	
STR_DECLARATION(VNode);	

#undef STR_DECLARATION

#endif
