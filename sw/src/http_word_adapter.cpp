#include "http_word_adapter.h"

Http_word_adapter::Http_word_adapter(const std::string & http_word)
{
	std::vector<Symbol> res;
	
	std::stringstream ss;
	ss << http_word;
	
	std::string s; 
	while (ss >> s)
	{
		Symbol symbol;
		symbol.symbol = s;
		res.push_back(symbol);
	}
	
	if (res.size() == 0)
	{
		this->errors.push_back(EMPTY_FIELD);
	}
	
	this->word = Word(res);
}

std::string Http_word_adapter::to_http() const 
{
	std::string res; 
	std::vector<Symbol> symbols = this->word.get_symbols();
	
	for (size_t i=0; i< symbols.size(); i++)
	{
		res += symbols.at(i).symbol + " ";
	}
	res = res.substr(0, res.size()-1);
	
	return res;
}



Word Http_word_adapter::get_word() const
{
	return this->word;
}

bool Http_word_adapter::has_errors() const
{
	return this->errors.size() != 0 
		|| this->word.has_errors();
}