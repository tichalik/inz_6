#include "tst_mod_parser.h"


void TST_mod_parser::_test_remove_chains(
	const Chomsky_grammar & input_grammar,
	const Chomsky_grammar & expected_grammar
)
{
	Grammar dummy;
	Chomskify chomskify(dummy);
	
	chomskify.res_grammar = input_grammar;
	chomskify.remove_chains();
	
	
	bool ok = compare(expected_grammar, chomskify.get_grammar(), "grammar");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}

}


void TST_mod_parser::test_remove_chains()
{
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " (no chains, broken rule):" << std::endl;
	std::cout << " A-> B 1" << std::endl;
	std::cout << " 1-> C D" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.terminals.insert("B");
		input_grammar.terminals.insert("C");
		input_grammar.terminals.insert("D");
		input_grammar.nonterminals.insert("A");
		input_grammar.added_nonterminals.insert("1");
		input_grammar.head  = "A";
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("B");
			rule.RHS.push_back("1");
			
			input_grammar.rules.push_back(rule);
		}
		
		{
			Chomsky_rule rule;
			rule.LHS = "1";
			rule.RHS.push_back("C");
			rule.RHS.push_back("D");
			
			input_grammar.rules.push_back(rule);
		}
		
		Chomsky_grammar expected_grammar = input_grammar;
		
		_test_remove_chains(
			input_grammar,
			expected_grammar
		);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " (single rue chain):" << std::endl;
	std::cout << " A-> b C" << std::endl;
	std::cout << " C -> D" << std::endl;
	std::cout << " D -> e" << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		
		Chomsky_grammar input_grammar;
		input_grammar.terminals.insert("b");
		input_grammar.terminals.insert("e");
		input_grammar.nonterminals.insert("A");
		input_grammar.nonterminals.insert("C");
		input_grammar.nonterminals.insert("D");
		input_grammar.head  = "A";
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("b");
			rule.RHS.push_back("C");
			
			input_grammar.rules.push_back(rule);
		}
		
		{
			Chomsky_rule rule;
			rule.LHS = "C";
			rule.RHS.push_back("D");
			
			input_grammar.rules.push_back(rule);
		}
		
		{
			Chomsky_rule rule;
			rule.LHS = "D";
			rule.RHS.push_back("e");
			
			input_grammar.rules.push_back(rule);
		}
		
		Chomsky_grammar expected_grammar = input_grammar;
		expected_grammar.rules.clear();
		
		{
			Chomsky_rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("b");
			rule.RHS.push_back("e");
			
			{
				Replaced_symbols_index replaced_symbol_index; 
				replaced_symbol_index.RHS_pos = 1;
				replaced_symbol_index.symbols.push_back("C");
				replaced_symbol_index.symbols.push_back("D");
				
				rule.replaced_symbols_indexes.push_back(replaced_symbol_index);
			}
			
			expected_grammar.rules.push_back(rule);
		}
		
		_test_remove_chains(
			input_grammar,
			expected_grammar
		);
	}
}


