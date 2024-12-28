#include "tester.h"
#include "tst_mod_check_errors.h"
#include "tst_mod_from_http.h"
#include "tst_mod_to_http.h"
#include "tst_mod_parser.h"
#include "tst_html_response.h"


#include "tst_visualize_grammar.h"

int main()
 {	
//    TST_mod_from_http mfh;
//	mfh.test_nonterminals_from_http();
//	mfh.test_terminals_from_http();
//	mfh.test_head_from_http();
//	mfh.test_rules_from_http();
//	mfh.test_word_from_http();
//	mfh.test_tokenize();

    TST_html_reponse htmlr; 
    htmlr.test();
	
	TST_mod_check_errors mce;
	mce.test_head_errors();
	mce.test_rules_errors();
	mce.test_word_errors();
	
	TST_mod_parser mp;
	mp.complete_parser_tests();
	
	TST_mod_to_http m2h;
	m2h.test_sppf_to_string();
	m2h.test_iterate_sppf();

	test_visualize();

}
