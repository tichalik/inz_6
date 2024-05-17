#ifndef HTTP_GRAMMAR_ADAPTER_H_
#define HTTP_GRAMMAR_ADAPTER_H_

#include <string>
#include <sstream>
#include <vector>

#include "grammar.h"
#include "utils.h"


/** 
 * \brief mediates between a Grammar and its http representation
 */
class Http_grammar_adapter
{
	/** 
	 * \brief the Grammar of which the object is a view
	 */
	Grammar grammar;
	
	
	
    /** 
	 * \brief extract grammar information from a string obtained from http request
	 *
	 * assume the string is already processed (htpp entities are translated to 
	 * normal string)
	 */
	void nonterminals_from_http(const std::string & param);
	
    /** 
	 * \brief extract grammar information from a string obtained from http request
	 *
	 * assume the string is already processed (htpp entities are translated to 
	 * normal string)
	 */
	void terminals_from_http(const std::string & param);
	
    
    /** 
	 * \brief generate http representation of a rule
	 */
	std::string rule_to_http(const Rule & rule) const;
	
	public:
	
	/** 
	 * \brief constructor, creates a grammar from http request
	 *
	 * assume the string is already processed (htpp entities are translated to 
	 * normal string)
	 */
	Http_grammar_adapter(
		const std::string & http_terminals,
		const std::string & http_nonterminals,
		const std::string & http_head,
		const std::string & http_rules);
	
	
	/** 
	 * \brief generate http representation of nonterminals
	 */
	std::string nonterminals_to_http() const;
	
	/** 
	 * \brief generate http representation of terminals
	 */
	std::string terminals_to_http() const;
	
	
};

#endif //HTTP_GRAMMAR_ADAPTER_H_