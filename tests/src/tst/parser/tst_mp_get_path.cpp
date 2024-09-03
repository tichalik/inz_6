#include "tst_mod_parser.h"


void TST_mod_parser::_test_get_path(
	const Symbol & head,
	Chain_trees & chain_trees,
	const std::vector<Symbols> & expected_symbols_vect
)
{
	Grammar dummy;
	Chomskify chomskify(dummy);
	
	Symbols current_path;
	std::vector<Symbols> real_symbols_vect = 
		chomskify.get_path( head, current_path, chain_trees);
	
	bool ok = compare(expected_symbols_vect, real_symbols_vect, "path");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}

}


void TST_mod_parser::test_get_path()
{
	std::cout << "===============================================================" << std::endl;
	std::cout << " A[B C[D}}" << std::endl;
	std::cout << " exits: B D" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Symbol head = "A";
		
		Chain_trees chain_trees;
		
		chain_trees["A"].symbols.push_back("B");
		chain_trees["A"].symbols.push_back("C");
		
		chain_trees["C"].symbols.push_back("D");
		
		chain_trees["B"].exit = true;
		chain_trees["D"].exit = true;

		
		std::vector<Symbols> expected_symbols_vect;
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("B");
			expected_symbols_vect.push_back(tmp);
		}
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			expected_symbols_vect.push_back(tmp);
		}
		
		_test_get_path(
			head,
			chain_trees,
			expected_symbols_vect
		);
		
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " A[B C[D}}" << std::endl;
	std::cout << " exits: C" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Symbol head = "A";
		
		Chain_trees chain_trees;
		
		chain_trees["A"].symbols.push_back("B");
		chain_trees["A"].symbols.push_back("C");
		
		chain_trees["C"].symbols.push_back("D");
		
		chain_trees["C"].exit = true;

		
		std::vector<Symbols> expected_symbols_vect;
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			expected_symbols_vect.push_back(tmp);
		}
		
		_test_get_path(
			head,
			chain_trees,
			expected_symbols_vect
		);
		
	}

	std::cout << "===============================================================" << std::endl;
	std::cout << "     A     " << std::endl;
	std::cout << "    / \\   " << std::endl;
	std::cout << "   B   C   " << std::endl;
	std::cout << "    \\ /   " << std::endl;
	std::cout << "     D     " << std::endl;
	std::cout << "    / \\   " << std::endl;
	std::cout << "   E   F   " << std::endl;
	std::cout << "    \\ /   " << std::endl;
	std::cout << "     G     " << std::endl;
	std::cout << " exits: A B F G     " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Symbol head = "A";
		
		Chain_trees chain_trees;
		
		chain_trees["A"].symbols.push_back("B");
		chain_trees["A"].symbols.push_back("C");
		
		chain_trees["B"].symbols.push_back("D");
		chain_trees["C"].symbols.push_back("D");
		
		chain_trees["D"].symbols.push_back("E");
		chain_trees["D"].symbols.push_back("F");
		
		chain_trees["E"].symbols.push_back("G");
		chain_trees["F"].symbols.push_back("G");
		
		chain_trees["A"].exit = true;
		chain_trees["B"].exit = true;
		chain_trees["F"].exit = true;
		chain_trees["G"].exit = true;
		
		
		std::vector<Symbols> expected_symbols_vect;
		
		{
			Symbols tmp;
			tmp.push_back("A");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("B");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("B");
			tmp.push_back("D");
			tmp.push_back("E");
			tmp.push_back("G");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("B");
			tmp.push_back("D");
			tmp.push_back("F");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("B");
			tmp.push_back("D");
			tmp.push_back("F");
			tmp.push_back("G");
			expected_symbols_vect.push_back(tmp);
		}
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			tmp.push_back("E");
			tmp.push_back("G");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			tmp.push_back("F");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			tmp.push_back("F");
			tmp.push_back("G");
			expected_symbols_vect.push_back(tmp);
		}
		
		_test_get_path(
			head,
			chain_trees,
			expected_symbols_vect
		);
		
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "    A         " << std::endl;
	std::cout << "    |\\       " << std::endl;
	std::cout << "    | C       " << std::endl;
	std::cout << "    |/ \\     " << std::endl;
	std::cout << "    D   F     " << std::endl;
	std::cout << "     \\ /     " << std::endl;
	std::cout << "      E       " << std::endl;
	std::cout << "  exits: C D F E " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Symbol head = "A";
		
		Chain_trees chain_trees;
		
		chain_trees["A"].symbols.push_back("D");
		chain_trees["A"].symbols.push_back("C");
		
		chain_trees["C"].symbols.push_back("D");
		chain_trees["C"].symbols.push_back("F");
		
		chain_trees["D"].symbols.push_back("E");
		chain_trees["F"].symbols.push_back("E");
	
		chain_trees["C"].exit = true;
		chain_trees["D"].exit = true;
		chain_trees["F"].exit = true;
		chain_trees["E"].exit = true;

		
		
		std::vector<Symbols> expected_symbols_vect;
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("D");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("D");
			tmp.push_back("E");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("D");
			tmp.push_back("E");
			expected_symbols_vect.push_back(tmp);
		}
		
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("F");
			expected_symbols_vect.push_back(tmp);
		}
		{
			Symbols tmp;
			tmp.push_back("A");
			tmp.push_back("C");
			tmp.push_back("F");
			tmp.push_back("E");
			expected_symbols_vect.push_back(tmp);
		}
		
		_test_get_path(
			head,
			chain_trees,
			expected_symbols_vect
		);
		
	}
}
