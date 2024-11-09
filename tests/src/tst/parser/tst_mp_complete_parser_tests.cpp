#include "tst_mod_parser.h"


void TST_mod_parser::_complete_parser_tests(
	const Grammar & grammar,
	const Word & word,
	const Errors & expected_errors,
	const PTrees & expected_ptrees
)
{
	Mod_parser parser(grammar, word);
	
	std::vector<std::vector<State> > states;
	bool ok = compare(states, parser.states, "parser's states");
//	if (ok)
//	{
//		std::cout << "OK" << std::endl;
//	}
//	else
//	{
//		std::cout << __FILE__ << "\tFAIL" << std::endl;
//	}

}

void TST_mod_parser::complete_parser_tests()
{
	std::cout << "===============================================================" << std::endl;
	std::cout << " grammar:  " << std::endl;
	std::cout << " S-> SS | b " << std::endl;
	std::cout << " input :  b b b " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Word word;
		word.push_back("b");
		word.push_back("b");
		word.push_back("b");

		Grammar grammar;
		grammar.terminals.insert("b");
		grammar.nonterminals.insert("S");
		grammar.head = "S";
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("S");
			rule.RHS.push_back("S");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("b");
			grammar.rules.push_back(rule);
		}

		Errors errors;
		PTrees ptrees;

		_complete_parser_tests(
			grammar,
			word, 
			errors, 
			ptrees
		);
	}

}
