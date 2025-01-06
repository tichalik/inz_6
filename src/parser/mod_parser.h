#ifndef _MOD_PARSER_H_
#define _MOD_PARSER_H_

#include "grammar.h"
#include "error.h"
#include "word.h"
#include "sppf.h"
#include <list>

/// parser state, according to the Earley algorithm
struct State
{
	/// LHS of processed rule
	Symbol LHS;
	/// RHS of processed rule
	Symbols RHS;
	/// separator between processed and unprocessed symbols in RHS;
	/// 0 means no symbols have been processed
	/// RHS.size() means all symbols have been processed
	size_t pos;
	/// state where processing this rule started
	size_t origin;
	/// contains parse trees
	SPPF_node* sppf_node = nullptr;
};

/** 
 * \brief parses words into parse trees using the Earley algorithm
 */
class Mod_parser
{
	/// sets of parserstates of the Earley algorithm
	std::vector<std::list<State> > states;

	/// reference for storing the results of parsing
	SPPF& sppf;
	/// reference for consulting grammar rules 
	const Grammar& grammar;

	/// method predict of the earley algorithm
	void predict(const State & state, size_t i);	
	/// method scan of the earley algorithm
	void scan(const State & state, size_t i);	
	/// method complete of the earley algorithm
	void complete(State & state, size_t i);	

	/// helper method -- whether i'th state set contains given state
	/// if yes, return its iterator, if no, returns end()
	std::list<State>::iterator find_in_set(const State & state, size_t i) ;


    public:
	
	/// constructor -- provide all necessary data
    Mod_parser(
		const Grammar & grammar,
		const Word & input,
		SPPF & _sppf
	);
};

#endif // _MOD_PARSER_H_

