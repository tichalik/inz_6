#include "rules.h"


std::vector<Symbols> Rules::get_rules(const Symbol& LHS) const
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