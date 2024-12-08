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

std::string Tester::iterate_sppf(SPPF & sppf)
{
	std::string res;

	sppf.start_iteration();

	do
	{
		if (sppf.current_node() != nullptr)
		{
//			std::cout <<  sppf.current_node()->tag + " "<< std::flush;
			res += sppf.current_node()->tag + " ";
		}
		
		SPPF::EN_ITERATION_MOVE move = sppf.next_node();

		while (move != SPPF::EN_ITERATION_MOVE::END)
		{
//			std::cout <<  sppf.current_node()->tag + " " << std::flush;
			if (move == SPPF::EN_ITERATION_MOVE::DOWN_AND_LOOP)
				res += "*";
			res += sppf.current_node()->tag + " ";
			move = sppf.next_node();
		}
		res += "\n";
//		std::cout << "\n";
	} while (sppf.next_tree());

	res.pop_back();

//	std::cout << res <<std::endl;
	return res;
}
