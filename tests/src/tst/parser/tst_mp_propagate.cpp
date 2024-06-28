#include "tst_mod_parser.h"

void TST_mod_parser::_test_propagate_parsing_table(
	const Grammar & grammar, 
	const Word & word, 
	const PTable & expected_ptable
)
{
	//create the tested module 
	// -- it will run all the necessary methods
	Mod_parser mod_parser(
		grammar, 
		word
	);
	
	//check whether the parsing table is identical to what is expected 
	bool ok = compare_ptable(expected_ptable, mod_parser.parsing_table);
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
		std::cout << "real parsing_table: " << std::endl;
		std::cout << ptable2string(mod_parser.parsing_table) << std::endl;
	}
}

void TST_mod_parser::test_propagate_parsing_table()
{
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " degraded Word -- single character" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		//only rules matter in parsing 
		Grammar grammar;
		
		Rule rule;
		rule.left = "a";
		rule.right1 = "A";
		rule.right2 = "A";
		grammar.rules.push_back(rule);
		
		Word degraded_word;
		degraded_word.push_back("a");
		
		PTable expected_ptable(degraded_word);
		
		_test_propagate_parsing_table(
			grammar, 
			degraded_word, 
			expected_ptable 
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " simplest case -- 2 symbols, 1 rule" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		//only rules matter in parsing 
		Grammar grammar;
		
		Rule rule;
		rule.left = "a";
		rule.right1 = "A";
		rule.right2 = "B";
		grammar.rules.push_back(rule);
		
		Word word;
		word.push_back("B");
		word.push_back("A");
		
		PTable expected_ptable(word);
		
		PTable_entry ptable_entry;
		ptable_entry.tag = "a";
		ptable_entry.visited = false;
		
		{
			PTable_reference child;
			child.x = 0;
			child.y = 0;
			child.list_index = 0;
			ptable_entry.children.push_back(child);
		}
		{
			PTable_reference child;
			child.x = 1;
			child.y = 0;
			child.list_index = 0;
			ptable_entry.children.push_back(child);
		}
		
		expected_ptable.tab[1][0].push_back(ptable_entry);
		
		_test_propagate_parsing_table(
			grammar, 
			word, 
			expected_ptable 
		);
	}
}

