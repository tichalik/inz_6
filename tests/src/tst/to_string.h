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

	
std::string str(const bool &i);
std::string str(const std::string &i);	
std::string str(const size_t &i);	
	
std::string str(const Error &error);
std::string str(const EN_ERROR_TYPE &error);
std::string str(const Errors &errors);


std::string str(
	const PTable & input
);
std::string str(
	const PTable_entry & input
);
std::string str(
	const PTable_reference & input
);

	
#endif
