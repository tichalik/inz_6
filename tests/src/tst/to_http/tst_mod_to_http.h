#ifndef TST_MOD_TO_HTTP
#define TST_MOD_TO_HTTP

#include "mod_to_http.h"
#include "tester.h"

class TST_mod_to_http
{
	PTree tree1; // A
	PTree tree2; // A[B C]
	PTree tree3; // A[B[D E] C]
	

	void _test_pnode_to_http(
		const PNode& pnode
	);

	void _test_ptree_to_http(
		const PTree& pnode
	);

	void _test_ptrees_to_http(
		const PTrees& pnode
	);

public:
	void test_pnode_to_http();
	void test_ptree_to_http();
	void test_ptrees_to_http();
	
	TST_mod_to_http();
};

#endif