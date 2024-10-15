#ifndef TOKEN_H_
#define TOKEN_H_

#include <vector>
#include <string>
#include "rule_parser.tab.h" //for token types enum 

struct Token
{ 
	size_t start_pos;
	std::string str;
	rule_tokentype type;
};

typedef std::vector<Token> Tokens;

#endif 
