#ifndef TST_MOD_PARSER_H_
#define TST_MOD_PARSER_H_

#include "tester.h"
#include "mod_parser.h"

class TST_mod_parser: public Tester
{	

//	void _test_parsing_grammar_adapter(
//		const Grammar& grammar
//	);
//	
//	void _test_extract_trees_from_parsing_table(
//		PTable & parsing_table,
//		const PTrees & expected_ptrees
//	);
	

	void _complete_parser_tests(
		const Grammar & grammar,
		const Word & word,
		const Errors & expected_errors,
		const PTrees & expected_ptrees
	);

	
public:

	void test_parsing_grammar_adapter();
	void test_extract_trees_from_parsing_table();
	
	void complete_parser_tests();
};
#endif
