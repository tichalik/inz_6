#include <iostream>
#include <vector>
#include <string>
#include <sstream>



struct Symbol
{
	std::string symbol;
	
	inline std::string to_http() const
	{
		return symbol;
	}
};


class Non_terminals 
{
	
public:
	
	
	std::vector<Symbol> symbols;
	
	Non_terminals(const std::vector<std::string> & vect);
	
	Non_terminals();
	
	std::vector<Symbol> get_symbols() const;
	
};


class Http_grammar_adapter
{
	public:
	
	Non_terminals nonterminals;
	
	std::vector<std::string> vector_from_str(const std::string & input);
	
	Http_grammar_adapter(
		const std::string & http_nonterminals);
	
	std::string nonterminals_to_http() const;
	
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



Http_grammar_adapter::Http_grammar_adapter(
	const std::string & http_nonterminals)
{
	// nonterminals_from_http(http_nonterminals);
	std::vector<std::string> str_nonterminals = vector_from_str(http_nonterminals);
	Non_terminals _nonterminals(str_nonterminals);
	this->nonterminals = _nonterminals;
}

std::string Http_grammar_adapter::nonterminals_to_http() const
{
	std::vector<Symbol> symbols = nonterminals.get_symbols();
	
	std::string res;
	for (size_t i; i< symbols.size(); i++)
	{
		res += symbols[i].symbol + " ";
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



Non_terminals::Non_terminals(const std::vector<std::string> & vect)
{
	for (size_t i = 0; i<vect.size(); i++)
	{
		Symbol s;
		s.symbol = vect[i];
		this->symbols.push_back(s);
	}
}
Non_terminals::Non_terminals()
{

}

std::vector<Symbol> Non_terminals::get_symbols() const
{
	return this->symbols;
}
