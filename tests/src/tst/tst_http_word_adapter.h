#ifndef TST_HTTP_WORD_ADAPTER_H_
#define TST_HTTP_WORD_ADAPTER_H_

#include "tester.h"
#include "http_word_adapter.h"

class TST_http_word_adapter: public Tester
{
	
	void _test(
		const std::string & str_input,
		const Grammar & grammar
	);
	
public:
	
	void test();
};
#endif
