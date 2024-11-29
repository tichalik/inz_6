#ifndef TST_MOD_TO_HTTP
#define TST_MOD_TO_HTTP

#include "mod_to_http.h"
#include "tester.h"

class TST_mod_to_http
{
	void _test_sppf_to_string(
		SPPF & sppf,
		const std::string & expected
	);
	void _test_iterate_sppf(
		SPPF & sppf, 
		const std::string & expected
	);
public:

	void test_sppf_to_string();
	void test_iterate_sppf();
};

#endif
