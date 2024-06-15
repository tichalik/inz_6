#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <vector>
#include <sstream>

#include "errorable.h"

#include "symbol.h"
#include "non_terminals.h"

class Word: public Errorable
{
	std::vector<Symbol> symbols;
	
public:
	std::string to_string();
	
	Word(const std::vector<Symbol> & _symbols):
		symbols(_symbols){};
	
	std::vector<Symbol> get_symbols() const;
	
	Word(){};
	
	void check_errors(
		const Non_terminals & terminals,
		const Non_terminals & nonterminals
	);
	
	bool has_errors() const;

};

#endif // WORD_H_
