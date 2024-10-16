#include "mod_from_http.h"

Non_terminals Mod_from_http::terminals_from_http(
	const std::string & param 
)
{	
	Non_terminals terminals;
	Tokens tokens = tokenize(param);

	for (size_t i=0; i<tokens.size(); i++)
	{
		switch(tokens[i].type)
		{
			case TOKEN_ERROR:
			case SEP:
			case OR:
			{
				this->add_error(UNKNOWN_SYMBOL, "terminals: symbol " + 
					tokens[i].str + ": ");
				break;
			}
			case TERM:
			{
				if (terminals.find(tokens[i].str) != terminals.end())
				{
					//double symbol 
					this->add_error(REPEATING_SYMBOL, "terminals: symbol " + 
						tokens[i].str + ": ");
				}
				else
				{
					terminals.insert(tokens[i].str);
				}
				break;
			}
			case NTERM:
			{
				this->add_error(NTERM_IN_TERMS, "terminals: symbol " + 
					tokens[i].str + ": ");
					
				break;
			}
			case LB:
			{
				// do nothing
				break;
			}
			
		}
	}

	if (terminals.size() == 0)
	{
		this->add_error(EMPTY_TERMINALS);
	}
	

	return terminals;
}


Non_terminals Mod_from_http::nonterminals_from_http(
	const std::string & param 
)
{	 
	Non_terminals nonterminals;
	Tokens tokens = tokenize(param);

	for (size_t i=0; i<tokens.size(); i++)
	{
		switch(tokens[i].type)
		{
			case TOKEN_ERROR:
			case SEP:
			case OR:
			{
				this->add_error(UNKNOWN_SYMBOL, "nonterminals: symbol " + 
					tokens[i].str + ": ");
				break;
	 		}
			case NTERM:
			{
				if (nonterminals.find(tokens[i].str) != nonterminals.end())
				{
					//double symbol 
					this->add_error(REPEATING_SYMBOL, "nonterminals: symbol " + 
						tokens[i].str + ": ");
				}
				else
				{
					nonterminals.insert(tokens[i].str);
				}
				break;
			}
			case TERM:
			{
				this->add_error(TERM_IN_NTERMS, "nonterminals: symbol " + 
					tokens[i].str + ": ");
					
				break;
			}
			case LB:
			{
				// do nothing
				break;
			}
			
	 	}
	} 

	if (nonterminals.size() == 0)
	{
		this->add_error(EMPTY_NONTERMINALS);
	}
	

	return nonterminals;
}

Head Mod_from_http::head_from_http(const std::string & param)
{
	Head head;
	std::vector<std::string> vect_head = Utils::vector_from_str(param);
	if (vect_head.size() == 0)
	{
		this->add_error(EMPTY_HEAD);
	}
	else if (vect_head.size() >1)
	{
		this->add_error(MULTIPLE_HEADS, "head:");
	}
	else 
	{
		head = (vect_head[0]);
	}
	
	return head;
}


Rules Mod_from_http::rules_from_http(const std::string & param)
{
	Rules rules;
	EN_PARSER_STATE state = INIT;
	bool ok = true;
	Tokens tokens = tokenize(param);
	size_t rule_start = 0;

	#define RAISE_ERROR(X)\
		this->add_error(TERMINAL_AS_LHS, "rules: rule start" + \
			param.substr(rule_start, tokens[i].start_pos-rule_start)\
			+ ": symbol: " + tokens[i].str + ": ");\
		ok = false;\
		break;

	for (size_t i=0; i<tokens.size() && ok; i++)
	{
		switch(tokens[i].type)
		{
			case TOKEN_ERROR:
	 		{
				RAISE_ERROR(UNKNOWN_SYMBOL);
	 		} 
			case SEP:
			{ 
				switch(state)
			 	{
					case INIT:
					{
						RAISE_ERROR(MISSING_LHS);
					}
					case SEP_FOUND:
					case SYMBOL_FOUND:
					case ALT_STARTED:
					{
						RAISE_ERROR(STRAY_SEP);
			 		}
					case HEAD_FOUND:
					{
						state = SEP_FOUND;
						break;
					}
				}
			}
			case OR:
			{ 
				switch(state)
			 	{
					case INIT:
					case HEAD_FOUND:
					case SEP_FOUND:
					case ALT_STARTED:
					{
						RAISE_ERROR(STRAY_OR);
					}
					case SYMBOL_FOUND:
					{
						state = ALT_STARTED;
						//an alternative -- efectively create a new rule
						rules.emplace_back();
						//the rule has the same LHS as the previous rule
						rules.back().LHS = rules[rules.size()-2].LHS;
						break;
					}
				}
			}
			case NTERM:
			case TERM:
			{
				switch(state)
				{
					case INIT:
					{
						if (tokens[i].type == TERM)
						{ 
							RAISE_ERROR(TERMINAL_AS_HEAD);
						}
						else
						{
							state = HEAD_FOUND;
							//a new rule started
							rules.emplace_back();
							rules.back().LHS = tokens[i].str; 
						}
						break;
					}
					case HEAD_FOUND:
					{  
						RAISE_ERROR(TOO_MANY_LHS);
					}
					case SEP_FOUND:
					case ALT_STARTED:
					case SYMBOL_FOUND:
					{
						//a member of a rule's RHS 
						rules.back().RHS.push_back(tokens[i].str);
						break;
					}
				}
			}
			case LB:
			{ 
				switch(state)
			 	{
					case SEP_FOUND:
					{
						RAISE_ERROR(MISSING_RHS);
					}
					case ALT_STARTED:
					case HEAD_FOUND:
					{
						RAISE_ERROR(STRAY_LB);
					}
					case SYMBOL_FOUND:
					case INIT:
					{
						state = INIT;
						//a rule is finished and already stored in rules
						rule_start = tokens[i].start_pos;
						break;
					}
				}
			}
		}
	} 

	#undef RAISE_ERROR

	if (rules.size() == 0)
	{
		this->add_error(EMPTY_RULES);
	}
	
	return rules;
}

Word Mod_from_http::word_from_http(const std::string & param)
{
	Word res;
	
	std::stringstream ss;
	ss << param;
	
	std::string s; 
	while (ss >> s)
	{
		res.push_back(s);
	}
	
	if (res.size() == 0)
	{
		this->add_error(EMPTY_WORD);
	}
	
	return res;
}

Mod_from_http::Mod_from_http(
	const std::string & http_terminals,
	const std::string & http_nonterminals,
	const std::string & http_head,
	const std::string & http_rules,
	const std::string & http_word
)
{
	this->grammar.terminals = terminals_from_http(http_terminals);
	this->grammar.nonterminals = nonterminals_from_http(http_nonterminals);
	this->grammar.head = head_from_http(http_head);
	this->grammar.rules = rules_from_http(http_rules);
	
	this->word = word_from_http(http_word);
}

Grammar Mod_from_http::get_grammar() const
{
	return this->grammar;
}

Word Mod_from_http::get_word() const
{
	return this->word;
}

Errors Mod_from_http::get_errors() const
{
	return this->errors;
}

void Mod_from_http::add_error(
	const EN_ERROR_TYPE & type,
	const std::string & source
)
{
	Error error;
	error.type = type;
	error.source = source;
	
	this->errors.push_back(error);
}
