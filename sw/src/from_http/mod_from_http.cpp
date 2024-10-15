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
		
	Tokens tokens = tokenize(param);

	//the trailing LB cannot be removed in the tokenizer
	//and introduced shift-reduce confilct in the parser
	// which i'm not going to solve because this is easier
	if (tokens.back().type = LB)
	{
		tokens.pop_back();
	} 
		
	Rules rules = parse_rules(tokens);

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
