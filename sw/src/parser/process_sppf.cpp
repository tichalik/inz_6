#include "process_sppf.h"


std::vector<std::vector<PNode*>> Process_SPPF::combine2(
	std::vector<std::vector<PNode*>> & list, 
	SPPF_node* sppf_node
)
{
	std::vector<std::vector<PNode*>> results;
	results.reserve(list.size() * sppf_node->pnodes.size());

	for (size_t i=0; i<list.size(); i++)
	{
		for (size_t j=0; j<sppf_node->pnodes.size(); j++)
		{
			results.push_back(list[i]);
			results.back().push_back(&sppf_node->pnodes[j]);
		}
	}

	return results;
}

std::vector<std::vector<PNode*>> Process_SPPF::all_combinations(
	const std::vector<SPPF_node *> & sppf_children
)
{

	std::vector<std::vector<PNode*>> result;

	//first child
	for (size_t i=0; i<sppf_children[0]->pnodes.size(); i++)
	{
		result.emplace_back();
		result.back().push_back(&sppf_children[0]->pnodes[i]);
	}

	for (size_t i=1; i<sppf_children.size(); i++)
	{
		result = this->combine2(result, sppf_children[i]);
	}

	return result;
}

void Process_SPPF::process_sppf(
	SPPF & sppf
)
{ 
	//order sppf nodes -- breadth first search 
	std::list<SPPF_node*> ordered_sppf;
    
	ordered_sppf.insert(ordered_sppf.begin(), sppf.roots.begin(), sppf.roots.end());
	
	for ( std::list<SPPF_node*>::iterator i = ordered_sppf.begin();
		i != ordered_sppf.end(); i++)
	{
		for (std::vector<SPPF_node*> & alt: (*i)->alts)
		{
			for (SPPF_node * node: alt)
			{
				if (node->visited == false)
				{
					ordered_sppf.push_back(node);
					node->visited = true;
				}
			}
		}
	}

	//starting from the leaves, create pnodes for each sppf node

	//for each SPPF_node 
	for ( std::list<SPPF_node*>::reverse_iterator i = ordered_sppf.rbegin();
		i != ordered_sppf.rend(); i++)
	{
		if ((*i)->alts.size() == 0)
		{
			(*i)->pnodes.emplace_back();
			(*i)->pnodes.back().tag = (*i)->tag;
		}
		else
		{
			for (const std::vector<SPPF_node*> & alt: (*i)->alts)
			{
				std::vector<std::vector<PNode*>> children_combinations = 
					all_combinations(alt);
				
				for (size_t j=0; j<children_combinations.size(); j++)
				{
					(*i)->pnodes.emplace_back();
					(*i)->pnodes.back().tag = (*i)->tag;
					(*i)->pnodes.back().children = children_combinations[j];
				}
			}
		}
	}
	
	//insert root's pnodes into sppf.res_pnodes
	for (size_t i=0; i<sppf.roots.size(); i++)
	{
		for (size_t j=0; j<sppf.roots[i]->pnodes.size(); j++)
		{
			sppf.res_pnodes.push_back(&sppf.roots[i]->pnodes[j]);
		}
	}
}
