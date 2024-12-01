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

	Html_response response;	

	std::string http_parse_trees = mod_to_http.sppf_to_string(sppf);
	response.fill_response(RESP_FIELDS::RESULTS, http_parse_trees);
	
	//twice, the call only fills one field
	response.fill_response(RESP_FIELDS::VISUALIZATION_AND_RESULTS_DISPLAY, "block");
	response.fill_response(RESP_FIELDS::VISUALIZATION_AND_RESULTS_DISPLAY, "block");
	response.fill_response(RESP_FIELDS::ERRORS_DISPLAY, "none");

	static int count = 0;

	std::stringstream filename;
	filename << "./debug/tc" << count++ << ".html";
	std::ofstream file;
	file.open(filename.str());
	file << response.get_response();
	file.close();
}
void TST_mod_to_http::test_sppf_to_string()
{
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " single node A" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		SPPF sppf;
		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "A";
		sppf.roots.push_back(&sppf.leaves.back());

		_test_sppf_to_string(
			sppf,
			""
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

		_test_sppf_to_string(
			sppf,
			""
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

		_test_sppf_to_string(
			sppf,
			""
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

		_test_sppf_to_string(
			sppf,
			""
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

		_test_sppf_to_string(
			sppf,
			""
		);
	
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " A[B[C[D[E]]]]" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{

		SPPF sppf;

		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "E";
		SPPF_node * E = & sppf.leaves.back();
		
		sppf.nodes.emplace_back();
		SPPF_node * D = & sppf.nodes.back();
		D->tag = "D";
		D->alts = {{E}};

		sppf.nodes.emplace_back();
		SPPF_node * C = & sppf.nodes.back();
		C->tag = "C";
		C->alts = {{D}};

		sppf.nodes.emplace_back();
		SPPF_node * B = & sppf.nodes.back();
		B->tag = "B";
		B->alts = {{C}};

		sppf.nodes.emplace_back();
		SPPF_node * A = & sppf.nodes.back();
		A->tag = "A";
		A->alts = {{B}};

		sppf.roots.push_back(A);

		_test_sppf_to_string(
			sppf,
			""
		);
	
	}
}
