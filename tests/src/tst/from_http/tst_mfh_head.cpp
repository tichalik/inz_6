#include "tst_mod_from_http.h"

void TST_mod_from_http::_test_head_from_http(
	const std::string & str_input,
	const Head & expected,
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
	Head result = mod_from_http.head_from_http(str_input);
	
	//check if the result is identical to expected
	bool ok_result = compare_head(expected, result)
	
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


void TST_mod_from_http::test_head_from_http()
{
	Head expected_head;
	expected_head = "head";
	
	Head empty_head;
	empty_head = "";
	
	Errors empty_errors;
	
	Errors empty_head_errors;
	
	Error error1;
	error1.type = EMPTY_HEAD;
	error1.source = "";
	empty_head_errors.push_back(error1);
	
	
	Errors multiple_head_errors;
	
	Error error3;
	error3.type = MULTIPLE_HEADS;
	error3.source = "";
	multiple_head_errors.push_back(error3);
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal head -- no whitespaces" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_head_from_http(
			"head",
			expected_head,
			empty_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal head -- leading whitespaces" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_head_from_http(
			"             \n\n \t   head",
			expected_head,
			empty_errors
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " normal head -- trailing whitespaces" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_head_from_http(
			"head\n\n         \t\n",
			expected_head,
			empty_errors
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty head -- empty string" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_head_from_http(
			"",
			expected_head,
			empty_head_errors
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty head -- whitespaces" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_head_from_http(
			"\n\n\t            \n\n",
			expected_head,
			empty_head_errors
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " multiple heads" << std::endl;
		std::cout << "===============================================================" << std::endl;
				
		_test_head_from_http(
			"head\n\n         \t\nevil_head\n\nevil_head2\n\n",
			expected_head,
			multiple_head_errors
		);
	}

	
}