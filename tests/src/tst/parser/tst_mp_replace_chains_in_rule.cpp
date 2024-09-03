#include "tst_mod_parser.h"



void TST_mod_parser::_test_replace_chain_in_rule(
	const Chomsky_rule & input_rule,
	Chain_trees& chain_trees, 
	const Chomsky_rules & expected_rule
)
{
	Grammar dummy;
	Chomskify chomskify(dummy);
	
	Chomsky_rules res_rule = chomskify.replace_chain_in_rule(
		input_rule,
		0,
		chain_trees
	);
	
	
	bool ok = compare(expected_rule, res_rule, "rule");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}

}


void TST_mod_parser::test_replace_chain_in_rule()
{
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " nothing to replace:" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Chain_trees chain_trees;
		
		Chomsky_rule input_rule;
		input_rule.LHS = "A";
		input_rule.RHS.push_back("B");
		input_rule.RHS.push_back("C");
		
		
		Chomsky_rules expected_rules;
		expected_rules.push_back(input_rule);
		
		_test_replace_chain_in_rule(
			input_rule,
			chain_trees,
			expected_rules
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
		Chain_trees chain_trees;
		
		chain_trees["B"].symbols.push_back("b");
		chain_trees["B"].exit = false;
		chain_trees["b"].exit = true;
		
		Chomsky_rule input_rule;
		input_rule.LHS = "A";
		input_rule.RHS.push_back("B");
		input_rule.RHS.push_back("C");
		
		
		
		Chomsky_rules expected_rules;
		
		{
			Chomsky_rule expected_rule;
			expected_rule.LHS = "A";
			expected_rule.RHS.push_back("b");
			expected_rule.RHS.push_back("C");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 0;
				replaced_symbol_index.symbols.push_back("B");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_rules.push_back(expected_rule);
		}
		
		_test_replace_chain_in_rule(
			input_rule,
			chain_trees,
			expected_rules
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
		Chain_trees chain_trees;
		
		chain_trees["B"].symbols.push_back("b");
		chain_trees["B"].exit = false;
		chain_trees["b"].exit = true;
		
		Chomsky_rule input_rule;
		input_rule.LHS = "A";
		input_rule.RHS.push_back("C");
		input_rule.RHS.push_back("B");
		
		
		
		Chomsky_rules expected_rules;
		
		{
			Chomsky_rule expected_rule;
			expected_rule.LHS = "A";
			expected_rule.RHS.push_back("C");
			expected_rule.RHS.push_back("b");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("B");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_rules.push_back(expected_rule);
		}
		
		_test_replace_chain_in_rule(
			input_rule,
			chain_trees,
			expected_rules
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
		Chain_trees chain_trees;
		
		chain_trees["B"].symbols.push_back("b");
		chain_trees["B"].exit = false;
		chain_trees["b"].exit = true;
		
		Chomsky_rule input_rule;
		input_rule.LHS = "A";
		input_rule.RHS.push_back("B");
		input_rule.RHS.push_back("B");
		
		
		
		Chomsky_rules expected_rules;
		
		{
			Chomsky_rule expected_rule;
			expected_rule.LHS = "A";
			expected_rule.RHS.push_back("b");
			expected_rule.RHS.push_back("b");
				
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 0;
				replaced_symbol_index.symbols.push_back("B");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			

			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("B");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_rules.push_back(expected_rule);
		}
		
		_test_replace_chain_in_rule(
			input_rule,
			chain_trees,
			expected_rules
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
		Chain_trees chain_trees;
			
		chain_trees["B"].symbols.push_back("b");
		chain_trees["B"].exit = false;
		chain_trees["b"].exit = true;
		
		chain_trees["C"].symbols.push_back("c");
		chain_trees["C"].exit = false;
		chain_trees["c"].exit = true;
		
		Chomsky_rule input_rule;
		input_rule.LHS = "A";
		input_rule.RHS.push_back("B");
		input_rule.RHS.push_back("C");
		
		
		
		Chomsky_rules expected_rules;
		
		{
			Chomsky_rule expected_rule;
			expected_rule.LHS = "A";
			expected_rule.RHS.push_back("b");
			expected_rule.RHS.push_back("c");
				
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 0;
				replaced_symbol_index.symbols.push_back("B");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			

			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("C");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_rules.push_back(expected_rule);
		}
		
		_test_replace_chain_in_rule(
			input_rule,
			chain_trees,
			expected_rules
		);
	}
		

	std::cout << "===============================================================" << std::endl;
	std::cout << " first symbol is replaced in two ways" << std::endl;
	std::cout << " rules:" << std::endl;
	std::cout << " A -> B C" << std::endl;
	std::cout << " B -> b1" << std::endl;
	std::cout << " B -> b2" << std::endl;
	std::cout << " terminals: b1,b2, C" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Chain_trees chain_trees;
		
		chain_trees["B"].symbols.push_back("b1");
		chain_trees["B"].symbols.push_back("b2");
		chain_trees["B"].exit = false;
		chain_trees["b1"].exit = true;
		chain_trees["b2"].exit = true;
		
		Chomsky_rule input_rule;
		input_rule.LHS = "A";
		input_rule.RHS.push_back("B");
		input_rule.RHS.push_back("C");
		
		
		
		Chomsky_rules expected_rules;
			
		{
			Chomsky_rule expected_rule;
			expected_rule.LHS = "A";
			expected_rule.RHS.push_back("b1");
			expected_rule.RHS.push_back("C");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 0;
				replaced_symbol_index.symbols.push_back("B");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_rules.push_back(expected_rule);
		}
		
		{
			Chomsky_rule expected_rule;
			expected_rule.LHS = "A";
			expected_rule.RHS.push_back("b2");
			expected_rule.RHS.push_back("C");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 0;
				replaced_symbol_index.symbols.push_back("B");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_rules.push_back(expected_rule);
		}
		
		_test_replace_chain_in_rule(
			input_rule,
			chain_trees,
			expected_rules
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " second symbol is replaced in two ways" << std::endl;
	std::cout << " rules:" << std::endl;
	std::cout << " A -> C B" << std::endl;
	std::cout << " B -> b1" << std::endl;
	std::cout << " B -> b2" << std::endl;
	std::cout << " terminals: b1,b2, C" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Chain_trees chain_trees;
		
		chain_trees["B"].symbols.push_back("b1");
		chain_trees["B"].symbols.push_back("b2");
		chain_trees["B"].exit = false;
		chain_trees["b1"].exit = true;
		chain_trees["b2"].exit = true;
		
		Chomsky_rule input_rule;
		input_rule.LHS = "A";
		input_rule.RHS.push_back("C");
		input_rule.RHS.push_back("B");
		
		
		
		Chomsky_rules expected_rules;
			
		{
			Chomsky_rule expected_rule;
			expected_rule.LHS = "A";
			expected_rule.RHS.push_back("C");
			expected_rule.RHS.push_back("b1");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("B");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_rules.push_back(expected_rule);
		}
		
		{
			Chomsky_rule expected_rule;
			expected_rule.LHS = "A";
			expected_rule.RHS.push_back("C");
			expected_rule.RHS.push_back("b2");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("B");
				expected_rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_rules.push_back(expected_rule);
		}
		
		_test_replace_chain_in_rule(
			input_rule,
			chain_trees,
			expected_rules
		);
	}
	


}


