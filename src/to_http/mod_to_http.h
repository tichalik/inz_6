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

class Mod_to_http
{
	std::string str_to_http(const std::string & str) const;
	
	std::string EN_ERROR_TYPE2str(const EN_ERROR_TYPE &error) const;
	std::string error_to_http(const Error & error) const;
	std::string errors_to_http(const Errors & error) const;
	
	std::string node_to_string(const VNode & node) const;
	std::string node_to_http(const VNode & node) const;
	std::string tree_to_http(const VNode & tree) const;

	std::string sppf_to_string(SPPF & sppf);
	std::string sppf_tree_to_string(SPPF & sppf);

	/** 
	 * \brief html to be sent as the responses
	 */
    Html_response response;
	
	public:
	
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
	
	std::string get_http();
};

#endif //TO_HTTP_H_
