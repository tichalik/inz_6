#ifndef CHECK_ERRORS_H_
#define CHECK_ERRORS_H_

#include "grammar.h"
#include "word.h"
#include "error.h"

class Mod_check_errors
{
	Errors errors;
		
		
	void add_error(
		const EN_ERROR_TYPE & type,
		const std::string & source
	);
	
		
	void check_symbol_errors(
		const std::string & parent_source,
		const Symbol &s,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	void word_check_errors(
		const std::string & parent_source,
		const Word &input,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);


	void grammar_check_errors(
		const std::string & parent_source,
		const Grammar &input
	);

	std::string rule_to_error_source(
		const std::string& parent_source,
		const Symbol& LHS,
		const std::vector<Symbols>& RHSs
	);

	void rules_check_errors(
		const std::string & parent_source,
		const Rules &input,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	void head_check_errors(
		const std::string & parent_source,
		const Head &input,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	public:
	
	Mod_check_errors(
		const Grammar & grammar, 
		const Word & word
	);
	
	Errors get_errors() const;
};

#endif //CHECK_ERRORS_H_
