#ifndef TESTER_H_
#define TESTER_H_

#include <iostream>


#include "parser.h"
#include "grammar.h"
#include "word.h"
#include "http_grammar_adapter.h"
#include "html_response.h"


class Tester
{
		
	void show_word(const Word &w) const ;
	void show_non_terminals(const Non_terminals & nt) const;
	
		
	std::string error2str(const EN_ERROR_TYPE &error) const ;
	std::string errors2str(const Errors &errors) const ;
	
public:
	
	void test_non_terminal_to_http();
};
#endif
