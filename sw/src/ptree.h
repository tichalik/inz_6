#ifndef PTREE_H
#define PTREE_H

#include <string>
#include <vector>
#include "word.h"
#include "grammar.h"


/** 
 * \brief node in a parsing tree
 */
struct PNode
{    
	/** 
	 * \brief the terminal/nonterminal at the parsing tree
	 */
	std::string tag;
	
	size_t rule_id = -1;
 
    /** 
	 * \brief child nodes
	 *
	 * cant have normal, non-pointer value cause it will make endless loops
     * we assume it can have either 0 or 2 children
	 */
	std::vector<PNode> children;
};


/** 
 * \brief parsing tree as a whole
 */
struct PTree
{
	/** 
	 * \brief root of the parsing tree
	 */
    PNode root;
};

typedef std::vector<PTree> PTrees;

typedef std::vector<PNode> PNodes;

#endif // PTREE_H