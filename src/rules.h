#ifndef RULES_H
#define RULES_H

#include <map>

#include "utils.h"
#include "symbol.h"


struct Rules: public std::map<Symbol, std::vector<Symbols> > 
{
	std::vector<Symbols> get_rules(const Symbol& LHS) const
	{
		auto it = this->find(LHS);
		if (it!= this->end())
		{
			return (it->second);
		}
		else 
		{
			return {};
		}
	}
};

#endif // RULES_H
