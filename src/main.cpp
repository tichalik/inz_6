#include "grammar.h"
#include "parser.h"
#include "tester.h"
#include "server.h"


int main()
{
    Tester t;
    // t.test_infix_chomsky_grammar();

	Server::init();
	Server::set_dummy_get("./src/html_templates/infix_arithmetic_filled_form.html");
	Server::run();

}
