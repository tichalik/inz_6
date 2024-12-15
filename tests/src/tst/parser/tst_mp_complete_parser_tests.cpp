#include "tst_mod_parser.h"


void TST_mod_parser::_complete_parser_tests(
	const Grammar & grammar,
	const Word & word,
	const std::vector<State_set> & expected_states,
	const std::string & expected_results
)
{
	SPPF sppf;
	Mod_parser parser(grammar, word, sppf);

	bool ok = compare(expected_states, parser.states, "parser's states");

	std::string results = iterate_sppf(sppf);

	ok &= compare(expected_results, results, "results");
//	for (auto i: parser.results)
//	{
//		std::cout << (i) << std::endl;
//	}


	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "expected: \t<" << expected_results << ">" << std::endl;
		std::cout << "real: \t\t<" << results << ">" << std::endl;
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}

} 

void TST_mod_parser::complete_parser_tests()
{ 
	std::cout << "===============================================================" << std::endl;
	std::cout << " grammar:  " << std::endl;
	std::cout << " S-> S | b " << std::endl;
	std::cout << " input :  b " << std::endl;
	std::cout << "===============================================================" << std::endl;
//	{
//		Word word;
//		word.push_back("b");
//
//		Grammar grammar;
//		grammar.terminals.insert("b");
//		grammar.nonterminals.insert("S");
//		grammar.head = "S";
//		grammar.rules ["S"] = {{"S"},{"b"}};
//		
//		std::vector<State_set> states( 2 , State_set(&state_compare));
//		// state[ 0 ]
//		states[0].insert({"S", {"S"},		 0, 0, nullptr, 0});
//		states[0].insert({"S", {"b"},		 0, 0, nullptr, 1});
//		// state[ 1 ]
//		states[1].insert({"S", {"b"},		 1, 0, nullptr, 0});
//		states[1].insert({"S", {"S"},		 1, 0, nullptr, 1});
//
//
//		_complete_parser_tests(
//			grammar,
//			word,
//			states,
//			"S b S \n"
//			"S S b S S \n"
//			"S *S S "
//		);
// 	 } 

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
		grammar.rules ["S"] = {{"S","S"},{"b"}};
		
		std::vector<State_set> states( 4 , State_set(&state_compare));
		// state[ 0 ]
		states[0].insert({"S", {"S", "S"},	 0, 0, nullptr, 0});
		states[0].insert({"S", {"b"},		 0, 0, nullptr, 1});
		// state[ 1 ]
		states[1].insert({"S", {"b"},		 1, 0, nullptr, 0});
		states[1].insert({"S", {"S", "S"},	 1, 0, nullptr, 1});
		states[1].insert({"S", {"S", "S"},	 0, 1, nullptr, 2});
		states[1].insert({"S", {"b"},		 0, 1, nullptr, 3});
		// state[ 2 ]
		states[2].insert({"S", {"b"},		 1, 1, nullptr, 0});
		states[2].insert({"S", {"S", "S"},	 2, 0, nullptr, 1});
		states[2].insert({"S", {"S", "S"},	 1, 1, nullptr, 2});
		states[2].insert({"S", {"S", "S"},	 1, 0, nullptr, 3});
		states[2].insert({"S", {"S", "S"},	 0, 2, nullptr, 4});
		states[2].insert({"S", {"b"},		 0, 2, nullptr, 5});
		// state[ 3 ]
		states[3].insert({"S", {"b"},		 1, 2, nullptr, 0});
		states[3].insert({"S", {"S", "S"},	 2, 1, nullptr, 1});
		states[3].insert({"S", {"S", "S"},	 2, 0, nullptr, 2});
		states[3].insert({"S", {"S", "S"},	 1, 2, nullptr, 3});
		states[3].insert({"S", {"S", "S"},	 1, 1, nullptr, 4});
		states[3].insert({"S", {"S", "S"},	 1, 0, nullptr, 5});
		states[3].insert({"S", {"S", "S"},	 0, 3, nullptr, 6});
		states[3].insert({"S", {"b"},		 0, 3, nullptr, 7});
		
		_complete_parser_tests(
			grammar,
			word,
			states,
			"S S S b S S S b S S S S b S S \n"
			"S S b S S S S b S S S b S S S "
		);
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
		grammar.rules ["P"] = {{"S"}};
		grammar.rules ["S"] = {{"S","+","M"}, {"M"}};
		grammar.rules ["M"] = {{"M","*","T"}, {"T"}};
		grammar.rules ["T"] = {{"x"}};
		
		std::vector<State_set> states( 6 , State_set(&state_compare));
		// state[ 0 ]
		states[0].insert({"P", {"S"},		 0, 0, nullptr, 0});
		states[0].insert({"S", {"S", "+", "M"},	 0, 0, nullptr, 1});
		states[0].insert({"S", {"M"},		 0, 0, nullptr, 2});
		states[0].insert({"M", {"M", "*", "T"},	 0, 0, nullptr, 3});
		states[0].insert({"M", {"T"},		 0, 0, nullptr, 4});
		states[0].insert({"T", {"x"},		 0, 0, nullptr, 5});
		// state[ 1 ]
		states[1].insert({"T", {"x"},		 1, 0, nullptr, 0});
		states[1].insert({"M", {"T"},		 1, 0, nullptr, 1});
		states[1].insert({"S", {"M"},		 1, 0, nullptr, 2});
		states[1].insert({"M", {"M", "*", "T"},	 1, 0, nullptr, 3});
		states[1].insert({"P", {"S"},		 1, 0, nullptr, 4});
		states[1].insert({"S", {"S", "+", "M"},	 1, 0, nullptr, 5});
		// state[ 2 ]
		states[2].insert({"S", {"S", "+", "M"},	 2, 0, nullptr, 0});
		states[2].insert({"M", {"M", "*", "T"},	 0, 2, nullptr, 1});
		states[2].insert({"M", {"T"},		 0, 2, nullptr, 2});
		states[2].insert({"T", {"x"},		 0, 2, nullptr, 3});
		// state[ 3 ]
		states[3].insert({"T", {"x"},		 1, 2, nullptr, 0});
		states[3].insert({"M", {"T"},		 1, 2, nullptr, 1});
		states[3].insert({"S", {"S", "+", "M"},	 3, 0, nullptr, 2});
		states[3].insert({"M", {"M", "*", "T"},	 1, 2, nullptr, 3});
		states[3].insert({"P", {"S"},		 1, 0, nullptr, 4});
		states[3].insert({"S", {"S", "+", "M"},	 1, 0, nullptr, 5});
		// state[ 4 ]
		states[4].insert({"M", {"M", "*", "T"},	 2, 2, nullptr, 0});
		states[4].insert({"T", {"x"},		 0, 4, nullptr, 1});
		// state[ 5 ]
		states[5].insert({"T", {"x"},		 1, 4, nullptr, 0});
		states[5].insert({"M", {"M", "*", "T"},	 3, 2, nullptr, 1});
		states[5].insert({"S", {"S", "+", "M"},	 3, 0, nullptr, 2});
		states[5].insert({"M", {"M", "*", "T"},	 1, 2, nullptr, 3});
		states[5].insert({"P", {"S"},		 1, 0, nullptr, 4});
		states[5].insert({"S", {"S", "+", "M"},	 1, 0, nullptr, 5});



		std::vector<std::string> results;
		results.push_back("P[ S[ S[ M[ T[ x]]] + M[ M[ T[ x]] * T[ x]]]]");

		_complete_parser_tests(
			grammar,
			word,
			states ,
			"P S S M T x T M S S + S M M T x T M M * M T x T M S P "	
		);
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
		grammar.rules ["S"] = {{"a","S"},{"a"}};
		
		std::vector<State_set> states( 5 , State_set(&state_compare));
		// state[ 0 ]
		states[0].insert({"S", {"a", "S"},	 0, 0, nullptr, 0});
		states[0].insert({"S", {"a"},		 0, 0, nullptr, 1});
		// state[ 1 ]
		states[1].insert({"S", {"a", "S"},	 1, 0, nullptr, 0});
		states[1].insert({"S", {"a"},		 1, 0, nullptr, 1});
		states[1].insert({"S", {"a", "S"},	 0, 1, nullptr, 2});
		states[1].insert({"S", {"a"},		 0, 1, nullptr, 3});
		// state[ 2 ]
		states[2].insert({"S", {"a", "S"},	 1, 1, nullptr, 0});
		states[2].insert({"S", {"a"},		 1, 1, nullptr, 1});
		states[2].insert({"S", {"a", "S"},	 0, 2, nullptr, 2});
		states[2].insert({"S", {"a"},		 0, 2, nullptr, 3});
		states[2].insert({"S", {"a", "S"},	 2, 0, nullptr, 4});
		// state[ 3 ]
		states[3].insert({"S", {"a", "S"},	 1, 2, nullptr, 0});
		states[3].insert({"S", {"a"},		 1, 2, nullptr, 1});
		states[3].insert({"S", {"a", "S"},	 0, 3, nullptr, 2});
		states[3].insert({"S", {"a"},		 0, 3, nullptr, 3});
		states[3].insert({"S", {"a", "S"},	 2, 1, nullptr, 4});
		states[3].insert({"S", {"a", "S"},	 2, 0, nullptr, 5});
		// state[ 4 ]
		states[4].insert({"S", {"a", "S"},	 1, 3, nullptr, 0});
		states[4].insert({"S", {"a"},		 1, 3, nullptr, 1});
		states[4].insert({"S", {"a", "S"},	 0, 4, nullptr, 2});
		states[4].insert({"S", {"a"},		 0, 4, nullptr, 3});
		states[4].insert({"S", {"a", "S"},	 2, 2, nullptr, 4});
		states[4].insert({"S", {"a", "S"},	 2, 1, nullptr, 5});
		states[4].insert({"S", {"a", "S"},	 2, 0, nullptr, 6});


		_complete_parser_tests(
			grammar,
			word,
			states ,
			"S a S S a S S a S S a S S S S "	
		);
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
		grammar.rules ["S"] = {{"S","a"},{"a"}};
		
		std::vector<State_set> states( 5 , State_set(&state_compare));
		// state[ 0 ]
		states[0].insert({"S", {"S", "a"},	 0, 0, nullptr, 0});
		states[0].insert({"S", {"a"},		 0, 0, nullptr, 1});
		// state[ 1 ]
		states[1].insert({"S", {"a"},		 1, 0, nullptr, 0});
		states[1].insert({"S", {"S", "a"},	 1, 0, nullptr, 1});
		// state[ 2 ]
		states[2].insert({"S", {"S", "a"},	 2, 0, nullptr, 0});
		states[2].insert({"S", {"S", "a"},	 1, 0, nullptr, 1});
		// state[ 3 ]
		states[3].insert({"S", {"S", "a"},	 2, 0, nullptr, 0});
		states[3].insert({"S", {"S", "a"},	 1, 0, nullptr, 1});
		// state[ 4 ]
		states[4].insert({"S", {"S", "a"},	 2, 0, nullptr, 0});
		states[4].insert({"S", {"S", "a"},	 1, 0, nullptr, 1});

		_complete_parser_tests(
			grammar,
			word,
			states ,
			"S S S S a S S a S S a S S a S "	
		);
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
		grammar.rules ["S"] = {{"S","A"},{"A"}};
		grammar.rules ["A"] = {{"a"},{"a","a"}};
		
		std::vector<State_set> states( 5 , State_set(&state_compare));
		// state[ 0 ]
		states[0].insert({"S", {"S", "A"},	 0, 0, nullptr, 0});
		states[0].insert({"S", {"A"},		 0, 0, nullptr, 1});
		states[0].insert({"A", {"a"},		 0, 0, nullptr, 2});
		states[0].insert({"A", {"a", "a"},	 0, 0, nullptr, 3});
		// state[ 1 ]
		states[1].insert({"A", {"a"},		 1, 0, nullptr, 0});
		states[1].insert({"A", {"a", "a"},	 1, 0, nullptr, 1});
		states[1].insert({"S", {"A"},		 1, 0, nullptr, 2});
		states[1].insert({"S", {"S", "A"},	 1, 0, nullptr, 3});
		states[1].insert({"A", {"a"},		 0, 1, nullptr, 4});
		states[1].insert({"A", {"a", "a"},	 0, 1, nullptr, 5});
		// state[ 2 ]
		states[2].insert({"A", {"a", "a"},	 2, 0, nullptr, 0});
		states[2].insert({"A", {"a"},		 1, 1, nullptr, 1});
		states[2].insert({"A", {"a", "a"},	 1, 1, nullptr, 2});
		states[2].insert({"S", {"A"},		 1, 0, nullptr, 3});
		states[2].insert({"S", {"S", "A"},	 2, 0, nullptr, 4});
		states[2].insert({"S", {"S", "A"},	 1, 0, nullptr, 5});
		states[2].insert({"A", {"a"},		 0, 2, nullptr, 6});
		states[2].insert({"A", {"a", "a"},	 0, 2, nullptr, 7});
		// state[ 3 ]
		states[3].insert({"A", {"a", "a"},	 2, 1, nullptr, 0});
		states[3].insert({"A", {"a"},		 1, 2, nullptr, 1});
		states[3].insert({"A", {"a", "a"},	 1, 2, nullptr, 2});
		states[3].insert({"S", {"S", "A"},	 2, 0, nullptr, 3});
		states[3].insert({"S", {"S", "A"},	 1, 0, nullptr, 4});
		states[3].insert({"A", {"a"},		 0, 3, nullptr, 5});
		states[3].insert({"A", {"a", "a"},	 0, 3, nullptr, 6});
		// state[ 4 ]
		states[4].insert({"A", {"a", "a"},	 2, 2, nullptr, 0});
		states[4].insert({"A", {"a"},		 1, 3, nullptr, 1});
		states[4].insert({"A", {"a", "a"},	 1, 3, nullptr, 2});
		states[4].insert({"S", {"S", "A"},	 2, 0, nullptr, 3});
		states[4].insert({"S", {"S", "A"},	 1, 0, nullptr, 4});
		states[4].insert({"A", {"a"},		 0, 4, nullptr, 5});
		states[4].insert({"A", {"a", "a"},	 0, 4, nullptr, 6});

		_complete_parser_tests(
			grammar,
			word,
			states ,
			"S S A a A a A S S A a A a A S \n"
			"S S S A a A S S A a A S S A a A a A S \n"
			"S S S A a A S S A a A a A S S A a A S \n"
			"S S S A a A a A S S A a A S S A a A S \n"
			"S S S S A a A S S A a A S S A a A S S A a A S "

		);
	}

}
