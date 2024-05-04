#include "server.h"


bool read_file(const std::string & filename,
	std::string & res)
{
	bool status;
	std::ifstream file(filename);
	if (file)
	{
		std::string line;
		while (std::getline(file, line))
		{
			res += line + "\n";
		}

		file.close();
		status = true;
	}
	else
	{
		std::cout << "cannot open file " << filename << std::endl;
		status = false;
	}

	return status;

}


void Server::get_handler(const httplib::Request & req,
	httplib::Response & resp)
{
	fill_response("result","");	
	fill_response("head","");
	fill_response("terminals","");
	fill_response("nonterminals","");
	fill_response("rules","");
	fill_response("input","");

	
	resp.set_content(response, "text/html");
}

void Server::post_handler(const httplib::Request & req,
	httplib::Response & resp)
{
	Grammar grammar;

	grammar.head_from_http(req.get_param_value("head"));
	grammar.terminals_from_http(req.get_param_value("terminals"));
	grammar.nonterminals_from_http(req.get_param_value("nonterminals"));
	grammar.rules_from_http(req.get_param_value("rules"));
	
	// std::vector<Error> grammar_errors = grammar.get_errors();

	Word input;
	input.from_http(req.get_param_value("input"));

	// std::vector<Error> input_errors = input.get_errors();

	// if (grammar_errors.size() == 0 && input_errors.size() == 0)
	// {
		Parser parser;

		PTrees result = parser.parse(input, grammar);

		// std::vector<Errors> parser_errors = parser.get_errors();
		fill_response("result", result.to_http());
		
	// }
	fill_response("head", grammar.head_to_http());
	fill_response("terminals", grammar.terminals_to_http());
	fill_response("nonterminals", grammar.nonterminals_to_http());
	fill_response("rules", grammar.rules_to_http());
	fill_response("input", input.to_http());




	resp.set_content(get_response(), "text/html");


}

void Server::fill_response(const std::string & field,  const std::string & content)
{

}

std::string Server::get_response()
{

}


void Server::init()
{
	server.Get("/", get_handler);
	// THE POST HAS THE PATH SPECIFIED IN THE ACTION ATTRIBUTE
	server.Post("/done", post_handler);
}

void Server::run()
{
	server.listen("0.0.0.0", 8413);
}