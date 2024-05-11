#ifndef SERVER_H_
#define SERVER_H_

#include "httplib.h"
#include "grammar.h"
#include "http_grammar_adapter.h"
#include "parsing_grammar_adapter.h"
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
	enum EN_RESPONSE_FIELDS
	{
		TERMINALS = 0,
		NONTERMINALS, 
		HEAD, 
		RULES, 
		ERRORS, 
		INPUT, 
		RESULTS
	} ;
	const static int NO_RESPONSE_FIELDS = 7;

	const static std::string RESPONSE_FIELDS_DICT[NO_RESPONSE_FIELDS];
	
    static httplib::Server server;
    static std::string response_template;
    static std::string response;
	
	// std::vector<Error> errors;

public:

	static void get_handler(const httplib::Request & req,
		httplib::Response & resp);
		
	static void post_handler(const httplib::Request & req,
		httplib::Response & resp);

	static void fill_response(const Server::EN_RESPONSE_FIELDS field, const std::string & content);
	
	static std::string get_response();
	
	static void clear_response();
	
    static void init();
	static void run();
	
	static void set_dummy_get(const std::string filename);
};

#endif // SERVER_H_
