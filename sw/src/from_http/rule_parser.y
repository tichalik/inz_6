
%{
  #include <iostream>
  #include <string>
  #include "token.h"
  #include "mod_from_http.h"

  int rule_lex (void);
  void rule_error (char const *);
     
%}

%define api.prefix {rule_}
%define api.value.type {char const*}

%token NTERM TERM SEP OR LB
// this is not used in the parser but has to be included in the enum 
%token TOKEN_ERROR

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

size_t rule_lex_pos = 0;

int rule_lex (void)
{
  return TOKENS[rule_lex_pos++]; 
}


void rule_error (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

Rules parse_rules(const Tokens & tokens)
{
	Rules rules;

	return rules;
}
