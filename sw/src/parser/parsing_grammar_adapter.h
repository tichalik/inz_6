#ifndef PARSING_GRAMMAR_ADAPTER_H_
#define PARSING_GRAMMAR_ADAPTER_H_

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

#include "chomsky_grammar.h"
#include "utils.h"

struct LHS_and_ID
{
	std::string LHS;
	size_t ID;
};


/** \brief represents how the grammar is seen during the parsing
 *
*/
class Parsing_grammar_adapter
{

	/** \brief representation of rules in easy-to-access form 
	 * 
	 * rules are in form 
	 *	0. LHS1 -> RSH1 RHS2 
	 *	1. LHS2 -> RSH1 RHS2 
	 *	2. LHS1 -> RSH3 RHS4
	 *
	 * the map is in form 
	 *	rule_map[RHS1 RULE_MAP_SEPARATOR RHS2] = { [LHS1,0], [LHS2,1]}
	 *	rule_map[RHS3 RULE_MAP_SEPARATOR RHS4] = { [LHS1,0]}
	*/
	std::unordered_map<std::string, std::vector<LHS_and_ID>> rule_map;

	/** \brief unique string used to form keys for the rule_map
	 * 
	 * an arrow is not allowed in the symbol set, therefore it is used 
	*/
	const std::string RULE_MAP_SEPARATOR = " -> ";
	
	public:
	
	/** \brief constructor
	 * 
	 * \param grammar the grammar this object is supposed to be a representation of
	*/
	Parsing_grammar_adapter( const Chomsky_grammar & grammar);

	/** \brief whether grammar has a rule with given RHS
	 *
	 * \returns true if a rule is present, false otherwise
	 * \param r1 1st symbol of rule's RHS
	 * \param r2 2nd symbol of rule's RHS 
	*/
	bool has_rule(const Symbol & r1, const Symbol & r2) const;
	
	/** \brief get all LHS that turn into given LHS
	 *
	 * \returns all LHS that turn into given LHS
	 * \param r1 1st symbol of rule's RHS
	 * \param r2 2nd symbol of rule's RHS 
	*/
	std::vector<LHS_and_ID> get_rule_head(const Symbol & r1, const Symbol & r2) const;
	

};

#endif //PARSING_GRAMMAR_ADAPTER_H_