#ifndef CHOMSKIFY_H_
#define CHOMSKIFY_H_

#include "grammar.h"
#include "chomsky_grammar.h"
#include "symbol.h"
#include "utils.h"
#include <unordered_map>


struct Chain_node
{
	Symbols symbols;
	bool exit = false;
};

typedef std::unordered_map<Symbol, Chain_node> Chain_trees;

struct Replaced_symbols
{
	Symbol result;
	Symbols chain;
	Cycle_warnings cycle_warnings;
};
typedef std::vector<Replaced_symbols> Replaced_symbolss;


class Chomskify
{
	int next_new_symbol;
	Chomsky_grammar res_grammar;
	Symbol create_new_symbol();
	
	/**
	 * \brief converts normal Grammar into Chomsky_grammar without changing anything
	 */
	Chomsky_grammar init_res_grammar(
		const Grammar& input_grammar
	) const;
	
	void break_rules();
	void remove_chains();
	
		

	std::vector<Symbols> get_path(
		Symbol head, 
		Symbols current_path,
		Chain_trees chain_trees
	);

	Chomsky_rules replace_chain_in_rule(
		const Chomsky_rule& rule,
		const size_t& RHS_pos,
		Chain_trees chain_trees
	);

	
	public:
	Chomskify(
		const Grammar& input_grammar
	);
	
	Chomsky_grammar get_grammar();
};

#endif // CHOMSKIFY_H_