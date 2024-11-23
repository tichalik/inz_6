#ifndef _MOD_PARSER_H_
#define _MOD_PARSER_H_

#include "parsing_grammar_adapter.h"
#include "grammar.h"
#include "error.h"
#include "word.h"
#include "sppf.h"
#include "pnode.h"
#include <list>

struct State
{
	Rule rule;
	size_t pos;
	size_t origin;
	SPPF_node* sppf_node = nullptr;
};

/** 
 * \brief parses words into parse trees
 */
class Mod_parser
{
	
	/// object for easier look up of rules
	Parsing_grammar_adapter parsing_grammar_adapter;

	std::vector<std::list<State> > states;

	SPPF& sppf;

	void predict(const State & state, size_t i);	
	void scan(const State & state, size_t i);	
	void complete(State & state, size_t i);	

	std::list<State>::iterator find_in_set(const State & state, size_t i) ;

	void process_sppf();

	std::vector<std::vector<PNode*>> combine2(
		std::vector<std::vector<PNode*>> & list, 
		SPPF_node* sppf_node
	);

	std::vector<std::vector<PNode*>> all_combinations(
		const std::vector<SPPF_node *> & sppf_children
	);

    public:
	
    Mod_parser(
		const Grammar & grammar,
		const Word & input,
		SPPF & _sppf
	);
};

#endif // _MOD_PARSER_H_

