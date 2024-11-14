#include "tst_mod_parser.h"


void TST_mod_parser::_complete_parser_tests(
	const Grammar & grammar,
	const Word & word
)
{
	SPPF sppf;
	Mod_parser parser(grammar, word, sppf);
	
	std::vector<std::list<State> > states;
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

		
		

//		_complete_parser_tests(
//			grammar,
//			word, 
//		);
 	} 

	std::cout << "===============================================================" << std::endl;
	std::cout << " grammar:  " << std::endl;
	std::cout << " P -> S " << std::endl;
	std::cout << " S -> S + M | M " << std::endl;
	std::cout << " M -> M * T | T " << std::endl;
	std::cout << " T -> x " << std::endl;
	std::cout << " input :  x + x * x " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Word word;
		word.push_back("x");
		word.push_back("+");
		word.push_back("x");
		word.push_back("*");
		word.push_back("x");

		Grammar grammar;
		grammar.terminals.insert("x");
		grammar.terminals.insert("+");
		grammar.terminals.insert("*");
		grammar.nonterminals.insert("P");
		grammar.nonterminals.insert("S");
		grammar.nonterminals.insert("M");
		grammar.nonterminals.insert("T");
		grammar.head = "P";
		{
			Rule rule;
			rule.LHS = "P";
			rule.RHS.push_back("S");
			grammar.rules.push_back(rule);
		} 
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("S");
			rule.RHS.push_back("+");
			rule.RHS.push_back("M");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("M");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "M";
			rule.RHS.push_back("M");
			rule.RHS.push_back("*");
			rule.RHS.push_back("T");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "M";
			rule.RHS.push_back("T");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "T";
			rule.RHS.push_back("x");
			grammar.rules.push_back(rule);
		}
		
		

//		_complete_parser_tests(
//			grammar,
//			word, 
//		);
	}


	std::cout << "===============================================================" << std::endl;
	std::cout << " grammar:  " << std::endl;
	std::cout << " S -> a S | a " << std::endl;
	std::cout << " input :  a a a a " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Word word;
		word.push_back("a");
		word.push_back("a");
		word.push_back("a");
		word.push_back("a");

		Grammar grammar;
		grammar.terminals.insert("a");
		grammar.nonterminals.insert("S");
		grammar.head = "S";
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("a");
			rule.RHS.push_back("S");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("a");
			grammar.rules.push_back(rule);
		}
		
		

//		_complete_parser_tests(
//			grammar,
//			word, 
//		);
	}


	std::cout << "===============================================================" << std::endl;
	std::cout << " grammar:  " << std::endl;
	std::cout << " S -> S a | a " << std::endl;
	std::cout << " input :  a a a a " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Word word;
		word.push_back("a");
		word.push_back("a");
		word.push_back("a");
		word.push_back("a");

		Grammar grammar;
		grammar.terminals.insert("a");
		grammar.nonterminals.insert("S");
		grammar.head = "S";
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("S");
			rule.RHS.push_back("a");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("a");
			grammar.rules.push_back(rule);
		}
		
		

//		_complete_parser_tests(
//			grammar,
//			word, 
//		);
	}

	std::cout << "===============================================================" << std::endl;
	std::cout << " grammar:  " << std::endl;
	std::cout << " S -> S A | A " << std::endl;
	std::cout << " A -> a | a a " << std::endl;
	std::cout << " input :  a a a a " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Word word;
		word.push_back("a");
		word.push_back("a");
		word.push_back("a");
		word.push_back("a");

		Grammar grammar;
		grammar.terminals.insert("a");
		grammar.nonterminals.insert("S");
		grammar.nonterminals.insert("A");
		grammar.head = "S";
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("S");
			rule.RHS.push_back("A");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("A");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("a");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("a");
			rule.RHS.push_back("a");
			grammar.rules.push_back(rule);
		}
		
		

//		_complete_parser_tests(
//			grammar,
//			word, 
//		);
	}


	std::cout << "===============================================================" << std::endl;
	std::cout << " grammar:  " << std::endl;
	std::cout << " S -> a S B B | a " << std::endl;
	std::cout << " B -> b | " << std::endl;
	std::cout << " input :  a a a b " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Word word;
		word.push_back("a");
		word.push_back("a");
		word.push_back("a");
		word.push_back("b");

		Grammar grammar;
		grammar.terminals.insert("a");
		grammar.terminals.insert("b");
		grammar.nonterminals.insert("S");
		grammar.nonterminals.insert("B");
		grammar.head = "S";
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("a");
			rule.RHS.push_back("S");
			rule.RHS.push_back("B");
			rule.RHS.push_back("B");
			grammar.rules.push_back(rule);
		}
		{ 
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("a");
			grammar.rules.push_back(rule);
		}
		{ 
			Rule rule;
			rule.LHS = "B";
			rule.RHS.push_back("b");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "B";
			grammar.rules.push_back(rule);
		}
		
		

//		_complete_parser_tests(
//			grammar,
//			word, 
//		);
	}


	std::cout << "===============================================================" << std::endl;
	std::cout << " grammar:  " << std::endl;
	std::cout << " S -> A " << std::endl;
	std::cout << " A -> B | " << std::endl;
	std::cout << " B -> A | " << std::endl;
	std::cout << " B -> a | " << std::endl;
	std::cout << " input :  a  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
		Word word;
		word.push_back("a");

		Grammar grammar;
		grammar.terminals.insert("a");
		grammar.nonterminals.insert("S");
		grammar.nonterminals.insert("A");
		grammar.nonterminals.insert("B");
		grammar.head = "S";
		{
			Rule rule;
			rule.LHS = "S";
			rule.RHS.push_back("A");
			grammar.rules.push_back(rule);
		}
		{ 
			Rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("B");
			grammar.rules.push_back(rule);
		}
		{ 
			Rule rule;
			rule.LHS = "B";
			rule.RHS.push_back("A");
			grammar.rules.push_back(rule);
		}
		{ 
			Rule rule;
			rule.LHS = "B";
			rule.RHS.push_back("a");
			grammar.rules.push_back(rule);
		}
		
		

		_complete_parser_tests(
			grammar,
			word 
		);
	}

}
