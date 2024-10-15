
%{
  #include <iostream>
  #include <string>
  #include "token.h"
  #include "mod_from_http.h"

  int yylex (void);
  void yyerror (char const *);
     
%}

%define api.prefix {rule_}

%union {
    int INT;
    //char * STR;
    //void VOID; -- impossible!!!
    std::string* STR; //this is ok, however we cannot use std::string as an union member, because it contains constructors
}

%token <STR> NTERM
%token <STR> TERM 
%token <INT> SEP 
%token <INT> OR 
%token <INT> LB 
%token <INT> TOKEN_ERROR // this is not used in the parser but has to be included in the enum 
%nterm <INT> rules
%nterm <STR> rule
%nterm <STR> alts
%nterm <STR> symbols
%nterm <STR> symbol

%%

rules :
  rule                  { std::cout << "rules -> rule " << std::endl;}
  | rules LB rule       { std::cout << "rules -> rule LB RULE" << std::endl;}
;

rule :
  NTERM SEP alts        { std::cout << "rule -> NTERM SEP alts " <<  sizeof($1) << " " <<  sizeof($2) << std::endl;}
;
  
alts :
  symbols               { std::cout << "alts -> symbols " << std::endl;}
  | alts OR symbols     { std::cout << "alts -> alts OR symbols " <<  sizeof($2) << std::endl;}
;

symbols :
  symbol                { std::cout << "symbols -> symbol " << std::endl;}
  | symbols symbol      { std::cout << "symbols -> symbols symbol " << std::endl;}
;

symbol :
  NTERM                 { std::cout << "symbol -> NTERM " << std::endl;}
  | TERM                { std::cout << "symbol -> TERM " << std::endl;}
; 

%%


rule_tokentype TOKENS[] = {
	NTERM, SEP, NTERM, TERM, TERM, OR, NTERM, NTERM, OR, TERM, LB, RULE_EOF
}; 

size_t yylex_pos = 0;

int yylex (void)
{
  return TOKENS[yylex_pos++]; 
}


void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

Rules parse_rules(const Tokens & tokens)
{
	Rules rules;

	return rules;
}
