#ifndef GRAMMAR
#define GRAMMAR

#include <string>
#include <vector>
#include <unordered_map>

/** \brief representation of grammatical rule X -> Y0 Y1 Y2...
 */

typedef std::string Symbol;

struct Rule
{
    Symbol left;
    Symbol right1, right2;

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
	std::unordered_map<Symbol, Symbol> rule_map;

	public:

	bool has_rule(const Symbol & r1, const Symbol & r2) const
	{
		std::string key = r1 + RULE_MAP_SEPARATOR + r2;
		if ( rule_map.find(key) == rule_map.end())
			return false;
		else
			return true;
	}

	Symbol get_rule_head(const Symbol & r1, const Symbol & r2) const
	{
		std::string key = r1 + RULE_MAP_SEPARATOR + r2;
		return rule_map.at(key);
	}

	/** \brief unified interface for getting nonterminals
     *
     */

    Nonterminals get_nonterminals() {return nonterminals;}

    /** \brief unified interface for getting terminals
     *
     */

    Terminals get_terminals() {return terminals;}

    /** \brief unified interface for getting head
     *
     */
    Head get_head() {return head;}

    /** \brief unified interface for getting rules
     *
     */
    Rules get_rules() {return rules;}

    /** \brief unified interface for setting nonterminals
     *
     */
    void set_nonterminals(const Nonterminals & _nonterminals)
	{
		nonterminals = _nonterminals;
	}

    /** \brief unified interface for setting terminals
     *
     */
    void set_terminals(const Terminals & _terminals)
	{
		terminals = _terminals;
	}

    /** \brief unified interface for setting head
     *
     */
    void set_head(const Head & _head)
	{
		head = _head;
	}

    /** \brief unified interface for setting rules
     *
     */
    void set_rules(const Rules & _rules)
	{
		rules = _rules;
		
		for (int i=0; i<rules.size(); i++)
		{
			std::string key = rules[i].right1 + RULE_MAP_SEPARATOR + rules[i].right2;
			rule_map[key] = rules[i].left;
		}
	}

};



#endif // GRAMMAR
