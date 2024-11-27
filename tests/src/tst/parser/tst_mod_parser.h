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
		const std::vector<std::list<State>> & expected_states,
		const std::vector<PNode*> & expected_results
	);

	
	void _tst_combine2(
		std::vector<std::vector<PNode*>>& input1,
		SPPF_node* input2, 
		std::vector<std::vector<PNode*>>& expected
	);

public:

	void tst_combine2();
	void test_parsing_grammar_adapter();
	void test_extract_trees_from_parsing_table();
	
	void complete_parser_tests();
};
#endif
