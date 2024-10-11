#include "tst_visualize_grammar.h"

void _test_visualize(
	const Grammar & grammar
)
{
	Mod_visualize_grammar mvg;
	
	std::cout << str(mvg.visualize_grammar(grammar, true), "") << std::endl;
}

void test_visualize()
{
	Grammar minut_19_p_1;
	{
		minut_19_p_1.nonterminals.insert("A");
		minut_19_p_1.nonterminals.insert("B");
		minut_19_p_1.nonterminals.insert("C");
		minut_19_p_1.nonterminals.insert("ABC");
		
		minut_19_p_1.terminals.insert("a");
		minut_19_p_1.terminals.insert("b");
		minut_19_p_1.terminals.insert("c");
		
		minut_19_p_1.head = "ABC";
		
		{
			Rule r;
			r.LHS = "A";
			r.RHS.push_back("a");
			
			minut_19_p_1.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "A";
			r.RHS.push_back("A");
			r.RHS.push_back("a");
			
			minut_19_p_1.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "B";
			r.RHS.push_back("b");
			
			minut_19_p_1.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "B";
			r.RHS.push_back("B");
			r.RHS.push_back("b");
			
			minut_19_p_1.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "C";
			r.RHS.push_back("c");
			
			minut_19_p_1.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "C";
			r.RHS.push_back("C");
			r.RHS.push_back("c");
			
			minut_19_p_1.rules.push_back(r);
		}
		
		
		
		{
			Rule r;
			r.LHS = "ABC";
			r.RHS.push_back("A");
			r.RHS.push_back("B");
			r.RHS.push_back("C");
			
			minut_19_p_1.rules.push_back(r);
		}
		
		
		
	}
	
	Grammar minut_19_p_2;
	{
		
		minut_19_p_2.nonterminals.insert("A");
		minut_19_p_2.nonterminals.insert("AB");
		minut_19_p_2.nonterminals.insert("ABC");
		
		minut_19_p_2.terminals.insert("a");
		minut_19_p_2.terminals.insert("b");
		minut_19_p_2.terminals.insert("c");
		
		minut_19_p_2.head = "ABC";
		
		
		{
			Rule r;
			r.LHS = "A";
			r.RHS.push_back("a");
			
			minut_19_p_2.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "A";
			r.RHS.push_back("A");
			r.RHS.push_back("a");
			
			minut_19_p_2.rules.push_back(r);
		}
		
		
		{
			Rule r;
			r.LHS = "AB";
			r.RHS.push_back("A");
			r.RHS.push_back("b");
			
			minut_19_p_2.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "AB";
			r.RHS.push_back("AB");
			r.RHS.push_back("b");
			
			minut_19_p_2.rules.push_back(r);
		}
		
		
		
		{
			Rule r;
			r.LHS = "ABC";
			r.RHS.push_back("AB");
			r.RHS.push_back("c");
			
			minut_19_p_2.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "ABC";
			r.RHS.push_back("ABC");
			r.RHS.push_back("c");
			
			minut_19_p_2.rules.push_back(r);
		}
		
		
	}
		
	Grammar minut_19_p_3;
	{
		
		minut_19_p_3.nonterminals.insert("C");
		minut_19_p_3.nonterminals.insert("BC");
		minut_19_p_3.nonterminals.insert("ABC");
		
		minut_19_p_3.terminals.insert("a");
		minut_19_p_3.terminals.insert("b");
		minut_19_p_3.terminals.insert("c");
		
		minut_19_p_3.head = "ABC";
		
		
		{
			Rule r;
			r.LHS = "C";
			r.RHS.push_back("c");
			
			minut_19_p_3.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "C";
			r.RHS.push_back("C");
			r.RHS.push_back("c");
			
			minut_19_p_3.rules.push_back(r);
		}
		
		
		{
			Rule r;
			r.LHS = "BC";
			r.RHS.push_back("b");
			r.RHS.push_back("C");
			
			minut_19_p_3.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "BC";
			r.RHS.push_back("b");
			r.RHS.push_back("BC");
			
			minut_19_p_3.rules.push_back(r);
		}
		
		
		
		{
			Rule r;
			r.LHS = "ABC";
			r.RHS.push_back("a");
			r.RHS.push_back("BC");
			
			minut_19_p_3.rules.push_back(r);
		}
		
		{
			Rule r;
			r.LHS = "ABC";
			r.RHS.push_back("a");
			r.RHS.push_back("ABC");
			
			minut_19_p_3.rules.push_back(r);
		}
		
		
	}
				
	std::cout << "===============================================================" << std::endl;
	std::cout << "  minut 19 p 1  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
		_test_visualize(minut_19_p_1);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  minut 19 p 2  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
		_test_visualize(minut_19_p_2);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  minut 19 p 3  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
		_test_visualize(minut_19_p_3);
	}
	
}

