#ifndef SERVER_H_
#define SERVER_H_

#include "httplib.h"
#include "mod_to_http.h"
#include "html_response.h"
#include "model.h"

 /**
 * \brief server running the program, the main controller class
 *
 * Everything is static because the handler methods must cannot be non-static.
 */
class Server
{	
	/// the underlying server object
    static httplib::Server server;
  
	/// response for request for the css file
  	static std::string css_file;
	/// response for request for the java script file
	static std::string js_file;
	/// response for request for the help page
	static std::string help_file;
	/// response for request for the information about grammars page
	static std::string grammars_file;
	/// response for request for the credits page
	static std::string credits_file;
   
public:

				 
	/// method handling GET / 
    static void main_get_handler(const httplib::Request & req,
		httplib::Response & resp);
	 
	/// method handling GET /help
    static void help_get_handler(const httplib::Request & req,
		httplib::Response & resp);
	 
	/// method handling GET /grammars 
    static void grammars_get_handler(const httplib::Request & req,
		httplib::Response & resp);
	 
	/// method handling GET /credits
    static void credits_get_handler(const httplib::Request & req,
		httplib::Response & resp);
		
	/// method handling GET /styles.css
    static void css_get_handler(const httplib::Request & req,
		httplib::Response & resp);
	  
	/// method handling GET /scripts.css
    static void js_get_handler(const httplib::Request & req,
		httplib::Response & resp);
		
	
	/// method handling the POST requests 
    static void post_handler(const httplib::Request & req,
		httplib::Response & resp);
	
	 /// constructor-like method
    static void init();
	 
	 /// start the server's infinite loop. BLOCKING METHOD
    static void run();
	
};

#endif // SERVER_H_
