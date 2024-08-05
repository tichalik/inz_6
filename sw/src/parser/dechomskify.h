#ifndef DECHOMSKIFY_H_
#define DECHOMSKIFY_H_

#include "ptree.h"

class Dechomskify
{
	PTrees result_trees;
	
	void unbreak_rules();
	void restore_chains();
	
	public:
	Dechomskify(
		const PTrees & input_trees
	);
	
	PTrees get_result_trees() const;
};

#endif // CHOMSKIFY_H_