#ifndef _MOD_POSTPROCESS_TREES_H_
#define _MOD_POSTPROCESS_TREES_H_

#include "grammar.h"
#include "word.h"
#include "ptree.h"

class Mod_postprocess_trees
{

	size_t get_leaf_size(
		const PNode& node
	);

    public:
	
    Mod_postprocess_trees(
		PTrees & ptrees,
		const Head & head,
		const Word & word
	);
};

#endif // _MOD_POSTPROCESS_TREES_H_

