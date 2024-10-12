%{
#include "mod_from_http.h"

Tokens tokens;
size_t pos = 0;

#define PUSH_TOKEN(x)\
{\
	Token token;\
	token.type = x;\
	token.str = yytext;\
	token.start_pos = pos;\
	\
	tokens.push_back(token);\
\
	pos += yyleng;\
}

%}

%option noyywrap

WC		[ \t]*
TXT		[A-Za-z0-9_]+

%%

{WC}{TXT}{WC}				PUSH_TOKEN(TERM)

{WC}\<{TXT}\>{WC}			PUSH_TOKEN(NTERM)

{WC}\|{WC}				PUSH_TOKEN(OR)

{WC}::={WC}				PUSH_TOKEN(SEP)

{WC}\n{WC}				PUSH_TOKEN(LB)

({WC}\\{WC}\n{WC})+		|
{WC}					{
							pos += yyleng;
						}

.						PUSH_TOKEN(TOKEN_ERROR)

%%


Tokens tokenize(const std::string & str)
{
	// prepare input for the parser
	YY_BUFFER_STATE buffer = yy_scan_string(str.c_str());

	//call the parser
	yylex();

	//cleanup
	Tokens tmp(tokens);
	tokens.clear();
	pos = 0;
	yy_delete_buffer(buffer);

	return tmp;
}
