#include "server.h"

httplib::Server Server::server;
std::string Server::css_file;
std::string Server::js_file;
std::string Server::help_file;
std::string Server::grammars_file;
std::string Server::credits_file;

void Server::main_get_handler(const httplib::Request & req,
	httplib::Response & resp)
{
	Html_response response;
	resp.set_content(response.get_response(), "text/html");
}



void Server::help_get_handler(const httplib::Request & req,
	httplib::Response & resp)
{ 
	resp.set_content(Server::help_file, "text/html");
}



void Server::grammars_get_handler(const httplib::Request & req,
	httplib::Response & resp)
{ 
	resp.set_content(Server::grammars_file, "text/html");
}



void Server::credits_get_handler(const httplib::Request & req,
	httplib::Response & resp)
{
	resp.set_content(Server::credits_file, "text/html");
}


void Server::js_get_handler(const httplib::Request & req,
	httplib::Response & resp)
{ 
	resp.set_content(Server::js_file, "text/javascript");
}


void Server::css_get_handler(const httplib::Request & req,
	httplib::Response & resp)
{
	resp.set_content(Server::css_file, "text/css");
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
	const bool simple_visualization = req.get_param_value("visualization") == "simple";
	
	Model model(
		 http_terminals ,
		 http_nonterminals ,
		 http_head ,
		 http_rules ,
		 http_word ,
		 simple_visualization
	);
	
	//transform Errors and Ptrees into http
	Mod_to_http mod_to_http(
		model.get_errors(),
		model.get_sppf(),
		model.get_vnode(),
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
	//load reused documents
	Utils::read_file("./src/html_templates/styles.css", Server::css_file);
	Utils::read_file("./src/html_templates/scripts.js", Server::js_file);
	Utils::read_file("./src/html_templates/help.html", Server::help_file);
	Utils::read_file("./src/html_templates/grammars.html", Server::grammars_file);
	Utils::read_file("./src/html_templates/credits.html", Server::credits_file);

	//set handlers for the server
	server.Get("/", main_get_handler);
	server.Get("/styles.css", css_get_handler);
	server.Get("/scripts.js", js_get_handler);
	server.Get("/help", help_get_handler);
	server.Get("/grammars", grammars_get_handler);
	server.Get("/credits", credits_get_handler);
	
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
