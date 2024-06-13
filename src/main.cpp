#include "grammar.h"
#include "parser.h"
#include "tester.h"
#include "server.h"


#include "tst_html_response.h"

int main()
{
    Tester t;
	
	TST_html_reponse t1;
	t1.test();
	
    // t.test_infix_chomsky_grammar();
	// t.test_non_terminal_from_http();
	// t.test_http_grammar_adapter_errors();
	// t.test_head_from_http();
	t.test_rules_from_http();
	// t.test_non_terminal_to_http();
	// t.test_html_response();

	// Server::init();
	// Server::set_dummy_get("./src/html_templates/infix_arithmetic_filled_form.html");
	// Server::run();

}
