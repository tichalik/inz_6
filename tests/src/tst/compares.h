#ifndef COMPARES_H_
#define COMPARES_H_

#include <iostream>

#include "to_string.h"


#include "non_terminals.h"
#include "word.h"
#include "error.h"
#include "grammar.h"

#include "mod_parser.h"

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

COMPARE_DECLARATION(Token);
COMPARE_DECLARATION(Tokens);
COMPARE_DECLARATION(EN_TOKEN_TYPE);


COMPARE_DECLARATION(Error);
COMPARE_DECLARATION(Non_terminals);
COMPARE_DECLARATION(Rule);


bool compare(
	const  PNode* expected,
	const  PNode* real,
	const std::string & message
);
//COMPARE_DECLARATION(PNode*);	//declaring it like this causes it not to work 
COMPARE_DECLARATION(std::vector<std::vector<PNode*>>);	
COMPARE_DECLARATION(std::vector<PNode*>);	
COMPARE_DECLARATION(State);	
COMPARE_DECLARATION(std::list<State>);	
COMPARE_DECLARATION(std::vector<std::list<State>>);	

#undef COMPARE_DECLARATION

#endif
