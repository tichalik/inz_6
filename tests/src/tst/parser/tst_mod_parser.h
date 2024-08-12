#ifndef TST_MOD_PARSER_H_
#define TST_MOD_PARSER_H_

#include "tester.h"
#include "mod_parser.h"

class TST_mod_parser: public Tester
{
	bool compare_ptable(
		const PTable & expected,
		const PTable & real
	) const;
	bool compare_ptable_entry(
		const PTable_entry & expected,
		const PTable_entry & real
	) const;
	bool compare_ptable_reference(
		const PTable_reference & expected,
		const PTable_reference & real
	) const;
	
	bool compare_ptrees(
		const PTrees & expected,
		const PTrees & real
	) const;
	bool compare_ptree(
		const PTree & expected,
		const PTree & real
	) const;
	bool compare_pnode(
		const PNode & expected,
		const PNode & real
	) const;
	
	bool compare_chomsky_grammar(
		const Chomsky_grammar & expected,
		const Chomsky_grammar & real
	) const;
	
	bool compare_chomsky_rule(
		const Chomsky_rule & expected,
		const Chomsky_rule & real
	) const;
	
	bool compare_chomsky_rules(
		const Chomsky_rules & expected,
		const Chomsky_rules & real
	) const;

	bool compare_cycle_warnigs(
		const Cycle_warning & expected,
		const Cycle_warning & real
	) const;
	
	std::string ptable2string(
		const PTable & input
	);
	std::string ptable_entry2string(
		const PTable_entry & input
	);
	std::string ptable_reference2string(
		const PTable_reference & input
	);
	
	
	void _test_propagate_parsing_table(
		const Grammar & grammar, 
		const Word & word, 
		const PTable & expected_ptable
	);
	
	void _test_parsing_grammar_adapter(
		const Grammar & grammar
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
