#include "tst_mod_from_http.h"


bool TST_mod_from_http::compare_non_terminals(
	const Non_terminals & expected,
	const Non_terminals & real
)
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
		std::cout << "DIFFERENT Non_terminals::size: expected: " 
			<< expected.size() << ", real: " 
			<< real.size() << std::endl;		
	}
	else 
	{
		for (auto i=expected.cbegin(); i!=expected.cend(); i++)
		{
			if (real.find(*i) == real.end())
			{
				same = false;
				std::cout << "DIFFERENT Non_terminals: missing " 
					<<  (*i)  << std::endl;
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
	if (expected.LHS != real.LHS)
	{
		same = false;
		std::cout << "DIFFERENT Rule::LHS: expected: " 
			<< expected.LHS << ", real: " 
			<< real.LHS << std::endl;
	}
	if (expected.RHS.size() != real.RHS.size())
	{
		same = false;
		std::cout << "DIFFERENT Rule.RHS::size: expected: " 
			<< expected.RHS.size() << ", real: " 
			<< real.RHS.size() << std::endl;		
	}
	else 
	{
		for (size_t i=0; i<expected.RHS.size(); i++)
		{
			if (expected.RHS[i] != real.RHS[i])
			{
				same = false;
				std::cout << "DIFFERENT Rule::RHS[" << i <<"]: expected: " 
					<< expected.RHS[i] << ", real: " 
					<< real.RHS[i] << std::endl;
			}
		}
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

	