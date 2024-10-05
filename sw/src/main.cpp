#include "server.h"


int main()
{
	
	Server::init();
	Server::set_dummy_get("./src/html_templates/tst.html", "tst");
	
	Server::set_dummy_get("./src/html_templates/tst1.html", "tst1");
	Server::set_dummy_get("./src/html_templates/tst2.html", "tst2");
	Server::set_dummy_get("./src/html_templates/tst3.html", "tst3");
	Server::set_dummy_get("./src/html_templates/tst4.html", "tst4");
	Server::set_dummy_get("./src/html_templates/tst_html_entities_errors.html", "tst_html_entities_errors");
	Server::set_dummy_get("./src/html_templates/tst_html_parse.html", "tst_html");
	Server::run();

}
