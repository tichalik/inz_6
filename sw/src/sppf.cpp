#include "sppf.h"
bool SPPF::next_tree()
{
	bool updated = false;
	while(path.size() != 0 && !updated)
	{
		if (path.back()->last_alt < path.back()->alts.size())
		{
			path.back()->last_alt++;
			updated = true;
		}
		else
		{
			path.back()->last_alt = 0;
			path.pop_back();
		}
	}

	path.clear();

	return updated;
}

bool SPPF::is_leaf(SPPF_node* node)
{
	return node->alts.size() == 0;
}

void SPPF::start_iteration()
{
	if (this->roots.size()!=0)
	{
		parents.push_back(this->roots[0]);
		used_children.push_back(-1);
	}
}

SPPF::EN_ITERATION_MOVE SPPF::next_node()
{
	EN_ITERATION_MOVE res;

	if (parents.size() != 0)
	{

		if (
			//if the node is not a leaf 
			!is_leaf(parents.back()) &&
			// and there are still unprocessed children of that node
			(used_children.back() ) < 
				(int) (parents.back()->alts[parents.back()->last_alt].size() -1) 
		)
		{ 
			path.push_back(parents.back());

			used_children.back() ++;

			parents.push_back(parents.back()
				->alts[parents.back()->last_alt][used_children.back()]);
			
			used_children.push_back(-1);
			
			res = EN_ITERATION_MOVE::DOWN;
		}
		else
		{
			used_children.pop_back();
			parents.pop_back();
			
			res = EN_ITERATION_MOVE::UP;
		}

 	}

	if (parents.size() == 0)
	{
		res = EN_ITERATION_MOVE::END;
	}

	return res;
}

SPPF_node* SPPF::current_node()
{
	if (parents.size() != 0)
		return parents.back();
	else
		return nullptr;
}

