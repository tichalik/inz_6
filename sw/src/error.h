#ifndef ERROR_H_
#define ERROR_H_

#include <string>
#include <vector>

enum EN_ERROR_TYPE
{
	//http errors
	EMPTY_NONTERMINALS,
	EMPTY_TERMINALS,
	EMPTY_HEAD,
	EMPTY_RULES,
	EMPTY_WORD,
	
	//general errors
	UNKNOWN_SYMBOL,
	
	//non/terminals related errors
	REPEATING_SYMBOL,
	TERM_IN_NTERMS,
	NTERM_IN_TERMS,

	//rule related errors
		//parsing related
	MISSING_LHS,
	MISSING_RHS,
	SINGLE_RHS,
	TOO_MANY_LHS,
	MISSING_ARROW,
	MULTIPLE_ARROWS,
		//semantic related
	TERMINAL_AS_LHS,
	
	//head related errors
	HEAD_NOT_IN_NONTERMINALS,
	MULTIPLE_HEADS,
	
	//input (word) related errors
	SYMBOL_IN_NONTERMINALS,
	
	//chomskification
	UNREMOVABLE_CHAIN
};

struct Error
{
	EN_ERROR_TYPE type;
	std::string source;
};


typedef std::vector<Error> Errors;

#endif // ERROR_H_
