#include "tst_visualize_grammar.h"
#include "mod_to_http.h"

void _test_visualize(
	const Grammar & grammar
)
{
	Mod_visualize_grammar mvg;
	VNode vnode = mvg.visualize_grammar(grammar, true);
	SPPF sppf;	
	Mod_to_http mth({},sppf, vnode, "","","","","");

	static int count = 0;

	std::stringstream filename;
	filename << "./build/tc_visualize_" << count++ << ".html";
	std::ofstream file;
	file.open(filename.str());
	file << mth.get_http();
	file.close();

}

void test_visualize()
{
	Grammar minut_19_p_1;
	{
		minut_19_p_1.nonterminals.insert("A");
		minut_19_p_1.nonterminals.insert("B");
		minut_19_p_1.nonterminals.insert("C");
		minut_19_p_1.nonterminals.insert("ABC");
		
		minut_19_p_1.terminals.insert("a");
		minut_19_p_1.terminals.insert("b");
		minut_19_p_1.terminals.insert("c");
		
		minut_19_p_1.head = "ABC";
		minut_19_p_1.rules["A"] = {{"a"},{"A","a"}};
		minut_19_p_1.rules["B"] = {{"b"},{"B","b"}};
		minut_19_p_1.rules["C"] = {{"c"},{"C","c"}};
		minut_19_p_1.rules["ABC"] = {{"A","B","C"}};
		
	}
	
	Grammar minut_19_p_2;
	{
		
		minut_19_p_2.nonterminals.insert("A");
		minut_19_p_2.nonterminals.insert("AB");
		minut_19_p_2.nonterminals.insert("ABC");
		
		minut_19_p_2.terminals.insert("a");
		minut_19_p_2.terminals.insert("b");
		minut_19_p_2.terminals.insert("c");
		
		minut_19_p_2.head = "ABC";
		
		minut_19_p_1.rules["A"] = {{"a"},{"A","a"}};
		minut_19_p_1.rules["AB"] = {{"A","b"},{"AB","b"}};
		minut_19_p_1.rules["ABC"] = {{"AB","c"},{"ABC","c"}};
	}
		
	Grammar minut_19_p_3;
	{
		
		minut_19_p_3.nonterminals.insert("C");
		minut_19_p_3.nonterminals.insert("BC");
		minut_19_p_3.nonterminals.insert("ABC");
		
		minut_19_p_3.terminals.insert("a");
		minut_19_p_3.terminals.insert("b");
		minut_19_p_3.terminals.insert("c");
		
		minut_19_p_3.head = "ABC";
		
		
		minut_19_p_1.rules["C"] = {{"c"},{"C","c"}};
		minut_19_p_1.rules["BC"] = {{"b","C"},{"b","BC"}};
		minut_19_p_1.rules["ABC"] = {{"a","BC"},{"a","ABC"}};
	}
				
	std::cout << "===============================================================" << std::endl;
	std::cout << "  minut 19 p 1  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
		_test_visualize(minut_19_p_1);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  minut 19 p 2  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
		_test_visualize(minut_19_p_2);
	}
	
	std::cout << "===============================================================" << std::endl;
	std::cout << "  minut 19 p 3  " << std::endl;
	std::cout << "===============================================================" << std::endl;
	{
			
		_test_visualize(minut_19_p_3);
	}
	
}

