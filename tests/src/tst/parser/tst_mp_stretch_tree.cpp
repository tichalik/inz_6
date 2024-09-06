#include "tst_mod_parser.h"

		
void TST_mod_parser::_test_stretch_tree(
	const PNode & root,
	const Symbols & symbols_to_add,
	const PNode & expected
)
{
	PTrees dummy;
	Chomsky_grammar dummy_grammar;
	Dechomskify dechomskify(
		dummy,
		dummy_grammar
	);

	PNode real = dechomskify.stretch_tree(root, symbols_to_add);

	bool ok = compare(expected, real, "tree");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}

}

void TST_mod_parser::test_stretch_tree()
{
	PNode single_tree;
	single_tree.tag = "A";

	PNode symmetrical_tree;
	symmetrical_tree.tag = "A";
	
	{
		PNode pnode;
		pnode.tag = "B";
		
		{
			PNode pnode2;
			pnode2.tag = "C";
			pnode.children.push_back(pnode2);
		}

		{
			PNode pnode2;
			pnode2.tag = "D";
			pnode.children.push_back(pnode2);
		}

		symmetrical_tree.children.push_back(pnode);
	}
	
	{
		PNode pnode;
		pnode.tag = "E";
		
		{
			PNode pnode2;
			pnode2.tag = "F";
			pnode.children.push_back(pnode2);
		}

		{
			PNode pnode2;
			pnode2.tag = "G";
			pnode.children.push_back(pnode2);
		}

		symmetrical_tree.children.push_back(pnode);
	}

	Symbols single_symbol;
	single_symbol.push_back("1");

	Symbols multiple_symbols;
	multiple_symbols.push_back("1");
	multiple_symbols.push_back("2");
	multiple_symbols.push_back("3");
	multiple_symbols.push_back("4");
		
	std::cout << "===============================================================" << std::endl;
	std::cout << " single tree, single symbol  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		PNode expected;
		expected.tag = "1";
		expected.children.push_back(single_tree);

		_test_stretch_tree(
			single_tree,
			single_symbol,
			expected
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " multiple symbol tree, single symbol  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		PNode expected;
		expected.tag = "1";
		expected.children.push_back(symmetrical_tree);

		_test_stretch_tree(
			symmetrical_tree,
			single_symbol,
			expected
		);
	}
				
	std::cout << "===============================================================" << std::endl;
	std::cout << " single tree, multiple  symbol  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		PNode n3;
		n3.tag = "4";
		n3.children.push_back(single_tree);
				
		PNode n2;
		n2.tag = "3";
		n2.children.push_back(n3);
		
		PNode n1;
		n1.tag = "2";
		n1.children.push_back(n2);
	
		PNode expected;
		expected.tag = "1";
		expected.children.push_back(n1);
		

		_test_stretch_tree(
			single_tree,
			multiple_symbols,
			expected
		);
	}
	

	std::cout << "===============================================================" << std::endl;
	std::cout << " symmetrical tree, multiple  symbol  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		PNode n3;
		n3.tag = "4";
		n3.children.push_back(symmetrical_tree);
				
		PNode n2;
		n2.tag = "3";
		n2.children.push_back(n3);
		
		PNode n1;
		n1.tag = "2";
		n1.children.push_back(n2);
	
		PNode expected;
		expected.tag = "1";
		expected.children.push_back(n1);
		

		_test_stretch_tree(
			symmetrical_tree,
			multiple_symbols,
			expected
		);
	}
	
}
