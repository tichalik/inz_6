#ifndef TST_HTTP_GRAMMAR_ADAPTER_H_
#define TST_HTTP_GRAMMAR_ADAPTER_H_

#include "tester.h"

class TST_http_grammar_adapter: public Tester
{
		
	std::string error2str(const EN_ERROR_TYPE &error);
	
	std::string errors2str(Errors errors);
	
	void show_non_terminals(const Non_terminals & nt);
	
	void test_terminals_and_nonterminals(
		const std::string & str_terminals,
		const std::string & str_nonterminals
	);
	
		
	void _test_rules_from_http(
		const std::string & str_terminals,
		const std::string & str_nonterminals,
		const std::string & str_head,
		const std::string & str_rules
	);
	
	std::string error_descs2str(std::vector<Error_desc> errors);
	
	
public:
	
	void test_non_terminal_from_http();
	void test_head_from_http();
	void test_rules_from_http();
	void test_http_grammar_adapter_errors();
	void test();
};
#endif
