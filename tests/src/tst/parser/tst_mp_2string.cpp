#include "tst_mod_parser.h"


std::string TST_mod_parser::ptable2string(
	const PTable & input
)
{
	std::stringstream res;
	
	for (size_t i = 0; i < input.SIZE; i++)
	{
		for (size_t j = 0; j < input.SIZE - i; j++)
		{
			for (size_t k=0; k<input.tab[i][j].size(); k++)
			{
				res << "[" << i << "]"
					<< "[" << j << "]"
					<< "\t" << k << ".\t"
					<< ptable_entry2string(input.tab[i][j][k]) << std::endl;
			}
		}	
	}
	
	return res.str();
}

std::string TST_mod_parser::ptable_entry2string(
	const PTable_entry & input
)
{
	std::stringstream res;
	
	res << "tag: " << input.tag << "\t"
		<< "visited: " << input.visited 
		<< "children: " << std::endl;
		
	for (size_t i=0; i<input.children.size(); i++)
	{
		res << "\t" << ptable_reference2string(input.children[i]) <<std::endl;
	}
	
	return res.str();
}

std::string TST_mod_parser::ptable_reference2string(
	const PTable_reference & input
)
{
	std::stringstream res;
	
	res << "x: " << input.x << "\t"
		<< "y: " << input.y << "\t"
		<< "list_index: " << input.list_index;
	
	return res.str();
}

