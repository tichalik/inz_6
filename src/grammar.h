#ifndef GRAMMAR
#define GRAMMAR

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "utils.h"

/** 
 * \brief representation of grammatical rule X -> Y0 Y1 Y2...
 */

typedef std::string Symbol;

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


class Grammar
{
	Nonterminals nonterminals;
	Terminals terminals;
	Head head;
	Rules rules;

	public:
	
	
    Nonterminals get_nonterminals() const;
    Terminals get_terminals() const;
    Head get_head() const;
    Rules get_rules() const;

    void set_nonterminals(const Nonterminals & _nonterminals);
    void set_terminals(const Terminals & _terminals);
    void set_head(const Head & _head);
    void set_rules(const Rules & _rules);
	
	std::string to_string();

};



#endif // GRAMMAR
