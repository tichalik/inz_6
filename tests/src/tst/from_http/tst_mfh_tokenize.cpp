#include "tst_mod_from_http.h"

void TST_mod_from_http::_test_tokenize(
	const std::string & str_input,
	const Tokens & expected
)
{
	if(compare(expected, tokenize(str_input), "expected"))
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
		
	
	{
		std::cout << "=============================================================" << std::endl;
		std::cout << " correct input with no spaces: <aaa>aaa::=|\\n  " << std::endl;
		std::cout << "=============================================================" << std::endl;
		
		std::string input = "<aaa>aaa::=|\n";

		Tokens expected;

		{
			Token token;
			token.type = NTERM;
			token.str = "<aaa>";
			token.start_pos = 0;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TERM;
			token.str = "aaa";
			token.start_pos = 5;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = SEP;
			token.str = "::=";
			token.start_pos = 8;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = OR;
			token.str = "|";
			token.start_pos = 11;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = LB;
			token.str = "\n";
			token.start_pos = 12;

			expected.push_back(token);
		}

		_test_tokenize(
			input,
			expected
		);
	}
	

	
	{
		std::cout << "=============================================================" << std::endl;
		std::cout << " correct input with spaces and tabs: <aaa>aaa::=|\\n  " << std::endl;
		std::cout << "=============================================================" << std::endl;
		
		std::string input = "  <aaa>  \taaa ::=    |     \n";

		Tokens expected;

		{
			Token token;
			token.type = NTERM;
			token.str = "<aaa>";
			token.start_pos = 0;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TERM;
			token.str = "aaa";
			token.start_pos = 5;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = SEP;
			token.str = "::=";
			token.start_pos = 8;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = OR;
			token.str = "|";
			token.start_pos = 11;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = LB;
			token.str = "\n";
			token.start_pos = 12;

			expected.push_back(token);
		}

		_test_tokenize(
			input,
			expected
		);
	}
	

}
