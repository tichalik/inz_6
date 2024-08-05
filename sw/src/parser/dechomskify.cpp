#include "dechomskify.h"


void Dechomskify::unbreak_rules()
{
	
}
void Dechomskify::restore_chains()
{
	
}

Dechomskify::Dechomskify(
	const PTrees & input_trees
)
{
	this->result_trees = input_trees;
	
	restore_chains();
	unbreak_rules();
}

PTrees Dechomskify::get_result_trees() const
{
	return this->result_trees;
}