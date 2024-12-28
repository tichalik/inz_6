#ifndef TOKEN_H_
#define TOKEN_H_

#include <vector>
#include <string>

enum EN_TOKEN_TYPE
{
	TOKEN_ERROR,

	TERM,
	NTERM,
	SEP,
	OR,
	LB


};

struct Token
{
	size_t start_pos;
	std::string str;
	EN_TOKEN_TYPE type;
};

typedef std::vector<Token> Tokens;

#endif 
