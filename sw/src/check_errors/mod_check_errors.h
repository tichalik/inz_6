#ifndef CHECK_ERRORS_H_
#define CHECK_ERRORS_H_

#include "grammar.h"
#include "word.h"
#include "error.h"

class Mod_check_errors
{
	Errors errors;
	
		
	void check_symbol_errors(
		Symbol &s,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	void word_check_errors(
		Word &input,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);


	void grammar_check_errors(Grammar &input);

	void rule_check_errors(
		Rule &input,
		const Non_terminals& terminals,
		const Non_terminals& nonterminals
	);

	void rules_check_errors(
		Rules &input,
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	void non_terminals_check_errors(
		Non_terminals& input,
		const Non_terminals & other
	);
	
	void head_check_errors(
		Head &input,
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