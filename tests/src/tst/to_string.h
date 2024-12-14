#ifndef TO_STRING_H_
#define TO_STRING_H_

#include <string>
#include <iostream>
#include <sstream>


#include "non_terminals.h"
#include "word.h"
#include "error.h"
#include "grammar.h"

#include "mod_parser.h"

#include "vnode.h"
#include "token.h"


#define STR_DECLARATION(TYPE)\
	std::string str(\
		const TYPE & i,\
		const std::string & tabs\
	);

STR_DECLARATION(std::string);
STR_DECLARATION(EN_ERROR_TYPE);
STR_DECLARATION(EN_TOKEN_TYPE);
STR_DECLARATION(bool);
STR_DECLARATION(size_t);

STR_DECLARATION(Symbols);
STR_DECLARATION(std::vector<Symbols>);
STR_DECLARATION(Errors);
STR_DECLARATION(Rules);

STR_DECLARATION(Token);
STR_DECLARATION(Tokens);

STR_DECLARATION(Error);
STR_DECLARATION(Non_terminals);

STR_DECLARATION(VNodes);	
STR_DECLARATION(VNode);	

STR_DECLARATION(State);	
STR_DECLARATION(std::list<State>);	
STR_DECLARATION(std::vector<std::list<State> >);	
#undef STR_DECLARATION

#endif
