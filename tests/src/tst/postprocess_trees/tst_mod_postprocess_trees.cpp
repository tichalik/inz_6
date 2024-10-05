#include "tst_mod_postprocess_trees.h"

TST_mod_postprocess_trees::TST_mod_postprocess_trees()
{
	{
	
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
		
		trees1.push_back(expected_ptree);
	}

	{
	
		PTree expected_ptree;
				
		{
			PNode pnode;
			pnode.tag = "b";
			expected_ptree.root.children.push_back(pnode);
		}

		trees2.push_back(expected_ptree);
	}

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
		
		{
			PNode pnode;
			pnode.tag = "E";
			expected_ptree.root.children.push_back(pnode);
		}
	
		trees3.push_back(expected_ptree);
	}

	{
		
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
		
		trees4.push_back(expected_ptree);
	}


}

void TST_mod_postprocess_trees::_test_get_leaf_size(
	const PNode & node,
	const size_t expected
)
{
	PTrees ptrees;
	Head head;
	Word word;
	
	Mod_postprocess_trees mpt(
		ptrees, 
		head,
		word
	);
	
	bool ok = compare(expected, mpt.get_leaf_size(node), "leaf size");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
}

void TST_mod_postprocess_trees::test_get_leaf_size()
{
				
	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[b c]  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
		_test_get_leaf_size(
			trees1[0].root,
			2
		);
	}
	


	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[b]  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
		_test_get_leaf_size(
			trees2[0].root,
			1
		);
	}
	


	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[B C D E]  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
		_test_get_leaf_size(
			trees3[0].root,
			4
		);
	}
	


	std::cout << "===============================================================" << std::endl;
	std::cout << "  A[B[E F G] C D]  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
		_test_get_leaf_size(
			trees4[0].root,
			5
		);
	}
	

}


void TST_mod_postprocess_trees::_test_postprocess_trees(
	const PTrees& input,
	const Head& head, 
	const Word& word,
	const PTrees& expected
)
{

	PTrees ptrees(input);
	Mod_postprocess_trees mpt(
		ptrees,
		head,
		word
	);
	
	bool ok = compare(expected, ptrees, "postprocessed_trees");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
}

void TST_mod_postprocess_trees::test_postprocess_trees()
{


	std::cout << "===============================================================" << std::endl;
	std::cout << " ok head, ok word  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Head head = "A";
		
		Word word;
		word.push_back("E");
		word.push_back("F");
		word.push_back("G");
		word.push_back("C");
		word.push_back("D");

		PTrees expected(trees4);
		expected[0].is_head_ok = true;
		expected[0].is_complete = true;

		_test_postprocess_trees(
			trees4,
			head, 
			word,
			expected
		);
	}
	


	std::cout << "===============================================================" << std::endl;
	std::cout << " bad head, ok word  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Head head = "B";
		
		Word word;
		word.push_back("E");
		word.push_back("F");
		word.push_back("G");
		word.push_back("C");
		word.push_back("D");

		PTrees expected(trees4);
		expected[0].is_head_ok = false;
		expected[0].is_complete = true;

		_test_postprocess_trees(
			trees4,
			head, 
			word,
			expected
		);
	}
	


	std::cout << "===============================================================" << std::endl;
	std::cout << " ok head, bad word  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Head head = "A";
		
		Word word;
		word.push_back("E");
		word.push_back("F");
		word.push_back("G");
		word.push_back("C");
		word.push_back("D");
		word.push_back("D");

		PTrees expected(trees4);
		expected[0].is_head_ok = true;
		expected[0].is_complete = false;

		_test_postprocess_trees(
			trees4,
			head, 
			word,
			expected
		);
	}
	


	std::cout << "===============================================================" << std::endl;
	std::cout << " bad head, bad word  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Head head = "A";
		
		Word word;
		word.push_back("E");
		word.push_back("F");
		word.push_back("G");
		word.push_back("C");
		word.push_back("D");
		word.push_back("D");

		PTrees expected(trees4);
		expected[0].is_head_ok = false;
		expected[0].is_complete = false;

		_test_postprocess_trees(
			trees4,
			head, 
			word,
			expected
		);
	}
	


}
