#include "tst_http_grammar_adapter.h"

void TST_http_grammar_adapter::_test_http_grammar_adapter_errors(
	const std::string & str_terminals,
	const std::string & str_nonterminals,
	const std::string & str_head,
	const std::string & str_rules
)
{
	Http_grammar_adapter http_grammar_adapter (
		str_terminals,
		str_nonterminals,
		str_head,
		str_rules
	);
	
	// http_grammar_adapter.check_errors();
	
	std::cout << "errors: " << errors2str(http_grammar_adapter.errors) << std::endl;
	std::cout << "has_errors(): " << http_grammar_adapter.has_errors() << std::endl;
	std::cout << "get_errors: " << errors2str(http_grammar_adapter.get_errors()) << std::endl;
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
		

	std::cout << "===============================================================" << std::endl;
	std::cout << " reference -- all fields filled" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_http_grammar_adapter_errors(
		str_ok_terminals,
		str_ok_nonterminals,
		str_ok_head,
		str_ok_rules
	);

	std::cout << "===============================================================" << std::endl;
	std::cout << " empty terminals" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_http_grammar_adapter_errors(
		"",
		str_ok_nonterminals,
		str_ok_head,
		str_ok_rules
	);

	std::cout << "===============================================================" << std::endl;
	std::cout << " empty nonterminals" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_http_grammar_adapter_errors(
		str_ok_terminals,
		"",
		str_ok_head,
		str_ok_rules
	);

	std::cout << "===============================================================" << std::endl;
	std::cout << " empty head" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_http_grammar_adapter_errors(
		str_ok_terminals,
		str_ok_nonterminals,
		"",
		str_ok_rules
	);

	std::cout << "===============================================================" << std::endl;
	std::cout << " empty rules" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_http_grammar_adapter_errors(
		str_ok_terminals,
		str_ok_nonterminals,
		str_ok_head,
		""
	);

	std::cout << "===============================================================" << std::endl;
	std::cout << " empty everything" << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_http_grammar_adapter_errors(
		"",
		"",
		"",
		""
	);

	std::cout << "===============================================================" << std::endl;
	std::cout << " double head " << std::endl;
	std::cout << "===============================================================" << std::endl;
	
	_test_http_grammar_adapter_errors(
		str_ok_terminals,
		str_ok_nonterminals,
		"A A A",
		str_ok_rules
	);

	
}
