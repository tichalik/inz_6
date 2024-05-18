#include <iostream>
#include <vector>
#include <string>
#include <sstream>


std::string nonterminals_to_http() 
{	
	std::vector<std::string> symbols;

	symbols.push_back("a");
	symbols.push_back("b");
	symbols.push_back("c");
	symbols.push_back("d");
	symbols.push_back("e");
	symbols.push_back("f");

	std::cout << "symbols:" << std::endl;
	for (size_t i=0; i<symbols.size(); i++)
	{
		std::cout << "<" << symbols[i] << "> " ;
	}
	std::cout << std::endl;
		

	std::string res;
	for (size_t i; i< symbols.size(); i++)
	{
		res += symbols[i] + " ";
	}
	
	res = res.substr(0, res.size()-1);
	
	return res ;
}


int main()
{
	
	std::cout << "-----------------------------------------------------" << std::endl;

	std::string res = nonterminals_to_http();
	
	std::cout << "result: <<" << res << ">>" << std::endl;

	std::cout << "-----------------------------------------------------" << std::endl;

}



