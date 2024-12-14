#include "tst_mod_parser.h"


void TST_mod_parser::_complete_parser_tests(
	const Grammar & grammar,
	const Word & word,
	const std::vector<std::list<State>> & expected_states,
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
	{
		Word word;
		word.push_back("b");

		Grammar grammar;
		grammar.terminals.insert("b");
		grammar.nonterminals.insert("S");
		grammar.head = "S";
		grammar.rules ["S"] = {{"S"},{"b"}};
		
		std::vector<std::list<State>> states( 2 );
		//states[ 0 ]
		{
			//S -> . S | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . b | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("b");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
		}
		//states[ 1 ]
		{
			//S -> b . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("b");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> S . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
		}

		_complete_parser_tests(
			grammar,
			word,
			states,
			"S b S \n"
			"S S b S S \n"
			"S *S S "
		);
 	 } 

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
		
		std::vector<std::list<State>> states( 4 );
		//states[ 0 ]
		{
			//S -> . S S | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . b | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("b");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
		}
		//states[ 1 ]
		{
			//S -> b . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("b");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> S . S | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> . S S | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
			//S -> . b | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("b");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
		}
		//states[ 2 ]
		{
			//S -> b . | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("b");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> S S . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> S . S | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> S . S | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> . S S | 2
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//S -> . b | 2
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("b");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
		}
		//states[ 3 ]
		{
			//S -> b . | 2
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("b");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> S S . | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 2;
				state.origin = 1;

				states[3].push_back(state);
			}
			//S -> S S . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 2;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> S . S | 2
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> S . S | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 1;

				states[3].push_back(state);
			}
			//S -> S . S | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> . S S | 3
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//S -> . b | 3
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("b");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
		}
		
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
		
		std::vector<std::list<State>> states( 6 );
		//states[ 0 ]
		{
			//P -> . S | 0
			{
				State state;
				state.LHS = "P";
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . S + M | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("+");
				state.RHS.push_back("M");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . M | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("M");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//M -> . M * T | 0
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("M");
				state.RHS.push_back("*");
				state.RHS.push_back("T");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//M -> . T | 0
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("T");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//T -> . x | 0
			{
				State state;
				state.LHS = "T";
				state.RHS.push_back("x");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
		}
		//states[ 1 ]
		{
			//T -> x . | 0
			{
				State state;
				state.LHS = "T";
				state.RHS.push_back("x");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//M -> T . | 0
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("T");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> M . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("M");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//M -> M . * T | 0
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("M");
				state.RHS.push_back("*");
				state.RHS.push_back("T");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//P -> S . | 0
			{
				State state;
				state.LHS = "P";
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> S . + M | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("+");
				state.RHS.push_back("M");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
		}
		//states[ 2 ]
		{
			//S -> S + . M | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("+");
				state.RHS.push_back("M");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//M -> . M * T | 2
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("M");
				state.RHS.push_back("*");
				state.RHS.push_back("T");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//M -> . T | 2
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("T");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//T -> . x | 2
			{
				State state;
				state.LHS = "T";
				state.RHS.push_back("x");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
		}
		//states[ 3 ]
		{
			//T -> x . | 2
			{
				State state;
				state.LHS = "T";
				state.RHS.push_back("x");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//M -> T . | 2
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("T");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> S + M . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("+");
				state.RHS.push_back("M");
				state.pos = 3;
				state.origin = 0;

				states[3].push_back(state);
			}
			//M -> M . * T | 2
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("M");
				state.RHS.push_back("*");
				state.RHS.push_back("T");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//P -> S . | 0
			{
				State state;
				state.LHS = "P";
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> S . + M | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("+");
				state.RHS.push_back("M");
				state.pos = 1;
				state.origin = 0;

				states[3].push_back(state);
			}
		}
		//states[ 4 ]
		{
			//M -> M * . T | 2
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("M");
				state.RHS.push_back("*");
				state.RHS.push_back("T");
				state.pos = 2;
				state.origin = 2;

				states[4].push_back(state);
			}
			//T -> . x | 4
			{
				State state;
				state.LHS = "T";
				state.RHS.push_back("x");
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
		}
		//states[ 5 ]
		{
			//T -> x . | 4
			{
				State state;
				state.LHS = "T";
				state.RHS.push_back("x");
				state.pos = 1;
				state.origin = 4;

				states[5].push_back(state);
			}
			//M -> M * T . | 2
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("M");
				state.RHS.push_back("*");
				state.RHS.push_back("T");
				state.pos = 3;
				state.origin = 2;

				states[5].push_back(state);
			}
			//S -> S + M . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("+");
				state.RHS.push_back("M");
				state.pos = 3;
				state.origin = 0;

				states[5].push_back(state);
			}
			//M -> M . * T | 2
			{
				State state;
				state.LHS = "M";
				state.RHS.push_back("M");
				state.RHS.push_back("*");
				state.RHS.push_back("T");
				state.pos = 1;
				state.origin = 2;

				states[5].push_back(state);
			}
			//P -> S . | 0
			{
				State state;
				state.LHS = "P";
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[5].push_back(state);
			}
			//S -> S . + M | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("+");
				state.RHS.push_back("M");
				state.pos = 1;
				state.origin = 0;

				states[5].push_back(state);
			}
		}


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
		
		std::vector<std::list<State>> states( 5 );
		//states[ 0 ]
		{
			//S -> . a S | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . a | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
		}
		//states[ 1 ]
		{
			//S -> a . S | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> a . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> . a S | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
			//S -> . a | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
		}
		//states[ 2 ]
		{
			//S -> a . S | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> a . | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> . a S | 2
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//S -> . a | 2
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//S -> a S . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
		}
		//states[ 3 ]
		{
			//S -> a . S | 2
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> a . | 2
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> . a S | 3
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//S -> . a | 3
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//S -> a S . | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 2;
				state.origin = 1;

				states[3].push_back(state);
			}
			//S -> a S . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 2;
				state.origin = 0;

				states[3].push_back(state);
			}
		}
		//states[ 4 ]
		{
			//S -> a . S | 3
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 1;
				state.origin = 3;

				states[4].push_back(state);
			}
			//S -> a . | 3
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 3;

				states[4].push_back(state);
			}
			//S -> . a S | 4
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
			//S -> . a | 4
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
			//S -> a S . | 2
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 2;
				state.origin = 2;

				states[4].push_back(state);
			}
			//S -> a S . | 1
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 2;
				state.origin = 1;

				states[4].push_back(state);
			}
			//S -> a S . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.RHS.push_back("S");
				state.pos = 2;
				state.origin = 0;

				states[4].push_back(state);
			}
		}


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
		
		std::vector<std::list<State>> states( 5 );
		//states[ 0 ]
		{
			//S -> . S a | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . a | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
		}
		//states[ 1 ]
		{
			//S -> a . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> S . a | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
		}
		//states[ 2 ]
		{
			//S -> S a . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("a");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> S . a | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[2].push_back(state);
			}
		}
		//states[ 3 ]
		{
			//S -> S a . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("a");
				state.pos = 2;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> S . a | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[3].push_back(state);
			}
		}
		//states[ 4 ]
		{
			//S -> S a . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("a");
				state.pos = 2;
				state.origin = 0;

				states[4].push_back(state);
			}
			//S -> S . a | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[4].push_back(state);
			}
		}

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
		grammar.rules ["S"] = {{"S","A"},{"a"}};
		grammar.rules ["A"] = {{"a"},{"a","a"}};
		
		std::vector<std::list<State>> states( 5 );
		//states[ 0 ]
		{
			//S -> . S A | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("A");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . A | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("A");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//A -> . a | 0
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//A -> . a a | 0
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
		}
		//states[ 1 ]
		{
			//A -> a . | 0
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//A -> a . a | 0
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> A . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> S . A | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//A -> . a | 1
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
			//A -> . a a | 1
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
		}
		//states[ 2 ]
		{
			//A -> a a . | 0
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//A -> a . | 1
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//A -> a . a | 1
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> A . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> S A . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("A");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> S . A | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[2].push_back(state);
			}
			//A -> . a | 2
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//A -> . a a | 2
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
		}
		//states[ 3 ]
		{
			//A -> a a . | 1
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 2;
				state.origin = 1;

				states[3].push_back(state);
			}
			//A -> a . | 2
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//A -> a . a | 2
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> S A . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("A");
				state.pos = 2;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> S . A | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[3].push_back(state);
			}
			//A -> . a | 3
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//A -> . a a | 3
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
		}
		//states[ 4 ]
		{
			//A -> a a . | 2
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 2;
				state.origin = 2;

				states[4].push_back(state);
			}
			//A -> a . | 3
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 3;

				states[4].push_back(state);
			}
			//A -> a . a | 3
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 1;
				state.origin = 3;

				states[4].push_back(state);
			}
			//S -> S A . | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("A");
				state.pos = 2;
				state.origin = 0;

				states[4].push_back(state);
			}
			//S -> S . A | 0
			{
				State state;
				state.LHS = "S";
				state.RHS.push_back("S");
				state.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[4].push_back(state);
			}
			//A -> . a | 4
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
			//A -> . a a | 4
			{
				State state;
				state.LHS = "A";
				state.RHS.push_back("a");
				state.RHS.push_back("a");
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
		}


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
