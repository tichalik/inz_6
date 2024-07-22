#include "server.h"


int main()
{
	
	Server::init();
	Server::set_dummy_get("./src/html_templates/prefilled_post_form.html", "tst");
	
	Server::set_dummy_get("./src/html_templates/tst1.html", "tst1");
	Server::set_dummy_get("./src/html_templates/tst2.html", "tst2");
	Server::set_dummy_get("./src/html_templates/tst3.html", "tst3");
	Server::set_dummy_get("./src/html_templates/tst4.html", "tst4");
	Server::run();

}
