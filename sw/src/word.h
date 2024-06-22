#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <vector>
#include <sstream>

#include "symbol.h"

struct Word
{
	std::vector<Symbol> symbols;
	
	std::string to_string();
	
	Word(const std::vector<Symbol> & _symbols):
		symbols(_symbols)
	{
		
	}
	
	Word(){};
};

#endif // WORD_H_
