#include "http_grammar_adapter.h"
#include <iostream>

int main()
{
	std::cout << "--------------chaining << no storing to string------" << std::endl;
    {
		//simulated http input
		std::string http_input = "a b w c w d";
		
		//http adapter -- filling head and rules with dummies
		Http_grammar_adapter http_grammar_adapter(
			http_input);
			
		std::cout << "http_grammar_adapter.nonterminals.symbols:" << std::endl;
		for (size_t i=0; i<http_grammar_adapter.nonterminals.symbols.size(); i++)
		{
			std::cout << "<" << http_grammar_adapter.nonterminals.symbols[i].symbol << "> " ;
		}
		std::cout << std::endl;
		
		std::cout << "http_grammar_adapter.nonterminals.get_symbols:" << std::endl;
		std::vector<Symbol> symbols =http_grammar_adapter.nonterminals.get_symbols();
		for (size_t i=0; i<symbols.size(); i++)
		{
			std::cout << "<" << symbols[i].symbol << "> " ;
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
			
			
		std::cout << "http_grammar_adapter.nonterminals.symbols:" << std::endl;
		for (size_t i=0; i<http_grammar_adapter.nonterminals.symbols.size(); i++)
		{
			std::cout << "<" << http_grammar_adapter.nonterminals.symbols[i].symbol << "> " ;
		}
		std::cout << std::endl;
		
		std::cout << "http_grammar_adapter.nonterminals.get_symbols:" << std::endl;
		std::vector<Symbol> symbols =http_grammar_adapter.nonterminals.get_symbols();
		for (size_t i=0; i<symbols.size(); i++)
		{
			std::cout << "<" << symbols[i].symbol << "> " ;
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
			
			
		std::cout << "http_grammar_adapter.nonterminals.symbols:" << std::endl;
		for (size_t i=0; i<http_grammar_adapter.nonterminals.symbols.size(); i++)
		{
			std::cout << "<" << http_grammar_adapter.nonterminals.symbols[i].symbol << "> " ;
		}
		std::cout << std::endl;
		
		std::cout << "http_grammar_adapter.nonterminals.get_symbols:" << std::endl;
		std::vector<Symbol> symbols =http_grammar_adapter.nonterminals.get_symbols();
		for (size_t i=0; i<symbols.size(); i++)
		{
			std::cout << "<" << symbols[i].symbol << "> " ;
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
			
			
		std::cout << "http_grammar_adapter.nonterminals.symbols:" << std::endl;
		for (size_t i=0; i<http_grammar_adapter.nonterminals.symbols.size(); i++)
		{
			std::cout << "<" << http_grammar_adapter.nonterminals.symbols[i].symbol << "> " ;
		}
		std::cout << std::endl;
		
		std::cout << "http_grammar_adapter.nonterminals.get_symbols:" << std::endl;
		std::vector<Symbol> symbols =http_grammar_adapter.nonterminals.get_symbols();
		for (size_t i=0; i<symbols.size(); i++)
		{
			std::cout << "<" << symbols[i].symbol << "> " ;
		}
		std::cout << std::endl;
			
			
		std::string res = http_grammar_adapter.nonterminals_to_http() ;
			
		std::cout << res
			<< std::endl;
	}
	std::cout << "-----------------------------------------------------" << std::endl;
	
	

}
