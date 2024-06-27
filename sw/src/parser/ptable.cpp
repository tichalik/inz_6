#include "ptable.h"


PTable::PTable(const Word & word):
	SIZE(word.size()),
	tab(nullptr)
{
	//initializing the table
    tab = new PTable_entries * [SIZE];
    for (int i=0; i<SIZE; i++)
    {
        tab[i] = new PTable_entries [SIZE-i];
    }

    //filling the first row
    for (int i=0; i<SIZE; i++)
    {
        PTable_entry pnode;
        pnode.tag = word[i];

        tab[0][i].push_back(pnode);
    }

}

PTable::~PTable()
{
	
    //clearing the table
    for (int i=0; i<SIZE; i++)
    {
        delete [] tab[i];
    }

    delete [] tab;
}
