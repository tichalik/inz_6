#include "tst_mod_parser.h"

bool TST_mod_parser::compare_chomsky_grammar(
	const Chomsky_grammar & expected,
	const Chomsky_grammar & real
) const
{
	
	bool same = true;
	if (compare_non_terminals(expected.orig_nonterminals, real.orig_nonterminals) == false)
	{
		same = false;
		std::cout << "different orig_nonterminals: " << std::endl;
	}
	if (compare_non_terminals(expected.orig_terminals, real.orig_terminals) == false)
	{
		same = false;
		std::cout << "different orig_terminals: " << std::endl;
	}
	if (compare_non_terminals(expected.added_nonterminals, real.added_nonterminals) == false)
	{
		same = false;
		std::cout << "different added_nonterminals: " << std::endl;
	}
	if (compare_head(expected.head, real.head) == false)
	{
		same = false;
		std::cout << "different head: " << std::endl;
	}
	
	if (compare_chomsky_rules(expected.orig_rules, real.orig_rules) == false)
	{
		same = false;
		std::cout << "different orig_rules: " << std::endl;
	}
	if (compare_chomsky_rules(expected.added_rules, real.added_rules) == false)
	{
		same = false;
		std::cout << "different added_rules: " << std::endl;
	}
	
	return same;
}

bool TST_mod_parser::compare_chomsky_rule(
	const Chomsky_rule & expected,
	const Chomsky_rule & real
) const
{
	
	bool same = true;
	
	if (expected.LHS != real.LHS)
	{
		same = false;
		std::cout << "different Chomsky_rule::LHS: "
			<< " expected: " << expected.LHS 
			<< " real: " << real.LHS 
			<< std::endl;
	}
	
	
	if (expected.RHS1 != real.RHS1)
	{
		same = false;
		std::cout << "different Chomsky_rule::RHS1: "
			<< " expected: " << expected.RHS1 
			<< " real: " << real.RHS1 
			<< std::endl;
	}
	
	
	if (expected.RHS2 != real.RHS2)
	{
		same = false;
		std::cout << "different Chomsky_rule::RHS2: "
			<< " expected: " << expected.RHS2 
			<< " real: " << real.RHS2 
			<< std::endl;
	}
	
	
	if (expected.source_rules_ids.size() != real.source_rules_ids.size())
	{
		same = false;
		std::cout << "different ::size(): "
			<< " expected: " << expected.source_rules_ids.size() 
			<< " real: " << real.source_rules_ids.size() 
			<< std::endl;
	}
	else
	{
		for (size_t i = 0; i < expected.source_rules_ids.size(); i++)
		{
			if (expected.source_rules_ids[i] != real.source_rules_ids[i])
			{
				same = false;
				std::cout << "different Chomsky_rule::source_rules_ids [" << i << "]: " 
					<< " expected: " << expected.source_rules_ids[i] 
					<< " real: " << real.source_rules_ids[i] 
					<< std::endl;
			}
		}
	}
	
	return same;
}

bool TST_mod_parser::compare_chomsky_rules(
	const Chomsky_rules & expected,
	const Chomsky_rules & real
) const
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
		std::cout << "different ::size(): "
			<< " expected: " << expected.size() 
			<< " real: " << real.size() 
			<< std::endl;
	}
	else
	{
		for (size_t i = 0; i < expected.size(); i++)
		{
			bool local_same = compare_chomsky_rule(expected[i], real[i]);
			same &= local_same;
			if (!local_same)
			{
				std::cout << "different Chomsky_rule[" << i << "]" << std::endl;
			}
		}
	}
	
	return same;
	
}


