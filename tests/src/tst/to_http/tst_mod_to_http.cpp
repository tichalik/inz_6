#include "tst_mod_to_http.h"

void TST_mod_to_http::_test_sppf_to_string(
	SPPF & sppf,
	const std::string & expected
)
{
	Errors errors;
	SPPF _sppf;
	_sppf.nodes.emplace_back();
	_sppf.roots.push_back(&_sppf.nodes.back());
	VNode vnode;
	
	Mod_to_http mod_to_http(
		errors,
		_sppf,
		vnode,
		"","","","",""
	);
	
	std::string res = mod_to_http.sppf_to_string(sppf);
	std::cout << res << std::endl;
}
void TST_mod_to_http::test_sppf_to_string()
{
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " single node A" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		SPPF sppf;
		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "A";
		sppf.roots.push_back(&sppf.leaves.back());

		_test_sppf_to_string(
			sppf,
			""
		);
	}

	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " A[B C]" << std::endl;
		std::cout << "===============================================================" << std::endl;
			
		SPPF sppf;

		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "B";
		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "C";
		
		sppf.nodes.emplace_back();
		sppf.nodes.back().tag = "A";
		sppf.nodes.back().alts.emplace_back();
		sppf.nodes.back().alts.back().push_back(& sppf.leaves[0]);
		sppf.nodes.back().alts.back().push_back(& sppf.leaves[1]);

		sppf.roots.push_back(&sppf.nodes.back());

		_test_sppf_to_string(
			sppf,
			""
		);
	
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " A[B[D E] C]" << std::endl;
		std::cout << "===============================================================" << std::endl;

		SPPF sppf;

		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "D";
		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "E";
		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "C";
		sppf.leaves.emplace_back();
		
		sppf.nodes.emplace_back();
		SPPF_node * B = & sppf.nodes.back();
		B->tag = "B";
		B->alts.emplace_back();
		B->alts.back().push_back(& sppf.leaves[0]);
		B->alts.back().push_back(& sppf.leaves[1]);

		sppf.nodes.emplace_back();
		SPPF_node * A = & sppf.nodes.back();
		A->tag = "A";
		A->alts.emplace_back();
		A->alts.back().push_back(B);
		A->alts.back().push_back(& sppf.leaves[2]);

		sppf.roots.push_back(A);

		_test_sppf_to_string(
			sppf,
			""
		);
	
	}
	
}
//
//
//void TST_mod_to_http::_test_ptree_to_http(
//	const PTree& ptree
//)
//{
//	Errors errors;
//	PTrees ptrees;
//	VNode vnode;
//	
//	Mod_to_http mod_to_http(
//		errors,
//		ptrees,
//		vnode,
//		"","","","",""
//	);
//	
//	std::string res = mod_to_http.tree_to_http(ptree);
//	std::cout << res << std::endl;
//}
//void TST_mod_to_http::test_ptree_to_http()
//{
//	
//	{
//		std::cout << "===============================================================" << std::endl;
//		std::cout << " single node A" << std::endl;
//		std::cout << "===============================================================" << std::endl;
//		
//		_test_ptree_to_http(tree1);
//	}
//	
//	{
//		std::cout << "===============================================================" << std::endl;
//		std::cout << " A[B C]" << std::endl;
//		std::cout << "===============================================================" << std::endl;
//		
//		_test_ptree_to_http(tree2);
//	}
//	
//	{
//		std::cout << "===============================================================" << std::endl;
//		std::cout << " A[B[D E] C]" << std::endl;
//		std::cout << "===============================================================" << std::endl;
//		
//		_test_ptree_to_http(tree3);
//	}
//	
//}
//
//
//

