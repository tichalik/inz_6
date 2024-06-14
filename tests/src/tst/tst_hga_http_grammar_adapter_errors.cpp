#include "tst_http_grammar_adapter.h"


std::string TST_http_grammar_adapter::error_descs2str(std::vector<Error_desc> errors)
{
	std::string res;
	for (size_t i=0; i<errors.size(); i++)
	{
		res += "(" + error2str(errors[i].error) + ", " + errors[i].description + ") ";
	}
	return res;
}


void TST_http_grammar_adapter::test_http_grammar_adapter_errors()
{
	std::string str_ok_terminals = "a b c d";
	std::string str_ok_nonterminals = "A B C D";
	std::string str_ok_head = "A";
	std::string str_ok_rules = 
		"A -> B b\n"
		"B -> A C\n"
		"C -> a D\n"
		"D -> c d\n";
		
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " reference -- all fields filled" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			str_ok_terminals,
			str_ok_nonterminals,
			str_ok_head,
			str_ok_rules
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty terminals" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			"",
			str_ok_nonterminals,
			str_ok_head,
			str_ok_rules
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty nonterminals" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			str_ok_terminals,
			"",
			str_ok_head,
			str_ok_rules
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty head" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			str_ok_terminals,
			str_ok_nonterminals,
			"",
			str_ok_rules
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty rules" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			str_ok_terminals,
			str_ok_nonterminals,
			str_ok_head,
			""
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " empty everything" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			"",
			"",
			"",
			""
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
		
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " double head " << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		Http_grammar_adapter http_grammar_adapter (
			str_ok_terminals,
			str_ok_nonterminals,
			"A A A",
			str_ok_rules
		);
		
		// http_grammar_adapter.check_errors();
		
		std::cout << "errors: " << error_descs2str(http_grammar_adapter.errors) << std::endl;
		std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	}
	
	
}
