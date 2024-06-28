#include "tst_mod_parser.h"


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

