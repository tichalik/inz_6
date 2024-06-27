#include "tst_mod_parser.h"

void TST_mod_parser::test_parser()
{

	// Grammar infix_chomsky_grammar;
	// Terminals terminals = {"A","+","-","*","/", "(",")"};
	// Nonterminals nonterminals = {"exp","exp1","exp2"};
	// Head head = "exp";

	// Rules rules = {
		// {"exp","exp1", "exp" },
		// {"exp","exp2", ")" },
		// {"exp","exp2", ")" }, // adding ambiguity

		// {"exp1","exp", "+" },
		// {"exp1","exp", "-" },
		// {"exp1","exp", "*" },
		// {"exp1","exp", "/" },

		// {"exp2","(", "exp" },
		// {"exp3","(", "exp" }  // adding ambiguity
	// };

	// infix_chomsky_grammar.set_terminals(terminals);
	// infix_chomsky_grammar.set_nonterminals(nonterminals);
	// infix_chomsky_grammar.set_head(head);
	// infix_chomsky_grammar.set_rules(rules);

	// std::vector<Word> words = {
		// {"exp", "+", "exp"},
		// {"(", "exp", "-", "exp", ")"},
		// {"exp", "*", "(", "exp", "-", "exp", ")"},
		// {"exp", "+", "exp", "*", "(", "exp", "-", "exp", ")"},
	// };

    // Parser p;
	// for (size_t i=0; i<words.size(); i++)
	// {
		// std::cout
			// << "-------------------------------------------------------" << std::endl
			// << word2str(words[i]) << std::endl
			// << "-------------------------------------------------------" << std::endl;


		// PTrees trees = p.parse(words[i], infix_chomsky_grammar);
		// for (size_t i=0; i<trees.size(); i++)
		// {
            // std::cout << trees[i].to_string() << std::endl;
		// }

	// }
}

