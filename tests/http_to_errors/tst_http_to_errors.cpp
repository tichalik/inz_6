#include "tst_http_to_errors.h"

void TST_http_to_errors::_test_http_to_errors(
	const std::string & http_nonterminals,
	const std::string & http_terminals,
	const std::string & http_head,
	const std::string & http_rules,
	const std::string & http_word
)
{
	Errors errors;
	SPPF sppf;
	VNode vnode;
	
	//transform http into Grammar and Word
	Mod_from_http mod_from_http(
		http_terminals,
		http_nonterminals,
		http_head,
		http_rules,
		http_word
	);
		
	const Errors http_errors = mod_from_http.get_errors();
	errors.insert(errors.end(), http_errors.begin(), http_errors.end());
	
	const Grammar grammar = mod_from_http.get_grammar();
	const Word word = mod_from_http.get_word();
	
	//check errors
	Mod_check_errors mod_check_errors(
		grammar, 
		word
	);
	
	const Errors semantic_errors = mod_check_errors.get_errors();
	errors.insert(errors.end(), semantic_errors.begin(), semantic_errors.end());


	//transform Errors and Ptrees into http
	Mod_to_http mod_to_http(
		errors,
		sppf,
		vnode,
		http_nonterminals,
		http_terminals,
		http_head,
		http_rules,
		http_word
	);
	
	std::cout << mod_to_http.errors_to_http(errors) << std::endl;

}

void TST_http_to_errors::test_http_to_errors()
{
	
	
	// {
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " no errors" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_http_to_errors(
			// "a b c",
			// "A B C",
			// "a",
			// "a -> A B\n"
			// "a -> a a\n"
			// "a -> A C\n",
			// "A B A C"
		// );
	// }
	// {
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " empty nonterminals" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_http_to_errors(
			// "",
			// "A B C",
			// "a",
			// "a -> A B\n"
			// "a -> a a\n"
			// "a -> A C\n",
			// "A B A C"
		// );
	// }
	// {
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " empty terminals" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_http_to_errors(
			// "a b c",
			// "",
			// "a",
			// "a -> A B\n"
			// "a -> a a\n"
			// "a -> A C\n",
			// "A B A C"
		// );
	// }
	// {
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " empty head" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_http_to_errors(
			// "a b c",
			// "A B C",
			// "",
			// "a -> A B\n"
			// "a -> a a\n"
			// "a -> A C\n",
			// "A B A C"
		// );
	// }
	// {
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " empty rules" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_http_to_errors(
			// "a b c",
			// "A B C",
			// "a",
			// "",
			// "A B A C"
		// );
	// }
	// {
		// std::cout << "===============================================================" << std::endl;
		// std::cout << " empty word" << std::endl;
		// std::cout << "===============================================================" << std::endl;
		
		// _test_http_to_errors(
			// "a b c",
			// "A B C",
			// "a",
			// "a -> A B\n"
			// "a -> a a\n"
			// "a -> A C\n",
			// ""
		// );
	// }
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " repeating symbol in terminals" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c c",
			"A B C",
			"a",
			"a -> A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B C"
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " repeating symbol in nonterminals" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c",
			"A B C C",
			"a",
			"a -> A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B C"
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " IN_BOTH_TERMINALS_AND_NONTERMINALS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c 1",
			"A B C 1",
			"a",
			"a -> A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B C"
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " MISSING_LHS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c",
			"A B C",
			"a",
			"-> A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B C"
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " TOO_MANY_LHS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c",
			"A B C",
			"a",
			"A A -> A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B C"
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " TOO_FEW_RHS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c",
			"A B C",
			"a",
			"A -> B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B C"
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " TOO_MANY_RHS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c",
			"A B C",
			"a",
			"A A -> A A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B C"
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " MISSING_ARROW" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c",
			"A B C",
			"a",
			"A A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B C"
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " MULTIPLE_ARROWS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c",
			"A B C",
			"a",
			"A -> A -> A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B C"
		);
	}
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " TERMINAL_AS_LHS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c",
			"A B C",
			"a",
			"A -> A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B C"
		);
	}
	
	
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " MULTIPLE_HEADS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c",
			"A B C",
			"a a a",
			"a -> A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B A C"
		);
	}
	{
		std::cout << "===============================================================" << std::endl;
		std::cout << " SYMBOL_IN_NONTERMINALS" << std::endl;
		std::cout << "===============================================================" << std::endl;
		
		_test_http_to_errors(
			"a b c",
			"A B C",
			"a",
			"a -> A B\n"
			"a -> a a\n"
			"a -> A C\n",
			"A B A  a C"
		);
	}
}
