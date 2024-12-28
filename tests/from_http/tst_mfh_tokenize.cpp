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
		
		std::string input = "  <aaa>  \taaa ::=    |     \n         ";

		Tokens expected;

		{
			Token token;
			token.type = NTERM;
			token.str = "<aaa>";
			token.start_pos = 2;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TERM;
			token.str = "aaa";
			token.start_pos = 10;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = SEP;
			token.str = "::=";
			token.start_pos = 14;

			expected.push_back(token);
		} 

		{
			Token token;
			token.type = OR;
			token.str = "|";
			token.start_pos = 21;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = LB;
			token.str = "\n";
			token.start_pos = 27;

			expected.push_back(token);
		}

		_test_tokenize(
			input,
			expected
		);
	}
		
	{
		std::cout << "=============================================================" << std::endl;
		std::cout << " correct input with spaces and tabs and escaped line breaks: <aaa>aaa::=|\\n  " << std::endl;
		std::cout << "=============================================================" << std::endl;
		
		std::string input = "\\\n  <aaa>\\  \n  \taaa ::=  \\  \n\\\n  |    \\\n\n\\\n\\\n";

		Tokens expected;

		{
			Token token;
			token.type = NTERM;
			token.str = "<aaa>";
			token.start_pos = 4;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TERM;
			token.str = "aaa";
			token.start_pos = 16;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = SEP;
			token.str = "::=";
			token.start_pos = 20;

			expected.push_back(token);
		} 

		{
			Token token;
			token.type = OR;
			token.str = "|";
			token.start_pos = 33;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = LB;
			token.str = "\n";
			token.start_pos = 40;

			expected.push_back(token);
		}

		_test_tokenize(
			input,
			expected
		);
	}
	
	{
		std::cout << "=============================================================" << std::endl;
		std::cout << " correct input with spaces and tabs and escaped line breaks + \\r <aaa>aaa::=|\\n  " << std::endl;
		std::cout << "=============================================================" << std::endl;
		
		std::string input = "\\\r\n  <aaa>\\  \r\n  \taaa ::=  \\  \r\n\\\r\n  |    \\\r\n\r\n\\\r\n\\\r\n";

		Tokens expected;

		{
			Token token;
			token.type = NTERM;
			token.str = "<aaa>";
			token.start_pos = 5;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TERM;
			token.str = "aaa";
			token.start_pos = 18;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = SEP;
			token.str = "::=";
			token.start_pos = 22;

			expected.push_back(token);
		} 

		{
			Token token;
			token.type = OR;
			token.str = "|";
			token.start_pos = 37;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = LB;
			token.str = "\r\n";
			token.start_pos = 45;

			expected.push_back(token);
		}

		_test_tokenize(
			input,
			expected
		);
	}
	
	{
		std::cout << "=============================================================" << std::endl;
		std::cout << " token errors  " << std::endl;
		std::cout << "=============================================================" << std::endl;
		
		std::string input = "<aa<a> <> . aa|aa \\ : :: :::= :=";

		Tokens expected;

		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = "<";
			token.start_pos = 0;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TERM;
			token.str = "aa";
			token.start_pos = 1;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = NTERM;
			token.str = "<a>";
			token.start_pos = 3;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = "<";
			token.start_pos = 7;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = ">";
			token.start_pos = 8;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = ".";
			token.start_pos = 10;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TERM;
			token.str = "aa";
			token.start_pos = 12;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = OR;
			token.str = "|";
			token.start_pos = 14;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TERM;
			token.str = "aa";
			token.start_pos = 15;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = "\\";
			token.start_pos = 18;

			expected.push_back(token);
		}

		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = ":";
			token.start_pos = 20;

			expected.push_back(token);
		}


		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = ":";
			token.start_pos = 22;

			expected.push_back(token);
		} 


		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = ":";
			token.start_pos = 23;

			expected.push_back(token);
		}


		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = ":";
			token.start_pos = 25;

			expected.push_back(token);
		}


		{
			Token token;
			token.type = SEP;
			token.str = "::=";
			token.start_pos = 26;

			expected.push_back(token);
		}


		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = ":";
			token.start_pos = 30;

			expected.push_back(token);
		}
		{
			Token token;
			token.type = TOKEN_ERROR;
			token.str = "=";
			token.start_pos = 31;

			expected.push_back(token);
		}


		_test_tokenize(
			input,
			expected
		);
	}
	

}
