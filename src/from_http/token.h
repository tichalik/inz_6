#ifndef TOKEN_H_
#define TOKEN_H_

#include <vector>
#include <string>

/// tag of token
enum EN_TOKEN_TYPE
{
	/// any symbol other than expected
	TOKEN_ERROR,

	/// symbol matching "[A-Za-z0-9_]+"
	TERM,
	/// symbol matching "<[A-Za-z0-9_]+>"
	NTERM,
	/// symbol ::=
	SEP,
	/// symbol |
	OR,
	/// linebreak
	LB
};

/// element of the rule with assigned tag
struct Token
{
	/// position in input string where this token started
	size_t start_pos;
	/// text of the token
	std::string str;
	/// tag of the token
	EN_TOKEN_TYPE type;
};

typedef std::vector<Token> Tokens;

#endif 
