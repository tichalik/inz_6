#include "ptree.h"



std::string PNode::toString() const
{
	if (children.size() == 0 )
		return tag;
	else
		return tag + "[" + children[0].toString() + " " + children[1].toString() + "]";
}

std::string PTree::toString() const
{
	return root.toString();
}

// typedef std::vector<PTree> PTrees;


std::string PTrees::to_string()
{
	
}

std::string PTrees::to_http()
{
	
}

