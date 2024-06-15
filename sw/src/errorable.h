#ifndef ERRORABLE_H_
#define ERRORABLE_H_

#include "error.h"

class Errorable
{
	protected:
	
	Errors errors;
	
	std::vector<Errorable*> errorable_components;
	
	
	public:
	
	void add_error(
		const EN_ERROR_TYPE & type,
		const std::string & description = ""
	);
	
};

typedef std::vector<Error> Errors;

#endif // ERROR_H_