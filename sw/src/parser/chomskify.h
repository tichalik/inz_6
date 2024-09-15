#ifndef CHOMSKIFY_H_
#define CHOMSKIFY_H_

#include "grammar.h"
#include "error.h"
#include "chomsky_grammar.h"
#include "symbol.h"
#include "utils.h"
#include <unordered_map>

class Chomskify
{
	Errors errors;
	
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
	
	public:
	Chomskify(
		const Grammar& input_grammar
	);
	
	Chomsky_grammar get_grammar() const;
	
	Errors get_errors() const;
};

#endif // CHOMSKIFY_H_