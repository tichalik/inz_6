#ifndef GRAMMAR
#define GRAMMAR

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "utils.h"
#include "error.h"
#include "symbol.h"
#include "non_terminals.h"

/** 
 * \brief representation of grammatical rule in form 
 *	left -> right1 right 2
 */
struct Rule
{
    Symbol left;
    Symbol right1, right2;

	std::string to_string() const;
};

typedef std::vector<Rule> Rules;
typedef std::string Head;

// struct Head
// {
	// Symbol symbol;
	// Errors errors;
	
	// void check_for_terminals_errors(const Non_terminals & terminals);
	// void check_for_nonterminals_errors(const Non_terminals & nonterminals);
// }


/** 
 * \brief grammar in Chomsky's normal form
 */
class Grammar
{
	
	Non_terminals nonterminals;
	Non_terminals terminals;
	Head head;
	Rules rules;
	
	Errors errors;

	public:
	
	
    /** 
	 * \brief getter
	 */
	Non_terminals get_nonterminals() const;
    
	/** 
	 * \brief getter
	 */
	Non_terminals get_terminals() const;
    
	/** 
	 * \brief getter
	 */
	Head get_head() const;
    
	/** 
	 * \brief getter
	 */
	Rules get_rules() const;

    /** 
	 * \brief setter
	 */
	void set_nonterminals(const Non_terminals & _nonterminals);
    
    /** 
	 * \brief setter
	 */
	void set_terminals(const Non_terminals & _terminals);
    
    /** 
	 * \brief setter
	 */
	void set_head(const Head & _head);
    
    /** 
	 * \brief setter
	 */
	void set_rules(const Rules & _rules);
	
		
	/** 
	 * \brief get grammar's printf friendly description
	 */
	std::string to_string() const;
	
	void check_errors();

};



#endif // GRAMMAR
