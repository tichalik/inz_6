#ifndef SERVER_H_
#define SERVER_H_

#include "httplib.h"
#include "grammar.h"
#include "http_grammar_adapter.h"
#include "parsing_grammar_adapter.h"
#include "html_response.h"
#include "utils.h"
#include "parser.h"
#include "word.h"
#include "error.h"

//handlers cannot be non-static
//in consequence most method of this class would be static
//therefore we just do it as a namespace

// but there are problems with the fields, so class with many static methods is easier
class Server
{
    static httplib::Server server;
   
	static Html_response response;
   
	// std::vector<Error> errors;

public:

	static void get_handler(const httplib::Request & req,
		httplib::Response & resp);
		
	static void post_handler(const httplib::Request & req,
		httplib::Response & resp);

	
	
    static void init();
	static void run();
	
	static void set_dummy_get(const std::string filename);
};

#endif // SERVER_H_
