#include "utils.h"

std::vector<std::string> Utils::vector_from_str(const std::string & input)
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
