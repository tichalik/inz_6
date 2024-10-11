#include "server.h"


int main()
{
	
	Server::init();
	
	Server::set_dummy_get("./src/html_templates/tst_html_entities_errors.html", "tst_html_entities_errors");
	Server::run();

}
