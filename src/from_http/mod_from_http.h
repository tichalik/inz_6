#ifndef FROM_HTTP_H_
#define FROM_HTTP_H_

#include <string>
#include <sstream>
#include <vector>

#include "grammar.h"
#include "word.h"
#include "error.h"
#include "token.h"

/// breaks provided string into tokens
Tokens tokenize(const std::string & str);

/// \brief construct structures from http input
/// all inputs are what the user sees when entering the input
class Mod_from_http
{
	/// constructed grammar
	Grammar grammar;
	/// constructed word
	Word word;
	/// errors preventing construction of grammar/word
	Errors errors;
	
	/// constructs an error and adds it to errors
	void add_error(
		const EN_ERROR_TYPE & type,
		const std::string & source = ""
	);
	
	/// try constructing nonterminals from given string
	Non_terminals nonterminals_from_http(
		const std::string & param
	);
	/// try constructing terminals from given string
	Non_terminals terminals_from_http(
		const std::string & param
	);
	
	/// try constructing head from given string
	Head head_from_http(const std::string & param);
	
	/// try constructing rules from given string
	Rules rules_from_http(const std::string & param);
	
	/// try constructing word from given string
	Word word_from_http(const std::string & param);
	
	public:

	/// constructor -- provide all necessary data
	Mod_from_http(
		const std::string & http_terminals,
		const std::string & http_nonterminals,
		const std::string & http_head,
		const std::string & http_rules,
		const std::string & http_word
	);
	
	/// get constructed grammar
	Grammar get_grammar() const;
	/// get constructed word
	Word get_word() const;
	/// get errors preventing costruction of grammar/word
	Errors get_errors() const;
	
};

#endif //FROM_HTTP_H_
