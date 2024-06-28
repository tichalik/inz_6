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
public:

	void test_parsing_grammar_adapter();
	void test_propagate_parsing_table();
	void test_extract_trees_from_parsing_table();
	void test_translate_table_entry_trees_into_parse_trees();
	
};
#endif
