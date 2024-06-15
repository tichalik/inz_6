#ifndef HTTP_WORD_ADAPTER_H_
#define HTTP_WORD_ADAPTER_H_

#include <string>
#include <sstream>
#include <vector>

#include "word.h"
#include "http_adapter.h"
#include "utils.h"

/** 
 * \brief mediates between a Word and its http representation
 */
class Http_word_adapter: public Http_adapter
{
	/** 
	 * \brief the Word of which the object is a view
	 */
	Word word;
	
	public:
	
	/** 
	 * \brief constructor, creates a wird from http request
	 *
	 * assume the string is already processed (htpp entities are translated to 
	 * normal string)
	 */
	Http_word_adapter(
		const std::string & http_word
	);
	
	/** 
	 * \brief constructor
	 */
	Http_word_adapter( const Word & word);
	
	/** 
	 * \brief generate http representation 
	 */
	std::string to_http() const;
	
	/** 
	 * \brief words's getter
	 */
	Word get_word() const;
	
	bool has_errors() const;
	
};

#endif //HTTP_GRAMMAR_ADAPTER_H_