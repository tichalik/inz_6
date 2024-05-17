#ifndef ERROR_H_
#define ERROR_H_

#include <string>
#include <vector>

enum EN_ERROR_TYPE
{
	REPEATING_SYMBOL,
	IN_BOTH_TERMINALS_AND_NONTERMINALS,
	MALFORMED_RULE,
	UNKNOWN_SYMBOL,
	NON_CHOMSKY_RULE
};


typedef EN_ERROR_TYPE Error;
typedef std::vector<Error> Errors;

#endif // ERROR_H_