#include "mod_parser.h"

void Mod_parser::propagate_parsing_table()
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

                   // std::cout << y << "," << x <<"\t->\t" << y1 << "," << x1 << "\t"
                       // << y2 << "," << x2 <<std::endl;



                //for every combination of pnodes available:
                for (size_t i=0; i<parsing_table.tab[y1][x1].size(); i++)
                {
                    PTable_entry p1 = parsing_table.tab[y1][x1][i];
                    for (size_t j=0; j<parsing_table.tab[y2][x2].size(); j++)
                    {
                        PTable_entry p2 = parsing_table.tab[y2][x2][j];
						
						// std::cout << p1.tag << "," << p2.tag << std::endl;

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

void Mod_parser::extract_trees_from_parsing_table()
{
	
    // PTrees result;

    // for (size_t i=0; i<matrix[N-1][0].size(); i++)
    // {
        // PTree t;
        // t.root = matrix[N-1][0][i];
        // result.push_back(t);
    // }
}

void Mod_parser::translate_table_entry_trees_into_parse_trees()
{
	
}



Mod_parser::Mod_parser(
	const Grammar & grammar,
	const Word & input
):
	parsing_table(input),
	parsing_grammar_adapter(grammar)
{
	propagate_parsing_table();
	extract_trees_from_parsing_table();
	translate_table_entry_trees_into_parse_trees();
}

PTrees Mod_parser::get_parse_trees() const
{
	return this->parse_trees;
}