#include "mod_parser.h"

void Mod_parser::propagate_parsing_table(
	PTable& parsing_table
)
{
	
    //iterating the matrix from top to bottom
    for (int y=1; y<parsing_table.SIZE; y++)
    {
        //iterating the matrix from left to right
        //the ith row has SIZE-i cells
        for (int x=0; x<parsing_table.SIZE-y; x++)
        {
            //we are at matrix[i][j]

            // a tree with root at matrix[y][x] covers all nodes in range
            // < matrix[0][x], matrix[0][x+y] >
            // we want to decompose  it into 2 trees that cover
            // 1st:  < matrix[0][x], matrix[0][x+_x] >
            // 2nd:  < matrix[0][x+_x+1], matrix[0][x+y]>
            // we want to have the second tree in the form
            // 		< matrix[0][A], matrix[0][A+B]>
            // therefore
            //		A = x+_x+1
            //		A+B = x+y
            //		B = A+B-A = x+y -(x+_x+1) = y-_x-1
            // 2nd': 	< matrix[0][x+_x+1], matrix[0][(x+_x+1)+(y-_x-1)]>
            // the trees have roots at:
            // 1st:
            //	matrix[_x][x]
            // 2nd:
            //	matrix[y-_x-1][x+_x+1]

            //we iterate for _x in range <0, y-1>
            for (int _x=0; _x<y; _x++)
            {

                // matrix[y][x] -> matrix[_x][x] matrix[y-_x-1][x+_x+1]
                // matrix[y][x] -> matrix[y1][x1] matrix[y2][x2]

                int y1 = _x;
                int x1 = x;
                int y2 = y-_x-1;
                int x2 = x+_x+1;

                       // << y2 << "," << x2 <<std::endl;



                //for every combination of pnodes available:
                for (size_t i=0; i<parsing_table.tab[y1][x1].size(); i++)
                {
                    PTable_entry p1 = parsing_table.tab[y1][x1][i];
                    for (size_t j=0; j<parsing_table.tab[y2][x2].size(); j++)
                    {
                        PTable_entry p2 = parsing_table.tab[y2][x2][j];
						

                        if (parsing_grammar_adapter.has_rule(p1.tag, p2.tag))
                        {
                            std::vector<std::string> heads = 
								parsing_grammar_adapter.get_rule_head(p1.tag, p2.tag);
                            for (size_t k=0; k<heads.size(); k++)
                            {
                                PTable_entry pnode;
                                pnode.tag = heads[k];
								
								PTable_reference child1;
								child1.y = y1;
								child1.x = x1;
								child1.list_index = i;
								
								PTable_reference child2;
								child2.y = y2;
								child2.x = x2;
								child2.list_index = j;
								
								
                                pnode.children.push_back(child1);
                                pnode.children.push_back(child2);

                                parsing_table.tab[y][x].push_back(pnode);
                            }
                        }
                    }
                }
            }
        }
    }
}

void Mod_parser::extract_trees_from_parsing_table(
	PTable& parsing_table
)
{

	//iterate the table top-to-bottom
	for (size_t i=parsing_table.SIZE-1; i+1>0; i--) //stupid thing
			//normally should be i>=0
			// but i is of size_t 
			// so it is ALWAYS > 0
			// decrementing beyond 0 just switches it around
			
	{

		for (size_t j=0; j<parsing_table.SIZE-i; j++)
		{

			//for each PTable_entry at given parsing_table index
			for (size_t k=0; k<parsing_table.tab[i][j].size(); k++)
			{

				//nodes not included in any other tree are taken as roots of their own trees
				if (parsing_table.tab[i][j][k].visited == false)
				{

					PTable_reference address;
					address.x = j;
					address.y = i;
					address.list_index = k;
					PTree ptree;
					ptree.root = ptable_entry_to_pnode(parsing_table, address);
					parse_trees.push_back(ptree);
				}
			}
		}
	}
}

PNode Mod_parser::ptable_entry_to_pnode(
	PTable& parsing_table,
	const PTable_reference & address
)
{

	//mark the node as visited, so it won't be the root of a tree
	parsing_table.tab[address.y][address.x][address.list_index].visited = true;

	//copy the tag
	PTable_entry source = parsing_table.tab[address.y][address.x][address.list_index];
	PNode res;
	res.tag = source.tag;

	//extract children of the node
	for (size_t i=0; i<source.children.size(); i++)
	{

		res.children.push_back(ptable_entry_to_pnode(parsing_table,source.children[i]));
	}

	return res;
}



Mod_parser::Mod_parser(
	const Grammar & grammar,
	const Word & input
):
	parsing_grammar_adapter(grammar)
{
	PTable parsing_table(input);
	propagate_parsing_table(parsing_table);

	extract_trees_from_parsing_table(parsing_table);
}

PTrees Mod_parser::get_parse_trees() const
{
	return this->parse_trees;
}