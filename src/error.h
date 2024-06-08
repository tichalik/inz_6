#ifndef ERROR_H_
#define ERROR_H_

#include <string>
#include <vector>

enum EN_ERROR_TYPE
{
	//general errors
	EMPTY_FIELD,
	UNKNOWN_SYMBOL,
	
	//non/terminals related errors
	REPEATING_SYMBOL,
	IN_BOTH_TERMINALS_AND_NONTERMINALS,
	
	//rule related errors
		//parsing related
	MISSING_LHS,
	TOO_MANY_LHS,
	TOO_FEW_RHS,
	TOO_MANY_RHS,
	MISSING_ARROW,
	MULTIPLE_ARROWS,
		//semantic related
	TERMINAL_AS_LHS,
	
	//head related errors
	HEAD_NOT_IN_NONTERMINALS,
	HEAD_IN_TERMINALS,
	MULTIPLE_HEADS
};


typedef EN_ERROR_TYPE Error;
typedef std::vector<Error> Errors;

#endif // ERROR_H_