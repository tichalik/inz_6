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
	Symbol get_new_symbol();
	
	public:
	Chomskify(
		const Grammar& input_grammar
	);
	
	Chomsky_grammar get_grammar();
};

#endif // CHOMSKIFY_H_