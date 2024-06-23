#ifndef TST_MOD_CHECK_ERRORS_H_
#define TST_MOD_CHECK_ERRORS_H_

#include "tester.h"
#include "mod_check_errors.h"

class TST_mod_check_errors: public Tester
{
	void _test_word_errors(
		const Word & word,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals,
		const Errors & expected_errors
	);

	void _test_rules_errors(
		const Rule & rule,
		const Non_terminals& terminals,
		const Non_terminals& nonterminals,
		const Errors & expected_errors
	);
	
	void _test_non_terminals_errors(
		const Non_terminals& input,
		const Non_terminals & other,
		const Errors & expected_errors
	);
	
	void _test_head_errors(
		const Head & head,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals,
		const Errors & expected_errors
	);
	
	
public:
	
	void test_head_errors();
	void test_rules_errors();
	void test_non_terminals_errors();
	void test_word_errors();
	
	
};
#endif
