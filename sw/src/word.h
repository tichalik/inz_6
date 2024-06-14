#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <vector>
#include <sstream>

#include "error.h"
#include "symbol.h"
#include "non_terminals.h"

class Word
{
	std::vector<Symbol> symbols;
	Errors errors;
	
public:
	std::string to_string();
	
	Word(const std::vector<Symbol> & _symbols):
		symbols(_symbols){};
	
	std::vector<Symbol> get_symbols() const;
	
	Word(){};
	
	void check_errors(
		const Non_terminals & terminals
	);
	
	bool has_errors() const;

};

#endif // WORD_H_
