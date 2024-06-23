#include "tst_mod_from_http.h"

void TST_mod_from_http::_test_word_from_http(
	const std::string & str_input,
	const Word & expected,
	const Errors & expected_errors
)
{
	//create the class whose method will be tested
	//initialize it with all empty strings
	Mod_from_http mod_from_http(
		"",
		"",
		"",
		"",
		""
	);

	
	//mod_from_http extracted Grammar and Word from empty strings 
	//leaving errors in mod_check_errors.errors. Thes results are ignored
	mod_from_http.errors.clean();
	
	//perform the conversion
	Word result = mod_from_http.word_from_http(str_input);
	
	//check if the result is identical to expected
	bool ok_result = compare_word(expected, result)
	
	//check if obtained errors are identical to expected 
	bool ok_errors = compare_errors(expected_errors, mod_check_errors.errors);
	if (ok_errors && ok_result)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
	
}


void TST_mod_from_http::test_word_from_http()
{
	Errors no_errors;
	
	Errors empty_word;

	Error error1;
	error1.type = EMPTY_WORD;
	error1.source = "";
	empty_word.push_back(error1);
	
	Word expected_word;
	expected_word.push_back("aaaa");
	expected_word.push_back("a");
	expected_word.push_back("c");
	expected_word.push_back("b");
	expected_word.push_back("b");
	expected_word.push_back("c");
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal word -- single spaces separate symbols  " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_word_from_http(
			"aaaa a c b b c",
			expected_word,
			no_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal word -- leading whitespace  " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_word_from_http(
			"\n\n\n   \t    \n aaaa a c b b c",
			expected_word,
			no_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal word -- trainling whitespace" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_word_from_http(
			"aaaa a c b b c\n\n\n\n\t\t    \n  ",
			expected_word,
			no_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal word -- whitespace in between" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_word_from_http(
			"aaaa a\nc\tb  \t \n  b c",
			expected_word,
			no_errors
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty field --completely empty" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_word_from_http(
			"",
			expected_word,
			empty_word
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty field -- whitespaces" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_word_from_http(
			"\n\n\n        \t\n\t   \t \n",
			expected_word,
			empty_word
		);
	}
	
}