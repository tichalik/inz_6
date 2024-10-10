#ifndef MOD_VISUALIZE_GRAMMAR_H_
#define MOD_VISUALIZE_GRAMMAR_H_

#include "vnode.h"
#include "grammar.h"

void append_children(
	VNode & root,
	const Rules & rules,
	const std::vector<bool> & was_used
);

VNode Visualize_grammar(
	const Grammar & grammar
);

#endif 
