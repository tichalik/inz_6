#include "tester.h"
#include "tst_mod_check_errors.h"
#include "tst_mod_from_http.h"
#include "tst_mod_to_http.h"
#include "tst_mod_parser.h"


#include "tst_visualize_grammar.h"


void test_compares()
{
	std::cout << "===============================================================" << std::endl;
	std::cout << "compare Symbol" << std::endl;
	std::cout << "===============================================================" << std::endl;

	Symbol a1 = "a";
	Symbol a2 = "a";
	Symbol b = "b";
	
	std::cout << "same symbols " << compare(a1,a2, "symbol") << std::endl; 
	std::cout << "different symbols " << compare(a1,b, "symbol") << std::endl; 
	
}

int main()
 {
	// test_compares();
	
//    TST_mod_from_http mfh;
//	mfh.test_nonterminals_from_http();
//	mfh.test_terminals_from_http();
//	mfh.test_head_from_http();
//	mfh.test_rules_from_http();
//	mfh.test_word_from_http();
//	mfh.test_tokenize();
	
	TST_mod_check_errors mce;
	mce.test_head_errors();
	mce.test_rules_errors();
	mce.test_word_errors();
	
	TST_mod_parser mp;
//	mp.complete_parser_tests();
	
	TST_mod_to_http m2h;
//	m2h.test_sppf_to_string();
//	m2h.test_iterate_sppf();

//	test_visualize();

}
