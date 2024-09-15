#ifndef DECHOMSKIFY_H_
#define DECHOMSKIFY_H_

#include "ptree.h"
#include "chomsky_grammar.h"

class Dechomskify
{
	PTrees result_trees;
	Chomsky_grammar grammar;
	
	void unbreak_rules();
	
	PNodes get_children(const PNode & parent);
	PNode fix_tree_unbreak(const PNode & root);

	public:
	Dechomskify(
		const PTrees & input_trees,
		const Chomsky_grammar & _grammar
	);
	
	PTrees get_result_trees() const;
};

#endif // CHOMSKIFY_H_
