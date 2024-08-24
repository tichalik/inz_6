#include "compares.h"


#define COMPARE_SIMPLE_TYPE(TYPE)\
	bool compare(\
		const TYPE & expected,\
		const TYPE & real,\
		const std::string & message\
	)\
	{\
		bool same = true;\
		if (expected != real)\
		{\
			same = false;\
			std::cout << "DIFFERENT " << message << "(" #TYPE "): expected: " \
				<< str(expected) << ", real: " \
				<< str(real) << std::endl;\
		}\
		\
		return same;\
	}


#define COMPARE_VECTOR_TYPE(TYPE)\
	bool compare(\
		const TYPE & expected,\
		const TYPE & real,\
		const std::string & message\
	) \
	{\
		bool same = true;\
		if (expected.size() != real.size())\
		{\
			same = false;\
			std::cout << "DIFFERENT " << message << "(" #TYPE ")::size: expected: " \
				<< expected.size() << ", real: " \
				<< real.size() << std::endl;		\
		}\
		else \
		{\
			for (size_t i=0; i<expected.size(); i++)\
			{\
				same &= compare(expected[i], real[i], message + " ");\
			}\
		}\
		\
		return same;\
	}

COMPARE_SIMPLE_TYPE(std::string);
COMPARE_SIMPLE_TYPE(EN_ERROR_TYPE);
COMPARE_SIMPLE_TYPE(bool);
COMPARE_SIMPLE_TYPE(size_t);

COMPARE_VECTOR_TYPE(Symbols);
COMPARE_VECTOR_TYPE(std::vector<Symbols>);
COMPARE_VECTOR_TYPE(Errors);
COMPARE_VECTOR_TYPE(Rules);
COMPARE_VECTOR_TYPE(Chomsky_rules);
COMPARE_VECTOR_TYPE(PTrees);


COMPARE_VECTOR_TYPE(Replaced_symbolss);
COMPARE_VECTOR_TYPE(Cycle_warnings);
COMPARE_VECTOR_TYPE(Cycle_warnings_indexes);
COMPARE_VECTOR_TYPE(Replaced_symbols_indexes);
COMPARE_VECTOR_TYPE(PTable_entries);
COMPARE_VECTOR_TYPE(PTable_references);
COMPARE_VECTOR_TYPE(PNodes);

#define COMPARE(FIELD)\
	same &= compare(expected.FIELD, real.FIELD, message + " " # FIELD);


bool compare(
	const Non_terminals & expected,
	const Non_terminals & real,
	const std::string & message
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


bool compare(
	const Replaced_symbols_index & expected,
	const Replaced_symbols_index & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(RHS_pos);
	COMPARE(symbols);
	return same;
}

bool compare(
	const Cycle_warnings_index & expected,
	const Cycle_warnings_index & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(RHS_pos);
	COMPARE(cycle_warnings);
	return same;
}


bool compare(
	const Replaced_symbols & expected,
	const Replaced_symbols & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(result);
	COMPARE(chain);
	COMPARE(cycle_warnings);
	return same;
}

bool compare(
	const Error & expected,
	const Error & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(type);
	COMPARE(source);
	return same;
}


bool compare(
	const Rule & expected,
	const Rule & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(LHS);
	COMPARE(RHS);
	return same;
}

bool compare(
	const Chomsky_grammar & expected,
	const Chomsky_grammar & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(nonterminals);
	COMPARE(terminals);
	COMPARE(added_nonterminals);
	COMPARE(head);
	COMPARE(rules);
	return same;
}

bool compare(
	const Chomsky_rule & expected,
	const Chomsky_rule & real,
	const std::string & message
)
{
	
	bool same = true;
	COMPARE(LHS);
	COMPARE(RHS);
	COMPARE(replaced_symbols_indexes);
	COMPARE(cycle_warnings_indexes);
	return same;
}

bool compare(
	const PTable & expected,
	const PTable & real,
	const std::string & message
)
{
	bool same = true;
	if (expected.SIZE != real.SIZE)
	{
		same = false;
		std::cout << "different PTable::SIZE: "
			<< " expected: " << expected.SIZE 
			<< " real: " << real.SIZE 
			<< std::endl;
	}
	else
	{
		for (size_t i = 0; i < expected.SIZE; i++)
		{
			for (size_t j = 0; j < expected.SIZE - i; j++)
			{
				COMPARE(tab[i][j]);
			}
		}
	}
	
	return same;
}

bool compare(
	const PTable_entry & expected,
	const PTable_entry & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(tag);
	COMPARE(visited);
	COMPARE(children);
	return same;
		
}

bool compare(
	const Cycle_warning & expected,
	const Cycle_warning & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(origin_pos);
	COMPARE(target_pos);
	return same;
		
}

bool compare(
	const PTable_reference & expected,
	const PTable_reference & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(x);
	COMPARE(y);
	COMPARE(list_index);
	return same;
		
}


bool compare(
	const PTree & expected,
	const PTree & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(root);
	return same;
}
bool compare(
	const PNode & expected,
	const PNode & real,
	const std::string & message
)
{
	bool same = true;
	COMPARE(tag);
	COMPARE(children);
	return same;
}

#undef COMPARE
#undef COMPARE_SIMPLE_TYPE
#undef COMPARE_VECTOR_TYPE