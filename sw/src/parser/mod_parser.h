#ifndef _MOD_PARSER_H_
#define _MOD_PARSER_H_

#include "grammar.h"
#include "error.h"
#include "word.h"
#include "sppf.h"
#include <set>

struct State
{
	Symbol LHS;
	Symbols RHS;
	size_t pos;
	size_t origin;
	SPPF_node* sppf_node = nullptr;
	size_t pos_in_set = -1;
};

bool state_compare(
	const State& s1,
	const State& s2
);

typedef bool(*State_compare)(const State&, const State&);
typedef std::set<State, State_compare> State_set;

/** 
 * \brief parses words into parse trees
 */
class Mod_parser
{
	
	std::vector<State_set > states;

	SPPF& sppf;
	const Grammar& grammar;

	void predict(const State & state, size_t i);	
	void scan(const State & state, size_t i);	
	void complete(const State & state, size_t i);	

	std::list<State>::iterator find_in_set(const State & state, size_t i) ;


    public:
	
    Mod_parser(
		const Grammar & grammar,
		const Word & input,
		SPPF & _sppf
	);
};

#endif // _MOD_PARSER_H_

