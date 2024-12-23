#ifndef SERVER_H_
#define SERVER_H_

#include "httplib.h"
#include "mod_to_http.h"
#include "html_response.h"
#include "model.h"


//handlers cannot be non-static
//in consequence most method of this class would be static
//therefore we just do it as a namespace

// but there are problems with the fields, so class with many static methods is easier

/** 
 * \brief server running the program, the main controller class
 */
class Server
{	
	/** 
	 * \brief the underlying server object
	 */
    static httplib::Server server;
  
  	static std::string css_file;
	static std::string js_file;
	static std::string help_file;
	static std::string grammars_file;
	static std::string credits_file;
   
	// std::vector<Error> errors;

public:

				/** 
	 * \brief method handling the GET requests
	 */ 
    static void main_get_handler(const httplib::Request & req,
		httplib::Response & resp);
	/** 
	 * \brief method handling the GET requests
	 */ 
    static void help_get_handler(const httplib::Request & req,
		httplib::Response & resp);
	/** 
	 * \brief method handling the GET requests
	 */ 
    static void grammars_get_handler(const httplib::Request & req,
		httplib::Response & resp);
	/** 
	 * \brief method handling the GET requests
	 */ 
    static void credits_get_handler(const httplib::Request & req,
		httplib::Response & resp);
		
	
	/** 
	 * \brief method handling the GET requests
	 */ 
    static void css_get_handler(const httplib::Request & req,
		httplib::Response & resp);
		
	
	/** 
	 * \brief method handling the GET requests
	 */ 
    static void js_get_handler(const httplib::Request & req,
		httplib::Response & resp);
		
	
	/** 
	 * \brief method handling the POST requests
	 */
    static void post_handler(const httplib::Request & req,
		httplib::Response & resp);
	
    
	/** 
	 * \brief constructor-like method
	 *
	 * can't have a constructor if all is static
	 */
    static void init();
	
	/** 
	 * \brief start the server's infinite loop. BLOCKING METHOD
	 */
    static void run();
	
	
	/** 
	 * \brief TEST ONLY set given file as the response at the /tst directory
	 *
	 * we can have pre-filled html forms thanks to that
	 */
    static void set_dummy_get(
		const std::string& filename,
		const std::string& url
	);
};

#endif // SERVER_H_
