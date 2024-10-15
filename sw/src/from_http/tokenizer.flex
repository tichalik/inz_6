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

{TXT}					PUSH_TOKEN(TERM)

\<{TXT}\>				PUSH_TOKEN(NTERM)

\|						PUSH_TOKEN(OR)

::=						PUSH_TOKEN(SEP)

\r?\n						PUSH_TOKEN(LB)

({WC}\\{WC}\r?\n{WC})+		|
{WC}					{
							pos += yyleng;
						}

.						PUSH_TOKEN(TOKEN_ERROR)

%%


Tokens tokenize(const std::string & str)
{
	tokens.clear();
	pos = 0;

	// prepare input for the parser
	YY_BUFFER_STATE buffer = yy_scan_string(str.c_str());

	//call the parser
	yylex();

	//cleanup
	yy_delete_buffer(buffer);

	return tokens;
}

