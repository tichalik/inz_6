#ifndef ERROR_H_
#define ERROR_H_

#include <string>
#include <vector>

enum EN_ERROR_TYPE
{
	/// the nonterminals field not filled in form
	EMPTY_NONTERMINALS,
	/// the terminals field not filled in form
	EMPTY_TERMINALS,
	/// the head field not filled in form
	EMPTY_HEAD,
	/// the rules field not filled in form
	EMPTY_RULES,
	/// the word field not filled in form
	EMPTY_WORD,
	
	/// symbol neither in terminals nor in nonterminals
	UNKNOWN_SYMBOL,
	
	/// symbol repeating within a set
	REPEATING_SYMBOL,
	/// terminal-like symbol in nonterminals
	TERM_IN_NTERMS,
	/// nonterminal-like symbol in terminals
	NTERM_IN_TERMS,

	/// unexpected | in a rule
	STRAY_OR,
	/// unexpected ::= in a rule
	STRAY_SEP,
	/// unexpected line break in a rule
	STRAY_LB,

	/// rule does not habe a LHS
	MISSING_LHS,
	/// rule does not habe a RHS
	MISSING_RHS,
	/// too many symbols on LHS
	TOO_MANY_LHS,
	/// terminal cannot be turned into anything
	TERMINAL_AS_LHS,
	
	/// head is in terminals
	HEAD_NOT_IN_NONTERMINALS,
	/// multiple symbols in the form's head field
	MULTIPLE_HEADS,
	
	/// word's symbol cannot be a nonterminal 
	SYMBOL_IN_NONTERMINALS,
};

/**
 *	\brief structure representing error in submitted grammar/word
 */
struct Error
{
	/// type of the error (eg. EMPTY_NONTERMINALS)
	EN_ERROR_TYPE type;
	/// string describing the element that generated the error
	std::string source;
};


typedef std::vector<Error> Errors;

#endif // ERROR_H_
