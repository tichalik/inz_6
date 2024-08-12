#ifndef TST_MOD_PARSER_H_
#define TST_MOD_PARSER_H_

#include "tester.h"
#include "mod_parser.h"

class TST_mod_parser: public Tester
{	
	void _test_propagate_parsing_table(
		const Grammar & grammar, 
		const Word & word, 
		const PTable & expected_ptable
	);
	
	void _test_parsing_grammar_adapter(
		const Chomsky_grammar& grammar
	);
	
	void _test_extract_trees_from_parsing_table(
		PTable & parsing_table,
		const PTrees & expected_ptrees
	);
	
	void _test_break_rules(
		const Grammar & input_grammar,
		const Chomsky_grammar expected_grammar
	);
	
	void _test_create_new_symbol(
		const Grammar & input_grammar,
		const Chomsky_grammar expected_grammar,
		const int NO_NEW_SYMBOLS
	);
		
	
	
public:

	void test_parsing_grammar_adapter();
	void test_propagate_parsing_table();
	void test_extract_trees_from_parsing_table();
	
	void test_break_rules();
	void test_create_new_symbol();
	
};
#endif
