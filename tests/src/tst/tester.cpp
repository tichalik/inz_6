#include "tester.h"



std::string Tester::error2str(const Error &error) const
{
	std::string res;
	
	for (size_t i=0; i<error.source.size(); i++)
	{
		res += error.source[i] + ":\t";
	}
	
	res +=  error_type2str(error.type) + "\t" + error.description;
	
	return res;
}

std::string Tester::error_type2str(const EN_ERROR_TYPE &error) const
{
	std::string res;
	switch (error)
	{
		case EMPTY_FIELD:
			res="EMPTY_FIELD";
			break;
		case UNKNOWN_SYMBOL:
			res="UNKNOWN_SYMBOL";
			break;
		case REPEATING_SYMBOL:
			res="REPEATING_SYMBOL";
			break;
		case IN_BOTH_TERMINALS_AND_NONTERMINALS:
			res="IN_BOTH_TERMINALS_AND_NONTERMINALS";
			break;
		case MISSING_LHS:
			res="MISSING_LHS";
			break;
		case TOO_MANY_LHS:
			res="TOO_MANY_LHS";
			break;
		case TOO_FEW_RHS:
			res="TOO_FEW_RHS";
			break;
		case TOO_MANY_RHS:
			res="TOO_MANY_RHS";
			break;
		case MISSING_ARROW:
			res="MISSING_ARROW";
			break;
		case MULTIPLE_ARROWS:
			res="MULTIPLE_ARROWS";
			break;
		case TERMINAL_AS_LHS:
			res="TERMINAL_AS_LHS";
			break;
		case HEAD_NOT_IN_NONTERMINALS:
			res="HEAD_NOT_IN_NONTERMINALS";
			break;
		case MULTIPLE_HEADS:
			res="MULTIPLE_HEADS";
			break;
		case SYMBOL_IN_NONTERMINALS:
			res="SYMBOL_IN_NONTERMINALS";
			break;
		default:
			res = "UNKNOWN ERROR";
			break;
	}
	
	return res;
}

std::string Tester::errors2str(const Errors &errors) const
{
	std::string res;
    for (size_t i=0; i<errors.size(); i++)
        res += error2str(errors[i])+ " ";
    return res;
}


void Tester::test_non_terminal_to_http()
{
	//simulated http input
	std::string http_input = "a b w c w d";
	
	//http adapter -- filling head and rules with dummies
	Http_grammar_adapter http_grammar_adapter(
		http_input, http_input,http_input, http_input);
		
	std::cout << http_grammar_adapter.nonterminals_to_http() << std::endl;
}


void Tester::show_word(const Word &w) const
{
	std::cout << "symbols: [<symbol>\\terrors\\thas_errors()]" << std::endl;
	std::vector<Symbol> symbols = w.get_symbols();
	for (size_t i=0; i<symbols.size(); i++)
	{
		std::cout << "<" << symbols[i].symbol << ">"
			<< "\t" << errors2str(symbols[i].errors) 
			<< "\t" << symbols[i].has_errors() << std::endl;
	}
	std::cout << "errors: " << std::endl << errors2str(w.errors) << std::endl; 
	std::cout << "has_errors(): " << std::endl << w.has_errors() << std::endl; 
}


void Tester::show_non_terminals(const Non_terminals & nt) const
{
	std::cout << "symbols: [<symbol>\\terrors\\thas_errors()]" << std::endl;
	std::vector<Symbol> symbols = nt.get_symbols();
	for (size_t i=0; i<symbols.size(); i++)
	{
		std::cout << "<" << symbols[i].symbol << ">"
			<< "\t" << errors2str(symbols[i].errors) 
			<< "\t" << symbols[i].has_errors() << std::endl;
	}
	std::cout << "errors: " << std::endl << errors2str(nt.errors) << std::endl; 
	std::cout << "get_errors(): " << std::endl << errors2str(nt.get_errors()) << std::endl; 
	std::cout << "has_errors(): " << std::endl << nt.has_errors() << std::endl; 
}
