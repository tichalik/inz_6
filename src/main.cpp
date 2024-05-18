#include <iostream>
#include <vector>
#include <string>
#include <sstream>



class Http_grammar_adapter
{
	public:
	
	std::vector<std::string> vector_from_str(const std::string & input);
	
	Http_grammar_adapter(
		const std::string & http_nonterminals);
	
	std::string nonterminals_to_http() const;
	
	std::vector<std::string> symbols;
	
};


int main()
{
	std::cout << "--------------chaining << no storing to string------" << std::endl;
    {
		//simulated http input
		std::string http_input = "a b w c w d";
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			http_input);
			
		std::cout << "http_grammar_adapter.symbols:" << std::endl;
		for (size_t i=0; i<http_grammar_adapter.symbols.size(); i++)
		{
			std::cout << "<" << http_grammar_adapter.symbols[i] << "> " ;
		}
		std::cout << std::endl;
			
			
		std::cout << "input:  <<" << http_input 
			<< ">>\nresult: <<" << http_grammar_adapter.nonterminals_to_http() 
			<< ">>" << std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
	
	std::cout << "--------------single << no storing to string------" << std::endl;
	{
		//simulated http input
		std::string http_input = "a b w c w d";
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			http_input);
			
			
		std::cout << "http_grammar_adapter.symbols:" << std::endl;
		for (size_t i=0; i<http_grammar_adapter.symbols.size(); i++)
		{
			std::cout << "<" << http_grammar_adapter.symbols[i] << "> " ;
		}
		std::cout << std::endl;
			
			
		std::cout << http_grammar_adapter.nonterminals_to_http() 
			<< std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
	
	std::cout << "--------------chaining << storing to string------" << std::endl;
	{
		//simulated http input
		std::string http_input = "a b w c w d";
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			http_input);
			
			
		std::cout << "http_grammar_adapter.symbols:" << std::endl;
		for (size_t i=0; i<http_grammar_adapter.symbols.size(); i++)
		{
			std::cout << "<" << http_grammar_adapter.symbols[i] << "> " ;
		}
		std::cout << std::endl;
			
		std::string res = http_grammar_adapter.nonterminals_to_http() ;
		
		std::cout << "input:  <<" << http_input 
			<< ">>\nresult: <<" <<  res
			<< ">>" << std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
	
	std::cout << "--------------single << storing to string------" << std::endl;
	{
		//simulated http input
		std::string http_input = "a b w c w d";
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			http_input);
			
			
		std::cout << "http_grammar_adapter.symbols:" << std::endl;
		for (size_t i=0; i<http_grammar_adapter.symbols.size(); i++)
		{
			std::cout << "<" << http_grammar_adapter.symbols[i] << "> " ;
		}
		std::cout << std::endl;
		
		std::string res = http_grammar_adapter.nonterminals_to_http() ;
			
		std::cout << res
			<< std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
	
	

}



Http_grammar_adapter::Http_grammar_adapter(
	const std::string & http_nonterminals)
{
	const std::vector<std::string> vect = vector_from_str(http_nonterminals);
	
	for (size_t i = 0; i<vect.size(); i++)
	{
		std::string s;
		s = vect[i];
		this->symbols.push_back(s);
	}
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



std::vector<std::string> Http_grammar_adapter::vector_from_str(const std::string & input)
{
	std::vector<std::string> output;
	std::stringstream ss;
	ss << input;
	
	std::string s; 
	while (ss >> s)
	{
		output.push_back(s);
	}

	return output;
}
