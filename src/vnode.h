#ifndef VNODE_H_ 
#define VNODE_H_

#include "symbol.h"
#include <vector>

struct VNode;
typedef std::vector<VNode> VNodes;

struct VNode
{
	Symbols tag;
	size_t parent_symbol_pos;
	VNodes children;
};

#endif 
