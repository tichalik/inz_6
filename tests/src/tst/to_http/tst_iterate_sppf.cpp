#include "tst_mod_to_http.h"

void TST_mod_to_http::_test_iterate_sppf(
	SPPF & sppf, 
	const std::string & expected
)
{
	std::string res;

	sppf.start_iteration();
	if (sppf.current_node() != nullptr)
	{
		res += sppf.current_node()->tag + " ";
	}

	do
	{
		SPPF::EN_ITERATION_MOVE move = sppf.next_node();
		while (move != SPPF::EN_ITERATION_MOVE::END)
		{
			res += sppf.current_node()->tag + " ";
			move = sppf.next_node();
		}
		
	} while (sppf.next_tree());

//	std::cout << res <<std::endl;
	bool ok = compare(expected, res, "iteration");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "expected: \t<" << expected << ">" << std::endl;
		std::cout << "real: \t\t<" << res << ">" << std::endl;
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
}

void TST_mod_to_http::test_iterate_sppf()
{
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " single node A" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		SPPF sppf;
		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "A";
		sppf.roots.push_back(&sppf.leaves.back());

		_test_iterate_sppf(
			sppf,
			"A "
		);
	}

	std::cout << "===============================================================" << std::endl;
	std::cout << " A[B C]" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
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

		_test_iterate_sppf(
			sppf,
			"A B A C A "
		);
	
	}
		
	std::cout << "===============================================================" << std::endl;
	std::cout << " A[B[D E] C]" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{

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

		_test_iterate_sppf(
			sppf,
			"A B D B E B A C A "
		);
	
	}
	std::cout << "===============================================================" << std::endl;
	std::cout << " A[B[D E C]]" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{

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
		B->alts.back().push_back(& sppf.leaves[2]);

		sppf.nodes.emplace_back();
		SPPF_node * A = & sppf.nodes.back();
		A->tag = "A";
		A->alts.emplace_back();
		A->alts.back().push_back(B);

		sppf.roots.push_back(A);

		_test_iterate_sppf(
			sppf,
			"A B D B E B C B A "
		);
	
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " A[B D E[C]]" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{

		SPPF sppf;

		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "B";
		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "D";
		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "C";
		sppf.leaves.emplace_back();
		
		sppf.nodes.emplace_back();
		SPPF_node * E = & sppf.nodes.back();
		E->tag = "E";
		E->alts.emplace_back();
		E->alts.back().push_back(& sppf.leaves[2]);

		sppf.nodes.emplace_back();
		SPPF_node * A = & sppf.nodes.back();
		A->tag = "A";
		A->alts.emplace_back();
		A->alts.back().push_back(&sppf.leaves[0]);
		A->alts.back().push_back(&sppf.leaves[1]);
		A->alts.back().push_back(E);

		sppf.roots.push_back(A);

		_test_iterate_sppf(
			sppf,
			"A B A D A E C E A "
		);
	
	}
}

