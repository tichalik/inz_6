#ifndef GRAMMAR
#define GRAMMAR

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

/** \brief representation of grammatical rule X -> Y0 Y1 Y2...
 */

typedef std::string Symbol;

struct Rule
{
    Symbol left;
    Symbol right1, right2;

	std::string to_string();
	std::string to_http();
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

	const std::string RULE_MAP_SEPARATOR = "afqawe23t2tqevq34";
	std::unordered_map<Symbol, std::vector<Symbol>> rule_map;

	public:

	bool has_rule(const Symbol & r1, const Symbol & r2) const;

	std::vector<Symbol> get_rule_head(const Symbol & r1, const Symbol & r2) const;

	/** \brief unified interface for getting nonterminals
     *
     */

    Nonterminals get_nonterminals();

    /** \brief unified interface for getting terminals
     *
     */

    Terminals get_terminals();
	
	/** \brief unified interface for getting head
     *
     */
    Head get_head();

    /** \brief unified interface for getting rules
     *
     */
    Rules get_rules();

    /** \brief unified interface for setting nonterminals
     *
     */
    void set_nonterminals(const Nonterminals & _nonterminals);

    /** \brief unified interface for setting terminals
     *
     */
    void set_terminals(const Terminals & _terminals);

    /** \brief unified interface for setting head
     *
     */
    void set_head(const Head & _head);

    /** \brief unified interface for setting rules
     *
     */
    void set_rules(const Rules & _rules);
	
	void nonterminals_from_http(const std::string & param);
	void terminals_from_http(const std::string & param);
	void head_from_http(const std::string & param);
	void rules_from_http(const std::string & param);
	
	std::string nonterminals_to_http();
	std::string terminals_to_http();
	std::string head_to_http();
	std::string rules_to_http();
	
	std::string to_string();

};



#endif // GRAMMAR
