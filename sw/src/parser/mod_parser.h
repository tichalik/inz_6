#ifndef _MOD_PARSER_H_
#define _MOD_PARSER_H_

#include "parsing_grammar_adapter.h"
#include "ptable.h"
#include "grammar.h"
#include "word.h"
#include "ptree.h"


/** 
 * \brief parses words into parse trees
 */
class Mod_parser
{
	/// table used for parsing
	PTable parsing_table;
	/// object for easier look up of rules
	Parsing_grammar_adapter parsing_grammar_adapter;
	/// result of the parsing module
	PTrees parse_trees;
	
	void propagate_parsing_table();
	void extract_trees_from_parsing_table();
	
	PNode ptable_entry_to_pnode(
		const PTable_reference & address
	);
	
    public:
	
    Mod_parser(
		const Grammar & grammar,
		const Word & input
	);
	
	PTrees get_parse_trees() const;
};

#endif // _MOD_PARSER_H_

