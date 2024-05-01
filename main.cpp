#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "grammar.h"

typedef std::vector<std::string> Word;

struct PNode
{
    Symbol tag;
    //cant have normal, non-pointer value cause it will make endless loops
    //we assume it can have either 0 or 2 children
    std::vector<PNode> children;

    std::string toString() const
    {
        if (children.size() == 0 )
            return tag;
        else
            return tag + "[" + children[0].toString() + " " + children[1].toString() + "]";
    }
};

struct PTree
{
    PNode root;

    std::string toString() const
    {
        return root.toString();
    }
};

typedef std::vector<PTree> PTrees;


std::string word2str(const Word &w)
{
    std::string res;
    for (int i=0; i<w.size(); i++)
        res += w[i] + " ";
    return res;
}


typedef std::vector<PNode> PNodes;

// int pnodesCount = 0;

// struct PNodes
// {
  // PNodes()
  // {
    // std::cout << "creating pnode" <<std::endl;
    // pnodesCount++;
  // }
  // ~PNodes()
  // {
    // std::cout << "deleting pnode" <<std::endl;
    // pnodesCount--;
  // }
// };

class Parser
{
    public:

    PTrees parse(const Word & input, const Grammar & g)
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
            pnode.tag = input[i];

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

//                    std::cout << y << "," << x <<"\t->\t" << y1 << "," << x1 << "\t"
//                        << y2 << "," << x2 <<std::endl;



                    //for every combination of pnodes available:
                    for (int i=0; i<matrix[y1][x1].size(); i++)
                    {
                        PNode p1 = matrix[y1][x1][i];
                        for (int j=0; j<matrix[y2][x2].size(); j++)
                        {
                            PNode p2 = matrix[y2][x2][j];

                            if (g.has_rule(p1.tag, p2.tag))
                            {
                                std::vector<Symbol> heads = g.get_rule_head(p1.tag, p2.tag);
                                for (int k=0; k<heads.size(); k++)
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

        for (int i=0; i<matrix[N-1][0].size(); i++)
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

};

int main()
{

	Grammar infix_chomsky_grammar;
	Terminals terminals = {"A","+","-","*","/", "(",")"};
	Nonterminals nonterminals = {"exp","exp1","exp2"};
	Head head = "exp";

	Rules rules = {
		{"exp","exp1", "exp" },
		{"exp","exp2", ")" },
		{"exp","exp2", ")" }, // adding ambiguity

		{"exp1","exp", "+" },
		{"exp1","exp", "-" },
		{"exp1","exp", "*" },
		{"exp1","exp", "/" },

		{"exp2","(", "exp" },
		{"exp3","(", "exp" }  // adding ambiguity
	};

	infix_chomsky_grammar.set_terminals(terminals);
	infix_chomsky_grammar.set_nonterminals(nonterminals);
	infix_chomsky_grammar.set_head(head);
	infix_chomsky_grammar.set_rules(rules);

	std::vector<Word> words = {
		{"exp", "+", "exp"},
		{"(", "exp", "-", "exp", ")"},
		{"exp", "*", "(", "exp", "-", "exp", ")"},
		{"exp", "+", "exp", "*", "(", "exp", "-", "exp", ")"},
	};

    Parser p;
	for (int i=0; i<words.size(); i++)
	{
		std::cout
			<< "-------------------------------------------------------" << std::endl
			<< word2str(words[i]) << std::endl
			<< "-------------------------------------------------------" << std::endl;


		PTrees trees = p.parse(words[i], infix_chomsky_grammar);
		for (int i=0; i<trees.size(); i++)
		{
            std::cout << trees[i].toString() << std::endl;
		}

	}

//     std::cout << pnodesCount <<std::endl;

}
