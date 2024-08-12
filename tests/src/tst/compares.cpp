#include "compares.h"


bool compare_head(
	const Head & expected,
	const Head & real
) 
{
	bool same = true;
	if (expected != real)
	{
		same = false;
		std::cout << "DIFFERENT Head: expected: " 
			<< expected << ", real: " 
			<< real << std::endl;
	}
	
	return same;
}

bool compare_non_terminals(
	const Non_terminals & expected,
	const Non_terminals & real
) 
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
		std::cout << "DIFFERENT Non_terminals::size: expected: " 
			<< expected.size() << ", real: " 
			<< real.size() << std::endl;		
	}
	else 
	{
		for (auto i=expected.cbegin(); i!=expected.cend(); i++)
		{
			if (real.find(*i) == real.end())
			{
				same = false;
				std::cout << "DIFFERENT Non_terminals: missing " 
					<<  (*i)  << std::endl;
			}
		}
	}
	
	return same;
}


bool compare_error(
	const Error & expected,
	const Error & real
)
{
	bool same = true;
	if (expected.type != real.type)
	{
		same = false;
		std::cout << "DIFFERENT Error::type: expected: " 
			<< error_type2str(expected.type) << ", real: " 
			<< error_type2str(real.type) << std::endl;
	}
	
	if (expected.source != real.source)
	{
		same = false;
		std::cout << "DIFFERENT Error::source: expected: " 
			<< expected.source << ", real: " 
			<< real.source << std::endl;
	}
	
	return same;
}

bool compare_errors(
	const Errors & expected,
	const Errors & real
)
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
		std::cout << "DIFFERENT Errors::size: expected: " 
			<< expected.size() << ", real: " 
			<< real.size() << std::endl;		
			
		std::cout << "real errors:" << std::endl;
		for (size_t i=0; i<real.size(); i++)
		{
			std::cout << "[" << i << "]\t" << error2str(real[i]) << std::endl;
		}
	}
	else 
	{
		for (size_t i=0; i<expected.size(); i++)
		{
			same &= compare_error(expected[i], real[i]);
		}
	}
	
	return same;
}



bool compare_rule(
	const Rule & expected,
	const Rule & real
)
{
	bool same = true;
	if (expected.LHS != real.LHS)
	{
		same = false;
		std::cout << "DIFFERENT Rule::LHS: expected: " 
			<< expected.LHS << ", real: " 
			<< real.LHS << std::endl;
	}
	if (expected.RHS.size() != real.RHS.size())
	{
		same = false;
		std::cout << "DIFFERENT Rule.RHS::size: expected: " 
			<< expected.RHS.size() << ", real: " 
			<< real.RHS.size() << std::endl;		
	}
	else 
	{
		for (size_t i=0; i<expected.RHS.size(); i++)
		{
			if (expected.RHS[i] != real.RHS[i])
			{
				same = false;
				std::cout << "DIFFERENT Rule::RHS[" << i <<"]: expected: " 
					<< expected.RHS[i] << ", real: " 
					<< real.RHS[i] << std::endl;
			}
		}
	}
	return same;
}

bool compare_rules(
	const Rules & expected,
	const Rules & real
)
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
		std::cout << "DIFFERENT Rules::size: expected: " 
			<< expected.size() << ", real: " 
			<< real.size() << std::endl;		
	}
	else 
	{
		for (size_t i=0; i<expected.size(); i++)
		{
			same &= compare_rule(expected[i], real[i]);
		}
	}
	
	return same;
}

bool compare_word(
	const Word & expected,
	const Word & real
)
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
		std::cout << "DIFFERENT Word::size: expected: " 
			<< expected.size() << ", real: " 
			<< real.size() << std::endl;		
	}
	else 
	{
		for (size_t i=0; i<expected.size(); i++)
		{
			if (expected[i] != real[i])
			{
				same = false;
				std::cout << "DIFFERENT Word[" << i << "]: expected: " 
					<< expected[i] << ", real: " 
					<< real[i] << std::endl;
			}
		}
	}
	
	return same;
}

