#ifndef PARSING_GRAMMAR_ADAPTER_H_
#define PARSING_GRAMMAR_ADAPTER_H_

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

#include "utils.h"
#include "grammar.h"

/** \brief represents how the grammar is seen during the parsing
 *
*/
class Parsing_grammar_adapter
{

	/** \brief representation of rules  LHS -> [[RHS1.1, RHS1.2...], [RHS2.1, RHS2.2...], ...]
	 * 
	*/
	std::unordered_map<std::string, std::vector<Symbols> > rule_map;

	
	public:
	
	Parsing_grammar_adapter( const Grammar & grammar);

	std::vector<Symbols> get_RHS(const Symbol & LHS) const;
	

};

#endif //PARSING_GRAMMAR_ADAPTER_H_
