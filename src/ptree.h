#ifndef PTREE_H
#define PTREE_H

#include <string>
#include <vector>
#include "word.h"
#include "grammar.h"


struct PNode
{
    Symbol tag;
    //cant have normal, non-pointer value cause it will make endless loops
    //we assume it can have either 0 or 2 children
    std::vector<PNode> children;

    std::string toString() const;
};

struct PTree
{
    PNode root;

    std::string toString() const;
};

// typedef std::vector<PTree> PTrees;


class PTrees: public std::vector<PTree>
{
public:
	std::string to_string();
	
	// Word(std::initializer_list<std::string> il);	
	
	std::string to_http();

};

typedef std::vector<PNode> PNodes;

#endif // PTREE_H