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


std::string Utils::vector2str(const std::vector<std::string> & vect, const std::string& sep)
{
	std::string res; 
	for (size_t i=0; i<vect.size(); i++)
	{
		res += vect[i] + sep;
	}
	res = res.substr(0, res.size()-sep.size());
	
	return res;
}


bool Utils::read_file(const std::string & filename,
	std::string & res)
{
	bool status;
	std::ifstream file(filename);
	if (file)
	{
		std::string line;
		while (std::getline(file, line))
		{
			res += line + "\n";
		}

		file.close();
		status = true;
	}
	else
	{
		std::cout << "cannot open file " << filename << std::endl;
		status = false;
	}

	return status;

}
