#include "tester.h"


bool Tester::compare_error(
	const Error & expected,
	const Error & real
)
{
	bool same = true;
	if (expected.type != real.type)
	{
		same = false;
		std::cout << "DIFFERENT Error::type: expected: " 
			<< error_type2str(expected.type) << ", real: " 
			<< error_type2str(real.type) << std::endl;
	}
	
	if (expected.source != real.source)
	{
		same = false;
		std::cout << "DIFFERENT Error::source: expected: " 
			<< expected.source << ", real: " 
			<< real.source << std::endl;
	}
	
	return same;
}

bool Tester::compare_errors(
	const Errors & expected,
	const Errors & real
)
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
		std::cout << "DIFFERENT Errors::size: expected: " 
			<< expected.size() << ", real: " 
			<< real.size() << std::endl;		
	}
	else 
	{
		for (size_t i=0; i<expected.size(); i++)
		{
			same &= compare_error(expected[i], real[i]);
		}
	}
	
	return same;
}

std::string Tester::error2str(const Error &error) const
{
	return error.source +":\t" + error_type2str(error.type);
}

std::string Tester::error_type2str(const EN_ERROR_TYPE &error) const
{
	std::string res;
	switch (error)
	{
		case EMPTY_NONTERMINALS:
			res = "EMPTY_NONTERMINALS";
			break;
		case EMPTY_TERMINALS:
			res = "EMPTY_TERMINALS";
			break;
		case EMPTY_HEAD:
			res = "EMPTY_HEAD";
			break;
		case EMPTY_RULES:
			res = "EMPTY_RULES";
			break;
		case EMPTY_WORD:
			res = "EMPTY_WORD";
			break;
		case UNKNOWN_SYMBOL:
			res = "UNKNOWN_SYMBOL";
			break;
		case REPEATING_SYMBOL:
			res = "REPEATING_SYMBOL";
			break;
		case IN_BOTH_TERMINALS_AND_NONTERMINALS:
			res = "IN_BOTH_TERMINALS_AND_NONTERMINALS";
			break;
		case MISSING_LHS:
			res = "MISSING_LHS";
			break;
		case TOO_MANY_LHS:
			res = "TOO_MANY_LHS";
			break;
		case TOO_FEW_RHS:
			res = "TOO_FEW_RHS";
			break;
		case TOO_MANY_RHS:
			res = "TOO_MANY_RHS";
			break;
		case MISSING_ARROW:
			res = "MISSING_ARROW";
			break;
		case MULTIPLE_ARROWS:
			res = "MULTIPLE_ARROWS";
			break;
		case TERMINAL_AS_LHS:
			res = "TERMINAL_AS_LHS";
			break;
		case HEAD_NOT_IN_NONTERMINALS:
			res = "HEAD_NOT_IN_NONTERMINALS";
			break;
		case MULTIPLE_HEADS:
			res = "MULTIPLE_HEADS";
			break;
		case SYMBOL_IN_NONTERMINALS:
			res = "SYMBOL_IN_NONTERMINALS";
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



void Tester::show_word(const Word &w) const
{
	for (size_t i=0; i<w.size(); i++)
	{
		std::cout << "<" << w[i]<< ">" << std::endl;
	}
}


void Tester::show_non_terminals(const Non_terminals & nt) const
{
	for (size_t i=0; i<nt.symbols.size(); i++)
	{
		std::cout << "<" << nt.symbols[i]<< ">" << std::endl;
	}
}
