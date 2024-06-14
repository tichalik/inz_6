#include "word.h"

std::string Word::to_string()
{
	std::string res;
	for (int i=0; i<this->size(); i++)
	{
		res += this->at(i).symbol + "> <";
	}
	res = res.substr(0, res.size() - 3);
	return "<" + res + ">" ;
}

Word::Word(std::initializer_list<std::string> il)
{
	for (auto i: il)
	{
		Symbol s;
		s.symbol = i;
		this->push_back(s);
	}
}

void Word::from_http(const std::string param)
{
	std::stringstream ss;
	ss << param;
	
	std::string s; 
	while (ss >> s)
	{
		Symbol symbol;
		symbol.symbol = s;
		this->push_back(symbol);
	}
}

std::string Word::to_http()
{
	std::string res; 
	for (size_t i=0; i<this->size(); i++)
	{
		res += this->at(i).symbol + " ";
	}
	res = res.substr(0, res.size()-1);
	
	return res;
}
