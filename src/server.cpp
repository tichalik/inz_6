#include "server.h"

httplib::Server Server::server;
std::string Server::response_template;
std::string Server::response;


const std::string Server::RESPONSE_FIELDS_DICT[Server::NO_RESPONSE_FIELDS] = {
	"{{TERMINALS}}",
	"{{NONTERMINALS}}",
	"{{HEAD}}",
	"{{RULES}}",
	"{{ERRORS}}",
	"{{INPUT}}",
	"{{RESULTS}}"
};


void Server::get_handler(const httplib::Request & req,
	httplib::Response & resp)
{
	fill_response(RESULTS,"");	
	fill_response(HEAD,"");
	fill_response(TERMINALS,"");
	fill_response(NONTERMINALS,"");
	fill_response(RULES,"");
	fill_response(INPUT,"");

	
	resp.set_content(get_response(), "text/html");
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
		
		std::cout << "RESULTS\n" << result.to_string() <<std::endl;

		// std::vector<Errors> parser_errors = parser.get_errors();
		fill_response(RESULTS, result.to_http());
		
	// }
	fill_response(HEAD, http_grammar_adapter.head_to_http());
	fill_response(TERMINALS, http_grammar_adapter.terminals_to_http());
	fill_response(NONTERMINALS, http_grammar_adapter.nonterminals_to_http());
	fill_response(RULES, http_grammar_adapter.rules_to_http());
	fill_response(INPUT, input.to_http());




	resp.set_content(get_response(), "text/html");


}

void Server::fill_response(const Server::EN_RESPONSE_FIELDS field,  const std::string & content)
{
	//string::replace(initial_pos, length, replacement_string);
	response.replace(response.find(RESPONSE_FIELDS_DICT[field]),
		RESPONSE_FIELDS_DICT[field].size(), content);
}

std::string Server::get_response()
{
	std::string tmp = response;
	clear_response();
	return tmp;
}

void Server::clear_response()
{
	Server::response = Server::response_template;
}


void Server::init()
{
	//load response template
	Utils::read_file("./src/html_templates/post_form.html", Server::response_template);
	clear_response();
	
	
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