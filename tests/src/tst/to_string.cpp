#include "to_string.h"

std::string error2str(const Error &error)
{
	return "source:<" + error.source +">, type:<" + error_type2str(error.type)+">";
}

std::string error_type2str(const EN_ERROR_TYPE &error)
{
	std::string res;
	switch (error)
	{
		case EMPTY_NONTERMINALS:
			res = "EMPTY_NONTERMINALS";
			break;
		case EMPTY_TERMINALS:
			res = "EMPTY_TERMINALS";
			break;
		case EMPTY_HEAD:
			res = "EMPTY_HEAD";
			break;
		case EMPTY_RULES:
			res = "EMPTY_RULES";
			break;
		case EMPTY_WORD:
			res = "EMPTY_WORD";
			break;
		case UNKNOWN_SYMBOL:
			res = "UNKNOWN_SYMBOL";
			break;
		case REPEATING_SYMBOL:
			res = "REPEATING_SYMBOL";
			break;
		case ARROW_AS_SYMBOL:
			res = "ARROW_AS_SYMBOL";
			break;
		case IN_BOTH_TERMINALS_AND_NONTERMINALS:
			res = "IN_BOTH_TERMINALS_AND_NONTERMINALS";
			break;
		case MISSING_LHS:
			res = "MISSING_LHS";
			break;
		case MISSING_RHS:
			res = "MISSING_RHS";
			break;
		case TOO_MANY_LHS:
			res = "TOO_MANY_LHS";
			break;
		case MISSING_ARROW:
			res = "MISSING_ARROW";
			break;
		case MULTIPLE_ARROWS:
			res = "MULTIPLE_ARROWS";
			break;	
		case TERMINAL_AS_LHS:
			res = "TERMINAL_AS_LHS";
			break;
		case HEAD_NOT_IN_NONTERMINALS:
			res = "HEAD_NOT_IN_NONTERMINALS";
			break;
		case MULTIPLE_HEADS:
			res = "MULTIPLE_HEADS";
			break;
		case SYMBOL_IN_NONTERMINALS:
			res = "SYMBOL_IN_NONTERMINALS";
			break;
		default:
			res = "UNKNOWN ERROR";
			break;
	}
	
	return res;
}

std::string errors2str(const Errors &errors)
{
	std::string res;
    for (size_t i=0; i<errors.size(); i++)
        res += error2str(errors[i])+ " ";
    return res;
}

std::string ptable2string(
	const PTable & input
)
{
	std::stringstream res;
	
	for (size_t i = 0; i < input.SIZE; i++)
	{
		for (size_t j = 0; j < input.SIZE - i; j++)
		{
			for (size_t k=0; k<input.tab[i][j].size(); k++)
			{
				res << "[" << i << "]"
					<< "[" << j << "]"
					<< "\t" << k << ".\t"
					<< ptable_entry2string(input.tab[i][j][k]) << std::endl;
			}
		}	
	}
	
	return res.str();
}

std::string ptable_entry2string(
	const PTable_entry & input
)
{
	std::stringstream res;
	
	res << "tag: " << input.tag << "\t"
		<< "visited: " << input.visited 
		<< "children: " << std::endl;
		
	for (size_t i=0; i<input.children.size(); i++)
	{
		res << "\t" << ptable_reference2string(input.children[i]) <<std::endl;
	}
	
	return res.str();
}

std::string ptable_reference2string(
	const PTable_reference & input
)
{
	std::stringstream res;
	
	res << "x: " << input.x << "\t"
		<< "y: " << input.y << "\t"
		<< "list_index: " << input.list_index;
	
	return res.str();
}

