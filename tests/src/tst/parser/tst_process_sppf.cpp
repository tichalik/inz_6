#include "tst_mod_parser.h"

void TST_mod_parser::_tst_process_sppf(
	SPPF & sppf,
	std::vector<PNode*> & expected
)
{
	Process_SPPF process_sppf;	
	process_sppf.process_sppf(sppf);

	bool ok = compare(expected, sppf.res_pnodes, "processed pnodes");

	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}


} 

void TST_mod_parser::tst_process_sppf()
{
	std::cout << "===============================================================" << std::endl;
	std::cout << " evil fucked up sppf :  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		SPPF sppf;
		
		sppf.nodes.push_back({"A"});
		SPPF_node* A = &sppf.nodes.back();
		sppf.nodes.push_back({"B"});
		SPPF_node* B = &sppf.nodes.back();
		sppf.nodes.push_back({"C"});
		SPPF_node* C = &sppf.nodes.back();
		sppf.nodes.push_back({"D"});
		SPPF_node* D = &sppf.nodes.back();
		sppf.nodes.push_back({"E"});
		SPPF_node* E = &sppf.nodes.back();
		sppf.nodes.push_back({"F"});
		SPPF_node* F = &sppf.nodes.back();
		sppf.nodes.push_back({"G"});
		SPPF_node* G = &sppf.nodes.back();
		sppf.nodes.push_back({"H"});
		SPPF_node* H = &sppf.nodes.back();
		sppf.nodes.push_back({"I"});
		SPPF_node* I = &sppf.nodes.back();
		sppf.nodes.push_back({"J"});
		SPPF_node* J = &sppf.nodes.back();

		A->alts = { {C,B}, {D,E,B} };
		C->alts = { {J}, {A} };
		D->alts = { {F,G}, {F,H} };
		I->alts = { {H} };

		sppf.nodes.push_back({"D1"});
		SPPF_node* D1 = &sppf.nodes.back();
		sppf.nodes.push_back({"D2"});
		SPPF_node* D2 = &sppf.nodes.back();
		sppf.nodes.push_back({"D3"});
		SPPF_node* D3 = &sppf.nodes.back();
		sppf.nodes.push_back({"D4"});
		SPPF_node* D4 = &sppf.nodes.back();
		sppf.nodes.push_back({"D5"});
		SPPF_node* D5 = &sppf.nodes.back();
		sppf.nodes.push_back({"D6"});
		SPPF_node* D6 = &sppf.nodes.back();
		
		D1->alts = { {D}, {D2,D3}, {D2,D4} };
		D6->alts = { {D1,D5} };

		sppf.roots = {A,I};

		PNode pA1 = {"A"};
		PNode pA2 = {"A"};
		PNode pA3 = {"A"};
		PNode pB = {"B"};
		PNode pC = {"C"};
		PNode pD1 = {"D"};
		PNode pD2 = {"D"};
		PNode pE = {"E"};
		PNode pF = {"F"};
		PNode pG = {"G"};
		PNode pH = {"H"};
		PNode pI = {"I"};
		PNode pJ = {"J"};

		pA1.children = {&pC, &pB};
		pC.children = {&pA1, &pJ};

		pA2.children = { &pD1, &pE, &pB };
		pD1.children = { &pF, &pG };

		pA3.children = { &pD2, &pE, &pB };
		pD2.children = { &pF, &pH };

		pI.children = {&pH};

		std::vector<PNode*> expected = { &pA1, &pA2, &pA3 ,&pI };

		_tst_process_sppf(sppf, expected);
	}
}
