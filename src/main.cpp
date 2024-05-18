#include <iostream>
#include <vector>
#include <string>
#include <sstream>



class Http_grammar_adapter
{
	public:
	
	Http_grammar_adapter();
	
	std::string nonterminals_to_http() const;
	
	
};


int main()
{
	
	std::cout << "-----------------------------------------------------" << std::endl;
	{
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter;
			
		std::string res = http_grammar_adapter.nonterminals_to_http() ;
		
		std::cout << "result: <<" << res << ">>" << std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;

}



Http_grammar_adapter::Http_grammar_adapter()
{ 
	
}

std::string Http_grammar_adapter::nonterminals_to_http() const
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
