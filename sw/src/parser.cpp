#include "parser.h"

#include <iostream>

PTrees Parser::parse(const Word & input, const Parsing_grammar_adapter & g)
{
    const int N = input.size();

    //initializing the table
    PNodes ** matrix = new PNodes * [N];
    for (int i=0; i<N; i++)
    {
        matrix[i] = new PNodes [N-i];
    }

    //filling the first row
    for (int i=0; i<N; i++)
    {
        PNode pnode;
        pnode.tag = input[i].symbol;

        matrix[0][i].push_back(pnode);
    }

    //parsing

    //iterating the matrix from top to bottom
    for (int y=1; y<N; y++)
    {
        //iterating the matrix from left to right
        //the ith row has N-i cells
        for (int x=0; x<N-y; x++)
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
                for (size_t i=0; i<matrix[y1][x1].size(); i++)
                {
                    PNode p1 = matrix[y1][x1][i];
                    for (size_t j=0; j<matrix[y2][x2].size(); j++)
                    {
                        PNode p2 = matrix[y2][x2][j];
						
						// std::cout << p1.tag << "," << p2.tag << std::endl;

                        if (g.has_rule(p1.tag, p2.tag))
                        {
                            std::vector<std::string> heads = g.get_rule_head(p1.tag, p2.tag);
                            for (size_t k=0; k<heads.size(); k++)
                            {
                                PNode pnode;
                                pnode.tag = heads[k];
                                pnode.children.push_back(p1);
                                pnode.children.push_back(p2);

                                matrix[y][x].push_back(pnode);
                            }
                        }
                    }
                }
            }
        }
    }

    PTrees result;

    for (size_t i=0; i<matrix[N-1][0].size(); i++)
    {
        PTree t;
        t.root = matrix[N-1][0][i];
        result.push_back(t);
    }

    //clearing the table
    for (int i=0; i<N; i++)
    {
        delete [] matrix[i];
    }

    delete [] matrix;

    return result;

}
