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
 
    /** 
	 * \brief child nodes
	 *
	 * cant have normal, non-pointer value cause it will make endless loops
     * we assume it can have either 0 or 2 children
	 */
	std::vector<PNode> children;

	
    /** 
	 * \brief get string representation in form 
	 *		tag [ child1.to_string() child2.to_string() ]
	 */
    std::string to_string() const;
    
	
    /** 
	 * \brief get string representation in form 
	 *		tag <div class="expandable"> child1.to_http() <BR> child2.to_http() </div>
	 */
	std::string to_http() const;
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
	
	/** 
	 * \brief get string representation in form 
	 *		root.to_string()
	 */
    std::string to_string() const;
	
    /** 
	 * \brief get string representation in form 
	 *		<div class="tree"> root.to_http() </div>
	 */
	std::string to_http() const;
};

// typedef std::vector<PTree> PTrees;



/** 
 * \brief represents a conplete (successful) parse output
 */
class PTrees: public std::vector<PTree>
{
public:

	/** 
	 * \brief get string representation in form 
	 *		tree1.to_string()\n
	 *		tree2.to_string()\n
	 *		tree3.to_string()
	 */
    std::string to_string() const;
	
    /** 
	 * \brief get string representation in form
	 *		tree1.to_http()\n
	 *		tree2.to_http()\n
	 *		tree3.to_http()
	 */
	std::string to_http() const;

};

typedef std::vector<PNode> PNodes;

#endif // PTREE_H