#include "errorable.h"


void Errorable::add_error(
	const EN_ERROR_TYPE & type,
	const std::string & description
)
{
	Error error;
	error.type = type;
	error.description = description;
	
	this->errors.push_back(error);
}
