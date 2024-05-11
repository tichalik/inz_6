#ifndef GRAMMAR
#define GRAMMAR

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "utils.h"


typedef std::string Symbol;

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

typedef std::vector<std::string> Terminals;
typedef std::vector<std::string> Nonterminals;
typedef std::vector<Rule> Rules;
typedef std::string Head;


/** 
 * \brief grammar in Chomsky's normal form
 */
class Grammar
{
	
	Nonterminals nonterminals;
	Terminals terminals;
	Head head;
	Rules rules;

	public:
	
	
    /** 
	 * \brief getter
	 */
	Nonterminals get_nonterminals() const;
    
	/** 
	 * \brief getter
	 */
	Terminals get_terminals() const;
    
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
	void set_nonterminals(const Nonterminals & _nonterminals);
    
    /** 
	 * \brief setter
	 */
	void set_terminals(const Terminals & _terminals);
    
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

};



#endif // GRAMMAR
