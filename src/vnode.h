#ifndef VNODE_H_ 
#define VNODE_H_

#include "symbol.h"
#include <vector>

struct VNode;
typedef std::vector<VNode> VNodes;

/// node of the visualization tree
struct VNode
{
	/// the symbol
	Symbols tag;
	/// what the symbol transforms into 
	VNodes children;
};

#endif 
