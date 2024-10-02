#include "dechomskify.h"


	
PNodes Dechomskify::get_children(const PNode & parent)
{
	PNodes res;
	//the node has to have  children due to the breaking process
	//the node has to have exactly 2 children 
	
	//the broken rule ends with both children having symbols not in the added nonnterminals
	//the first child always has such a symbol
	if (grammar.added_nonterminals.contains(parent.children[1].tag))
	{
		res.push_back(parent.children[0]);
		
		PNodes children = get_children(parent.children[1]);
		res.insert(res.end(), children.begin(), children.end());
	}
	else
	{
		res.push_back(parent.children[0]);
		res.push_back(parent.children[1]);
	}
	
	return res;
}

PNode Dechomskify::fix_tree_unbreak(const PNode & root)
{
	PNode res;
	res.tag = root.tag;
	
	PNodes tmp_children;
	
	//if it is not a leaf
	if (root.children.size() != 0)
	{
		//if if it a beginning of a broken rule
		if (root.children.size() == 2 
			&& grammar.added_nonterminals.contains(root.children[1].tag))
		{
			tmp_children = get_children(root);
		}
		else
		{
			tmp_children = root.children;
		}
	}
	
	for (size_t i=0; i<tmp_children.size(); i++)
	{
		res.children.push_back(fix_tree_unbreak(tmp_children[i]));
	}
	
	return res;
}	

void Dechomskify::unbreak_rules()
{
	PTrees res;
	for (size_t i=0; i<result_trees.size(); i++)
	{
		PTree tmp;
		tmp.root = fix_tree_unbreak(result_trees[i].root);
		res.push_back(tmp);
	}
	this->result_trees = res;
}

Dechomskify::Dechomskify(
	const PTrees & input_trees,
	const Chomsky_grammar & _grammar
)
{
	this->result_trees = input_trees;
	this->grammar = _grammar;
	
	unbreak_rules();
}

PTrees Dechomskify::get_result_trees() const
{
	return this->result_trees;
}
