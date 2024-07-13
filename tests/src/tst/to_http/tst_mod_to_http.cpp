#include "tst_mod_to_http.h"


void TST_mod_to_http::_test_pnode_to_http(
	const PNode& pnode
)
{
	Errors errors;
	PTrees ptrees;
	
	Mod_to_http mod_to_http(
		errors,
		ptrees
	);
	
	std::string res = mod_to_http.pnode_to_http(pnode);
	std::cout << res << std::endl;
}
void TST_mod_to_http::test_pnode_to_http()
{
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " single node A" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_pnode_to_http(tree1.root);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " A[B C]" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_pnode_to_http(tree2.root);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " A[B[D E] C]" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_pnode_to_http(tree3.root);
	}
	
}


void TST_mod_to_http::_test_ptree_to_http(
	const PTree& ptree
)
{
	Errors errors;
	PTrees ptrees;
	
	Mod_to_http mod_to_http(
		errors,
		ptrees
	);
	
	std::string res = mod_to_http.ptree_to_http(ptree);
	std::cout << res << std::endl;
}
void TST_mod_to_http::test_ptree_to_http()
{
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " single node A" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_ptree_to_http(tree1);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " A[B C]" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_ptree_to_http(tree2);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " A[B[D E] C]" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_ptree_to_http(tree3);
	}
	
}



TST_mod_to_http::TST_mod_to_http()
{
	{
		PNode A;
		A.tag = "A";
		
		tree1.root = A;
	}
	{
		PNode A,B,C;
		A.tag = "A";
		B.tag = "B";
		C.tag = "C";
		
		A.children.push_back(B);
		A.children.push_back(C);
		
		tree2.root = A;
	}
	{
		PNode A,B,C,D,E;
		A.tag = "A";
		B.tag = "B";
		C.tag = "C";
		D.tag = "D";
		E.tag = "E";
		
		B.children.push_back(D);
		B.children.push_back(E);
		
		A.children.push_back(B);
		A.children.push_back(C);
		
		tree3.root = A;
	}
}