#include "tst_mod_to_http.h"

void TST_mod_to_http::_test_iterate_sppf(
	SPPF & sppf, 
	const std::string & expected
)
{
	std::string res = Tester::iterate_sppf(sppf);
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
		
	std::cout << "=========================================================" << std::endl;
	std::cout << " no roots " << std::endl;
	std::cout << "=========================================================" << std::endl;
	{
		
		SPPF sppf;
		sppf.leaves.emplace_back();
		sppf.leaves.back().tag = "A";
		_test_iterate_sppf(
			sppf,
			""
		);
	}
	std::cout << "=========================================================" << std::endl;
	std::cout << " single node A" << std::endl;
	std::cout << "=========================================================" << std::endl;
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

	//single trees
	{
		std::cout << "=========================================================" << std::endl;
		std::cout << " A[B C]" << std::endl;
		std::cout << "=========================================================" << std::endl;
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
			
		std::cout << "=========================================================" << std::endl;
		std::cout << " A[B[D E] C]" << std::endl;
		std::cout << "=========================================================" << std::endl;
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
		
		std::cout << "=========================================================" << std::endl;
		std::cout << " A[B[D E C]]" << std::endl;
		std::cout << "=========================================================" << std::endl;
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
		
		std::cout << "=========================================================" << std::endl;
		std::cout << " A[B D E[C]]" << std::endl;
		std::cout << "=========================================================" << std::endl;
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

	//packed trees
	{
		std::cout << "=========================================================" << std::endl;
		std::cout << " A[B[C D[F]]]" << std::endl;
		std::cout << " A[B[C E[F]]]" << std::endl;
		std::cout << "=========================================================" << std::endl;
		{

			SPPF sppf;

			sppf.leaves.reserve(2);

			sppf.leaves.push_back({"C"});
			SPPF_node * C = &sppf.leaves.back();
			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();

			A -> alts = { {B} }; 
			B -> alts = { {C, D}, {C, E} }; 
			D -> alts = { {F} }; 
			E -> alts = { {F} }; 
		
			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B C B D F D B A \n"
				"A B C B E F E B A "
			);
		
		}
		std::cout << "=========================================================" << std::endl;
		std::cout << " A[B[D[F]] C]" << std::endl;
		std::cout << " A[B[E[F]] C]" << std::endl;
		std::cout << "=========================================================" << std::endl;
		{

			SPPF sppf;

			sppf.leaves.reserve(2);

			sppf.leaves.push_back({"C"});
			SPPF_node * C = &sppf.leaves.back();
			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();

			A -> alts = { {B} }; 
			B -> alts = { {D, C}, {E, C} }; 
			D -> alts = { {F} }; 
			E -> alts = { {F} }; 
		
			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B D F D B C B A \n"
				"A B E F E B C B A "
			);
		
		}
		std::cout << "=========================================================" << std::endl;
		std::cout << " A[B[C D[F] G[H]]]" << std::endl;
		std::cout << " A[B[C E[F] G[H]]]" << std::endl;
		std::cout << "=========================================================" << std::endl;
		{

			SPPF sppf;

			sppf.leaves.reserve(3);

			sppf.leaves.push_back({"C"});
			SPPF_node * C = &sppf.leaves.back();
			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();
			sppf.leaves.push_back({"H"});
			SPPF_node * H = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();
			sppf.nodes.push_back({"G"});
			SPPF_node * G = &sppf.nodes.back();

			A -> alts = { {B} }; 
			B -> alts = { {C, D, G}, {C, E, G} }; 
			D -> alts = { {F} }; 
			E -> alts = { {F} }; 
			G -> alts = { {H} };
		
			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B C B D F D B G H G B A \n"
				"A B C B E F E B G H G B A "
			);
		
		}
		std::cout << "=========================================================" << std::endl;
		std::cout << " A[B[C[F] H J]" << std::endl;
		std::cout << " A[B[D[F] G[H J]]]" << std::endl;
		std::cout << " A[B[E[F] G[H J]]]" << std::endl;
		std::cout << "=========================================================" << std::endl;
		{

			SPPF sppf;

			sppf.leaves.reserve(3);

			sppf.leaves.push_back({"J"});
			SPPF_node * J = &sppf.leaves.back();
			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();
			sppf.leaves.push_back({"H"});
			SPPF_node * H = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();
			sppf.nodes.push_back({"C"});
			SPPF_node * C = &sppf.nodes.back();
			sppf.nodes.push_back({"G"});
			SPPF_node * G = &sppf.nodes.back();

			A -> alts = { {B} }; 
			B -> alts = { {C, H, J}, {D, G}, {E, G} }; 
			C -> alts = { {F} }; 
			D -> alts = { {F} }; 
			E -> alts = { {F} }; 
			G -> alts = { {H, J} };
		
			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B C F C B H B J B A \n"
				"A B D F D B G H G J G B A \n"
				"A B E F E B G H G J G B A "
			);
		
		}
		std::cout << "=========================================================" << std::endl;
		std::cout << " A[B[C D]]" << std::endl;
		std::cout << " A[B[C E[F[D]]]]" << std::endl;
		std::cout << " A[B[C E[G[D]]]]" << std::endl;
		std::cout << "=========================================================" << std::endl;
		{

			SPPF sppf;
			sppf.leaves.reserve(2);

			sppf.leaves.push_back({"C"});
			SPPF_node * C = &sppf.leaves.back();
			sppf.leaves.push_back({"D"});
			SPPF_node * D = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();
			sppf.nodes.push_back({"F"});
			SPPF_node * F = &sppf.nodes.back();
			sppf.nodes.push_back({"G"});
			SPPF_node * G = &sppf.nodes.back();

			A->alts = { {B}}; 
			B->alts = { {C,D}, {C,E}}; 
			E->alts = { {F},{G}}; 
			F->alts = { {D}}; 
			G->alts = { {D}}; 
			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B C B D B A \n"
				"A B C B E F D F E B A \n"
				"A B C B E G D G E B A "
			);
		
		}
		std::cout << "=========================================================" << std::endl;
		std::cout << " A[B[C[H[J]] D]]" << std::endl;
		std::cout << " A[B[C[I[J]] D]]" << std::endl;
		std::cout << " A[B[C[I[J]] E[F[D]]]]" << std::endl;
		std::cout << " A[B[C[I[J]] E[G[D]]]]" << std::endl;
		std::cout << "=========================================================" << std::endl;
		{

			SPPF sppf;
			sppf.leaves.reserve(2);

			sppf.leaves.push_back({"D"});
			SPPF_node * D = &sppf.leaves.back();
			sppf.leaves.push_back({"J"});
			SPPF_node * J = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"C"});
			SPPF_node * C = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();
			sppf.nodes.push_back({"F"});
			SPPF_node * F = &sppf.nodes.back();
			sppf.nodes.push_back({"G"});
			SPPF_node * G = &sppf.nodes.back();
			sppf.nodes.push_back({"H"});
			SPPF_node * H = &sppf.nodes.back();
			sppf.nodes.push_back({"I"});
			SPPF_node * I = &sppf.nodes.back();

			A->alts = {{B}}; 
			B->alts = {{C,D},{C,E}}; 
			C->alts = {{H},{I}}; 
			E->alts = {{F},{G}}; 
			F->alts = {{D}}; 
			G->alts = {{D}}; 
			H->alts = {{J}}; 
			I->alts = {{J}};

			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B C H J H C B D B A \n"
				"A B C I J I C B D B A \n"
				"A B C H J H C B E F D F E B A \n"
				"A B C H J H C B E G D G E B A \n"
				"A B C I J I C B E F D F E B A \n"
				"A B C I J I C B E G D G E B A "
			);
		
		}

		std::cout << "=========================================================" << std::endl;
		std::cout << " N[I[H] F[D[A B] C] L[K]]" << std::endl;
		std::cout << " N[I[H] F[B E[B C]] L[K]]" << std::endl;
		std::cout << " N[I[H] F[D[A B] C] M[K]]" << std::endl;
		std::cout << " N[I[H] F[B E[B C]] M[K]]" << std::endl;
		std::cout << " N[I[H] F[D[A B] C] L[K]]" << std::endl;
		std::cout << " N[I[H] F[B E[B C]] L[K]]" << std::endl;
		std::cout << " N[J[H] F[D[A B] C] M[K]]" << std::endl;
		std::cout << " N[J[H] F[B E[B C]] M[K]]" << std::endl;
		std::cout << "=========================================================" << std::endl;
		{

			SPPF sppf;
			sppf.leaves.reserve(5);

			sppf.leaves.push_back({"H"});
			SPPF_node * H = &sppf.leaves.back();
			sppf.leaves.push_back({"A"});
			SPPF_node * A = &sppf.leaves.back();
			sppf.leaves.push_back({"B"});
			SPPF_node * B = &sppf.leaves.back();
			sppf.leaves.push_back({"C"});
			SPPF_node * C = &sppf.leaves.back();
			sppf.leaves.push_back({"K"});
			SPPF_node * K = &sppf.leaves.back();

			sppf.nodes.push_back({"I"});
			SPPF_node * I = &sppf.nodes.back();
			sppf.nodes.push_back({"J"});
			SPPF_node * J = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();
			sppf.nodes.push_back({"L"});
			SPPF_node * L = &sppf.nodes.back();
			sppf.nodes.push_back({"M"});
			SPPF_node * M = &sppf.nodes.back();
			sppf.nodes.push_back({"F"});
			SPPF_node * F = &sppf.nodes.back();
			sppf.nodes.push_back({"N"});
			SPPF_node * N = &sppf.nodes.back();
			sppf.nodes.push_back({"O"});
			SPPF_node * O = &sppf.nodes.back();

			I->alts = { {H} }; 
			J->alts = { {H} }; 
			D->alts = { {A,B} }; 
			E->alts = { {B,C}}; 
			L->alts = { {K} }; 
			M->alts = { {K} }; 
			F->alts = { {D, C}, {A, E} }; 
			N->alts = { {I,F,L}, {I,F,M}, {J,F,L}, {J,F,M}}; 

			sppf.roots.push_back(N);

			_test_iterate_sppf(
				sppf,
				"N I H I N F D A D B D F C F N L K L N \n"
				"N I H I N F A F E B E C E F N L K L N \n"
				"N I H I N F D A D B D F C F N M K M N \n"
				"N I H I N F A F E B E C E F N M K M N \n"
				"N J H J N F D A D B D F C F N L K L N \n"
				"N J H J N F A F E B E C E F N L K L N \n"
				"N J H J N F D A D B D F C F N M K M N \n"
				"N J H J N F A F E B E C E F N M K M N "
			);
		
		}
	}

	//multile roots
	std::cout << "=========================================================" << std::endl;
	std::cout << " A[B[C D[F]]]" << std::endl;
	std::cout << " A[B[C E[F]]]" << std::endl;
	std::cout << " A[G[C D[F]]]" << std::endl;
	std::cout << " A[G[C E[F]]]" << std::endl;
	std::cout << " A[C E[F]]" << std::endl;
	std::cout << "=========================================================" << std::endl;
	{

		SPPF sppf;

		sppf.leaves.reserve(2);

		sppf.leaves.push_back({"C"});
		SPPF_node * C = &sppf.leaves.back();
		sppf.leaves.push_back({"F"});
		SPPF_node * F = &sppf.leaves.back();

		sppf.nodes.push_back({"A"});
		SPPF_node * App = &sppf.nodes.back();
		sppf.nodes.push_back({"A"});
		SPPF_node * Ap = &sppf.nodes.back();
		sppf.nodes.push_back({"A"});
		SPPF_node * A = &sppf.nodes.back();
		sppf.nodes.push_back({"B"});
		SPPF_node * B = &sppf.nodes.back();
		sppf.nodes.push_back({"D"});
		SPPF_node * D = &sppf.nodes.back();
		sppf.nodes.push_back({"E"});
		SPPF_node * E = &sppf.nodes.back();
		sppf.nodes.push_back({"G"});
		SPPF_node * G = &sppf.nodes.back();

		A -> alts = { {B} }; 
		Ap -> alts = { {G} }; 
		App -> alts = { {C, D}, {C, E} };
		B -> alts = { {C, D}, {C, E} }; 
		D -> alts = { {F} }; 
		E -> alts = { {F} }; 
		G -> alts = { {C,D}, {C,E} };

		sppf.roots.push_back(A);
		sppf.roots.push_back(Ap);
		sppf.roots.push_back(App);

		_test_iterate_sppf(
			sppf,
			"A B C B D F D B A \n"
			"A B C B E F E B A \n"
			"A G C G D F D G A \n"
			"A G C G E F E G A \n"
			"A C A D F D A \n"
			"A C A E F E A "
		);
	
	}
	
	//loops 
	{
		std::cout << "=========================================================" << std::endl;
		std::cout << " looping " << std::endl;
		std::cout << " rules: " << std::endl;
		std::cout << "     C ::= A " << std::endl;
		std::cout << "     A ::= A | B " << std::endl;
		std::cout << "=========================================================" << std::endl;
		{ 

			SPPF sppf;

			sppf.leaves.reserve(2);

			sppf.leaves.push_back({"B"});
			SPPF_node * B = &sppf.leaves.back();

			sppf.nodes.push_back({"C"});
			SPPF_node * C = &sppf.nodes.back();
			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			
			A -> alts = { {B}, {A} }; 
			C -> alts = { {A} }; 

			sppf.roots.push_back(C);

			_test_iterate_sppf(
				sppf,
				"C A B A C \n"
				"C A *A A C "
			);
		
		}
		std::cout << "=========================================================" << std::endl;
		std::cout << " looping " << std::endl;
		std::cout << " rules: " << std::endl;
		std::cout << "     A ::= B " << std::endl;
		std::cout << "     B ::= C " << std::endl;
		std::cout << "     C ::= C | D" << std::endl;
		std::cout << "     D ::= B | E" << std::endl;
		std::cout << "     E ::= F " << std::endl;
		std::cout << "=========================================================" << std::endl;
		{  

			SPPF sppf;
			sppf.leaves.reserve(1);

			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"C"});
			SPPF_node * C = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();

			A->alts = {{B}}; 
			B->alts = {{C}}; 
			C->alts = {{C},{D}}; 
			D->alts = {{B},{E}}; 
			E->alts = {{F}}; 

			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B C *C C B A \n"
				"A B C D *B D C B A \n"
				"A B C D E F E D C B A "
			);
		
		}
		std::cout << "=========================================================" << std::endl;
		std::cout << " looping " << std::endl;
		std::cout << " rules: " << std::endl;
		std::cout << "     A ::= B " << std::endl;
		std::cout << "     B ::= C " << std::endl;
		std::cout << "     C ::= D | C" << std::endl;
		std::cout << "     D ::= E | B" << std::endl;
		std::cout << "     E ::= F " << std::endl;
		std::cout << "=========================================================" << std::endl;
		{  

			SPPF sppf;
			sppf.leaves.reserve(1);

			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"C"});
			SPPF_node * C = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();

			A->alts = {{B}}; 
			B->alts = {{C}}; 
			C->alts = {{D},{C}}; 
			D->alts = {{E},{B}}; 
			E->alts = {{F}}; 

			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B C D E F E D C B A \n"
				"A B C D *B D C B A \n"
				"A B C *C C B A "
			);
		
		}
		std::cout << "=========================================================" << std::endl;
		std::cout << " looping " << std::endl;
		std::cout << " rules: " << std::endl;
		std::cout << "     A ::= B " << std::endl;
		std::cout << "     B ::= C " << std::endl;
		std::cout << "     C ::= D " << std::endl;
		std::cout << "     D ::= E | C | B" << std::endl;
		std::cout << "     E ::= F " << std::endl;
		std::cout << "=========================================================" << std::endl;
		{   

			SPPF sppf;
			sppf.leaves.reserve(1);

			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"C"});
			SPPF_node * C = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();

			A->alts = {{B}}; 
			B->alts = {{C}}; 
			C->alts = {{D}}; 
			D->alts = {{E},{C},{B}}; 
			E->alts = {{F}}; 

			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B C D E F E D C B A \n"
				"A B C D *C D C B A \n"
				"A B C D *B D C B A "
			);
		
		}
		std::cout << "=========================================================" << std::endl;
		std::cout << " looping " << std::endl;
		std::cout << " rules: " << std::endl;
		std::cout << "     A ::= B " << std::endl;
		std::cout << "     B ::= C " << std::endl;
		std::cout << "     C ::= D " << std::endl;
		std::cout << "     D ::= E | B" << std::endl;
		std::cout << "     E ::= F | C" << std::endl;
		std::cout << "=========================================================" << std::endl;
		{   

			SPPF sppf;
			sppf.leaves.reserve(1);

			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"C"});
			SPPF_node * C = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();

			A->alts = {{B}}; 
			B->alts = {{C}}; 
			C->alts = {{D}}; 
			D->alts = {{E},{B}}; 
			E->alts = {{F},{C}	}; 

			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B C D E F E D C B A \n"
				"A B C D E *C E D C B A \n"
				"A B C D *B D C B A "
			);
		
		}
		std::cout << "=========================================================" << std::endl;
		std::cout << " looping " << std::endl;
		std::cout << " rules: " << std::endl;
		std::cout << "     A ::= B | C" << std::endl;
		std::cout << "     B ::= D " << std::endl;
		std::cout << "     C ::= E " << std::endl;
		std::cout << "     D ::= F" << std::endl;
		std::cout << "     E ::= F | B" << std::endl;
		std::cout << "=========================================================" << std::endl;
		{    

			SPPF sppf;
			sppf.leaves.reserve(1);

			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"C"});
			SPPF_node * C = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();

			A->alts = {{B},{C}}; 
			B->alts = {{D}}; 
			C->alts = {{E}}; 
			D->alts = {{F}}; 
			E->alts = {{F},{B}}; 

			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B D F D B A \n"
				"A C E F E C A \n" 
				"A C E B D F D B E C A "
			);
		
		}std::cout << "=========================================================" << std::endl;
		std::cout << " looping " << std::endl;
		std::cout << " rules: " << std::endl;
		std::cout << "     A ::= B | C" << std::endl;
		std::cout << "     B ::= D " << std::endl;
		std::cout << "     C ::= E " << std::endl;
		std::cout << "     D ::= F | C" << std::endl;
		std::cout << "     E ::= F | B" << std::endl;
		std::cout << "=========================================================" << std::endl;
		{    

			SPPF sppf;
			sppf.leaves.reserve(1);

			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"B"});
			SPPF_node * B = &sppf.nodes.back();
			sppf.nodes.push_back({"C"});
			SPPF_node * C = &sppf.nodes.back();
			sppf.nodes.push_back({"D"});
			SPPF_node * D = &sppf.nodes.back();
			sppf.nodes.push_back({"E"});
			SPPF_node * E = &sppf.nodes.back();

			A->alts = {{B},{C}}; 
			B->alts = {{D}}; 
			C->alts = {{E}}; 
			D->alts = {{F},{C}}; 
			E->alts = {{F},{B}}; 

			sppf.roots.push_back(A);

			_test_iterate_sppf(
				sppf,
				"A B D F D B A \n"
				"A B D C E F E C D B A \n"
				"A B D C E *B E C D B A \n"
				"A C E F E C A \n"
				"A C E B D F D B E C A \n"
				"A C E B D *C D B E C A "
			);
		
		}
		std::cout << " looping " << std::endl;
		std::cout << " rules: " << std::endl;
		std::cout << "     A ::= A | F " << std::endl;
		std::cout << "=========================================================" << std::endl;
		{    

			SPPF sppf;
			sppf.leaves.reserve(1);

			sppf.leaves.push_back({"F"});
			SPPF_node * F = &sppf.leaves.back();

			sppf.nodes.push_back({"A"});
			SPPF_node * A = &sppf.nodes.back();
			sppf.nodes.push_back({"A"});
			SPPF_node * Ap = &sppf.nodes.back();
			sppf.nodes.push_back({"C"});
			SPPF_node * C = &sppf.nodes.back();

			A->alts = {{F}}; 
			Ap->alts = {{Ap},{C}}; 
			C->alts = {{F},{C}}; 

			sppf.roots.push_back(A);
			sppf.roots.push_back(Ap);

			_test_iterate_sppf(
				sppf,
				"A F A \n"
				"A *A A \n"
				"A C F C A \n"
				"A C *C C A "
			);
		
		}
	}
}

