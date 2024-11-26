#include "tst_mod_parser.h"

void TST_mod_parser::_tst_combine2(
	PNodes & input1,
	PNodes & input2, 
	std::vector<PNodes> & expected
)
{
	std::vector<PNode*> p_input1;
	std::vector<std::vector<PNode*>> p_expected, p_real;
	for (size_t i=0; i<input1.size(); i++)
		p_input1.push_back(&input1[i]);
	for (size_t i=0; i<expected.size(); i++)
	{
		p_expected.emplace_back();
		for (size_t j=0; j<expected[i].size(); j++)
			p_expected.back().push_back(&expected[i][j]);
	}

	SPPF_node sppf_node;
	sppf_node.pnodes = input1;

	Grammar grammar;
	Word word;
	SPPF sppf;
	Mod_parser parser(grammar, word, sppf);
	
	bool ok = compare(p_expected, p_real, "combinations");

	if (ok)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}


}

void TST_mod_parser::tst_combine2()
{

}
