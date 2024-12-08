#ifndef TESTER_H_
#define TESTER_H_

#include <iostream>


#include "non_terminals.h"
#include "word.h"
#include "error.h"
#include "grammar.h"
#include "sppf.h"

#include "compares.h"


class Tester
{

	void show_word(const Word &w) const ;
	void show_non_terminals(const Non_terminals & nt) const;
	
	std::string rule2str(const Rule & rule) const;
	
public:
	std::string iterate_sppf(SPPF& sppf);	
};
#endif
