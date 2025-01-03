#ifndef _SPPF_H_
#define _SPPF_H_

#include <vector>
#include <list>
#include "rules.h"

/**
 * \brief single SPPF node 
 * 
 * if both these rules are fulfilled:
 \verbatim
	<A> ::= <B> <C> | <B> <D>
 \endverbatim
 * then the SPPF looks like this:
 \verbatim
	SPPF_node B = {"<B>", {...}, ... };
	SPPF_node C = {"<C>", {...}, ... };
	SPPF_node D = {"<D>", {...}, ... };
	
	SPPF_node A = {"<A>", {{&B, &C},{&B, &D}, ... };
 \endverbatim
*/
struct SPPF_node
{ 
	/// tag of the node (LHS of the rule)
	Symbol tag;
	///alternative children of the node 
	std::vector<std::vector<SPPF_node*> > alts;
	
	/// used for iteration
	int last_alt = 0;
	/// used for iteration
	bool visited = false;
};

/**
 * \brief Shared Packed Parse Forest
 * 
 * Structure for storing parsed results. Nodes are linked as pointers, 
 * so when trees share subtrees, only one subtree is stored. 
 * Keep in mind, that a parsing containing ambiguity at the head of the grammar
 * will be represented as multiple trees. 
 *
 * Iterates over complete parsing trees.
 * When iterating, do:
 \verbatim
	start_iteration()
	do  // iterate alternative trees
	{
		do // iterate single tree
		{
			...
		}while (sppf.next_node() != SPPF::EN_ITERATION_MOVE::END)
	} while (sppf.next_tree() == true);
	
 \endverbatim
 The first time access to current_node needs to be checked if it is not nullptr. 
 This happens, when there are no roots.
*/
class SPPF
{
	/// for single tree iteration -- path from root to the current node
	std::list<SPPF_node*> parents;
	/// for single tree iteration -- choices of children on the path 
	/// from root to the current node
	std::list<int> used_children;
	
	/// for SPPF iteration -- nodes (without leaves) visited during interation
	std::list<SPPF_node*> path;

	/// whether previous iteration move was EN_ITERATION_MOVE::UP
	bool was_up;
	/// whether previous iteration move was EN_ITERATION_MOVE::DOWN_AND_LOOP
	bool was_loop;
	/// index of the sppf tree which is currently iterated.
	size_t current_root = 0;

	/// prepare for iteration of a single tree
	void start_tree();
public:
	/// terminals of the given word
	std::vector<SPPF_node> leaves;	
	/// container for all nodes except leaves
	std::list<SPPF_node> nodes;	
	/// pointers to nodes which form roots of the parse trees
	std::vector<SPPF_node*> roots;	
	
	// the class cannot be copied -- too much work with managing the pointers,
	// therefore deleting the copy constructors
	SPPF( const SPPF&) = delete;
	SPPF& operator=(const SPPF&) = delete;

	/// default constuctor still needs to be defined
	SPPF() = default;

	/// kind of move made during single tree iteration
	enum class EN_ITERATION_MOVE
	{
		/// reached end of iteration
		END,
		/// moved from child to parent
		UP,
		/// moved from parent to a new child 
		DOWN,
		/// moved from parent to a previously-visited child
		DOWN_AND_LOOP
	};

	/// return current node 
	SPPF_node* current_node();
	/// advance in single tree iteration
	EN_ITERATION_MOVE next_node();
	/// advance in SPPF iteration
	bool next_tree();
	/// helper method -- if the node is a leaf
	bool is_leaf(SPPF_node* node);
	/// mark end of SPPF construction, start iteration
	void start_iteration();	
};

#endif
