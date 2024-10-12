%{
#include "mod_from_http.h"

Tokens tokens;
%}

%option noyywrap

%%


%%


Tokens tokenize(const std::string & str)
{


	Tokens tmp(tokens);
	tokens.clear();
	return tmp;
}
