#ifndef _PARSER_H_
#define _PARSER_H_

#include <vector>
#include <string>
#include <map>

#include "grammar.h"
#include "parser.h"
#include "word.h"


struct PNode
{
    Symbol tag;
    //cant have normal, non-pointer value cause it will make endless loops
    //we assume it can have either 0 or 2 children
    std::vector<PNode> children;

    std::string toString() const
    {
        if (children.size() == 0 )
            return tag;
        else
            return tag + "[" + children[0].toString() + " " + children[1].toString() + "]";
    }
};

struct PTree
{
    PNode root;

    std::string toString() const
    {
        return root.toString();
    }
};

typedef std::vector<PTree> PTrees;

typedef std::vector<PNode> PNodes;


class Parser
{
    public:

    PTrees parse(const Word & input, const Grammar & g);

};

#endif // _PARSER_H_

