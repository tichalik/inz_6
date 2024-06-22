#ifndef FROM_HTTP_H_
#define FROM_HTTP_H_

#include <string>
#include <sstream>
#include <vector>

#include "grammar.h"
#include "word.h"
#include "error.h"

class Mod_from_http: Errorable
{
	
	Grammar grammar;
	Word word;
	// Errors errors;
	
	
	
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
	
	
	void word_from_http(const std::string & param);
	
	public:
	
	Mod_from_http(
		const std::string & http_terminals,
		const std::string & http_nonterminals,
		const std::string & http_head,
		const std::string & http_rules,
		const std::string & http_word
	);
	
	Grammar get_grammar() const;
	Word get_word() const;
	Errors get_errors() const;
	
};

#endif //FROM_HTTP_H_