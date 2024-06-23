#ifndef TESTER_H_
#define TESTER_H_

#include <iostream>


#include "parser.h"
#include "grammar.h"
#include "word.h"
#include "html_response.h"
#include "error.h"


class Tester
{
	bool compare_error(
		const Error & expected,
		const Error & real
	);
	
	bool compare_errors(
		const Errors & expected,
		const Errors & real
	);
		
	void show_word(const Word &w) const ;
	void show_non_terminals(const Non_terminals & nt) const;
	
		
	std::string error2str(const Error &error) const ;
	std::string error_type2str(const EN_ERROR_TYPE &error) const;
	std::string errors2str(const Errors &errors) const ;
	
public:
	
};
#endif