bool compare_chomsky_grammar(
	const Chomsky_grammar & expected,
	const Chomsky_grammar & real
)
{
	
	bool same = true;
	if (compare_non_terminals(expected.nonterminals, real.nonterminals) == false)
	{
		same = false;
		std::cout << "different nonterminals: " << std::endl;
	}
	if (compare_non_terminals(expected.terminals, real.terminals) == false)
	{
		same = false;
		std::cout << "different terminals: " << std::endl;
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
	
	if (compare_chomsky_rules(expected.rules, real.rules) == false)
	{
		same = false;
		std::cout << "different rules: " << std::endl;
	}
	if (compare_chomsky_rules(expected.rules, real.rules) == false)
	{
		same = false;
		std::cout << "different rules: " << std::endl;
	}
	
	return same;
}

bool compare_chomsky_rule(
	const Chomsky_rule & expected,
	const Chomsky_rule & real
)
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
	
	
	if (expected.RHS[0] != real.RHS[0])
	{
		same = false;
		std::cout << "different Chomsky_rule::RHS[0]: "
			<< " expected: " << expected.RHS[0] 
			<< " real: " << real.RHS[0] 
			<< std::endl;
	}
	
	
	if (expected.RHS[1] != real.RHS[1])
	{
		same = false;
		std::cout << "different Chomsky_rule::RHS[1]: "
			<< " expected: " << expected.RHS[1] 
			<< " real: " << real.RHS[1] 
			<< std::endl;
	}
	
	if (expected.replaced_symbols.size() != real.replaced_symbols.size())
	{
		same = false;
		std::cout << "different ::size(): "
			<< " expected: " << expected.replaced_symbols.size() 
			<< " real: " << real.replaced_symbols.size() 
			<< std::endl;
	}
	else
	{
		for (size_t i = 0; i < expected.replaced_symbols.size(); i++)
		{
			if (expected.replaced_symbols[i] != real.replaced_symbols[i])
			{
				same = false;
				std::cout << "different Chomsky_rule::replaced_symbols [" << i << "]: " 
					<< " expected: " << expected.replaced_symbols[i] 
					<< " real: " << real.replaced_symbols[i] 
					<< std::endl;
			}
		}
	}
	
	if (expected.cycle_warnings.size() != real.cycle_warnings.size())
	{
		same = false;
		std::cout << "different ::size(): "
			<< " expected: " << expected.cycle_warnings.size() 
			<< " real: " << real.cycle_warnings.size() 
			<< std::endl;
	}
	else
	{
		for (size_t i = 0; i < expected.cycle_warnings.size(); i++)
		{
			if (! compare_cycle_warnigs(expected.cycle_warnings[i], real.cycle_warnings[i]))
			{
				same = false;
				std::cout << "different Chomsky_rule::cycle_warnings [" << i << "]: " 
					<< std::endl;
			}
		}
	}
	
	return same;
}

bool compare_chomsky_rules(
	const Chomsky_rules & expected,
	const Chomsky_rules & real
)
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


bool compare_ptable(
	const PTable & expected,
	const PTable & real
)
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

bool compare_ptable_entry(
	const PTable_entry & expected,
	const PTable_entry & real
)
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

bool compare_cycle_warnigs(
	const Cycle_warning & expected,
	const Cycle_warning & real
)
{
	bool same = true;
	
	if (expected.origin_pos != real.origin_pos)
	{
		same = false;
		std::cout << "different Cycle_warning::origin_pos: "
			<< " expected: " << expected.origin_pos 
			<< " real: " << real.origin_pos 
			<< std::endl;
	}
	
	if (expected.target_pos != real.target_pos)
	{
		same = false;
		std::cout << "different Cycle_warning::target_pos: "
			<< " expected: " << expected.target_pos 
			<< " real: " << real.target_pos 
			<< std::endl;
	}
	
	return same;
		
}

bool compare_ptable_reference(
	const PTable_reference & expected,
	const PTable_reference & real
)
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


bool compare_ptrees(
	const PTrees & expected,
	const PTrees & real
)
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
bool compare_ptree(
	const PTree & expected,
	const PTree & real
)
{
	return compare_pnode(expected.root, real.root);
}
bool compare_pnode(
	const PNode & expected,
	const PNode & real
)
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