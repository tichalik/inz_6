#ifndef TST_HTTP_GRAMMAR_ADAPTER_H_
#define TST_HTTP_GRAMMAR_ADAPTER_H_

#include "tester.h"

class TST_http_grammar_adapter: public Tester
{
			
	void _test_http_grammar_adapter_errors(
		const std::string & str_terminals,
		const std::string & str_nonterminals,
		const std::string & str_head,
		const std::string & str_rules
	);
	
	void _test_head_from_http(
		const std::string & str_terminals,
		const std::string & str_nonterminals,
		const std::string & str_head
	);

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
	
public:
	
	void test_non_terminal_from_http();
	void test_head_from_http();
	void test_rules_from_http();
	void test_http_grammar_adapter_errors();
	void test();
};
#endif
