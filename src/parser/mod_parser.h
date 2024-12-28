#ifndef _MOD_PARSER_H_
#define _MOD_PARSER_H_

#include "grammar.h"
#include "error.h"
#include "word.h"
#include "sppf.h"
#include <list>

struct State
{
	Symbol LHS;
	Symbols RHS;
	size_t pos;
	size_t origin;
	SPPF_node* sppf_node = nullptr;
};

/** 
 * \brief parses words into parse trees
 */
class Mod_parser
{
	
	std::vector<std::list<State> > states;

	SPPF& sppf;
	const Grammar& grammar;

	void predict(const State & state, size_t i);	
	void scan(const State & state, size_t i);	
	void complete(State & state, size_t i);	

	std::list<State>::iterator find_in_set(const State & state, size_t i) ;


    public:
	
    Mod_parser(
		const Grammar & grammar,
		const Word & input,
		SPPF & _sppf
	);
};

#endif // _MOD_PARSER_H_

