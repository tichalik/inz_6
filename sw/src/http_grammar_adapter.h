#ifndef HTTP_GRAMMAR_ADAPTER_H_
#define HTTP_GRAMMAR_ADAPTER_H_

#include <string>
#include <sstream>
#include <vector>

#include "http_adapter.h"
#include "grammar.h"
#include "utils.h"

/** 
 * \brief mediates between a Grammar and its http representation
 */
class Http_grammar_adapter: public Http_adapter
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
	 * \brief extract grammar information from a string obtained from http request
	 *
	 * assume the string is already processed (htpp entities are translated to 
	 * normal string)
	 */
	void head_from_http(const std::string & param);
	
    /** 
	 * \brief extract grammar information from a string obtained from http request
	 *
	 * assume the string is already processed (htpp entities are translated to 
	 * normal string)
	 */
	void rules_from_http(const std::string & param);
	
	
	
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
	 * \brief constructor
	 */
	Http_grammar_adapter( const Grammar & grammar);
	
	/** 
	 * \brief generate http representation of nonterminals
	 */
	std::string nonterminals_to_http() const;
	
	/** 
	 * \brief generate http representation of terminals
	 */
	std::string terminals_to_http() const;
	
	/** 
	 * \brief generate http representation of the head
	 */
	std::string head_to_http() const;
	
	/** 
	 * \brief generate http representation of the rules
	 */
	std::string rules_to_http() const;
	
	
	
	/** 
	 * \brief grammar's getter
	 */
	Grammar get_grammar() const;
	
	bool has_errors() const;
	
	Errors get_errors() const;
	
};

#endif //HTTP_GRAMMAR_ADAPTER_H_