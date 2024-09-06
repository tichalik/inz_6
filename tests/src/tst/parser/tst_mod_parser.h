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
	
	void _test_remove_chains(
		const Chomsky_grammar & input_grammar,
		const Chomsky_grammar & expected_grammar
	);
		
	void _test_get_path(
		const Symbol & head,
		Chain_trees & chain_trees,
		const std::vector<Symbols> & expected_symbols_vect
	);
		
	void _test_unbreak_rules(
		const PTrees & input_trees,
		const Chomsky_grammar& grammar,
		const PTrees & expected_ptrees
	);
	
	void _test_replace_chain_in_rule(
		const Chomsky_rule & input_rule,
		Chain_trees& chain_trees, 
		const Chomsky_rules & expected_rule
	);
	
	void _test_restore_chains();
	
	void _test_fix_tree_add_chains(
		const PNode & input,
		const PNodes & expected
	);
			
	void _test_stretch_tree(
		const PNode & root,
		const Symbols & symbols_to_add,
		const PNode & expected
	);


	
public:

	void test_parsing_grammar_adapter();
	void test_propagate_parsing_table();
	void test_extract_trees_from_parsing_table();
	
	void test_break_rules();
	void test_create_new_symbol();
	void test_remove_chains();
	void test_get_path();
	void test_replace_chain_in_rule();
	
	void test_unbreak_rules();
	void test_restore_chains();
	
	void test_fix_tree_add_chains();
	void test_stretch_tree();
};
#endif
