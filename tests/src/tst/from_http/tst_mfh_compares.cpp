#include "tst_mod_from_http.h"


bool TST_mod_from_http::compare_non_terminals(
	const Non_terminals & expected,
	const Non_terminals & real
)
{
	bool same = true;
	if (expected.symbols.size() != real.symbols.size())
	{
		same = false;
		std::cout << "DIFFERENT Non_terminals::size: expected: " 
			<< expected.symbols.size() << ", real: " 
			<< real.symbols.size() << std::endl;		
	}
	else 
	{
		for (size_t i=0; i<expected.symbols.size(); i++)
		{
			if (expected.symbols[i] != real.symbols[i])
			{
				same = false;
				std::cout << "DIFFERENT Non_terminals::symbols[" << i << "]: expected: " 
					<< expected.symbols[i] << ", real: " 
					<< real.symbols[i] << std::endl;
			}
		}
	}
	
	return same;
}

bool TST_mod_from_http::compare_head(
	const Head & expected,
	const Head & real
)
{
	bool same = true;
	if (expected != real)
	{
		same = false;
		std::cout << "DIFFERENT Head: expected: " 
			<< expected << ", real: " 
			<< real << std::endl;
	}
	
	return same;
}

bool TST_mod_from_http::compare_rule(
	const Rule & expected,
	const Rule & real
)
{
	bool same = true;
	if (expected.left != real.left)
	{
		same = false;
		std::cout << "DIFFERENT Rule::left: expected: " 
			<< expected.left << ", real: " 
			<< real.left << std::endl;
	}
	
	if (expected.right1 != real.right1)
	{
		same = false;
		std::cout << "DIFFERENT Rule::right1: expected: " 
			<< expected.right1 << ", real: " 
			<< real.right1 << std::endl;
	}
	
	if (expected.right2 != real.right2)
	{
		same = false;
		std::cout << "DIFFERENT Rule::right2: expected: " 
			<< expected.right2 << ", real: " 
			<< real.right2 << std::endl;
	}
	return same;
}

bool TST_mod_from_http::compare_rules(
	const Rules & expected,
	const Rules & real
)
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
		std::cout << "DIFFERENT Rules::size: expected: " 
			<< expected.size() << ", real: " 
			<< real.size() << std::endl;		
	}
	else 
	{
		for (size_t i=0; i<expected.size(); i++)
		{
			same &= compare_rule(expected[i], real[i]);
		}
	}
	
	return same;
}

bool TST_mod_from_http::compare_word(
	const Word & expected,
	const Word & real
)
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
		std::cout << "DIFFERENT Word::size: expected: " 
			<< expected.size() << ", real: " 
			<< real.size() << std::endl;		
	}
	else 
	{
		for (size_t i=0; i<expected.size(); i++)
		{
			if (expected[i] != real[i])
			{
				same = false;
				std::cout << "DIFFERENT Word[" << i << "]: expected: " 
					<< expected[i] << ", real: " 
					<< real[i] << std::endl;
			}
		}
	}
	
	return same;
}

	