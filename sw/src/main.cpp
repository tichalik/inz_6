#include "server.h"


int main()
{
	
	Server::init();
	Server::set_dummy_get("./src/html_templates/infix_arithmetic_filled_form.html");
	Server::run();

}
