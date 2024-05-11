#ifndef HTTP_GRAMMAR_ADAPTER_H_
#define HTTP_GRAMMAR_ADAPTER_H_

#include <string>
#include <sstream>
#include <vector>

#include "grammar.h"
#include "utils.h"

class Http_grammar_adapter
{
	Grammar grammar;
	
	void nonterminals_from_http(const std::string & param);
	void terminals_from_http(const std::string & param);
	void head_from_http(const std::string & param);
	void rules_from_http(const std::string & param);
	
	public:
	Http_grammar_adapter(
		const std::string & http_terminals,
		const std::string & http_nonterminals,
		const std::string & http_head,
		const std::string & http_rules);
	
	Http_grammar_adapter( const Grammar & grammar);
	
	std::string nonterminals_to_http();
	std::string terminals_to_http();
	std::string head_to_http();
	std::string rules_to_http();
	
	Grammar get_grammar();
	
};

#endif //HTTP_GRAMMAR_ADAPTER_H_