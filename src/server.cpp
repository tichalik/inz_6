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
	const std::string http_terminals = req.get_param_value("terminals");
	const std::string http_nonterminals = req.get_param_value("nonterminals");
	const std::string http_head = req.get_param_value("head");
	const std::string http_rules = req.get_param_value("rules");
	
	Http_grammar_adapter http_grammar_adapter(
		http_terminals,
		http_nonterminals,
		http_head,
		http_rules);
		
	Grammar grammar = http_grammar_adapter.get_grammar();
	
	Parsing_grammar_adapter parsing_grammar_adapter(grammar);

	std::cout << grammar.to_string() <<std::endl;
	
	// std::vector<Error> grammar_errors = grammar.get_errors();

	Word input;
	input.from_http(req.get_param_value("input"));
	std::cout << "INPUT\n" << input.to_string() <<std::endl;

	// std::vector<Error> input_errors = input.get_errors();

	// if (grammar_errors.size() == 0 && input_errors.size() == 0)
	// {
		Parser parser;

		PTrees result = parser.parse(input, parsing_grammar_adapter );
		
		std::cout << "RESULTS\n" << result.to_string() << std::endl;

		// std::vector<Errors> parser_errors = parser.get_errors();
		response.fill_response(RESP_FIELDS::RESULTS, result.to_http());
		
	// }
	response.fill_response(RESP_FIELDS::HEAD, http_grammar_adapter.head_to_http());
	response.fill_response(RESP_FIELDS::TERMINALS, http_grammar_adapter.terminals_to_http());
	response.fill_response(RESP_FIELDS::NONTERMINALS, http_grammar_adapter.nonterminals_to_http());
	response.fill_response(RESP_FIELDS::RULES, http_grammar_adapter.rules_to_http());
	response.fill_response(RESP_FIELDS::INPUT, input.to_http());
	
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