#ifndef _MOD_PARSER_H_
#define _MOD_PARSER_H_

#include "parsing_grammar_adapter.h"
#include "grammar.h"
#include "error.h"
#include "word.h"
#include "ptree.h"

struct SPPF
{
	Symbol tag;
	std::vector<std::vector<SPPF*> > alts;
};

struct State
{
	Rule rule;
	size_t pos;
	size_t origin;
	SPPF sppf;
};

/** 
 * \brief parses words into parse trees
 */
class Mod_parser
{
	
	/// object for easier look up of rules
	Parsing_grammar_adapter parsing_grammar_adapter;
	/// result of the parsing module
	PTrees parse_trees;

	std::vector<std::vector<State> > states;
	std::vector<SPPF> leaves;

	std::vector<SPPF*> res;

	void predict(const State & state, size_t i);	
	void scan(const State & state, size_t i);	
	void complete(State & state, size_t i);	

	size_t find_in_set(const State & state, size_t i) const;

    public:
	
    Mod_parser(
		const Grammar & grammar,
		const Word & input
	);
	
	PTrees get_parse_trees() const;
	
};

#endif // _MOD_PARSER_H_

