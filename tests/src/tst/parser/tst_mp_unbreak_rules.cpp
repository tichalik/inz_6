#include "tst_mod_parser.h"

void TST_mod_parser::_test_unbreak_rules(
	const PTrees & input_trees,
	const Chomsky_grammar& grammar,
	const PTrees & expected_ptrees
)
{
	PTrees dummy;
	Dechomskify dechomskify(
		dummy,
		grammar
	);
	
	dechomskify.result_trees = input_trees;
	dechomskify.unbreak_rules();
	
	
	bool ok = compare(expected_ptrees, dechomskify.get_result_trees(), "trees");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
}

void TST_mod_parser::test_unbreak_rules()
{
	//we actually only care about the added nonterminals fields of a Chomsky_grammar
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " normal node A[b c] " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		
		
		PTree expected_ptree;
		
		{
			PNode pnode;
			pnode.tag = "b";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode pnode;
			pnode.tag = "c";
			expected_ptree.root.children.push_back(pnode);
		}
		
		PTrees expected_ptrees;
		expected_ptrees.push_back(expected_ptree);
		
		PTrees input_trees = expected_ptrees;
		
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " normal node A[b] " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		
		
		PTree expected_ptree;
		
		{
			PNode pnode;
			pnode.tag = "b";
			expected_ptree.root.children.push_back(pnode);
		}
		
		PTrees expected_ptrees;
		expected_ptrees.push_back(expected_ptree);
		
		PTrees input_trees = expected_ptrees;
		
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[B 1[C D]] " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.added_nonterminals.insert("1");
		
		//-------------------input trees----------------------------------------
		PTree input_ptree;
		input_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			input_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode child_node;
			child_node.tag = "1";
			
			{
				PNode pnode;
				pnode.tag = "C";
				child_node.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "D";
				child_node.children.push_back(pnode);
			}
			
			input_ptree.root.children.push_back(child_node);
		}
		
		PTrees input_trees;
		input_trees.push_back(input_ptree);
		
		//-------------------expected trees-------------------------------------
		
		PTree expected_ptree;
		expected_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode pnode;
			pnode.tag = "C";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode pnode;
			pnode.tag = "D";
			expected_ptree.root.children.push_back(pnode);
		}
		
	
		
		PTrees expected_ptrees;
		expected_ptrees.push_back(expected_ptree);
		
		//----------------------------------------------------------------------
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[B b[C D]] (normal rule)" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		
		//-------------------input trees----------------------------------------
		PTree input_ptree;
		input_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			input_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode child_node;
			child_node.tag = "b";
			
			{
				PNode pnode;
				pnode.tag = "C";
				child_node.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "D";
				child_node.children.push_back(pnode);
			}
			
			input_ptree.root.children.push_back(child_node);
		}
		
		PTrees input_trees;
		input_trees.push_back(input_ptree);
		
		//-------------------expected trees-------------------------------------
		
		PTree expected_ptree;
		expected_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode child_node;
			child_node.tag = "b";
			
			{
				PNode pnode;
				pnode.tag = "C";
				child_node.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "D";
				child_node.children.push_back(pnode);
			}
			
			expected_ptree.root.children.push_back(child_node);
		}
		
		
		PTrees expected_ptrees;
		expected_ptrees.push_back(expected_ptree);
		
		//----------------------------------------------------------------------
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[B 1[C 2[D E]]] " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.added_nonterminals.insert("1");
		input_grammar.added_nonterminals.insert("2");
		
		//-------------------input trees----------------------------------------
		PTree input_ptree;
		input_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			input_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode child_node;
			child_node.tag = "1";
			
			{
				PNode pnode;
				pnode.tag = "C";
				child_node.children.push_back(pnode);
			}
			
			
			{
				PNode child_node2;
				child_node2.tag = "2";
				
				{
					PNode pnode;
					pnode.tag = "D";
					child_node2.children.push_back(pnode);
				}
				
				{
					PNode pnode;
					pnode.tag = "E";
					child_node2.children.push_back(pnode);
				}
				
				child_node.children.push_back(child_node2);
			}
			
			input_ptree.root.children.push_back(child_node);
		}
		
		PTrees input_trees;
		input_trees.push_back(input_ptree);
		
		//-------------------expected trees-------------------------------------
		
		PTree expected_ptree;
		expected_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode pnode;
			pnode.tag = "C";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode pnode;
			pnode.tag = "D";
			expected_ptree.root.children.push_back(pnode);
		}
		
	
		{
			PNode pnode;
			pnode.tag = "E";
			expected_ptree.root.children.push_back(pnode);
		}
		
	
		
		PTrees expected_ptrees;
		expected_ptrees.push_back(expected_ptree);
		
		//----------------------------------------------------------------------
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " input:\t A[B 1[C D[E 2[F G]]]] " << std::endl;
	std::cout << " expected:\tA[B C D[E F G]] " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.added_nonterminals.insert("1");
		input_grammar.added_nonterminals.insert("2");
		
		//-------------------input trees----------------------------------------
		PTree input_ptree;
		input_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			input_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode node1;
			node1.tag = "1";
			
			{
				PNode pnode;
				pnode.tag = "C";
				node1.children.push_back(pnode);
			}

			{		
				PNode nodeD;
				nodeD.tag = "D";

				
				{
					PNode pnode;
					pnode.tag = "E";
					nodeD.children.push_back(pnode);
				}
				
				{
					PNode node2;
					node2.tag = "2";
					
					{
						PNode pnode;
						pnode.tag = "F";
						node2.children.push_back(pnode);
					}
					
					{
						PNode pnode;
						pnode.tag = "G";
						node2.children.push_back(pnode);
					}
					
					nodeD.children.push_back(node2);
				}
				
				node1.children.push_back(nodeD);
			}
			input_ptree.root.children.push_back(node1);

		}
		
		PTrees input_trees;
		input_trees.push_back(input_ptree);
		
		//-------------------expected trees-------------------------------------
		
		PTree expected_ptree;
		expected_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode pnode;
			pnode.tag = "C";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode nodeD;
			nodeD.tag = "D";
			
			{
				PNode pnode;
				pnode.tag = "E";
				nodeD.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "F";
				nodeD.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "G";
				nodeD.children.push_back(pnode);
			}
			
			expected_ptree.root.children.push_back(nodeD);
		}
		
	
		
		PTrees expected_ptrees;
		expected_ptrees.push_back(expected_ptree);
		
		//----------------------------------------------------------------------
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " input:\t A[B[E 2[F G]] 1[C D]] " << std::endl;
	std::cout << " expected:\tA[B[E F G] C D] " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.added_nonterminals.insert("1");
		input_grammar.added_nonterminals.insert("2");
		
		//-------------------input trees----------------------------------------
		PTree input_ptree;
		input_ptree.root.tag = "A";
		
		{
			PNode nodeB;
			nodeB.tag = "B";
		
			{
				PNode pnode;
				pnode.tag = "E";
				nodeB.children.push_back(pnode);
			}
			
			{
				PNode node2;
				node2.tag = "2";
				
				{
					PNode pnode;
					pnode.tag = "F";
					node2.children.push_back(pnode);
				}
				
				{
					PNode pnode;
					pnode.tag = "G";
					node2.children.push_back(pnode);
				}
				
				nodeB.children.push_back(node2);
			}
			
			input_ptree.root.children.push_back(nodeB);
		}
		
		{
			PNode node1;
			node1.tag = "1";
			
			{
				PNode pnode;
				pnode.tag = "C";
				node1.children.push_back(pnode);
			}

			{		
				PNode nodeD;
				nodeD.tag = "D";
				node1.children.push_back(nodeD);
			}
			input_ptree.root.children.push_back(node1);

		}
		
		PTrees input_trees;
		input_trees.push_back(input_ptree);
		
		//-------------------expected trees-------------------------------------
		
		PTree expected_ptree;
		expected_ptree.root.tag = "A";
		
		{
			PNode nodeB;
			nodeB.tag = "B";
			
			
			{
				PNode pnode;
				pnode.tag = "E";
				nodeB.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "F";
				nodeB.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "G";
				nodeB.children.push_back(pnode);
			}
			
			expected_ptree.root.children.push_back(nodeB);
		}
		
		{
			PNode pnode;
			pnode.tag = "C";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode nodeD;
			nodeD.tag = "D";
			expected_ptree.root.children.push_back(nodeD);
		}
		
	
		
		PTrees expected_ptrees;
		expected_ptrees.push_back(expected_ptree);
		
		//----------------------------------------------------------------------
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[B 1[C D]], E[F 2[G H]] (two trees)" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.added_nonterminals.insert("1");
		input_grammar.added_nonterminals.insert("2");
		
		//-------------------input trees----------------------------------------
		PTrees input_trees;
		
		{
			PTree input_ptree;
			input_ptree.root.tag = "A";
			
			{
				PNode pnode;
				pnode.tag = "B";
				input_ptree.root.children.push_back(pnode);
			}
			
			{
				PNode child_node;
				child_node.tag = "1";
				
				{
					PNode pnode;
					pnode.tag = "C";
					child_node.children.push_back(pnode);
				}
				
				{
					PNode pnode;
					pnode.tag = "D";
					child_node.children.push_back(pnode);
				}
				
				input_ptree.root.children.push_back(child_node);
			}
			input_trees.push_back(input_ptree);
		}
		
		{
			PTree input_ptree;
			input_ptree.root.tag = "E";
			
			{
				PNode pnode;
				pnode.tag = "F";
				input_ptree.root.children.push_back(pnode);
			}
			
			{
				PNode child_node;
				child_node.tag = "2";
				
				{
					PNode pnode;
					pnode.tag = "G";
					child_node.children.push_back(pnode);
				}
				
				{
					PNode pnode;
					pnode.tag = "H";
					child_node.children.push_back(pnode);
				}
				
				input_ptree.root.children.push_back(child_node);
			}
			input_trees.push_back(input_ptree);
		}
		
		//-------------------expected trees-------------------------------------
		PTrees expected_ptrees;
		
		{
			PTree expected_ptree;
			expected_ptree.root.tag = "A";
			
			{
				PNode pnode;
				pnode.tag = "B";
				expected_ptree.root.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "C";
				expected_ptree.root.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "D";
				expected_ptree.root.children.push_back(pnode);
			}
			
			expected_ptrees.push_back(expected_ptree);
		}
		
		{
			PTree expected_ptree;
			expected_ptree.root.tag = "E";
			
			{
				PNode pnode;
				pnode.tag = "F";
				expected_ptree.root.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "G";
				expected_ptree.root.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "H";
				expected_ptree.root.children.push_back(pnode);
			}
			
			expected_ptrees.push_back(expected_ptree);
		}
		
		
		//----------------------------------------------------------------------
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[E [B 1[C D]]] (chain then break) " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.added_nonterminals.insert("1");
		
		//-------------------input trees----------------------------------------
		PTree input_ptree;
		input_ptree.root.tag = "A";
		
		{
			PNode nodeE;
			nodeE.tag = "E";
			
			{
				PNode pnode;
				pnode.tag = "B";
				nodeE.children.push_back(pnode);
			}
			
			{
				PNode child_node;
				child_node.tag = "1";
				
				{
					PNode pnode;
					pnode.tag = "C";
					child_node.children.push_back(pnode);
				}
				
				{
					PNode pnode;
					pnode.tag = "D";
					child_node.children.push_back(pnode);
				}
				
				nodeE.children.push_back(child_node);
			}
			
			input_ptree.root.children.push_back(nodeE);
		}
		
		PTrees input_trees;
		input_trees.push_back(input_ptree);
		
		//-------------------expected trees-------------------------------------
		
		PTree expected_ptree;
		expected_ptree.root.tag = "A";
		{
			PNode nodeE;
			nodeE.tag = "E";
			
		
			{
				PNode pnode;
				pnode.tag = "B";
				nodeE.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "C";
				nodeE.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "D";
				nodeE.children.push_back(pnode);
			}
			
			expected_ptree.root.children.push_back(nodeE);
		}
		
		PTrees expected_ptrees;
		expected_ptrees.push_back(expected_ptree);
		
		//----------------------------------------------------------------------
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[B 1[C D[E]]] (break rule then a chain)" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.added_nonterminals.insert("1");
		
		//-------------------input trees----------------------------------------
		PTree input_ptree;
		input_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			input_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode child_node;
			child_node.tag = "1";
			
			{
				PNode pnode;
				pnode.tag = "C";
				child_node.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "D";

				{
					PNode pnode2;
					pnode2.tag = "E";
					pnode.children.push_back(pnode2);
				}
				
				child_node.children.push_back(pnode);
			}
			
			input_ptree.root.children.push_back(child_node);
		}
		
		PTrees input_trees;
		input_trees.push_back(input_ptree);
		
		//-------------------expected trees-------------------------------------
		
		PTree expected_ptree;
		expected_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode pnode;
			pnode.tag = "C";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode pnode;
			pnode.tag = "D";
			
			{
				PNode pnode2;
				pnode2.tag = "E";
				pnode.children.push_back(pnode2);
			}
			
			expected_ptree.root.children.push_back(pnode);
		}
		
	
		
		PTrees expected_ptrees;
		expected_ptrees.push_back(expected_ptree);
		
		//----------------------------------------------------------------------
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[B 1[C[E] D]] (break rule then a chain)" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.added_nonterminals.insert("1");
		
		//-------------------input trees----------------------------------------
		PTree input_ptree;
		input_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			input_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode child_node;
			child_node.tag = "1";
			
			{
				PNode pnode;
				pnode.tag = "C";

				{
					PNode pnode2;
					pnode2.tag = "E";
					pnode.children.push_back(pnode2);
				}
				
				child_node.children.push_back(pnode);
			}
			
			{
				PNode pnode;
				pnode.tag = "D";
				child_node.children.push_back(pnode);
			}
			
			input_ptree.root.children.push_back(child_node);
		}
		
		PTrees input_trees;
		input_trees.push_back(input_ptree);
		
		//-------------------expected trees-------------------------------------
		
		PTree expected_ptree;
		expected_ptree.root.tag = "A";
		
		{
			PNode pnode;
			pnode.tag = "B";
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode pnode;
			pnode.tag = "C";
			
			{
				PNode pnode2;
				pnode2.tag = "E";
				pnode.children.push_back(pnode2);
			}
			
			expected_ptree.root.children.push_back(pnode);
		}
		
		{
			PNode pnode;
			pnode.tag = "D";
			expected_ptree.root.children.push_back(pnode);
		}
		
	
		
		PTrees expected_ptrees;
		expected_ptrees.push_back(expected_ptree);
		
		//----------------------------------------------------------------------
		_test_unbreak_rules(
			input_trees,
			input_grammar,
			expected_ptrees
		);
	}
	
	//unbreak then chain
}
