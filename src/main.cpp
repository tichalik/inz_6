#include "grammar.h"
#include "parser.h"
#include "tester.h"
#include "server.h"


int main()
{
    Tester t;
    // t.test_infix_chomsky_grammar();
	// t.test_non_terminal_from_http();
	// t.test_http_grammar_adapter_errors();
	t.test_head_from_http();
	// t.test_non_terminal_to_http();
	// t.test_html_response();

	// Server::init();
	// Server::set_dummy_get("./src/html_templates/infix_arithmetic_filled_form.html");
	// Server::run();

}
