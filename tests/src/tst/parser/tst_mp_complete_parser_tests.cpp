#include "tst_mod_parser.h"


void TST_mod_parser::_complete_parser_tests(
	const Grammar & grammar,
	const Word & word,
	const Errors & expected_errors,
	const PTrees & expected_ptrees
)
{
	Mod_parser parser(grammar, word);
	
	
	bool ok = compare(expected_errors, parser.get_errors(), "errors");
	ok &= compare(expected_ptrees, parser.get_parse_trees(), "parse trees");
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
	std::cout << " completely chomsky grammar with no ambiguity " << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << " terminals: a, b, c" << std::endl;
	std::cout << " nonterminals: A, B" << std::endl;
	std::cout << " head: A" << std::endl;
	std::cout << " rules: " << std::endl;
	std::cout << " \tA-> B c" << std::endl;
	std::cout << " \tB-> a b" << std::endl;
	{
		Grammar grammar;
		
		grammar.terminals.insert("a");
		grammar.terminals.insert("b");
		grammar.terminals.insert("c");
		
		grammar.nonterminals.insert("A");
		grammar.nonterminals.insert("B");
		
		grammar.head = "A";
		
		{
			Rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("B");
			rule.RHS.push_back("c");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "B";
			rule.RHS.push_back("a");
			rule.RHS.push_back("b");
			
			grammar.rules.push_back(rule);
		}
		
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << " degraded input -- single symbol " << std::endl;
		std::cout << " word: a" << std::endl;
		{
			
			Word word;
			word.push_back("a");
			
			Errors expected_errors;
			
			PTrees expected_ptrees;
			
			{
				PTree ptree;
				ptree.root.tag = "a";
				
				expected_ptrees.push_back(ptree);
			}
			
			_complete_parser_tests(
				grammar,
				word, 
				expected_errors,
				expected_ptrees
			);
		}
		
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << " correct input " << std::endl;
		std::cout << " word: a b c " << std::endl;
		{
			
			Word word;
			word.push_back("a");
			word.push_back("b");
			word.push_back("c");
			
			Errors expected_errors;
			
			PTrees expected_ptrees;
			
			{
				PNode node0;
				node0.tag = "A";
				
				{
					PNode node1;
					node1.tag = "B";
					
					{
						PNode node2;
						node2.tag = "a";
						
						node1.children.push_back(node2);
					}
					{
						PNode node2;
						node2.tag = "b";
						
						node1.children.push_back(node2);
					}
					
					node0.children.push_back(node1);
				}
				{
					PNode node1;
					node1.tag = "c";
					
					node0.children.push_back(node1);
				}
				
				PTree ptree;
				ptree.root = node0;
				
				expected_ptrees.push_back(ptree);
			}
			
			_complete_parser_tests(
				grammar,
				word, 
				expected_errors,
				expected_ptrees
			);
		}
		
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << " incomplete parse -- wrong word " << std::endl;
		std::cout << " word: a b a " << std::endl;
		{
			
			Word word;
			word.push_back("a");
			word.push_back("b");
			word.push_back("a");
			
			Errors expected_errors;
			
			PTrees expected_ptrees;
			
			{
				PNode node1;
				node1.tag = "B";
				
				{
					PNode node2;
					node2.tag = "a";
					
					node1.children.push_back(node2);
				}
				{
					PNode node2;
					node2.tag = "b";
					
					node1.children.push_back(node2);
				}
				
				PTree ptree;
				ptree.root = node1;
				
				expected_ptrees.push_back(ptree);
			}
			
			{
				PNode node1;
				node1.tag = "a";
				
				PTree ptree;
				ptree.root = node1;
				
				expected_ptrees.push_back(ptree);
			}
			
			_complete_parser_tests(
				grammar,
				word, 
				expected_errors,
				expected_ptrees
			);
		}
	
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << " incomplete parse -- correct parse and then some inputs" << std::endl;
		std::cout << " word: a b c c" << std::endl;
		{
			
			Word word;
			word.push_back("a");
			word.push_back("b");
			word.push_back("c");
			word.push_back("c");
			
			Errors expected_errors;
			
			PTrees expected_ptrees;
			
			{
				PNode node0;
				node0.tag = "A";
				
				{
					PNode node1;
					node1.tag = "B";
					
					{
						PNode node2;
						node2.tag = "a";
						
						node1.children.push_back(node2);
					}
					{
						PNode node2;
						node2.tag = "b";
						
						node1.children.push_back(node2);
					}
					
					node0.children.push_back(node1);
				}
				{
					PNode node1;
					node1.tag = "c";
					
					node0.children.push_back(node1);
				}
				
				PTree ptree;
				ptree.root = node0;
				
				expected_ptrees.push_back(ptree);
			}
			
			{
				PNode node0;
				node0.tag = "c";
								
				PTree ptree;
				ptree.root = node0;
				
				expected_ptrees.push_back(ptree);
			}
			
			_complete_parser_tests(
				grammar,
				word, 
				expected_errors,
				expected_ptrees
			);
		}
		
		std::cout << "===============================================================" << std::endl;
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " completely chomsky grammar with ambiguity " << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << " terminals: a, b, c" << std::endl;
	std::cout << " nonterminals: A, B, C" << std::endl;
	std::cout << " head: A" << std::endl;
	std::cout << " rules: " << std::endl;
	std::cout << " \tA-> B c" << std::endl;
	std::cout << " \tB-> a b" << std::endl;
	std::cout << " \tA-> a C" << std::endl;
	std::cout << " \tC-> b c" << std::endl;
	{
		Grammar grammar;
		
		grammar.terminals.insert("a");
		grammar.terminals.insert("b");
		grammar.terminals.insert("c");
		
		grammar.nonterminals.insert("A");
		grammar.nonterminals.insert("B");
		grammar.nonterminals.insert("C");
		
		grammar.head = "A";
		
		{
			Rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("B");
			rule.RHS.push_back("c");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "B";
			rule.RHS.push_back("a");
			rule.RHS.push_back("b");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("a");
			rule.RHS.push_back("C");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "C";
			rule.RHS.push_back("b");
			rule.RHS.push_back("c");
			
			grammar.rules.push_back(rule);
		}
		
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << " degraded input -- single symbol " << std::endl;
		std::cout << " word: a" << std::endl;
		{
			
			Word word;
			word.push_back("a");
			
			Errors expected_errors;
			
			PTrees expected_ptrees;
			
			{
				PTree ptree;
				ptree.root.tag = "a";
				
				expected_ptrees.push_back(ptree);
			}
			
			_complete_parser_tests(
				grammar,
				word, 
				expected_errors,
				expected_ptrees
			);
		}
		
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << " correct input " << std::endl;
		std::cout << " word: a b c " << std::endl;
		{
			
			Word word;
			word.push_back("a");
			word.push_back("b");
			word.push_back("c");
			
			Errors expected_errors;
			
			PTrees expected_ptrees;
			
			{
				PNode node0;
				node0.tag = "A";
				
				{
					PNode node1;
					node1.tag = "a";
					
					node0.children.push_back(node1);
				}
				{
					PNode node1;
					node1.tag = "C";
					
					{
						PNode node2;
						node2.tag = "b";
						
						node1.children.push_back(node2);
					}
					{
						PNode node2;
						node2.tag = "c";
						
						node1.children.push_back(node2);
					}
					
					node0.children.push_back(node1);
				}
				
				PTree ptree;
				ptree.root = node0;
				
				expected_ptrees.push_back(ptree);
			}
			
			{
				PNode node0;
				node0.tag = "A";
				
				{
					PNode node1;
					node1.tag = "B";
					
					{
						PNode node2;
						node2.tag = "a";
						
						node1.children.push_back(node2);
					}
					{
						PNode node2;
						node2.tag = "b";
						
						node1.children.push_back(node2);
					}
					
					node0.children.push_back(node1);
				}
				{
					PNode node1;
					node1.tag = "c";
					
					node0.children.push_back(node1);
				}
				
				PTree ptree;
				ptree.root = node0;
				
				expected_ptrees.push_back(ptree);
			}
			
			
			_complete_parser_tests(
				grammar,
				word, 
				expected_errors,
				expected_ptrees
			);
		}
		
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << " incomplete parse -- wrong word " << std::endl;
		std::cout << " word: a b a " << std::endl;
		{
			
			Word word;
			word.push_back("a");
			word.push_back("b");
			word.push_back("a");
			
			Errors expected_errors;
			
			PTrees expected_ptrees;
			
			{
				PNode node1;
				node1.tag = "B";
				
				{
					PNode node2;
					node2.tag = "a";
					
					node1.children.push_back(node2);
				}
				{
					PNode node2;
					node2.tag = "b";
					
					node1.children.push_back(node2);
				}
				
				PTree ptree;
				ptree.root = node1;
				
				expected_ptrees.push_back(ptree);
			}
			
			{
				PNode node1;
				node1.tag = "a";
				
				PTree ptree;
				ptree.root = node1;
				
				expected_ptrees.push_back(ptree);
			}
			
			_complete_parser_tests(
				grammar,
				word, 
				expected_errors,
				expected_ptrees
			);
		}
	
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << " incomplete parse -- correct parse and then some inputs" << std::endl;
		std::cout << " word: a b c c" << std::endl;
		{
			
			Word word;
			word.push_back("a");
			word.push_back("b");
			word.push_back("c");
			word.push_back("c");
			
			Errors expected_errors;
			
			PTrees expected_ptrees;
			
			{
				PNode node0;
				node0.tag = "A";
				{
					PNode node1;
					node1.tag = "a";
					
					node0.children.push_back(node1);
				}
				
				{
					PNode node1;
					node1.tag = "C";
					
					{
						PNode node2;
						node2.tag = "b";
						
						node1.children.push_back(node2);
					}
					{
						PNode node2;
						node2.tag = "c";
						
						node1.children.push_back(node2);
					}
					
					node0.children.push_back(node1);
				}
				
				PTree ptree;
				ptree.root = node0;
				
				expected_ptrees.push_back(ptree);
			}
			
			{
				PNode node0;
				node0.tag = "A";
				
				{
					PNode node1;
					node1.tag = "B";
					
					{
						PNode node2;
						node2.tag = "a";
						
						node1.children.push_back(node2);
					}
					{
						PNode node2;
						node2.tag = "b";
						
						node1.children.push_back(node2);
					}
					
					node0.children.push_back(node1);
				}
				{
					PNode node1;
					node1.tag = "c";
					
					node0.children.push_back(node1);
				}
				
				PTree ptree;
				ptree.root = node0;
				
				expected_ptrees.push_back(ptree);
			}
			
			{
				PNode node0;
				node0.tag = "c";
								
				PTree ptree;
				ptree.root = node0;
				
				expected_ptrees.push_back(ptree);
			}
			
			_complete_parser_tests(
				grammar,
				word, 
				expected_errors,
				expected_ptrees
			);
		}
		
		std::cout << "===============================================================" << std::endl;

	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << " grammar with breakable rules with ambiguity" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << " terminals: a, b, c, d, e, f, g, h, i, j" << std::endl;
	std::cout << " nonterminals: A, B, C, D, E" << std::endl;
	std::cout << " head: A" << std::endl;
	std::cout << " rules: " << std::endl;
	std::cout << " \tA-> B C" << std::endl;
	std::cout << " \tA-> B C D" << std::endl;
	std::cout << " \tA-> B C D E" << std::endl;
	std::cout << std::endl;
	std::cout << " \tB-> a b" << std::endl;
	std::cout << " \tB-> a b c" << std::endl;
	std::cout << " \tB-> a b c d" << std::endl;
	std::cout << std::endl;
	std::cout << " \tC-> c d" << std::endl;
	std::cout << " \tC-> c d e " << std::endl;
	std::cout << " \tC-> c d e f" << std::endl;
	std::cout << " \tC-> d e f" << std::endl;
	std::cout << " \tC-> e f" << std::endl;
	std::cout << std::endl;
	std::cout << " \tD-> e f" << std::endl;
	std::cout << " \tD-> e f g" << std::endl;
	std::cout << " \tD-> e f g h" << std::endl;
	std::cout << " \tD-> f g h" << std::endl;
	std::cout << " \tD-> g h" << std::endl;
	std::cout << std::endl;
	std::cout << " \tE-> g h i j " << std::endl;
	std::cout << " \tE-> h i j " << std::endl;
	std::cout << " \tE-> i j " << std::endl;
	{
		Grammar grammar;
		
		grammar.terminals.insert("a");
		grammar.terminals.insert("b");
		grammar.terminals.insert("c");
		grammar.terminals.insert("d");
		grammar.terminals.insert("e");
		grammar.terminals.insert("f");
		grammar.terminals.insert("g");
		grammar.terminals.insert("h");
		grammar.terminals.insert("i");
		grammar.terminals.insert("j");
		
		grammar.nonterminals.insert("A");
		grammar.nonterminals.insert("B");
		grammar.nonterminals.insert("C");
		grammar.nonterminals.insert("D");
		grammar.nonterminals.insert("E");
		
		grammar.head = "A";
		
		{
			Rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("B");
			rule.RHS.push_back("C");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("B");
			rule.RHS.push_back("C");
			rule.RHS.push_back("D");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "A";
			rule.RHS.push_back("B");
			rule.RHS.push_back("C");
			rule.RHS.push_back("D");
			rule.RHS.push_back("E");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "B";
			rule.RHS.push_back("a");
			rule.RHS.push_back("b");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "B";
			rule.RHS.push_back("a");
			rule.RHS.push_back("b");
			rule.RHS.push_back("c");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "B";
			rule.RHS.push_back("a");
			rule.RHS.push_back("b");
			rule.RHS.push_back("c");
			rule.RHS.push_back("d");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "C";
			rule.RHS.push_back("c");
			rule.RHS.push_back("d");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "C";
			rule.RHS.push_back("c");
			rule.RHS.push_back("d");
			rule.RHS.push_back("e");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "C";
			rule.RHS.push_back("c");
			rule.RHS.push_back("d");
			rule.RHS.push_back("e");
			rule.RHS.push_back("f");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "C";
			rule.RHS.push_back("d");
			rule.RHS.push_back("e");
			rule.RHS.push_back("f");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "C";
			rule.RHS.push_back("e");
			rule.RHS.push_back("f");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "D";
			rule.RHS.push_back("e");
			rule.RHS.push_back("f");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "D";
			rule.RHS.push_back("e");
			rule.RHS.push_back("f");
			rule.RHS.push_back("g");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "D";
			rule.RHS.push_back("e");
			rule.RHS.push_back("f");
			rule.RHS.push_back("g");
			rule.RHS.push_back("h");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "D";
			rule.RHS.push_back("f");
			rule.RHS.push_back("g");
			rule.RHS.push_back("h");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "D";
			rule.RHS.push_back("g");
			rule.RHS.push_back("h");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "E";
			rule.RHS.push_back("g");
			rule.RHS.push_back("h");
			rule.RHS.push_back("i");
			rule.RHS.push_back("j");
			
			grammar.rules.push_back(rule);
		}
		
		{
			Rule rule;
			rule.LHS = "E";
			rule.RHS.push_back("h");
			rule.RHS.push_back("i");
			rule.RHS.push_back("j");
			
			grammar.rules.push_back(rule);
		}

		{
			Rule rule;
			rule.LHS = "E";
			rule.RHS.push_back("i");
			rule.RHS.push_back("j");
			
			grammar.rules.push_back(rule);
		}
		
		
		// std::cout << "---------------------------------------------------------------" << std::endl;
		// std::cout << " degraded input -- single symbol " << std::endl;
		// std::cout << " word: a" << std::endl;
		// {
			
			// Word word;
			// word.push_back("a");
			
			// Errors expected_errors;
			
			// PTrees expected_ptrees;
			
			// {
				// PTree ptree;
				// ptree.root.tag = "a";
				
				// expected_ptrees.push_back(ptree);
			// }
			
			// _complete_parser_tests(
				// grammar,
				// word, 
				// expected_errors,
				// expected_ptrees
			// );
		// }
		
		// std::cout << "---------------------------------------------------------------" << std::endl;
		// std::cout << " correct input " << std::endl;
		// std::cout << " word: a b c d e f g h i j " << std::endl;
		// {
			
			// Word word;
			// word.push_back("a");
			// word.push_back("b");
			// word.push_back("c");
			// word.push_back("d");
			// word.push_back("e");
			// word.push_back("f");
			// word.push_back("g");
			// word.push_back("h");
			// word.push_back("i");
			// word.push_back("j");
			
			// Errors expected_errors;
			
			// PTrees expected_ptrees;
			
			// {
				// PNode node0;
				// node0.tag = "A";
				
				// {
					// PNode node1;
					// node1.tag = "a";
					
					// node0.children.push_back(node1);
				// }
				// {
					// PNode node1;
					// node1.tag = "C";
					
					// {
						// PNode node2;
						// node2.tag = "b";
						
						// node1.children.push_back(node2);
					// }
					// {
						// PNode node2;
						// node2.tag = "c";
						
						// node1.children.push_back(node2);
					// }
					
					// node0.children.push_back(node1);
				// }
				
				// PTree ptree;
				// ptree.root = node0;
				
				// expected_ptrees.push_back(ptree);
			// }
			
			// {
				// PNode node0;
				// node0.tag = "A";
				
				// {
					// PNode node1;
					// node1.tag = "B";
					
					// {
						// PNode node2;
						// node2.tag = "a";
						
						// node1.children.push_back(node2);
					// }
					// {
						// PNode node2;
						// node2.tag = "b";
						
						// node1.children.push_back(node2);
					// }
					
					// node0.children.push_back(node1);
				// }
				// {
					// PNode node1;
					// node1.tag = "c";
					
					// node0.children.push_back(node1);
				// }
				
				// PTree ptree;
				// ptree.root = node0;
				
				// expected_ptrees.push_back(ptree);
			// }
			
			
			// _complete_parser_tests(
				// grammar,
				// word, 
				// expected_errors,
				// expected_ptrees
			// );
		// }
		
		// // std::cout << "---------------------------------------------------------------" << std::endl;
		// // std::cout << " incomplete parse -- wrong word " << std::endl;
		// // std::cout << " word: a b a " << std::endl;
		// // {
			
			// // Word word;
			// // word.push_back("a");
			// // word.push_back("b");
			// // word.push_back("a");
			
			// // Errors expected_errors;
			
			// // PTrees expected_ptrees;
			
			// // {
				// // PNode node1;
				// // node1.tag = "B";
				
				// // {
					// // PNode node2;
					// // node2.tag = "a";
					
					// // node1.children.push_back(node2);
				// // }
				// // {
					// // PNode node2;
					// // node2.tag = "b";
					
					// // node1.children.push_back(node2);
				// // }
				
				// // PTree ptree;
				// // ptree.root = node1;
				
				// // expected_ptrees.push_back(ptree);
			// // }
			
			// // {
				// // PNode node1;
				// // node1.tag = "a";
				
				// // PTree ptree;
				// // ptree.root = node1;
				
				// // expected_ptrees.push_back(ptree);
			// // }
			
			// // _complete_parser_tests(
				// // grammar,
				// // word, 
				// // expected_errors,
				// // expected_ptrees
			// // );
		// // }
	
		// // std::cout << "---------------------------------------------------------------" << std::endl;
		// // std::cout << " incomplete parse -- correct parse and then some inputs" << std::endl;
		// // std::cout << " word: a b c c" << std::endl;
		// // {
			
			// // Word word;
			// // word.push_back("a");
			// // word.push_back("b");
			// // word.push_back("c");
			// // word.push_back("c");
			
			// // Errors expected_errors;
			
			// // PTrees expected_ptrees;
			
			// // {
				// // PNode node0;
				// // node0.tag = "A";
				// // {
					// // PNode node1;
					// // node1.tag = "a";
					
					// // node0.children.push_back(node1);
				// // }
				
				// // {
					// // PNode node1;
					// // node1.tag = "C";
					
					// // {
						// // PNode node2;
						// // node2.tag = "b";
						
						// // node1.children.push_back(node2);
					// // }
					// // {
						// // PNode node2;
						// // node2.tag = "c";
						
						// // node1.children.push_back(node2);
					// // }
					
					// // node0.children.push_back(node1);
				// // }
				
				// // PTree ptree;
				// // ptree.root = node0;
				
				// // expected_ptrees.push_back(ptree);
			// // }
			
			// // {
				// // PNode node0;
				// // node0.tag = "A";
				
				// // {
					// // PNode node1;
					// // node1.tag = "B";
					
					// // {
						// // PNode node2;
						// // node2.tag = "a";
						
						// // node1.children.push_back(node2);
					// // }
					// // {
						// // PNode node2;
						// // node2.tag = "b";
						
						// // node1.children.push_back(node2);
					// // }
					
					// // node0.children.push_back(node1);
				// // }
				// // {
					// // PNode node1;
					// // node1.tag = "c";
					
					// // node0.children.push_back(node1);
				// // }
				
				// // PTree ptree;
				// // ptree.root = node0;
				
				// // expected_ptrees.push_back(ptree);
			// // }
			
			// // {
				// // PNode node0;
				// // node0.tag = "c";
								
				// // PTree ptree;
				// // ptree.root = node0;
				
				// // expected_ptrees.push_back(ptree);
			// // }
			
			// // _complete_parser_tests(
				// // grammar,
				// // word, 
				// // expected_errors,
				// // expected_ptrees
			// // );
		// // }
		
		std::cout << "===============================================================" << std::endl;

	}
	
	
}