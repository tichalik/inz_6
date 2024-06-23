#include "tester.h"
#include "tst_mod_check_errors.h"
#include "tst_mod_from_http.h"

int main()
{
	TST_mod_from_http mfh;
	mfh.test_non_terminal_from_http();
	mfh.test_head_from_http();
	mfh.test_rules_from_http();
	mfh.test_word_from_http();
	
	
	TST_mod_check_errors mce;
	mce.test_head_errors();
	mce.test_non_terminals_errors();
	mce.test_rules_errors();
	mce.test_word_errors();
	
	
}
