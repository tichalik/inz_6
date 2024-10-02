#include "tester.h"

std::string Tester::rule2str(const Rule & rule) const
{
	return rule.to_string();
}



void Tester::show_word(const Word &w) const
{
	for (size_t i=0; i<w.size(); i++)
	{
		std::cout << "<" << w[i]<< ">" << std::endl;
	}
}


void Tester::show_non_terminals(const Non_terminals & nt) const
{
	for (auto i=nt.cbegin(); i!=nt.cend(); i++)
	{
		std::cout << "<" << (*i) << ">" << std::endl;
	}
}
