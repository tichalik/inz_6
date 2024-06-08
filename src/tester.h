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
public:
    void test_infix_chomsky_grammar();
	
	void test_non_terminal_from_http();
	void test_non_terminal_to_http();
	void test_http_grammar_adapter_with_empty_fields();
	
	void test_html_response();
};
#endif
