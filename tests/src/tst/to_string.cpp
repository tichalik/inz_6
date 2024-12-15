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
VECTOR_STR(VNodes);
VECTOR_STR(Tokens);



std::string str(
	const State_set & i,
	const std::string & tabs
)
{
	std::stringstream res;
	size_t pos = 0;
	for (State_set::const_iterator j = i.cbegin(); j != i.cend(); j++)
	{
		res << tabs << (pos++)  <<".\n" << str(*j, tabs + "\t") << std::endl;
	} 
	return res.str();
}
	

VECTOR_STR(std::vector<State_set>);


std::string str(
	const State& i,
	const std::string & tabs
) 
{
	std::string res =  tabs + "\t" + i.LHS + " -> ";
	for (size_t j=0; j<i.RHS.size(); j++)
	{
		if (j == i.pos)
			res += ". ";
		res += i.RHS[j] + " ";
	}
	if (i.pos == i.RHS.size())
		res += " .";
	res += " | " + str(i.origin, "");
	return res;
}



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
	const Symbol & LHS,
	const std::vector<Symbols> & RHS,
	const std::string & tabs

)
{ 
	std::string res;
	res += tabs + "rule \n" + str(LHS, tabs+"\t") + "\n";
	res += tabs + "\t" + str(RHS, tabs+"\t") + "\n";
	return res;
}



std::string str(
	const Rules& i,
	const std::string & tabs

)
{ 
	std::string res;
	for (Rules::const_iterator j=i.cbegin(); j!=i.cend(); j++)
	{
		res += str(j->first, j->second, tabs+"\t");
	}
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
		case STRAY_SEP:
			res = "STRAY_SEP";
			break;
		case STRAY_OR:
			res = "STRAY_OR";
			break;
		case STRAY_LB:
			res = "STRAY_LB";
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
	const EN_TOKEN_TYPE &token,
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
