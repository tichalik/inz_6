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

PNode Dechomskify::stretch_tree(
	const PNode & root,
	const Symbols & symbols_to_add
)
{
	PNode res;
	res.tag = symbols_to_add[0];
	PNode*  p_latest = &res;
	
	for (size_t i=1; i<symbols_to_add.size(); i++)
	{
		PNode new_node;
		new_node.tag = symbols_to_add[i];
		p_latest->children.push_back(new_node);

		p_latest = & p_latest->children[0];
	}

	p_latest->children.push_back(root);

	return res;
}

PNodes Dechomskify::fix_tree_add_chains(
	const PNode & root
)
{
	PNodes res;

	//if this is not a leaf
	if (root.children.size() != 0)
	{	
		Chomsky_rule rule = grammar.rules[root.rule_id];
		//if there is something to replace
 		if ( rule.replaced_symbols_indexes.size() != 0 )
			{
			//this number is ensured because the input comes from the parser
			const size_t NO_CHILDREN = 2;

			//fix the direct chilren 
			PNodes new_children[NO_CHILDREN];
			
			for(size_t i=0; i<rule.replaced_symbols_indexes.size(); i++)
			{
				size_t rhs_pos = rule.replaced_symbols_indexes[i].RHS_pos;

				new_children[rhs_pos].push_back(
					stretch_tree( 
						root.children[rhs_pos], 
						rule.replaced_symbols_indexes[i].symbols));
						
			}

			for (size_t i=0; i<NO_CHILDREN; i++)
			{
				//if this child needed no replacements, move it to the 
				//  new children
				if (new_children[i].size() == 0)
				{
					new_children[i].push_back(root.children[i]);
				}
				

				//fix the further parts of the trees 
				PNodes new_new_children;
				for (size_t j=0; j<new_children[i].size(); j++)
				{
					PNodes tmp = fix_tree_add_chains(new_children[i][j]);
					new_new_children.insert(
						new_new_children.end(), tmp.begin(), tmp.end());
				}
				new_children[i] = new_new_children;


			}

			//generate combinations of new children 
			for (size_t i=0; i < new_children[0].size(); i++)
			{
				for (size_t j=0; j < new_children[1].size(); j++)
				{
					PNode node;
					node.tag = root.tag;
					node.children.push_back(new_children[0][i]);
					node.children.push_back(new_children[1][j]);
					res.push_back(node);
				}
			}
		}

	}
	else 
	{
		res.push_back(root);
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

void Dechomskify::restore_chains()
{
	PTrees res;
	for (size_t i=0; i<result_trees.size(); i++)
	{
		PNodes tmp = fix_tree_add_chains(result_trees[i].root);
		for (size_t j=0; j<tmp.size(); j++)
		{
			PTree tree;
			tree.root = tmp[j];
			res.push_back(tree);
		}
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
	
	restore_chains();
	unbreak_rules();
}

PTrees Dechomskify::get_result_trees() const
{
	return this->result_trees;
}
