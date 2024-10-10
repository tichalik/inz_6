#include "mod_visualize_grammar.h"

void Mod_visualize_grammar::append_children(
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
				
				root.children.emplace_back();
				VNode & child = root.children.back();
				
				//copy all items before the i'th
				child.tag.insert(
					child.tag.end(),
					root.tag.begin(), 
					root.tag.begin() + i
				);

				//copy RHS of the matched rule
				child.tag.insert(
					child.tag.end(),
					rules[j].RHS.begin(), 
					rules[j].RHS.end()
				);

				//copy rest of parent's tag
				child.tag.insert(
					child.tag.end(),
					root.tag.begin() + i + 1,
					root.tag.end()
				);

				child.parent_symbol_pos = i;

				std::vector<bool> was_used_copy(was_used);
				was_used_copy[j] = true;

				append_children(
					child,
					rules,
					was_used_copy
				);
			}
		}
	}
}

VNode Mod_visualize_grammar::visualize_grammar(
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


