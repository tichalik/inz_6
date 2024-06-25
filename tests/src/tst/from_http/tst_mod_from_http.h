#ifndef TST_MOD_FROM_HTTP_H_
#define TST_MOD_FROM_HTTP_H_

#include "tester.h"
#include "mod_from_http.h"

class TST_mod_from_http: public Tester
{
	bool compare_non_terminals(
		const Non_terminals & expected,
		const Non_terminals & real
	);
	bool compare_head(
		const Head & expected,
		const Head & real
	);
	bool compare_rule(
		const Rule & expected,
		const Rule & real
	);
	bool compare_rules(
		const Rules & expected,
		const Rules & real
	);
	bool compare_word(
		const Word & expected,
		const Word & real
	);
		
	
	
	void _test_non_terminals_from_http(
		const std::string & str_input,
		const bool is_nonterminals,
		const Non_terminals & expected,
		const Errors & expected_errors
	);
	void _test_head_from_http(
		const std::string & str_input,
		const Head & expected,
		const Errors & expected_errors
	);
	void _test_rule_from_http(
		const std::string & str_input,
		const Rule & expected,
		const Errors & expected_errors
	);
	void _test_rules_from_http(
		const std::string & str_input,
		const Rules & expected,
		const Errors & expected_errors
	);
	void _test_word_from_http(
		const std::string & str_input,
		const Word & expected,
		const Errors & expected_errors
	);
	
public:
	
	void test_non_terminal_from_http();
	void test_head_from_http();
	void test_rule_from_http();
	void test_rules_from_http();
	void test_word_from_http();
	
};
#endif
