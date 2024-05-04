#include "word.h"

std::string Word::to_string()
{
	std::string res;
	for (int i=0; i<this->size(); i++)
	{
		res += this->at(i) + SEPARATOR;
	}
	res = res.substr(0, res.size() - SEPARATOR.size());
	return res;
}

Word::Word(std::initializer_list<std::string> il): std::vector<std::string>(il)
{
	
}

void Word::from_http(const std::string param)
{
	
}

std::string Word::to_http()
{
	
}
