#include "mod_from_http.h"

Non_terminals Mod_from_http::non_terminals_from_http(
	const std::string & param, 
	const bool is_nonterminals
)
{	
	Non_terminals nonterminals;
	std::vector<std::string> str_nonterminals = Utils::vector_from_str(param);
	if (str_nonterminals.size() == 0)
	{
		this->add_error( 
			(is_nonterminals? EMPTY_NONTERMINALS: EMPTY_TERMINALS )
		);
	}
	else 
	{
		for (size_t i=0; i<str_nonterminals.size(); i++)
		{
			Symbol s = str_nonterminals[i];
			if (nonterminals.find(s) != nonterminals.end())
			{
				//double symbol 
				Error error;
				error.type = REPEATING_SYMBOL;
				error.source = (is_nonterminals? "nonterminals: " : "terminals: ");
				error.source += "symbol "+s+":";
				
				this->errors.push_back(error);
			}
			else
			{
				nonterminals.insert(s);
			}
		}
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

Rule Mod_from_http::rule_from_http(const std::string & param, bool & ok)
{
	
	
	//state variable -- true if on LHS of the rule
	bool is_LHS = true;
	
	//error flags, for error reporting hierarchy
	bool f_MISSING_LHS = false;
	bool f_MISSING_RHS = true;
	bool f_MISSING_ARROW = true;
	bool f_MULTIPLE_ARROWS = false;
	bool f_TOO_MANY_LHS = false;
	
	Rule rule;
	
	std::stringstream ss;
	ss << param;
	
	std::string tmp;
	while ( ss >> tmp )
	{		
		//if it is a normal symbol
		if (tmp != "->")
		{
					
			if (is_LHS == true)
			{
						
				if (rule.LHS == "")
				{		
							
					rule.LHS = tmp;
				}
				else 
				{		
							
					f_TOO_MANY_LHS = true;
				}
			}
			else
			{				
				rule.RHS.push_back(tmp);
				f_MISSING_RHS = false;
			}
		}
		else //it is the separator between LHS and RHS
		{		
			f_MISSING_ARROW = false;
			
			if (is_LHS == true)
			{		
				is_LHS = false;

				if (rule.LHS == "")
				{				
					//the LHS has not been filled! 
					f_MISSING_LHS = true;
				}
				
			}
			else
			{				
				f_MULTIPLE_ARROWS = true;
			}
		}
	}
			
	//if something's messed up with the arrow, there is no LHS and RHS
	// so there's no use in reporting its errors
	if (f_MISSING_ARROW == true)
	{		
		this->add_error(MISSING_ARROW, "rule "+param+": ");
	}
	else if (f_MULTIPLE_ARROWS == true)
	{		
		this->add_error(MULTIPLE_ARROWS, "rule "+param+": ");
	}
	else
	{		
		if (f_MISSING_LHS == true)
		{		
			this->add_error(MISSING_LHS, "rule "+param+": ");
		}
		if (f_MISSING_RHS == true)
		{		
			this->add_error(MISSING_RHS, "rule "+param+": ");
		}
		if (f_TOO_MANY_LHS == true)
		{		
			this->add_error(TOO_MANY_LHS, "rule "+param+": ");
		}
	}

					
	//auxiliary return value -- it will be true if there were no errors
	ok = ! (f_MISSING_LHS || f_MISSING_RHS || f_MISSING_ARROW || f_TOO_MANY_LHS || f_MULTIPLE_ARROWS);
	
	return rule;
}

Rules Mod_from_http::rules_from_http(const std::string & param)
{
	Rules rules;
	
	std::stringstream ss;
	ss << param;
	std::string line;
	while(std::getline(ss, line))
	{
		bool ok;
		Rule rule = rule_from_http(line, ok);
		if (ok)
		{
			rules.push_back(rule);
		}
	}
	
	
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
	this->grammar.terminals = non_terminals_from_http(http_terminals, false);
	this->grammar.nonterminals = non_terminals_from_http(http_nonterminals, true);
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