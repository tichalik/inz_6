#include "tst_http_grammar_adapter.h"


std::string TST_http_grammar_adapter::error2str(const EN_ERROR_TYPE &error)
{
	std::string res;
	switch (error)
	{
		case EMPTY_FIELD:
			res="EMPTY_FIELD";
			break;
		case UNKNOWN_SYMBOL:
			res="UNKNOWN_SYMBOL";
			break;
		case REPEATING_SYMBOL:
			res="REPEATING_SYMBOL";
			break;
		case IN_BOTH_TERMINALS_AND_NONTERMINALS:
			res="IN_BOTH_TERMINALS_AND_NONTERMINALS";
			break;
		case MISSING_LHS:
			res="MISSING_LHS";
			break;
		case TOO_MANY_LHS:
			res="TOO_MANY_LHS";
			break;
		case TOO_FEW_RHS:
			res="TOO_FEW_RHS";
			break;
		case TOO_MANY_RHS:
			res="TOO_MANY_RHS";
			break;
		case MISSING_ARROW:
			res="MISSING_ARROW";
			break;
		case MULTIPLE_ARROWS:
			res="MULTIPLE_ARROWS";
			break;
		case TERMINAL_AS_LHS:
			res="TERMINAL_AS_LHS";
			break;
		case HEAD_NOT_IN_NONTERMINALS:
			res="HEAD_NOT_IN_NONTERMINALS";
			break;
		case MULTIPLE_HEADS:
			res="MULTIPLE_HEADS";
			break;
		default:
			break;
	}
	
	return res;
}

std::string TST_http_grammar_adapter::errors2str(Errors errors)
{
	std::string res;
    for (size_t i=0; i<errors.size(); i++)
        res += error2str(errors[i])+ " ";
    return res;
}
