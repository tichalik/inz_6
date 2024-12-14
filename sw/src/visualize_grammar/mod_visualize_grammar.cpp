#include "mod_visualize_grammar.h"

void Mod_visualize_grammar::simple_append_children(
	VNode & root,
	const Rules & rules,
	std::map<Symbol, std::vector<bool>> & was_used
)
{
	for (size_t i=0; i<root.tag.size(); i++)
	{
		const std::vector<Symbols> & RHS = rules.at(root.tag[i]);
		for (size_t j=0; j<RHS.size(); j++)
		{
			if (was_used[root.tag[i]][j] == false ) 
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
					RHS[j].cbegin(), 
					RHS[j].cend()
				);

				//copy rest of parent's tag
				child.tag.insert(
					child.tag.end(),
					root.tag.begin() + i + 1,
					root.tag.end()
				);

				child.parent_symbol_pos = i;

				was_used[root.tag[i]][j] = true;

				simple_append_children(
					child,
					rules,
					was_used
				);
			}
		}
	}
}


void Mod_visualize_grammar::append_children(
	VNode & root,
	const Rules & rules,
	const std::map<Symbol, std::vector<bool>> & was_used
)
{
	for (size_t i=0; i<root.tag.size(); i++)
	{
		const std::vector<Symbols> & RHS = rules.at(root.tag[i]);
		for (size_t j=0; j<RHS.size(); j++)
		{
			if (was_used.at(root.tag[i])[j] == false ) 
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
					RHS[j].cbegin(), 
					RHS[j].cend()
				);

				//copy rest of parent's tag
				child.tag.insert(
					child.tag.end(),
					root.tag.begin() + i + 1,
					root.tag.end()
				);

				child.parent_symbol_pos = i;

				std::map<Symbol, std::vector<bool>> was_used_copy(was_used);
				was_used_copy[root.tag[i]][j] = true;

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
	const Grammar & grammar,
	const bool simple
)
{
	VNode res;
	res.tag.push_back(grammar.head);

	std::map<Symbol, std::vector<bool>> was_used;
	for (auto i=grammar.rules.cbegin(); i != grammar.rules.cend(); i++)
	{
		was_used[i->first] = std::vector<bool>(i->second.size(), false);
	}

	if (simple)
	{
		simple_append_children(
			res,
			grammar.rules,
			was_used
		);
	}
	else
	{
		append_children(
			res,
			grammar.rules,
			was_used
		);
	}
	
	return res;

}


