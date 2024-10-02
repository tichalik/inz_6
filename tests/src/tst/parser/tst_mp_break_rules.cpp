#include "tst_mod_parser.h"


void TST_mod_parser::_test_break_rules(
	const Grammar & input_grammar,
	const Chomsky_grammar expected_grammar
)
{
	Grammar dummy;
	Chomskify chomskify(dummy);
	
	chomskify.res_grammar = chomskify.init_res_grammar(input_grammar);
	chomskify.break_rules();
	
	
	bool ok = compare(expected_grammar, chomskify.get_grammar(), "grammar");
	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
}


void TST_mod_parser::test_break_rules()
{
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " rule A -> b c" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Grammar input_grammar;
		input_grammar.terminals.insert("b");
		input_grammar.terminals.insert("c");
		input_grammar.nonterminals.insert("A");
		input_grammar.head  = "A";
		
		Rule rule;
		rule.LHS = "A";
		rule.RHS.push_back("b");
		rule.RHS.push_back("c");
		
		input_grammar.rules.push_back(rule);
		
		Chomsky_grammar expected_grammar;
		expected_grammar.terminals.insert("b");
		expected_grammar.terminals.insert("c");
		expected_grammar.nonterminals.insert("A");
		expected_grammar.head = "A";
		
		Rule crule;
		crule.LHS = "A";
		crule.RHS.push_back("b");
		crule.RHS.push_back("c");
		
		
		expected_grammar.rules.push_back(crule);
		
		_test_break_rules(
			input_grammar,
			expected_grammar
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " rule A -> b c d" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Grammar input_grammar;
		input_grammar.terminals.insert("b");
		input_grammar.terminals.insert("c");
		input_grammar.terminals.insert("d");
		input_grammar.nonterminals.insert("A");
		input_grammar.head  = "A";
		
		Rule rule;
		rule.LHS = "A";
		rule.RHS.push_back("b");
		rule.RHS.push_back("c");
		rule.RHS.push_back("d");
		
		input_grammar.rules.push_back(rule);
		
		Chomsky_grammar expected_grammar;
		expected_grammar.terminals.insert("b");
		expected_grammar.terminals.insert("c");
		expected_grammar.terminals.insert("d");
		expected_grammar.nonterminals.insert("A");
		expected_grammar.head = "A";
		
		expected_grammar.added_nonterminals.insert("0");
		
		{
			Rule crule;
			crule.LHS = "A";
			crule.RHS.push_back("b");
			crule.RHS.push_back("0");
			
			
			expected_grammar.rules.push_back(crule);
		}
		
		{
			Rule crule;
			crule.LHS = "0";
			crule.RHS.push_back("c");
			crule.RHS.push_back("d");
			
			
			expected_grammar.rules.push_back(crule);
		}
		
		
		_test_break_rules(
			input_grammar,
			expected_grammar
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " rule A -> b c d e" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Grammar input_grammar;
		input_grammar.terminals.insert("b");
		input_grammar.terminals.insert("c");
		input_grammar.terminals.insert("d");
		input_grammar.terminals.insert("e");
		input_grammar.nonterminals.insert("A");
		input_grammar.head  = "A";
		
		Rule rule;
		rule.LHS = "A";
		rule.RHS.push_back("b");
		rule.RHS.push_back("c");
		rule.RHS.push_back("d");
		rule.RHS.push_back("e");
		
		input_grammar.rules.push_back(rule);
		
		Chomsky_grammar expected_grammar;
		expected_grammar.terminals.insert("b");
		expected_grammar.terminals.insert("c");
		expected_grammar.terminals.insert("d");
		expected_grammar.terminals.insert("e");
		expected_grammar.nonterminals.insert("A");
		expected_grammar.head = "A";
		
		expected_grammar.added_nonterminals.insert("0");
		expected_grammar.added_nonterminals.insert("1");
		
		{
			Rule crule;
			crule.LHS = "A";
			crule.RHS.push_back("b");
			crule.RHS.push_back("0");
			
			
			expected_grammar.rules.push_back(crule);
		}
		
		{
			Rule crule;
			crule.LHS = "0";
			crule.RHS.push_back("c");
			crule.RHS.push_back("1");
			
			
			expected_grammar.rules.push_back(crule);
		}
		
		{
			Rule crule;
			crule.LHS = "1";
			crule.RHS.push_back("d");
			crule.RHS.push_back("e");
			
			
			expected_grammar.rules.push_back(crule);
		}
		
		
		_test_break_rules(
			input_grammar,
			expected_grammar
		);
	}

	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " problematic html grammar " << std::endl;
		std::cout << " terminals: " << std::endl;
		std::cout << "    < > \" = a / " << std::endl;
		std::cout << " nonterminals: " << std::endl;
		std::cout << "    TAG NAME PROPERTY PROPERTIES " << std::endl;
		std::cout << " rules: " << std::endl;
		std::cout << "    TAG -> < NAME > " << std::endl;
		std::cout << "    TAG -> < / NAME > " << std::endl;
		std::cout << "    TAG -> < NAME PROPERTY > " << std::endl;
		std::cout << "    TAG -> < NAME PROPERTIES > " << std::endl;
		std::cout << "    PROPERTIES -> PROPERTY PROPERTY " << std::endl;
		std::cout << "    PROPERTIES -> PROPERTIES PROPERTY " << std::endl;
		std::cout << "    PROPERTY -> NAME = \" NAME \" " << std::endl;
		std::cout << "    NAME -> a a " << std::endl;
		std::cout << "    NAME -> NAME a " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Grammar input_grammar;
		
		input_grammar.terminals.insert("<");
		input_grammar.terminals.insert(">");
		input_grammar.terminals.insert("\"");
		input_grammar.terminals.insert("=");
		input_grammar.terminals.insert("a");
		input_grammar.terminals.insert("/");
		
		input_grammar.nonterminals.insert("TAG");
		input_grammar.nonterminals.insert("NAME");
		input_grammar.nonterminals.insert("PROPERTY");
		input_grammar.nonterminals.insert("PROPERTIES");
		
		input_grammar.head  = "TAG";
				
		{
				Rule rule;
				rule.LHS = "TAG";
				rule.RHS.push_back("<");
				rule.RHS.push_back("NAME");
				rule.RHS.push_back(">");
				input_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "TAG";
				rule.RHS.push_back("<");
				rule.RHS.push_back("/");
				rule.RHS.push_back("NAME");
				rule.RHS.push_back(">");
				input_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "TAG";
				rule.RHS.push_back("<");
				rule.RHS.push_back("NAME");
				rule.RHS.push_back("PROPERTY");
				rule.RHS.push_back(">");
				input_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "TAG";
				rule.RHS.push_back("<");
				rule.RHS.push_back("NAME");
				rule.RHS.push_back("PROPERTIES");
				rule.RHS.push_back(">");
				input_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "PROPERTIES";
				rule.RHS.push_back("PROPERTY");
				rule.RHS.push_back("PROPERTY");
				input_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "PROPERTIES";
				rule.RHS.push_back("PROPERTIES");
				rule.RHS.push_back("PROPERTY");
				input_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "PROPERTY";
				rule.RHS.push_back("NAME");
				rule.RHS.push_back("=");
				rule.RHS.push_back("\"");
				rule.RHS.push_back("NAME");
				rule.RHS.push_back("\"");
				input_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "NAME";
				rule.RHS.push_back("a");
				rule.RHS.push_back("a");
				input_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "NAME";
				rule.RHS.push_back("NAME");
				rule.RHS.push_back("a");
				input_grammar.rules.push_back(rule);
		}

		Chomsky_grammar expected_grammar;

		expected_grammar.terminals.insert("<");
		expected_grammar.terminals.insert(">");
		expected_grammar.terminals.insert("\"");
		expected_grammar.terminals.insert("=");
		expected_grammar.terminals.insert("a");
		expected_grammar.terminals.insert("/");
		
		expected_grammar.nonterminals.insert("TAG");
		expected_grammar.nonterminals.insert("NAME");
		expected_grammar.nonterminals.insert("PROPERTY");
		expected_grammar.nonterminals.insert("PROPERTIES");
		
		expected_grammar.head  = "TAG";
				
		expected_grammar.added_nonterminals.insert("0");
		expected_grammar.added_nonterminals.insert("1");
		expected_grammar.added_nonterminals.insert("2");
		expected_grammar.added_nonterminals.insert("3");
		expected_grammar.added_nonterminals.insert("4");
		expected_grammar.added_nonterminals.insert("5");
		expected_grammar.added_nonterminals.insert("6");
		expected_grammar.added_nonterminals.insert("7");
		expected_grammar.added_nonterminals.insert("8");
		expected_grammar.added_nonterminals.insert("9");
		
				
		{
				Rule rule;
				rule.LHS = "TAG";
				rule.RHS.push_back("<");
				rule.RHS.push_back("0");
				expected_grammar.rules.push_back(rule);
		}
		{
				Rule rule;
				rule.LHS = "0";
				rule.RHS.push_back("NAME");
				rule.RHS.push_back(">");
				expected_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "TAG";
				rule.RHS.push_back("<");
				rule.RHS.push_back("1");
				expected_grammar.rules.push_back(rule);
		}
		{
				Rule rule;
				rule.LHS = "1";
				rule.RHS.push_back("/");
				rule.RHS.push_back("2");
				expected_grammar.rules.push_back(rule);
		}
		{
				Rule rule;
				rule.LHS = "2";
				rule.RHS.push_back("NAME");
				rule.RHS.push_back(">");
				expected_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "TAG";
				rule.RHS.push_back("<");
				rule.RHS.push_back("3");
				expected_grammar.rules.push_back(rule);
		}
		{
				Rule rule;
				rule.LHS = "3";
				rule.RHS.push_back("NAME");
				rule.RHS.push_back("4");
				expected_grammar.rules.push_back(rule);
		}
		{
				Rule rule;
				rule.LHS = "4";
				rule.RHS.push_back("PROPERTY");
				rule.RHS.push_back(">");
				expected_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "TAG";
				rule.RHS.push_back("<");
				rule.RHS.push_back("5");
				expected_grammar.rules.push_back(rule);
		}
		{
				Rule rule;
				rule.LHS = "5";
				rule.RHS.push_back("NAME");
				rule.RHS.push_back("6");
				expected_grammar.rules.push_back(rule);
		}
		{
				Rule rule;
				rule.LHS = "6";
				rule.RHS.push_back("PROPERTIES");
				rule.RHS.push_back(">");
				expected_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "PROPERTIES";
				rule.RHS.push_back("PROPERTY");
				rule.RHS.push_back("PROPERTY");
				expected_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "PROPERTIES";
				rule.RHS.push_back("PROPERTIES");
				rule.RHS.push_back("PROPERTY");
				expected_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "PROPERTY";
				rule.RHS.push_back("NAME");
				rule.RHS.push_back("7");
				expected_grammar.rules.push_back(rule);
		}
		{
				Rule rule;
				rule.LHS = "7";
				rule.RHS.push_back("=");
				rule.RHS.push_back("8");
				expected_grammar.rules.push_back(rule);
		}
		{
				Rule rule;
				rule.LHS = "8";
				rule.RHS.push_back("\"");
				rule.RHS.push_back("9");
				expected_grammar.rules.push_back(rule);
		}
		{
				Rule rule;
				rule.LHS = "9";
				rule.RHS.push_back("NAME");
				rule.RHS.push_back("\"");
				expected_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "NAME";
				rule.RHS.push_back("a");
				rule.RHS.push_back("a");
				expected_grammar.rules.push_back(rule);
		}

		{
				Rule rule;
				rule.LHS = "NAME";
				rule.RHS.push_back("NAME");
				rule.RHS.push_back("a");
				expected_grammar.rules.push_back(rule);
		}
		
		_test_break_rules(
			input_grammar,
			expected_grammar
		);
	}


}


