#include <iostream>
#include <vector>
#include <string>
#include <sstream>



class Http_grammar_adapter
{
	public:
	
	std::vector<std::string> get_example_vector();
	
	Http_grammar_adapter();
	
	std::string nonterminals_to_http() const;
	
	std::vector<std::string> symbols;
	
};


int main()
{
	
	std::cout << "--------------chaining << storing to string------" << std::endl;
	{
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter;
			
			
		std::cout << "http_grammar_adapter.symbols:" << std::endl;
		for (size_t i=0; i<http_grammar_adapter.symbols.size(); i++)
		{
			std::cout << "<" << http_grammar_adapter.symbols[i] << "> " ;
		}
		std::cout << std::endl;
			
		std::string res = http_grammar_adapter.nonterminals_to_http() ;
		
		std::cout << "result: <<" << res << ">>" << std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;

}



Http_grammar_adapter::Http_grammar_adapter()
{ 
	this->symbols = get_example_vector();
}

std::string Http_grammar_adapter::nonterminals_to_http() const
{	
	std::string res;
	for (size_t i; i< symbols.size(); i++)
	{
		res += symbols[i] + " ";
	}
	
	res = res.substr(0, res.size()-1);
	
	return res ;
}



std::vector<std::string> Http_grammar_adapter::get_example_vector()
{
	std::vector<std::string> output;
	
	output.push_back("a");
	output.push_back("b");
	output.push_back("c");
	output.push_back("d");
	output.push_back("e");
	output.push_back("f");
	
	return output;
}
