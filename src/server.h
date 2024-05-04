#ifndef SERVER_H_
#define SERVER_H_

#include "httplib.h"
#include "grammar.h"
#include "parser.h"
#include "word.h"
#include "error.h"


namespace Server
{
    httplib::Server server;
    std::string response_template;
    std::string response;
	
	std::vector<Error> errors;

	void get_handler(const httplib::Request & req,
		httplib::Response & resp);
		
	void post_handler(const httplib::Request & req,
		httplib::Response & resp);

	void fill_response(const std::string & field, const std::string & content);
	
	std::string get_response();
	
    void init();
	void run();
};

#endif // SERVER_H_
