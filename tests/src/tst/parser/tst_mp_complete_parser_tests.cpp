#include "tst_mod_parser.h"


void TST_mod_parser::_complete_parser_tests(
	const Grammar & grammar,
	const Word & word,
	const std::vector<std::list<State>> & expected_states,
	const std::vector<PNode*> & expected_results
)
{
	SPPF sppf;
	Mod_parser parser(grammar, word, sppf);
	
	bool ok = compare(expected_states, parser.states, "parser's states");
//	ok &= compare(expected_results, sppf.res_pnodes,  "results");

	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}

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

		
		std::vector<std::list<State>> states( 4 );
		//states[ 0 ]
		{
			//S -> . S S | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . b | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> S . S | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> . S S | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
			//S -> . b | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> S S . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> S . S | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> S . S | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> . S S | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//S -> . b | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> S S . | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 2;
				state.origin = 1;

				states[3].push_back(state);
			}
			//S -> S S . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 2;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> S . S | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> S . S | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 1;

				states[3].push_back(state);
			}
			//S -> S . S | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> . S S | 3
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//S -> . b | 3
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
		}
		PNodes result_holder(16);

		std::vector<PNode*> results;

		// S[S[S[b] S[b]] S[b]]

		result_holder[0 + 0].tag = "S";
		result_holder[0 + 1].tag = "S";
		result_holder[0 + 2].tag = "S";
		result_holder[0 + 3].tag = "b";
		result_holder[0 + 4].tag = "S";
		result_holder[0 + 5].tag = "b";
		result_holder[0 + 6].tag = "S";
		result_holder[0 + 7].tag = "b";

		result_holder[0 + 0].children.push_back(&result_holder[0 + 1]);
		result_holder[0 + 1].children.push_back(&result_holder[0 + 2]);
		result_holder[0 + 2].children.push_back(&result_holder[0 + 3]);
		result_holder[0 + 1].children.push_back(&result_holder[0 + 4]);
		result_holder[0 + 4].children.push_back(&result_holder[0 + 5]);
		result_holder[0 + 0].children.push_back(&result_holder[0 + 6]);
		result_holder[0 + 6].children.push_back(&result_holder[0 + 7]);

		results.push_back(&result_holder[0]);


		// S[S[b] S[S[b] S[b]]]

		result_holder[8 + 0].tag = "S";
		result_holder[8 + 1].tag = "S";
		result_holder[8 + 2].tag = "b";
		result_holder[8 + 3].tag = "S";
		result_holder[8 + 4].tag = "S";
		result_holder[8 + 5].tag = "b";
		result_holder[8 + 6].tag = "S";
		result_holder[8 + 7].tag = "b";

		result_holder[8 + 0].children.push_back(&result_holder[8 + 1]);
		result_holder[8 + 1].children.push_back(&result_holder[8 + 2]);
		result_holder[8 + 0].children.push_back(&result_holder[8 + 3]);
		result_holder[8 + 3].children.push_back(&result_holder[8 + 4]);
		result_holder[8 + 4].children.push_back(&result_holder[8 + 5]);
		result_holder[8 + 3].children.push_back(&result_holder[8 + 6]);
		result_holder[8 + 6].children.push_back(&result_holder[8 + 7]);

		results.push_back(&result_holder[8]);

		_complete_parser_tests(
			grammar,
			word,
			states,
			results
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

		
		std::vector<std::list<State>> states( 4 );
		//states[ 0 ]
		{
			//S -> . S S | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . b | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> S . S | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> . S S | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
			//S -> . b | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> S S . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> S . S | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> S . S | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> . S S | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//S -> . b | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> S S . | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 2;
				state.origin = 1;

				states[3].push_back(state);
			}
			//S -> S S . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 2;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> S . S | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> S . S | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 1;

				states[3].push_back(state);
			}
			//S -> S . S | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> . S S | 3
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//S -> . b | 3
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("b");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
		}
		
		std::vector<PNode*> results;

		_complete_parser_tests(
			grammar,
			word,
			states,
			results
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
		
		std::vector<std::list<State>> states( 6 );
		//states[ 0 ]
		{
			//P -> . S | 0
			{
				State state;
				state.rule.LHS = "P";
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . S + M | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("+");
				state.rule.RHS.push_back("M");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . M | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("M");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//M -> . M * T | 0
			{
				State state;
				state.rule.LHS = "M";
				state.rule.RHS.push_back("M");
				state.rule.RHS.push_back("*");
				state.rule.RHS.push_back("T");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//M -> . T | 0
			{
				State state;
				state.rule.LHS = "M";
				state.rule.RHS.push_back("T");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//T -> . x | 0
			{
				State state;
				state.rule.LHS = "T";
				state.rule.RHS.push_back("x");
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
				state.rule.LHS = "T";
				state.rule.RHS.push_back("x");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//M -> T . | 0
			{
				State state;
				state.rule.LHS = "M";
				state.rule.RHS.push_back("T");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> M . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("M");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//M -> M . * T | 0
			{
				State state;
				state.rule.LHS = "M";
				state.rule.RHS.push_back("M");
				state.rule.RHS.push_back("*");
				state.rule.RHS.push_back("T");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//P -> S . | 0
			{
				State state;
				state.rule.LHS = "P";
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> S . + M | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("+");
				state.rule.RHS.push_back("M");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("+");
				state.rule.RHS.push_back("M");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//M -> . M * T | 2
			{
				State state;
				state.rule.LHS = "M";
				state.rule.RHS.push_back("M");
				state.rule.RHS.push_back("*");
				state.rule.RHS.push_back("T");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//M -> . T | 2
			{
				State state;
				state.rule.LHS = "M";
				state.rule.RHS.push_back("T");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//T -> . x | 2
			{
				State state;
				state.rule.LHS = "T";
				state.rule.RHS.push_back("x");
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
				state.rule.LHS = "T";
				state.rule.RHS.push_back("x");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//M -> T . | 2
			{
				State state;
				state.rule.LHS = "M";
				state.rule.RHS.push_back("T");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> S + M . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("+");
				state.rule.RHS.push_back("M");
				state.pos = 3;
				state.origin = 0;

				states[3].push_back(state);
			}
			//M -> M . * T | 2
			{
				State state;
				state.rule.LHS = "M";
				state.rule.RHS.push_back("M");
				state.rule.RHS.push_back("*");
				state.rule.RHS.push_back("T");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//P -> S . | 0
			{
				State state;
				state.rule.LHS = "P";
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> S . + M | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("+");
				state.rule.RHS.push_back("M");
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
				state.rule.LHS = "M";
				state.rule.RHS.push_back("M");
				state.rule.RHS.push_back("*");
				state.rule.RHS.push_back("T");
				state.pos = 2;
				state.origin = 2;

				states[4].push_back(state);
			}
			//T -> . x | 4
			{
				State state;
				state.rule.LHS = "T";
				state.rule.RHS.push_back("x");
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
				state.rule.LHS = "T";
				state.rule.RHS.push_back("x");
				state.pos = 1;
				state.origin = 4;

				states[5].push_back(state);
			}
			//M -> M * T . | 2
			{
				State state;
				state.rule.LHS = "M";
				state.rule.RHS.push_back("M");
				state.rule.RHS.push_back("*");
				state.rule.RHS.push_back("T");
				state.pos = 3;
				state.origin = 2;

				states[5].push_back(state);
			}
			//S -> S + M . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("+");
				state.rule.RHS.push_back("M");
				state.pos = 3;
				state.origin = 0;

				states[5].push_back(state);
			}
			//M -> M . * T | 2
			{
				State state;
				state.rule.LHS = "M";
				state.rule.RHS.push_back("M");
				state.rule.RHS.push_back("*");
				state.rule.RHS.push_back("T");
				state.pos = 1;
				state.origin = 2;

				states[5].push_back(state);
			}
			//P -> S . | 0
			{
				State state;
				state.rule.LHS = "P";
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[5].push_back(state);
			}
			//S -> S . + M | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("+");
				state.rule.RHS.push_back("M");
				state.pos = 1;
				state.origin = 0;

				states[5].push_back(state);
			}
		}


		std::vector<PNode*> results;


		_complete_parser_tests(
			grammar,
			word,
			states ,
			results
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
		
		std::vector<std::list<State>> states( 5 );
		//states[ 0 ]
		{
			//S -> . a S | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . a | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> a . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> . a S | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
			//S -> . a | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> a . | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> . a S | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//S -> . a | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//S -> a S . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> a . | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> . a S | 3
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//S -> . a | 3
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//S -> a S . | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 2;
				state.origin = 1;

				states[3].push_back(state);
			}
			//S -> a S . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 1;
				state.origin = 3;

				states[4].push_back(state);
			}
			//S -> a . | 3
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 3;

				states[4].push_back(state);
			}
			//S -> . a S | 4
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
			//S -> . a | 4
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
			//S -> a S . | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 2;
				state.origin = 2;

				states[4].push_back(state);
			}
			//S -> a S . | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 2;
				state.origin = 1;

				states[4].push_back(state);
			}
			//S -> a S . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.pos = 2;
				state.origin = 0;

				states[4].push_back(state);
			}
		}


		std::vector<PNode*> results;

		_complete_parser_tests(
			grammar,
			word,
			states ,
			results
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
		
		std::vector<std::list<State>> states( 5 );
		//states[ 0 ]
		{
			//S -> . S a | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . a | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> S . a | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("a");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("a");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> S . a | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("a");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("a");
				state.pos = 2;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> S . a | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("a");
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
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("a");
				state.pos = 2;
				state.origin = 0;

				states[4].push_back(state);
			}
			//S -> S . a | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[4].push_back(state);
			}
		}

		std::vector<PNode*> results;

		_complete_parser_tests(
			grammar,
			word,
			states ,
			results
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
		
		std::vector<std::list<State>> states( 5 );
		//states[ 0 ]
		{
			//S -> . S A | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("A");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . A | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("A");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//A -> . a | 0
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//A -> . a a | 0
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
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
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//A -> a . a | 0
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> A . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> S . A | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//A -> . a | 1
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
			//A -> . a a | 1
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
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
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//A -> a . | 1
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//A -> a . a | 1
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> A . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> S A . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("A");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> S . A | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[2].push_back(state);
			}
			//A -> . a | 2
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//A -> . a a | 2
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
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
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
				state.pos = 2;
				state.origin = 1;

				states[3].push_back(state);
			}
			//A -> a . | 2
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//A -> a . a | 2
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> S A . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("A");
				state.pos = 2;
				state.origin = 0;

				states[3].push_back(state);
			}
			//S -> S . A | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[3].push_back(state);
			}
			//A -> . a | 3
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//A -> . a a | 3
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
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
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
				state.pos = 2;
				state.origin = 2;

				states[4].push_back(state);
			}
			//A -> a . | 3
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 3;

				states[4].push_back(state);
			}
			//A -> a . a | 3
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 3;

				states[4].push_back(state);
			}
			//S -> S A . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("A");
				state.pos = 2;
				state.origin = 0;

				states[4].push_back(state);
			}
			//S -> S . A | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[4].push_back(state);
			}
			//A -> . a | 4
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
			//A -> . a a | 4
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
		}


		std::vector<PNode*> results;

		_complete_parser_tests(
			grammar,
			word,
			states ,
			results
		);
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
		
		std::vector<std::list<State>> states( 5 );
		//states[ 0 ]
		{
			//S -> . a S B B | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//S -> . a | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
		}
		//states[ 1 ]
		{
			//S -> a . S B B | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> a . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> . a S B B | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
			//S -> . a | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 1;

				states[1].push_back(state);
			}
		}
		//states[ 2 ]
		{
			//S -> a . S B B | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> a . | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 1;

				states[2].push_back(state);
			}
			//S -> . a S B B | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//S -> . a | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//S -> a S . B B | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 2;
				state.origin = 0;

				states[2].push_back(state);
			}
			//B -> . b | 2
			{
				State state;
				state.rule.LHS = "B";
				state.rule.RHS.push_back("b");
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//B -> . | 2
			{
				State state;
				state.rule.LHS = "B";
				state.pos = 0;
				state.origin = 2;

				states[2].push_back(state);
			}
			//S -> a S B . B | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 3;
				state.origin = 0;

				states[2].push_back(state);
			}
			//S -> a S B B . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 4;
				state.origin = 0;

				states[2].push_back(state);
			}
		}
		//states[ 3 ]
		{
			//S -> a . S B B | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> a . | 2
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 2;

				states[3].push_back(state);
			}
			//S -> . a S B B | 3
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//S -> . a | 3
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//S -> a S . B B | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 2;
				state.origin = 1;

				states[3].push_back(state);
			}
			//B -> . b | 3
			{
				State state;
				state.rule.LHS = "B";
				state.rule.RHS.push_back("b");
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//B -> . | 3
			{
				State state;
				state.rule.LHS = "B";
				state.pos = 0;
				state.origin = 3;

				states[3].push_back(state);
			}
			//S -> a S B . B | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 3;
				state.origin = 1;

				states[3].push_back(state);
			}
			//S -> a S B B . | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 4;
				state.origin = 1;

				states[3].push_back(state);
			}
			//S -> a S . B B | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 2;
				state.origin = 0;

				states[3].push_back(state);
			}
		}
		//states[ 4 ]
		{
			//B -> b . | 3
			{
				State state;
				state.rule.LHS = "B";
				state.rule.RHS.push_back("b");
				state.pos = 1;
				state.origin = 3;

				states[4].push_back(state);
			}
			//S -> a S B . B | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 3;
				state.origin = 1;

				states[4].push_back(state);
			}
			//S -> a S B B . | 1
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 4;
				state.origin = 1;

				states[4].push_back(state);
			}
			//S -> a S B . B | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 3;
				state.origin = 0;

				states[4].push_back(state);
			}
			//B -> . b | 4
			{
				State state;
				state.rule.LHS = "B";
				state.rule.RHS.push_back("b");
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
			//B -> . | 4
			{
				State state;
				state.rule.LHS = "B";
				state.pos = 0;
				state.origin = 4;

				states[4].push_back(state);
			}
			//S -> a S . B B | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 2;
				state.origin = 0;

				states[4].push_back(state);
			}
			//S -> a S B B . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("a");
				state.rule.RHS.push_back("S");
				state.rule.RHS.push_back("B");
				state.rule.RHS.push_back("B");
				state.pos = 4;
				state.origin = 0;

				states[4].push_back(state);
			}
		}


		std::vector<PNode*> results;

		_complete_parser_tests(
			grammar,
			word,
			states ,
			results
		);
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
		
		std::vector<std::list<State>> states( 2 );
		//states[ 0 ]
		{
			//S -> . A | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("A");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//A -> . B | 0
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("B");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//B -> . A | 0
			{
				State state;
				state.rule.LHS = "B";
				state.rule.RHS.push_back("A");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
			//B -> . a | 0
			{
				State state;
				state.rule.LHS = "B";
				state.rule.RHS.push_back("a");
				state.pos = 0;
				state.origin = 0;

				states[0].push_back(state);
			}
		}
		//states[ 1 ]
		{
			//B -> a . | 0
			{
				State state;
				state.rule.LHS = "B";
				state.rule.RHS.push_back("a");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//A -> B . | 0
			{
				State state;
				state.rule.LHS = "A";
				state.rule.RHS.push_back("B");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//S -> A . | 0
			{
				State state;
				state.rule.LHS = "S";
				state.rule.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
			//B -> A . | 0
			{
				State state;
				state.rule.LHS = "B";
				state.rule.RHS.push_back("A");
				state.pos = 1;
				state.origin = 0;

				states[1].push_back(state);
			}
		}


		std::vector<PNode*> results;


		_complete_parser_tests(
			grammar,
			word,
			states,
			results
		);
	}

}  
