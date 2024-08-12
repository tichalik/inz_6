#ifndef TO_STRING_H_
#define TO_STRING_H_

#include <string>
#include <iostream>


#include "non_terminals.h"
#include "word.h"
#include "error.h"
#include "grammar.h"
#include "ptree.h"

#include "chomsky_grammar.h"
#include "parsing_grammar_adapter.h"
#include "ptable.h"

	
std::string error2str(const Error &error);
std::string error_type2str(const EN_ERROR_TYPE &error);
std::string errors2str(const Errors &errors);


std::string ptable2string(
	const PTable & input
);
std::string ptable_entry2string(
	const PTable_entry & input
);
std::string ptable_reference2string(
	const PTable_reference & input
);

	
#endif
