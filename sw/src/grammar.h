#ifndef GRAMMAR
#define GRAMMAR

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "utils.h"
#include "errorable.h"
#include "symbol.h"
#include "non_terminals.h"
#include "head.h"
#include "rules.h"

/** 
 * \brief grammar in Chomsky's normal form
 */
class Grammar: public Errorable
{
	
	Non_terminals nonterminals;
	Non_terminals terminals;
	Head head;
	Rules rules;

	public:
	
	Grammar() {}
	
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
	
	bool has_errors();
	
	

};



#endif // GRAMMAR
