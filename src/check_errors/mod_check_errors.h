#ifndef CHECK_ERRORS_H_
#define CHECK_ERRORS_H_

#include "grammar.h"
#include "word.h"
#include "error.h"

/// class for checking formal errors in grammar
class Mod_check_errors
{
	/// container for errors generated during checking
	Errors errors;
		
	/// helper method - construct given error
	void add_error(
		const EN_ERROR_TYPE & type,
		const std::string & source
	);
	
	
	/// check whether symbol is defined somewhere 
	void check_symbol_errors(
		const std::string & parent_source,
		const Symbol &s,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	/// check if the word is composed of terminals 
	void word_check_errors(
		const std::string & parent_source,
		const Word &input,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);

	/// check all grammar errors
	void grammar_check_errors(
		const std::string & parent_source,
		const Grammar &input
	);

	/// helper method - transform rule into error source description
	std::string rule_to_error_source(
		const std::string& parent_source,
		const Symbol& LHS,
		const std::vector<Symbols>& RHSs
	);

	/// check whether all symbols in rules are defined somewhere
	void rules_check_errors(
		const std::string & parent_source,
		const Rules &input,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	/// check whether the head is a defined nonterminal
	void head_check_errors(
		const std::string & parent_source,
		const Head &input,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	public:
	
	/// constructor -- provide all necessary data
	Mod_check_errors(
		const Grammar & grammar, 
		const Word & word
	);
	
	/// get errors 	obtained during error checking
	Errors get_errors() const;
};

#endif //CHECK_ERRORS_H_
