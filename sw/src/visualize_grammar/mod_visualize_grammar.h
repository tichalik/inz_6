#ifndef MOD_VISUALIZE_GRAMMAR_H_
#define MOD_VISUALIZE_GRAMMAR_H_

#include "vnode.h"
#include "grammar.h"

class Mod_visualize_grammar
{
	
	void append_children(
		VNode & root,
		const Rules & rules,
		const std::vector<bool> & was_used
	);
	
public:

	VNode visualize_grammar(
		const Grammar & grammar
	);

};
#endif 
