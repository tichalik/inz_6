#include "tester.h"
#include "tst_html_response.h"
#include "tst_http_grammar_adapter.h"
#include "tst_parser.h"

int main()
{
	// TST_html_reponse t1;
	// t1.test();
	
	// TST_parser t2;
	// t2.test();
	
	TST_http_grammar_adapter t3;
	// t3.test_non_terminal_from_http();
	// t3.test_head_from_http();
	t3.test_rules_from_http();
	// t3.test_http_grammar_adapter_errors();
	
	
}
