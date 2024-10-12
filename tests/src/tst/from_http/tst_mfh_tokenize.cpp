#include "tst_mod_from_http.h"

void TST_mod_from_http::_test_tokenize(
	const std::string & str_input,
	const Tokens & expected
)
{
	if(compare(expected, tokenize(str_input), "tokens"))
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << __FILE__ << "\tFAIL" << std::endl;
	}
}


void TST_mod_from_http::test_tokenize()
{

}
