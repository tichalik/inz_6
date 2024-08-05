#ifndef CHOMSKIFY_H_
#define CHOMSKIFY_H_

#include "grammar.h"
#include "chomsky_grammar.h"
#include "symbol.h"
#include "utils.h"



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
	
	public:
	Chomskify(
		const Grammar& input_grammar
	);
	
	Chomsky_grammar get_grammar();
};

#endif // CHOMSKIFY_H_