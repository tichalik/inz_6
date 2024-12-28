#ifndef TST_HTTP_TO_ERRORS_H_
#define TST_HTTP_TO_ERRORS_H_

#include "mod_from_http.h"
#include "mod_check_errors.h"
#include "mod_to_http.h"

/**
 * \brief tcs simulating inputing something to the sw and receiving errors
 */
class TST_http_to_errors
{	
	void _test_http_to_errors(
		const std::string & http_nonterminals,
		const std::string & http_terminals,
		const std::string & http_head,
		const std::string & http_rules,
		const std::string & http_word
	);

public:
	void test_http_to_errors();
};

#endif // TST_HTTP_TO_ERRORS_H_
