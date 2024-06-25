#include "server.h"

httplib::Server Server::server;
Html_response Server::response;


void Server::get_handler(const httplib::Request & req,
	httplib::Response & resp)
{
	resp.set_content(response.get_response(), "text/html");
}

void Server::post_handler(const httplib::Request & req,
	httplib::Response & resp)
{
	//get data from http 
	const std::string http_terminals = req.get_param_value("terminals");
	const std::string http_nonterminals = req.get_param_value("nonterminals");
	const std::string http_head = req.get_param_value("head");
	const std::string http_rules = req.get_param_value("rules");
	const std::string http_word = req.get_param_value("input");
	
	//directly pass the http values into the result form 
	response.fill_response(RESP_FIELDS::TERMINALS, http_terminals);
	response.fill_response(RESP_FIELDS::NONTERMINALS, http_nonterminals);
	response.fill_response(RESP_FIELDS::HEAD, http_head);
	response.fill_response(RESP_FIELDS::RULES, http_rules);
	response.fill_response(RESP_FIELDS::INPUT, http_word);
	
	
	Errors errors;
	PTrees parsing_trees;

	//transform http into Grammar and Word
	Mod_from_http mod_from_http(
		http_terminals,
		http_nonterminals,
		http_head,
		http_rules,
		http_word
	);
		
	const Errors http_errors = mod_from_http.get_errors();
	errors.insert(errors.end(), http_errors.begin(), http_errors.end());
	
	//if there are no http errors, proceed
	if (http_errors.size() == 0 )
	{
		const Grammar grammar = mod_from_http.get_grammar();
		const Word word = mod_from_http.get_word();
		
		//check errors
		Mod_check_errors mod_check_errors(
			grammar, 
			word
		);
		
		const Errors semantic_errors = mod_check_errors.get_errors();
		errors.insert(errors.end(), semantic_errors.begin(), semantic_errors.end());

		
		//parse if there are no errors
		if (semantic_errors.size() == 0)
		{
			
			Parsing_grammar_adapter parsing_grammar_adapter(grammar);
			Parser parser;

			parsing_trees = parser.parse(word, parsing_grammar_adapter);
		}
	}
	
	//transform Errors and Ptrees into http
	Mod_to_http mod_to_http(
		errors,
		parsing_trees
	);
	
	//fill out the rest of the form 
	response.fill_response(RESP_FIELDS::ERRORS, mod_to_http.get_http_errors());
	response.fill_response(RESP_FIELDS::RESULTS, mod_to_http.get_http_parse_trees());
	
	resp.set_content(response.get_response(), "text/html");

}


void Server::init()
{	
	//set handlers for the server
	server.Get("/", get_handler);
	// THE POST HAS THE PATH SPECIFIED IN THE ACTION ATTRIBUTE
	server.Post("/done", post_handler);
}

void Server::run()
{
	server.listen("0.0.0.0", 8413);
}


void Server::set_dummy_get(const std::string filename)
{
	std::string file;
	Utils::read_file(filename, file);
	
	server.Get("/tst", [=] (const httplib::Request & req,
	httplib::Response & resp)
	{
		resp.set_content(file, "text/html");
	});
}