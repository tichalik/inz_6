#ifndef TST_MOD_FROM_HTTP_H_
#define TST_MOD_FROM_HTTP_H_

#include "tester.h"
#include "mod_from_http.h"

class TST_mod_from_http: public Tester
{	
	void _test_terminals_from_http(
		const std::string & str_input,
		const Non_terminals & expected,
		const Errors & expected_errors
	);
	void _test_nonterminals_from_http(
		const std::string & str_input,
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
		const bool expected_ok,
		const Symbol& LHS,
		const Symbols& RHS,
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
	void _test_tokenize(
		const std::string & str_input,
		const Tokens & expected
	);
	
public:
	
	void test_nonterminals_from_http();
	void test_terminals_from_http();
	void test_head_from_http();
	void test_rule_from_http();
	void test_rules_from_http();
	void test_word_from_http();
	void test_tokenize();
	
};
#endif
