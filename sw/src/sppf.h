#ifndef _SPPF_H_
#define _SPPF_H_

#include <vector>
#include <list>
#include "rules.h"
#include "pnode.h"

struct SPPF_node
{ 
	Symbol tag;
	std::vector<std::vector<SPPF_node*> > alts;
	PNodes pnodes;
};

struct SPPF
{
	std::vector<SPPF_node> leaves;	
	std::list<SPPF_node> nodes;	
	std::vector<SPPF_node*> roots;	
	
	//if the class is copied, shit will ensure with pointers
	//therefore deleting the copy constructors
	SPPF( const SPPF&) = delete;
	SPPF& operator=(const SPPF&) = delete;

	//apparently default constuctor still needs to be defined
	SPPF() = default;
};

#endif
