#ifndef HTTP_ADAPTER_H_
#define HTTP_ADAPTER_H_

#include <string>
#include <sstream>
#include <vector>

#include "word.h"
#include "errorable.h"
#include "utils.h"

/** 
 * \brief mediates between a Word and its http representation
 */
class Http_adapter: public Errorable
{
	
	std::string EN_ERROR_TYPE2str(const EN_ERROR_TYPE &error) const;
	
	protected:
	
	std::string error_to_http(const Error & error) const;
	std::string errors_to_http(const Errors & error) const;
	
	public:
	
};

#endif //HTTP_GRAMMAR_ADAPTER_H_