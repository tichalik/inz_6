#ifndef TST_MOD_POSTPROCESS_TREES
#define TST_MOD_POSTPROCESS_TREES

#include "mod_postprocess_trees.h"
#include "tester.h"

class TST_mod_postprocess_trees
{ 
	PTrees trees1; //A[b c]	
	PTrees trees2; //A[b]
	PTrees trees3; //A[B C D E]
	PTrees trees4; //A[B[E F G] C D]
	
	void _test_get_leaf_size(
		const PNode & node,
		const size_t expected
	);

	void _test_postprocess_trees(
		const PTrees& input,
		const Head& head, 
		const Word& word,
		const PTrees& expected
	);
public:
	void test_get_leaf_size();
	void test_postprocess_trees();
	
	TST_mod_postprocess_trees();
};

#endif
