#ifndef TO_HTTP_H_
#define TO_HTTP_H_

#include <string>
#include <sstream>
#include <vector>

#include "error.h"
#include "html_response.h"
#include "vnode.h"
#include "sppf.h"

#include "utils.h"

/// \brief produces html view of app's data
class Mod_to_http
{
	/// convert string to html entities 
	std::string str_to_http(const std::string & str) const;
	
	/// get error message based on error type
	std::string EN_ERROR_TYPE2str(const EN_ERROR_TYPE &error) const;
	/// convert error to error message
	std::string error_to_http(const Error & error) const;
	/// convert multiple errors to error messages
	std::string errors_to_http(const Errors & error) const;
	
	/// create view of visualization node
	std::string node_to_http(const VNode & node) const;
	/// create view of visualization tree (given the root node)
	std::string tree_to_http(const VNode & tree) const;

	/// create view of all parsing results
	std::string sppf_to_string(SPPF & sppf);
	/// create view of single parsing result
	std::string sppf_tree_to_string(SPPF & sppf);

	/// brief html to be sent as the responses
    Html_response response;
	
	public:
	
	/// constructor -- provide all necessary data
	Mod_to_http(
		const Errors & errors, 
		SPPF & sppf, 
		const VNode & node,
		const std::string & http_nonterminals,
		const std::string & http_terminals,
		const std::string & http_head,
		const std::string & http_rules,
		const std::string & http_word
	);
	
	/// get the resulting html 
	std::string get_http();
};

#endif //TO_HTTP_H_
