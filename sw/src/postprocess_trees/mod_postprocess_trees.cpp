#include "mod_postprocess_trees.h"

size_t Mod_postprocess_trees::get_leaf_size(
	const PNode& node
)
{
	size_t res;
	if (node.children.size() == 0)
	{
		res = 1;
	}
	else
	{
		for (size_t i=0; i<node.children.size(); i++)
		{
			res += get_leaf_size(node.children[i]);
		}
	}
	return res;
}


Mod_postprocess_trees::Mod_postprocess_trees(
	PTrees & ptrees,
	const Head & head,
	const Word & word
)
{
	size_t wsize = word.size();
	for (size_t i=0; i<ptrees.size(); i++)
	{
		ptrees[i].is_head_ok = ptrees[i].root.tag == head;
		ptrees[i].is_complete = get_leaf_size(ptrees[i].root) == wsize;
	}
}