bool TST_mod_parser::compare_ptable(
	const PTable & expected,
	const PTable & real
) const
{
	bool same = true;
	if (expected.SIZE != real.SIZE)
	{
		same = false;
		std::cout << "different PTable::SIZE: "
			<< " expected: " << expected.SIZE 
			<< " real: " << real.SIZE 
			<< std::endl;
	}
	else
	{
		for (size_t i = 0; i < expected.SIZE; i++)
		{
			for (size_t j = 0; j < expected.SIZE - i; j++)
			{
				PTable_entries exp = expected.tab[i][j];
				PTable_entries rel = real.tab[i][j];
				
				if (exp.size() != rel.size())
				{
					same = false;
					std::cout << "different PTable::tab[" << i << "][" << j << "]::size "
						<< " expected: " << exp.size()
						<< " real: " << rel.size() 
						<< std::endl;
				}
				else 
				{
					for (size_t k=0; k<exp.size(); k++)
					{
						same &= compare_ptable_entry(exp[k], rel[k]);
					}
				}
			}	
		}
	}
	
	return same;
}

bool TST_mod_parser::compare_ptable_entry(
	const PTable_entry & expected,
	const PTable_entry & real
) const
{
	bool same = true;
	
	if (expected.tag != real.tag)
	{
		same = false;
		std::cout << "different PTable_entry::tag: "
			<< " expected: " << expected.tag 
			<< " real: " << real.tag 
			<< std::endl;
	}
	
	if (expected.visited != real.visited)
	{
		same = false;
		std::cout << "different PTable_entry::visited: "
			<< " expected: " << expected.visited 
			<< " real: " << real.visited 
			<< std::endl;
	}
	
	if (expected.children.size() != real.children.size())
	{
		same = false;
		std::cout << "different PTable_entry::children.size(): "
			<< " expected: " << expected.children.size() 
			<< " real: " << real.children.size() 
			<< std::endl;
	}
	else if (expected.children.size() == 2 && real.children.size() == 2)
	{
		same &= compare_ptable_reference(expected.children[0], real.children[0]);
		same &= compare_ptable_reference(expected.children[1], real.children[1]);
	}
	
	return same;
		
}

bool TST_mod_parser::compare_ptable_reference(
	const PTable_reference & expected,
	const PTable_reference & real
) const
{
	bool same = true;
	
	if (expected.x != real.x)
	{
		same = false;
		std::cout << "different PTable_reference::x: "
			<< " expected: " << expected.x 
			<< " real: " << real.x 
			<< std::endl;
	}
	
	if (expected.y != real.y)
	{
		same = false;
		std::cout << "different PTable_reference::x: "
			<< " expected: " << expected.y 
			<< " real: " << real.y 
			<< std::endl;
	}
	
	if (expected.list_index != real.list_index)
	{
		same = false;
		std::cout << "different PTable_reference::x: "
			<< " expected: " << expected.list_index 
			<< " real: " << real.list_index 
			<< std::endl;
	}
			
	return same;
		
}


bool TST_mod_parser::compare_ptrees(
	const PTrees & expected,
	const PTrees & real
) const
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
		std::cout << "different Pa::size(): "
			<< " expected: " << expected.size() 
			<< " real: " << real.size() 
			<< std::endl;
	}
	else
	{
		for (size_t i = 0; i < expected.size(); i++)
		{
			bool local_same = compare_ptree(expected[i], real[i]);
			same &= local_same;
			if (!local_same)
			{
				std::cout << "different PTrees[" << i << "]" << std::endl;
			}
		}
	}
	
	return same;
}
bool TST_mod_parser::compare_ptree(
	const PTree & expected,
	const PTree & real
) const
{
	return compare_pnode(expected.root, real.root);
}
bool TST_mod_parser::compare_pnode(
	const PNode & expected,
	const PNode & real
) const
{
	bool same = true;
	if (expected.tag != real.tag)
	{
		same = false;
		std::cout << "different PNode::tag: "
			<< " expected: " << expected.tag 
			<< " real: " << real.tag 
			<< std::endl;
	}
	
	if (expected.children.size() != real.children.size())
	{
		same = false;
		std::cout << "different PNode::children.size(): "
			<< " expected: " << expected.children.size() 
			<< " real: " << real.children.size() 
			<< std::endl;
	}
	else
	{
		for (size_t i = 0; i < expected.children.size(); i++)
		{
			same &= compare_pnode(expected.children[i], real.children[i]);	
		}
	}
	
	return same;
}