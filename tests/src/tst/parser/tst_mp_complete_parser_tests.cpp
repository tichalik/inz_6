#include "tst_mod_parser.h"


void TST_mod_parser::_complete_parser_tests(
	const Grammar & grammar,
	const Word & word,
	const Errors & expected_errors,
	const PTrees & expected_ptrees
)
{
	Mod_parser parser(grammar, word);
	
	
	bool ok = compare(expected_ptrees, parser.get_parse_trees(), "parse trees");
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
	
	{

		std::vector<std::vector<State >> states1, states2;
		
		State s1;
		s1.rule.LHS = "a";
		s1.rule.RHS.push_back("A");
		s1.rule.RHS.push_back("B");
		s1.rule.RHS.push_back("C");
		s1.rule.RHS.push_back("D");
		s1.pos = 2;
		s1.origin = 4;
		states1.emplace_back();
		states1.back().push_back(s1);

		std::cout << "one state missing " << compare(states1, states2, "states") << std::endl;
	}
	{

		std::vector<std::vector<State >> states1, states2;
		
		State s1;
		s1.rule.LHS = "a";
		s1.rule.RHS.push_back("A");
		s1.rule.RHS.push_back("B");
		s1.rule.RHS.push_back("C");
		s1.rule.RHS.push_back("D");
		s1.pos = 2;
		s1.origin = 4;
		states1.emplace_back();
		states1.back().push_back(s1);


		State s2;
		s2.rule.LHS = "a";
		s2.rule.RHS.push_back("A");
		s2.rule.RHS.push_back("B");
		s2.rule.RHS.push_back("C");
		s2.rule.RHS.push_back("D");
		s2.pos = 2;
		s2.origin = 4;
		states2.emplace_back();
		states2.back().push_back(s2);

		std::cout << "identical states " << compare(states1, states2, "states") << std::endl;
	}
	{

		std::vector<std::vector<State >> states1, states2;
		
		State s1;
		s1.rule.LHS = "a";
		s1.rule.RHS.push_back("A");
		s1.rule.RHS.push_back("B");
		s1.rule.RHS.push_back("C");
		s1.rule.RHS.push_back("D");
		s1.pos = 2;
		s1.origin = 4;
		states1.emplace_back();
		states1.back().push_back(s1);


		State s2;
		s2.rule.LHS = "a";
		s2.rule.RHS.push_back("A");
		s2.rule.RHS.push_back("B");
		s2.rule.RHS.push_back("C");
		s2.rule.RHS.push_back("D");
		s2.pos = 1;
		s2.origin = 4;
		states2.emplace_back();
		states2.back().push_back(s2);

		std::cout << "identical states " << compare(states1, states2, "states") << std::endl;
	}
	{

		std::vector<std::vector<State >> states1, states2;
		
		State s1;
		s1.rule.LHS = "a";
		s1.rule.RHS.push_back("A");
		s1.rule.RHS.push_back("B");
		s1.rule.RHS.push_back("C");
		s1.rule.RHS.push_back("D");
		s1.pos = 2;
		s1.origin = 4;
		states1.emplace_back();
		states1.back().push_back(s1);


		State s2;
		s2.rule.LHS = "a";
		s2.rule.RHS.push_back("A");
		s2.rule.RHS.push_back("B");
		s2.rule.RHS.push_back("different one!!!");
		s2.rule.RHS.push_back("D");
		s2.pos = 2;
		s2.origin = 4;
		states2.emplace_back();
		states2.back().push_back(s2);

		std::cout << "identical states " << compare(states1, states2, "states") << std::endl;
	}

}
