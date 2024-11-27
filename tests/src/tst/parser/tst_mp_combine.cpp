#include "tst_mod_parser.h"

void TST_mod_parser::_tst_combine2(
	std::vector<std::vector<PNode*>>& input1,
	SPPF_node* input2, 
	std::vector<std::vector<PNode*>>& expected
)
{
	Process_SPPF process_sppf;	
	std::vector<std::vector<PNode*>> real = process_sppf.combine2(input1, input2);

	bool ok = compare(expected, real, "combinations");

	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}


} 

void TST_mod_parser::tst_combine2()
{
	std::cout  << "=============================================================" << std::endl;
	std::cout  << " [] x [] " << std::endl;
	std::cout  << "=============================================================" << std::endl;
	{
		std::vector<std::vector<PNode*>> in1;
		SPPF_node sppf_node;

		std::vector<std::vector<PNode*>> expected;

		_tst_combine2(in1, &sppf_node, expected);
	}
	
	std::cout  << "=============================================================" << std::endl;
	std::cout  << " [ [a1], [b1, b2], [c1, c2, c3]] x [x1] " << std::endl;
	std::cout  << "=============================================================" << std::endl;
	{
		PNode a1 = {"a1", {}};
		PNode b1 = {"b1", {}};
		PNode b2 = {"b2", {}};
		PNode c1 = {"c1", {}};
		PNode c2 = {"c2", {}};
		PNode c3 = {"c3", {}};
		
		std::vector<std::vector<PNode*>> in1;
		
		in1.push_back({&a1});
		in1.push_back({&b1, &b2});
		in1.push_back({&c1, &c2, &c3});

		SPPF_node sppf_node;
		sppf_node.pnodes.push_back({"x1",{}});

		std::vector<std::vector<PNode*>> expected;
		expected.push_back({&a1, &sppf_node.pnodes[0]});
		expected.push_back({&b1, &b2, &sppf_node.pnodes[0]});
		expected.push_back({&c1, &c2, &c3, &sppf_node.pnodes[0]});

		_tst_combine2(in1, &sppf_node, expected);
	}
	std::cout  << "=============================================================" << std::endl;
	std::cout  << " [ [], [a1], [b1, b2], [c1, c2, c3]] x [x1, x2, x3] " << std::endl;
	std::cout  << "=============================================================" << std::endl;
	{
		PNode a1 = {"a1", {}};
		PNode b1 = {"b1", {}};
		PNode b2 = {"b2", {}};
		PNode c1 = {"c1", {}};
		PNode c2 = {"c2", {}};
		PNode c3 = {"c3", {}};
		
		std::vector<std::vector<PNode*>> in1;
		
		in1.push_back({});
		in1.push_back({&a1});
		in1.push_back({&b1, &b2});
		in1.push_back({&c1, &c2, &c3});

		SPPF_node sppf_node;
		sppf_node.pnodes.push_back({"x1",{}});
		sppf_node.pnodes.push_back({"x2",{}});
		sppf_node.pnodes.push_back({"x3",{}});

		std::vector<std::vector<PNode*>> expected;
		expected.push_back({&sppf_node.pnodes[0]});
		expected.push_back({&sppf_node.pnodes[1]});
		expected.push_back({&sppf_node.pnodes[2]});
		expected.push_back({&a1, &sppf_node.pnodes[0]});
		expected.push_back({&a1, &sppf_node.pnodes[1]});
		expected.push_back({&a1, &sppf_node.pnodes[2]});
		expected.push_back({&b1, &b2, &sppf_node.pnodes[0]});
		expected.push_back({&b1, &b2, &sppf_node.pnodes[1]});
		expected.push_back({&b1, &b2, &sppf_node.pnodes[2]});
		expected.push_back({&c1, &c2, &c3, &sppf_node.pnodes[0]});
		expected.push_back({&c1, &c2, &c3, &sppf_node.pnodes[1]});
		expected.push_back({&c1, &c2, &c3, &sppf_node.pnodes[2]});

		_tst_combine2(in1, &sppf_node, expected);
	}
}

void TST_mod_parser::_tst_combine_all(
	const std::vector<SPPF_node *> & input,
	const std::vector<std::vector<PNode*>> & expected
)
{
	Process_SPPF process_sppf;	
	std::vector<std::vector<PNode*>> real = process_sppf.all_combinations(input);

	bool ok = compare(expected, real, "combinations");

	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}


} 

void TST_mod_parser::tst_combine_all()
{
	std::cout  << "=============================================================" << std::endl;
	std::cout  << " [[a1] [b1 b2] [c1 c2 c3] " << std::endl;
	std::cout  << "=============================================================" << std::endl;
	{
		SPPF_node a;
		a.pnodes.push_back({"a1",{}});
		
		SPPF_node b;
		b.pnodes.push_back({"b1",{}});
		b.pnodes.push_back({"b2",{}});
		
		SPPF_node c;
		c.pnodes.push_back({"c1",{}});
		c.pnodes.push_back({"c2",{}});
		c.pnodes.push_back({"c3",{}});

		std::vector<SPPF_node*> input = {&a, &b, &c};

		std::vector<std::vector<PNode*>> expected;
		expected.push_back({&a.pnodes[0], &b.pnodes[0], &c.pnodes[0]});
		expected.push_back({&a.pnodes[0], &b.pnodes[0], &c.pnodes[1]});
		expected.push_back({&a.pnodes[0], &b.pnodes[0], &c.pnodes[2]});
		expected.push_back({&a.pnodes[0], &b.pnodes[1], &c.pnodes[0]});
		expected.push_back({&a.pnodes[0], &b.pnodes[1], &c.pnodes[1]});
		expected.push_back({&a.pnodes[0], &b.pnodes[1], &c.pnodes[2]});
		
		_tst_combine_all(input, expected);
	}
	std::cout  << "=============================================================" << std::endl;
	std::cout  << " [[a1] [b1] [c1]] " << std::endl;
	std::cout  << "=============================================================" << std::endl;
	{
		SPPF_node a;
		a.pnodes.push_back({"a1",{}});
		
		SPPF_node b;
		b.pnodes.push_back({"b1",{}});
		
		SPPF_node c;
		c.pnodes.push_back({"c1",{}});

		std::vector<SPPF_node*> input = {&a, &b, &c};

		std::vector<std::vector<PNode*>> expected;
		expected.push_back({&a.pnodes[0], &b.pnodes[0], &c.pnodes[0]});
		
		_tst_combine_all(input, expected);
	}
	std::cout  << "=============================================================" << std::endl;
	std::cout  << " [[a1]] " << std::endl;
	std::cout  << "=============================================================" << std::endl;
	{
		SPPF_node a;
		a.pnodes.push_back({"a1",{}});
		
		std::vector<SPPF_node*> input = {&a};

		std::vector<std::vector<PNode*>> expected;
		expected.push_back({&a.pnodes[0]});
		
		_tst_combine_all(input, expected);
	}
}
