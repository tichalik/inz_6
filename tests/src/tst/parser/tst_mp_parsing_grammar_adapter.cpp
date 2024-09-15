#include "tst_mod_parser.h"

void TST_mod_parser::_test_parsing_grammar_adapter(
	const Chomsky_grammar & grammar
)
{
	bool ok = true;
	Parsing_grammar_adapter parsing_grammar_adapter(grammar);
	
	for (size_t i=0; i<grammar.rules.size(); i++)
	{
		const Rule r = grammar.rules[i];
		
		//test whether the rule is in the adapter
		
		bool has_rule = parsing_grammar_adapter.has_rule(
			r.RHS[0], r.RHS[1]
		);
		
		if (!has_rule)
		{
			std::cout << "Parsing_grammar_adapter::has_rule() returned false "
				<< " for existing rule no." << i << std::endl;
			ok = false;
		}
		
		//test whether rule's LHS is returned correctly
		std::vector<LHS_and_ID> LHSs = parsing_grammar_adapter.get_rule_head(r.RHS[0], r.RHS[1]);
		bool found = false;
		for (size_t j=0; j<LHSs.size(); j++)
		{
			if (LHSs[j].LHS == r.LHS && LHSs[j].ID == i)
			{
				found = true;
			}
		}
		
		if (!found)
		{
			std::cout << "Parsing_grammar_adapter::get_rule_head() did not return  "
				<< " head for existing rule no. " << i << std::endl;
			ok = false;
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

void TST_mod_parser::test_parsing_grammar_adapter()
{
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " single rule with identical right1 and right2 " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		//only rules matter in parsing 
		Chomsky_grammar grammar;
		
		Rule rule;
		rule.LHS = "a";
		rule.RHS.push_back("A");
		rule.RHS.push_back("A");
		grammar.rules.push_back(rule);
		
		_test_parsing_grammar_adapter(
			grammar
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " single rule with different right1 and right2 " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		//only rules matter in parsing 
		Chomsky_grammar grammar;
		
		Rule rule;
		rule.LHS = "a";
		rule.RHS.push_back("A");
		rule.RHS.push_back("B");
		grammar.rules.push_back(rule);
		
		_test_parsing_grammar_adapter(
			grammar
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " two rules with different LHSs and same RHSs" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		//only rules matter in parsing 
		Chomsky_grammar grammar;
		
		{
			Rule rule;
			rule.LHS = "a";
			rule.RHS.push_back("A");
			rule.RHS.push_back("B");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "a";
			rule.RHS.push_back("B");
			rule.RHS.push_back("A");
			grammar.rules.push_back(rule);
		}
		
		_test_parsing_grammar_adapter(
			grammar
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " two rules with different LHSs and RHSs" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		//only rules matter in parsing 
		Chomsky_grammar grammar;
		
		{
			Rule rule;
			rule.LHS = "a";
			rule.RHS.push_back("A");
			rule.RHS.push_back("B");
			grammar.rules.push_back(rule);
		}
		{
			Rule rule;
			rule.LHS = "a";
			rule.RHS.push_back("A");
			rule.RHS.push_back("B");
			grammar.rules.push_back(rule);
		}
		
		_test_parsing_grammar_adapter(
			grammar
		);
	}
	
}