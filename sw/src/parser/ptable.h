#ifndef _PTABLE_H_
#define _PTABLE_H_

#include "word.h"
#include "symbol.h"
#include <vector>

struct PTable_reference
{
	size_t y; // position in the first dimension
	size_t x; // position in the second dimension
	size_t list_index; // position in the list
};
typedef std::vector<PTable_reference>  PTable_references;


struct PTable_entry
{
	Symbol tag;
	size_t rule_id = -1;
	bool visited;
	PTable_references children;
	
	PTable_entry():
		visited(false)
	{}
};

typedef std::vector<PTable_entry> PTable_entries;

struct PTable
{
	size_t SIZE;
	PTable_entries ** tab;
	
	PTable(const Word & word);
		
	~PTable();
};

#endif // _PTABLE_H_

