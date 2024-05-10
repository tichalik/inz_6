#include "word.h"

std::string Word::to_string()
{
	std::string res;
	for (int i=0; i<this->size(); i++)
	{
		res += this->at(i) + "> <";
	}
	res = res.substr(0, res.size() - 3);
	return "<" + res + ">" ;
}

Word::Word(std::initializer_list<std::string> il): std::vector<std::string>(il)
{
	
}

void Word::from_http(const std::string param)
{
	std::stringstream ss;
	ss << param;
	
	std::string s; 
	while (ss >> s)
	{
		this->push_back(s);
	}
}

std::string Word::to_http()
{
	std::string res; 
	for (size_t i=0; i<this->size(); i++)
	{
		res += this->at(i) + " ";
	}
	res = res.substr(0, res.size()-1);
	
	return res;
}
