#include "tst_mod_parser.h"

void TST_mod_parser::_test_fix_tree_add_chains(
	const PNode & input,
	const Chomsky_grammar & grammar,
	const PNodes & expected
)
{
	PTrees dummy;
	Chomsky_grammar dummy_grammar;
	Dechomskify dechomskify(
		dummy,
		grammar
	);

	PNodes real = dechomskify.fix_tree_add_chains(input);

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
void TST_mod_parser::test_fix_tree_add_chains()
{
			
	std::cout << "===============================================================" << std::endl;
	std::cout << " Rules:  " << std::endl;
	std::cout << " A -> B C  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Chomsky_grammar grammar;
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("B");
			rule.RHS.push_back("C");

			grammar.rules.push_back(rule);

		}
		
		PNode input;
		input.tag = "A";
		input.rule_id = 0;

		{
			PNode node;
			node.tag = "B";
			input.children.push_back(node);
		}

		{
			PNode node;
			node.tag = "C";
			input.children.push_back(node);
		}

		PNodes expected;
		expected.push_back(input);

		_test_fix_tree_add_chains(
			input,
			grammar,
			expected
		);
	}
				
	std::cout << "===============================================================" << std::endl;
	std::cout << " first symbol to replace with a single symbol:" << std::endl;
	std::cout << " rules:" << std::endl;
	std::cout << " A -> B C" << std::endl;
	std::cout << " B -> b" << std::endl;
	std::cout << " terminals: b, C" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Chomsky_grammar grammar;
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("b");
			rule.RHS.push_back("C");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 0;
				replaced_symbol_index.symbols.push_back("B");
				rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			grammar.rules.push_back(rule);
		}
			
		PNode input;
		input.tag = "A";
		input.rule_id = 0;

		{
			PNode node;
			node.tag = "b";
			input.children.push_back(node);
		}

		{
			PNode node;
			node.tag = "C";
			input.children.push_back(node);
		}


		PNodes expected;
		{			
			PNode node0;
			node0.tag = "A";

			{
				PNode node;
				node.tag = "B";

				{
					PNode node2;
					node2.tag = "b";
					node.children.push_back(node2);
				}

				node0.children.push_back(node);
			}

			{
				PNode node;
				node.tag = "C";
				node0.children.push_back(node);
			}

			expected.push_back(node0);
		}
	
		_test_fix_tree_add_chains(
			input,
			grammar,
			expected
		);
	}
	

	std::cout << "===============================================================" << std::endl;
	std::cout << " second symbol to replace with a single symbol:" << std::endl;
	std::cout << " rules:" << std::endl;
	std::cout << " A -> C B" << std::endl;
	std::cout << " B -> b" << std::endl;
	std::cout << " terminals: b, C" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
	
		Chomsky_grammar grammar;
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("C");
			rule.RHS.push_back("b");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("B");
				rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			grammar.rules.push_back(rule);
		}
				
		PNode input;
		input.tag = "A";
		input.rule_id = 0;

		{
			PNode node;
			node.tag = "C";
			input.children.push_back(node);
		}


		{
			PNode node;
			node.tag = "b";
			input.children.push_back(node);
		}

		PNodes expected;
		{			
			PNode node0;
			node0.tag = "A";

			{
				PNode node;
				node.tag = "C";
				node0.children.push_back(node);
			}

			{
				PNode node;
				node.tag = "B";

				{
					PNode node2;
					node2.tag = "b";
					node.children.push_back(node2);
				}

				node0.children.push_back(node);
			}


			expected.push_back(node0);
		}
	
		_test_fix_tree_add_chains(
			input,
			grammar,
			expected
		);
		
	}
	

	std::cout << "===============================================================" << std::endl;
	std::cout << " both symbols to replace with a single symbol:" << std::endl;
	std::cout << " rules:" << std::endl;
	std::cout << " A -> B B" << std::endl;
	std::cout << " B -> b" << std::endl;
	std::cout << " terminals: b" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Chomsky_grammar grammar;
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("b");
			rule.RHS.push_back("b");
				
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 0;
				replaced_symbol_index.symbols.push_back("B");
				rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			

			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("B");
				rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			grammar.rules.push_back(rule);
		}
				
		PNode input;
		input.tag = "A";
		input.rule_id = 0;

		{
			PNode node;
			node.tag = "b";
			input.children.push_back(node);
		}


		{
			PNode node;
			node.tag = "b";
			input.children.push_back(node);
		}

		PNodes expected;
		{			
			PNode node0;
			node0.tag = "A";

			{
				PNode node;
				node.tag = "B";

				{
					PNode node2;
					node2.tag = "b";
					node.children.push_back(node2);
				}

				node0.children.push_back(node);
			}


			{
				PNode node;
				node.tag = "B";

				{
					PNode node2;
					node2.tag = "b";
					node.children.push_back(node2);
				}

				node0.children.push_back(node);
			}


			expected.push_back(node0);
		}
	
		_test_fix_tree_add_chains(
			input,
			grammar,
			expected
		);
	}
	
			
	std::cout << "===============================================================" << std::endl;
	std::cout << " both symbols to replace with uniques single symbols:" << std::endl;
	std::cout << " rules:" << std::endl;
	std::cout << " A -> B C" << std::endl;
	std::cout << " B -> b" << std::endl;
	std::cout << " C -> c" << std::endl;
	std::cout << " terminals: b, c" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
	
		Chomsky_grammar grammar;
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("b");
			rule.RHS.push_back("c");
				
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 0;
				replaced_symbol_index.symbols.push_back("B");
				rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			

			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("C");
				rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			grammar.rules.push_back(rule);
		

		}

			
		PNode input;
		input.tag = "A";
		input.rule_id = 0;

		{
			PNode node;
			node.tag = "b";
			input.children.push_back(node);
		}


		{
			PNode node;
			node.tag = "c";
			input.children.push_back(node);
		}

		PNodes expected;
		{			
			PNode node0;
			node0.tag = "A";

			{
				PNode node;
				node.tag = "B";

				{
					PNode node2;
					node2.tag = "b";
					node.children.push_back(node2);
				}

				node0.children.push_back(node);
			}


			{
				PNode node;
				node.tag = "C";

				{
					PNode node2;
					node2.tag = "c";
					node.children.push_back(node2);
				}

				node0.children.push_back(node);
			}


			expected.push_back(node0);
		}
	
		_test_fix_tree_add_chains(
			input,
			grammar,
			expected
		);

	}



	std::cout << "===============================================================" << std::endl;
	std::cout << " both symbols to replace with uniques single symbols:" << std::endl;
	std::cout << " rules:" << std::endl;
	std::cout << " A -> B C" << std::endl;
	std::cout << " B -> D E" << std::endl;
	std::cout << " D -> d" << std::endl;
	std::cout << " E -> F" << std::endl;
	std::cout << " F -> f" << std::endl;
	std::cout << " terminals: b, c" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
	
		Chomsky_grammar grammar;
			
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("B");
			rule.RHS.push_back("C");
			grammar.rules.push_back(rule);


		}


		{
			Chomsky_rule rule;
			rule.LHS = "B";
			rule.RHS.push_back("d");
			rule.RHS.push_back("f");
				
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 0;
				replaced_symbol_index.symbols.push_back("D");
				rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			

			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("E");
				replaced_symbol_index.symbols.push_back("F");
				rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			grammar.rules.push_back(rule);
		

		}

			
		PNode input;
		input.tag = "A";
		input.rule_id = 0;

		{
			PNode node;
			node.tag = "B";
			node.rule_id = 1;

			{
				PNode node1;
				node1.tag = "d";
				node.children.push_back(node1);
			}


			{
				PNode node1;
				node1.tag = "f";
				node.children.push_back(node1);
			}

			input.children.push_back(node);
		}

		{
			PNode node;
			node.tag = "C";
			input.children.push_back(node);
		}

		PNodes expected;
		{			
			PNode node0;
			node0.tag = "A";
			node0.rule_id = 0;
			
			{ 
				PNode node;
				node.tag = "B";
				node.rule_id = 1;

				{
					PNode node2;
					node2.tag = "D";
					{
						PNode node3;
						node3.tag = "d";
						node2.children.push_back(node3);
					}

					node.children.push_back(node2);
				}
	
				{
					PNode node2;
					node2.tag = "E";
					{
						PNode node3;
						node3.tag = "F";
				
						{
							PNode node4;
							node4.tag = "f";
							node3.children.push_back(node4);
						}
						
						node2.children.push_back(node3);
					}

					node.children.push_back(node2);
				}
			
				node0.children.push_back(node);
			
			}


			{
				PNode node;
				node.tag = "C";
				node0.children.push_back(node);
			}


			expected.push_back(node0);
		}
	
		_test_fix_tree_add_chains(
			input,
			grammar,
			expected
		);

	}
}

