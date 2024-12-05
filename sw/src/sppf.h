#ifndef _SPPF_H_
#define _SPPF_H_

#include <vector>
#include <list>
#include "rules.h"

struct SPPF_node
{ 
	Symbol tag;
	std::vector<std::vector<SPPF_node*> > alts;
	int last_alt = 0;
};

class SPPF
{
	
	std::list<SPPF_node*> parents;
	std::list<SPPF_node*> path;
	std::list<int> used_children;

	bool was_up;

	void start_tree();
public:
	std::vector<SPPF_node> leaves;	
	std::list<SPPF_node> nodes;	
	std::vector<SPPF_node*> roots;	
	
	//if the class is copied, shit will ensure with pointers
	//therefore deleting the copy constructors
	SPPF( const SPPF&) = delete;
	SPPF& operator=(const SPPF&) = delete;

	//apparently default constuctor still needs to be defined
	SPPF() = default;

	enum class EN_ITERATION_MOVE
	{
		END,
		UP,
		DOWN
	};

	SPPF_node* current_node();
	EN_ITERATION_MOVE next_node();
	bool next_tree();
	bool is_leaf(SPPF_node* node);
	void start_iteration();	
};

#endif
