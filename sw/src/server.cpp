#include "server.h"

httplib::Server Server::server;


void Server::get_handler(const httplib::Request & req,
	httplib::Response & resp)
{
	Html_response response;
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
	
	Model model(
		 http_terminals ,
		 http_nonterminals ,
		 http_head ,
		 http_rules ,
		 http_word 
	);
	
	//transform Errors and Ptrees into http
	Mod_to_http mod_to_http(
		model.get_errors(),
		model.get_ptrees(),
		http_nonterminals,
		http_terminals,
		http_head,
		http_rules,
		http_word
	);
	
	resp.set_content(mod_to_http.get_http(), "text/html");

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


void Server::set_dummy_get(
	const std::string& filename,
	const std::string& url
)
{
	std::string file;
	Utils::read_file(filename, file);
	
	server.Get("/" + url, [=] (const httplib::Request & req,
	httplib::Response & resp)
	{
		resp.set_content(file, "text/html");
	});
}