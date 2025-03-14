#include "tst_html_response.h"

void save_file(const std::string &filename, const std::string &content)
{
	std::ofstream file(filename);
	if (file)
	{
		file << content;
		file.close();
	}
	else
	{
		std::cout << "cannot open file <<" << filename << ">>" << std::endl;
	}
}

void TST_html_reponse::test()
{
	Html_response response;
	
	save_file("html_resp_tests/empty.html", response.get_response());
	
	
	response.fill_response(RESP_FIELDS::HEAD,"TESTING");
	save_file("build/html_response_tests_head_filled.html", response.get_response());
	
	response.fill_response(RESP_FIELDS::TERMINALS,"TESTING");
	save_file("build/html_response_tests_terminals_filled.html", response.get_response());
	
	response.fill_response(RESP_FIELDS::NONTERMINALS,"TESTING");
	save_file("build/html_response_tests_nonterminals_filled.html", response.get_response());
	
	response.fill_response(RESP_FIELDS::RULES,"TESTING");
	save_file("build/html_response_tests_rules_filled.html", response.get_response());
	
	response.fill_response(RESP_FIELDS::INPUT,"TESTING");
	save_file("build/html_response_tests_input_filled.html", response.get_response());
	
	response.reset();
	save_file("build/html_response_tests_reset.html", response.get_response());
	
}
