#ifndef FROM_HTTP_H_
#define FROM_HTTP_H_

#include <string>
#include <sstream>
#include <vector>

#include "grammar.h"
#include "word.h"
#include "error.h"
#include "token.h"

Tokens tokenize(const std::string & str);

class Mod_from_http
{
	
	Grammar grammar;
	Word word;
	Errors errors;
	
	
	void add_error(
		const EN_ERROR_TYPE & type,
		const std::string & source = ""
	);
	
    /** 
	 * \brief extract grammar information from a string obtained from http request
	 *
	 * \param is_nonterminals if param is empty and this is true raise nonterminals error
	 * else if param is empty and this is false raise terminals error
	 *
	 * assume the string is already processed (htpp entities are translated to 
	 * normal string)
	 */
	Non_terminals nonterminals_from_http(
		const std::string & param
	);
	Non_terminals terminals_from_http(
		const std::string & param
	);
	
    /** 
	 * \brief extract grammar information from a string obtained from http request
	 *
	 * assume the string is already processed (htpp entities are translated to 
	 * normal string)
	 */
	Head head_from_http(const std::string & param);
	
    /** 
	 * \brief extract grammar information from a string obtained from http request
	 *
	 * assume the string is already processed (htpp entities are translated to 
	 * normal string)
	 */
	Rules rules_from_http(const std::string & param);
	
	
	Word word_from_http(const std::string & param);
	
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
