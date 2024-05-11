#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>

class Utils
{
	public:
	
	/** \brief break string at whitespaces 
	 *
	 * \param input string to be broken
	 * \returns vector of string tokens
	 */
	static std::vector<std::string> vector_from_str(const std::string & input);
	
	/** \brief make string from given vector. items are separated by `sep`
	 *
	 */
	static std::string vector2str(const std::vector<std::string> & vect, const std::string& sep);
	
	/** \brief read file
	 *
	 * in case of failure prints an error message
	 *
	 * \param filename path to file, nothing is added to it
	 * \param res output for the file contents
	 * \returns true if successful, false otherwise
	 */
	static bool read_file(const std::string & filename, std::string & res);

};

#endif // _UTILS_H_