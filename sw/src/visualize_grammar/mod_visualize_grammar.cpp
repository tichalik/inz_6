#include "mod_visualize_grammar.h"

void append_children(
	VNode & root,
	const Rules & rules,
	const std::vector<bool> & was_used
)
{
	for (size_t i=0; i<root.tag.size(); i++)
	{
		for (size_t j=0; j<rules.size(); j++)
		{
			if (was_used[j] == false &&
				root.tag[i] == rules[j].LHS)
			{
				
				VNode child;
				//copy all items before the i'th
				//this shoudl be done by insert
				for (size_t k=0; k<i; k++)
				{
					child.tag.push_back(root.tag[k]);
				}

				//copy RHS of the matched rule
				for (size_t k=0; k<rules[j].RHS.size(); k++)
				{
					child.tag.push_back(rules[j].RHS[k]);
				}

				//copy rest of parent's tag
				for (size_t k=i+1; k<root.tag.size(); k++)
				{
					child.tag.push_back(root.tag[k]);
				}

				child.parent_symbol_pos = i;

				std::vector<bool> was_used_copy(was_used);
				was_used_copy[j] = true;

				append_children(
					child,
					rules,
					was_used_copy
				);

				root.children.push_back(child);
			}
		}
	}
}

VNode Visualize_grammar(
	const Grammar & grammar
)
{
	VNode res;
	res.tag.push_back(grammar.head);

	std::vector was_used(grammar.rules.size(), false);

	append_children(
		res,
		grammar.rules,
		was_used
	);

	return res;

}


