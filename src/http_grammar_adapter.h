#ifndef HTTP_GRAMMAR_ADAPTER_H_
#define HTTP_GRAMMAR_ADAPTER_H_

#include <string>
#include <sstream>
#include <vector>
#include "non_terminals.h"
#include "utils.h"


/** 
 * \brief mediates between a Grammar and its http representation
 */
class Http_grammar_adapter
{
	
	Non_terminals nonterminals;
	
	public:
	
	/** 
	 * \brief constructor, creates a grammar from http request
	 *
	 * assume the string is already processed (htpp entities are translated to 
	 * normal string)
	 */
	Http_grammar_adapter(
		const std::string & http_nonterminals);
	
	
	/** 
	 * \brief generate http representation of nonterminals
	 */
	std::string nonterminals_to_http() const;
	
};

#endif //HTTP_GRAMMAR_ADAPTER_H_