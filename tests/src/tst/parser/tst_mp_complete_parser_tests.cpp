#include "tst_mod_parser.h"


void TST_mod_parser::_complete_parser_tests(
	const Grammar & grammar,
	const Word & word,
	const std::vector<std::list<State>> & expected_states,
	const std::vector<PNode*> & expected_results
)
{
	SPPF sppf;
	Mod_parser parser(grammar, word, sppf);
	
//	bool ok = compare(expected_states, parser.states, "parser's states");
//	ok &= compare(expected_results, parser.results, "results");
////	for (auto i: parser.results)
//	{
//		std::cout << (i) << std::endl;
//	}
//	if (ok)
//	{
//		std::cout << "OK" << std::endl;
//	}
//	else
//	{
//		std::cout << __FILE__ << "\tFAIL" << std::endl;
//	}

} 

void TST_mod_parser::complete_parser_tests()
{ 
	PNodes result1_holder(5);

	std::vector<PNode*> result1s;

	// a[b c[e] d]

	result1_holder[0 + 0].tag = "a";
	result1_holder[0 + 1].tag = "b";
	result1_holder[0 + 2].tag = "c";
	result1_holder[0 + 3].tag = "e";
	result1_holder[0 + 4].tag = "d";

	result1_holder[0 + 0].children.push_back(&result1_holder[0 + 1]);
	result1_holder[0 + 0].children.push_back(&result1_holder[0 + 2]);
	result1_holder[0 + 2].children.push_back(&result1_holder[0 + 3]);
	result1_holder[0 + 0].children.push_back(&result1_holder[0 + 4]);

	result1s.push_back(&result1_holder[0]);
	
	
	
	
	
	
	PNodes result2_holder(5);

	std::vector<PNode*> result2s;

	// a[b c[e] d]

	result2_holder[0 + 0].tag = "a";
	result2_holder[0 + 1].tag = "b";
	result2_holder[0 + 2].tag = "c";
	result2_holder[0 + 3].tag = "e";
	result2_holder[0 + 4].tag = "d";

	result2_holder[0 + 0].children.push_back(&result2_holder[0 + 1]);
	result2_holder[0 + 0].children.push_back(&result2_holder[0 + 2]);
	result2_holder[0 + 2].children.push_back(&result2_holder[0 + 3]);
	result2_holder[0 + 2].children.push_back(&result2_holder[0 + 4]);

	result2s.push_back(&result2_holder[0]);
	
	std::cout << compare(&result1_holder[0], &result2_holder[0], "whatever");
}
