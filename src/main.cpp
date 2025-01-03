#include "server.h"


int main()
{
	/// initialize the server
	Server::init();	
	/// serve forever
	Server::run();
}
