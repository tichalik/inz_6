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

	if (expected_results.size() != sppf.res_pnodes.size())
	{
		ok &= false;
		std::cout << "real " << sppf.res_pnodes.size() << ", expected " << expected_results.size() << std::endl;
	}
	else 
	{
		for (size_t i=0; i<expected_results.size(); i++)
		{
			ok &= compare(expected_results[i], sppf.res_pnodes[i], "result["+str(i,"")+"]");
		}
	}
	

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
}
