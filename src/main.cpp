#include "http_grammar_adapter.h"


int main()
{
    {
		//simulated http input
		std::string http_input = "a b w c w d";
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			http_input);
			
		std::cout << "input:  <<" << http_input 
			<< ">>\nresult: <<" << http_grammar_adapter.nonterminals_to_http() 
			<< ">>" << std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
	
	{
		//simulated http input
		std::string http_input = "a b w c w d";
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			http_input);
			
		std::cout << http_grammar_adapter.nonterminals_to_http() 
			<< std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
	
	{
		//simulated http input
		std::string http_input = "a b w c w d";
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			http_input);
			
		std::string res = http_grammar_adapter.nonterminals_to_http() ;
		
		std::cout << "input:  <<" << http_input 
			<< ">>\nresult: <<" <<  res
			<< ">>" << std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
	
	{
		//simulated http input
		std::string http_input = "a b w c w d";
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			http_input);
			
		std::string res = http_grammar_adapter.nonterminals_to_http() ;
			
		std::cout << res
			<< std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
	
	

}
