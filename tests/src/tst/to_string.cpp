#include "to_string.h"

#define ADD_FIELD(NAME)\
	res += tabs + ( #NAME ":\n") + str(i.NAME, tabs+"\t") + "\n";

#define VECTOR_STR(TYPE)\
	std::string str(\
		const TYPE & i,\
		const std::string & tabs\
		)\
	{\
		std::stringstream res;\
		for (size_t j=0; j<i.size(); j++)\
		{\
			res << tabs << j <<".\n" << str(i[j], tabs + "\t") << std::endl;\
		}\
		return res.str();\
	}
	

VECTOR_STR(Symbols);
VECTOR_STR(std::vector<Symbols>);
VECTOR_STR(Errors);
VECTOR_STR(Rules);
VECTOR_STR(PTrees);
VECTOR_STR(VNodes);
VECTOR_STR(Tokens);


VECTOR_STR(PTable_entries);
VECTOR_STR(PTable_references);
VECTOR_STR(PNodes);


std::string str(
	const Non_terminals & i,
	const std::string & tabs
) 
{
	std::string res;
	for (auto j=i.cbegin(); j!=i.cend(); j++)
	{
		res += str(*j, tabs+"\t") + ", ";
	}
	return res;
}

std::string str(
	const Error & i,
	const std::string & tabs

)
{
	std::string res;
	ADD_FIELD(type);
	ADD_FIELD(source);
	return res;
} 


std::string str(
	const Token & i,
	const std::string & tabs

)
{
	std::string res;
	ADD_FIELD(type);
	ADD_FIELD(str);
	ADD_FIELD(start_pos);
	return res;
} 


std::string str(
	const VNode & i,
	const std::string & tabs

)
{
	std::string res;
	ADD_FIELD(tag);
	ADD_FIELD(parent_symbol_pos);
	ADD_FIELD(children);
	return res;
}


std::string str(
	const Rule & i,
	const std::string & tabs

)
{
	std::string res;
	ADD_FIELD(LHS);
	ADD_FIELD(RHS);
	return res;
}

std::string str(
	const Chomsky_grammar & i,
	const std::string & tabs

)
{
	std::string res;
	ADD_FIELD(nonterminals);
	ADD_FIELD(terminals);
	ADD_FIELD(added_nonterminals);
	ADD_FIELD(head);
	ADD_FIELD(rules);
	return res;
}

std::string str(
	const PTable & i,
	const std::string & tabs

)
{
	std::string res;
	for (size_t k = 0; k < i.SIZE; k++)
	{
		for (size_t j = 0; j < i.SIZE - k; j++)
		{
			ADD_FIELD(tab[k][j]);
		}
	}

	
	return res;
}

std::string str(
	const PTable_entry & i,
	const std::string & tabs

)
{
	std::string res;
	ADD_FIELD(tag);
	ADD_FIELD(visited);
	ADD_FIELD(rule_id);
	ADD_FIELD(children);
	return res;
		
}

std::string str(
	const PTable_reference & i,
	const std::string & tabs

)
{
	std::string res;
	ADD_FIELD(x);
	ADD_FIELD(y);
	ADD_FIELD(list_index);
	return res;
		
}


std::string str(
	const PTree & i,
	const std::string & tabs

)
{
	std::string res;
	ADD_FIELD(root);
	return res;
}
std::string str(
	const PNode & i,
	const std::string & tabs

)
{
	std::string res;
	ADD_FIELD(tag);
	ADD_FIELD(children);
	return res;
}



std::string str(
	const bool &i,
	const std::string & tabs

)
{
	std::stringstream ss;
	ss << i;
	return tabs + ss.str();
}

std::string str(
	const size_t &i,
	const std::string & tabs

)
{
	std::stringstream ss;
	ss << i;
	return tabs + ss.str();
}

std::string str(
	const std::string &i,
	const std::string & tabs

)
{
	return tabs +  i;
}

std::string str(
	const EN_ERROR_TYPE &error,
	const std::string & tabs

)
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
		case MISSING_LHS:
			res = "MISSING_LHS";
			break;
		case MISSING_RHS:
			res = "MISSING_RHS";
			break;
		case SINGLE_RHS:
			res = "SINGLE_RHS";
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
	
	return tabs + res;
}

std::string str(
	const rule_tokentype &token,
	const std::string & tabs

)
{
	std::string res;
	switch (token)
	{
			
		case TERM:
			res = "TERM";
			break;
		case NTERM:
			res = "NTERM";
			break;
		case SEP:
			res = "SEP";
			break;
		case OR:
			res = "OR";
			break;
		case LB:
			res = "LB";
			break;
	
		default:
			res = "UNKNOWN TOKEN TYPE";
			break;
	}
	
	return tabs + res;
}


#undef ADD_FIELD
#undef VECTOR_STR
