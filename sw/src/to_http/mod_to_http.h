#ifndef TO_HTTP_H_
#define TO_HTTP_H_

#include <string>
#include <sstream>
#include <vector>

#include "ptree.h"
#include "error.h"

class Mod_to_http
{
	std::string http_errors;
	std::string http_parse_trees;
	
	
	std::string EN_ERROR_TYPE2str(const EN_ERROR_TYPE &error) const;
	std::string error_to_http(const Error & error) const;
	std::string errors_to_http(const Errors & error) const;
	

	std::string pnode_to_string(const PNode & pnode) const;
	std::string pnode_to_http(const PNode & pnode) const;
	std::string ptree_to_string(const PTree & ptree) const;
	std::string ptree_to_http(const PTree & ptree) const;
	std::string ptrees_to_string(const PTrees & ptrees) const;
	std::string ptrees_to_http(const PTrees & ptrees) const;
	
	public:
	
	Mod_to_http(
		const Errors & errors, 
		const PTrees & ptrees
	);
	
	std::string get_http_errors() const;
	std::string get_http_parse_trees() const;
};

#endif //TO_HTTP_H_