#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>


/** 
 * \brief groups utility methods used in many places
 */
class Utils
{
	public:
	
	/** \brief break string at whitespaces 
	 *
	 * \param input string to be broken
	 * \returns vector of string tokens
	 */
	static std::vector<std::string> vector_from_str(const std::string & input);
	
};

#endif // _UTILS_H_