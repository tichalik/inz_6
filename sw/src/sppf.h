#ifndef _SPPF_H_
#define _SPPF_H_

#include <vector>
#include <list>
#include "rules.h"

struct SPPF_node
{ 
	Symbol tag;
	std::vector<std::vector<SPPF_node*> > alts;
};

struct SPPF
{
	std::vector<SPPF_node> leaves;	
	std::list<SPPF_node> nodes;	
	std::vector<SPPF_node*> roots;	
};

#endif
