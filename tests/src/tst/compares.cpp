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
		}\
		\
		return same;\
	}


#define COMPARE(FIELD)\
	same &= compare(expected.FIELD, real.FIELD, message + " " # FIELD);

#define END_COMPARE\
	if (!same)\
	{\
		std::cout << "difference in " << message << std::endl\
			<< "expected: " << std::endl << str(expected, "\t") << std::endl\
			<< "real: " << std::endl << str(real, "\t") << std::endl;\
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
		}\
		else \
		{\
			for (size_t i=0; i<expected.size(); i++)\
			{\
				same &= compare(expected[i], real[i], message + " ");\
			}\
		}\
		\
		END_COMPARE;\
		return same;\
	} 

COMPARE_SIMPLE_TYPE(std::string);
COMPARE_SIMPLE_TYPE(EN_ERROR_TYPE);
COMPARE_SIMPLE_TYPE(EN_TOKEN_TYPE);
COMPARE_SIMPLE_TYPE(bool);
COMPARE_SIMPLE_TYPE(size_t);

COMPARE_VECTOR_TYPE(Symbols);
COMPARE_VECTOR_TYPE(std::vector<Symbols>);
COMPARE_VECTOR_TYPE(std::vector<std::vector<PNode*>>);
COMPARE_VECTOR_TYPE(std::vector<PNode*>);
COMPARE_VECTOR_TYPE(Errors);
COMPARE_VECTOR_TYPE(Rules);
COMPARE_VECTOR_TYPE(Tokens);



bool compare(
	const  PNode* expected,
	const  PNode* real,
	const std::string & message
) 
{ 
	bool same = true;
	
	same &= compare(expected->tag, real->tag, message + " tag");

	if (expected->children.size() != real->children.size())
	{
		same = false;
	}
	else 
	{
		for (size_t i=0; i<expected->children.size(); i++)
		{
			same &= compare(expected->children[i], real->children[i], message + " ");
		}
	}
	
	END_COMPARE;
	
	return same;
} 


bool compare(
	const  std::list<State>& expected,
	const  std::list<State>& real,
	const std::string & message
) 
{
	bool same = true;
	if (expected.size() != real.size())
	{
		same = false;
	}
	else 
	{
		std::list<State>::const_iterator i_real = real.begin();
		for (std::list<State>::const_iterator i=expected.begin(); i != expected.end(); i++)
		{
			same &= compare(*i, *i_real, message + " ");
			i_real++;
		}
	}
	
	END_COMPARE;
	return same;
} 
COMPARE_VECTOR_TYPE(std::vector<std::list<State> >);

bool compare(
	const State& expected,
	const State& real,
	const std::string & message
) 
{ 
	bool same = true;
	COMPARE(rule);
	COMPARE(pos);
	COMPARE(origin);
	END_COMPARE;
	return same;
}


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
	END_COMPARE;
	
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
	END_COMPARE;
	return same;
}


bool compare(
	const Token & expected,
	const Token & real,
	const std::string & message
)
{ 
	bool same = true;
	COMPARE(type);
	COMPARE(str);
	COMPARE(start_pos);
	END_COMPARE;
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
	END_COMPARE;
	return same;
}



#undef END_COMPARE
#undef COMPARE
#undef COMPARE_SIMPLE_TYPE
#undef COMPARE_VECTOR_TYPE
