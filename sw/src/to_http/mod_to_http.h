#ifndef TO_HTTP_H_
#define TO_HTTP_H_

#include <string>
#include <sstream>
#include <vector>

#include "ptree.h"
#include "error.h"
#include "html_response.h"
#include "vnode.h"

#include "utils.h"

class Mod_to_http
{
	std::string str_to_http(const std::string & str) const;
	
	std::string EN_ERROR_TYPE2str(const EN_ERROR_TYPE &error) const;
	std::string error_to_http(const Error & error) const;
	std::string errors_to_http(const Errors & error) const;
	
	std::string vnode_to_http(const VNode & vnode) const;
	std::string vtree_to_http(const VNode & vtree) const;

	std::string pnode_to_string(const PNode & pnode) const;
	std::string pnode_to_http(const PNode & pnode) const;
	std::string ptree_to_string(const PTree & ptree) const;
	std::string ptree_to_http(const PTree & ptree) const;
	std::string ptrees_to_string(const PTrees & ptrees) const;
	std::string ptrees_to_http(const PTrees & ptrees) const;
	
	
	/** 
	 * \brief html to be sent as the responses
	 */
    Html_response response;
	
	public:
	
	Mod_to_http(
		const Errors & errors, 
		const PTrees & ptrees, 
		const VNode & vnode,
		const std::string & http_nonterminals,
		const std::string & http_terminals,
		const std::string & http_head,
		const std::string & http_rules,
		const std::string & http_word
	);
	
	std::string get_http();
};

#endif //TO_HTTP_H_