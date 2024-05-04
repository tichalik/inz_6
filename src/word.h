#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <vector>
#include <sstream>


class Word: public std::vector<std::string>
{
	const std::string SEPARATOR = " ";
public:
	std::string to_string();
	
	Word(std::initializer_list<std::string> il);
	Word(){};
	
	void from_http(const std::string param);
	std::string to_http();

};

#endif // WORD_H_
