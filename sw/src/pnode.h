#ifndef PNODE_H_
#define PNODE_H_

#include <string>
#include <vector>


struct PNode  
{
	std::string tag;
	std::vector<PNode*> children;
	bool visited = false;
};


typedef std::vector<PNode> PNodes;

#endif // PNODE_H_
