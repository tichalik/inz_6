#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <vector>
#include <sstream>

#include "errorable.h"

#include "symbol.h"
#include "non_terminals.h"

struct Word: public Errorable
{
	std::vector<Symbol> symbols;
	
	std::string to_string();
	
	Word(const std::vector<Symbol> & _symbols):
		symbols(_symbols){};
	
	std::vector<Symbol> get_symbols() const;
	
	Word(){};
	
	Errors get_errors() const;
	

};

#endif // WORD_H_
