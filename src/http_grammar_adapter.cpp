#include "http_grammar_adapter.h"

Http_grammar_adapter::Http_grammar_adapter(
	const std::string & http_terminals,
	const std::string & http_nonterminals,
	const std::string & http_head,
	const std::string & http_rules)
{
	terminals_from_http(http_terminals);
	nonterminals_from_http(http_nonterminals);
	head_from_http(http_head);
	rules_from_http(http_rules);
}

Http_grammar_adapter::Http_grammar_adapter( const Grammar & _grammar):
	grammar(_grammar)
{
	
}

Grammar Http_grammar_adapter::get_grammar() const
{
	return this->grammar;
}


void Http_grammar_adapter::nonterminals_from_http(const std::string & param)
{	
	std::vector<std::string> str_nonterminals = Utils::vector_from_str(param);
	if (str_nonterminals.size() == 0)
	{
		Error_desc error;
		error.error = EMPTY_FIELD;
		error.description = "empty nonterminals";
		this->errors.push_back(error);
	}
	else 
	{
		Non_terminals nonterminals(str_nonterminals);
		this->grammar.set_nonterminals(nonterminals);
	}
}

void Http_grammar_adapter::terminals_from_http(const std::string & param)
{
	std::vector<std::string> str_terminals = Utils::vector_from_str(param);
	if (str_terminals.size() == 0)
	{
		Error_desc error;
		error.error = EMPTY_FIELD;
		error.description = "empty terminals";
		this->errors.push_back(error);
	}
	else 
	{
		Non_terminals terminals(str_terminals);
		this->grammar.set_terminals(terminals);
	}
}

void Http_grammar_adapter::head_from_http(const std::string & param)
{
	std::vector<std::string> head = Utils::vector_from_str(param);
	if (head.size() == 0)
	{
		Error_desc error;
		error.error = EMPTY_FIELD;
		error.description = "empty head";
		this->errors.push_back(error);
	}
	else if (head.size() >1)
	{
		Error_desc error;
		error.error = MULTIPLE_HEADS;
		error.description = "";
		this->errors.push_back(error);
	}
	else 
	{
		Head _head(head[0]);
		this->grammar.set_head(_head);
	}
}

void Http_grammar_adapter::rules_from_http(const std::string & param)
{
	std::vector<Rule> _tules;
	
	std::stringstream ss;
	ss << param;

	std::string line;
	while(std::getline(ss, line))
	{
		//state variable -- true if on LHS of the rule
		bool is_LHS = true;
		//control variable -- true if line is empty
		bool is_empty = true;
		
		std::string str_LHS, str_RHS1, str_RHS2;
		
		Rule rule;
		
		std::string tmp;
		//THE ARROW HAS TO BE SURROUNDED BY WHITESPACE!!!
		for (size_t i=0; i<line.size(); i++)
		{
			switch(line[i])
			{
				case ' ':
				case '\t':
				{
					//whitespace character
					if (!is_empty)
					{
						//if there was some input 
						if (tmp == "->")
						{
							//last parsed item was an arrow
							if (is_LHS == true)
							{
								//there already has been an arrow
								rule.errors.push_back(MULTIPLE_ARROWS);
							}
							else
							{
								//we are on LHS and encounter the arrow -- 
								//  -- we switch to RHS
								is_LHS = false;
							}
						}
						else
						{
							//last parsed item was a token of the rule
							if (is_LHS == true)
							{
								//we are on the LHS
								if (str_LHS != "")
								{
									//the LHS was already filled! 
									rule.errors.push_back(TOO_MANY_LHS);									
								}
								else
								{
									//it is the first LHS 
									str_LHS = tmp;
								}
							}
							else 
							{
								//we are on RHS
								if (str_RHS1 == "")
								{
									//RHS1 is empty -- we fill it
									str_RHS1 = tmp;
								}
								else if (str_RHS2 == "")
								{
									//RHS2 is empty -- we fill it
									str_RHS2 = tmp;
								}
								else 
								{
									//both RHS1 and RHS2 have been filled -- error
									rule.errors.push_back(TOO_MANY_RHS);									
								}
							}
						}
						
						//clear tmp
						tmp = "";
					}
					else
					{
						//whitespace at the beginning of line -- skip it
					}
				
					break;
				}
				default:
				{
					//non-whitespace character
					is_empty = false;
					tmp += line[i];
					break;
				}
			}
		}
		
		//skipping empty lines
		if (!is_empty)
		{
			//check if rule misses any pieces 
			bool ok = true;
			
			if (str_LHS == "")
			{
				rule.errors.push_back(MISSING_LHS);		
				ok = false;
			}
			
			if (str_RHS1 == "" || str_RHS2 == "")
			{
				rule.errors.push_back(TOO_FEW_RHS);									
				ok = false;
			}
			
			if (ok == true)
			{
				rule.left.symbol = str_LHS;
				rule.right1.symbol = str_RHS1;
				rule.right2.symbol = str_RHS2;
				_tules.push_back(rule);
			}
		}
	}
	
	if (_tules.size() == 0)
	{
		Error_desc error;
		error.error = EMPTY_FIELD;
		error.description = "empty rules";
		this->errors.push_back(error);
	}
	
	this->grammar.set_rules(_tules);
}



std::string Http_grammar_adapter::rule_to_http(const Rule & rule) const 
{
	return rule.left.to_http() + " -> " 
		+ rule.right1.to_http() + " " + rule.right2.to_http();
}



std::string Http_grammar_adapter::nonterminals_to_http() const
{
	Non_terminals nonterminals = grammar.get_nonterminals();
	std::vector<Symbol> symbols = nonterminals.get_symbols();
	
	std::string res;
	for (size_t i=0; i< symbols.size(); i++)
	{
		res += symbols[i].symbol + " ";
	}
	
	res = res.substr(0, res.size()-1);
	
	return res ;
}

std::string Http_grammar_adapter::terminals_to_http() const
{
	Non_terminals terminals = grammar.get_terminals();
	std::vector<Symbol> symbols = terminals.get_symbols();
	
	std::string res;
	for (size_t i=0; i< symbols.size(); i++)
	{
		res += symbols[i].symbol + " ";
	}
	
	res = res.substr(0, res.size()-1);
	
	return res ;
}

std::string Http_grammar_adapter::head_to_http() const
{
	return this->grammar.get_head().to_string();
}

std::string Http_grammar_adapter::rules_to_http() const
{
	std::string res; 
	
	Rules rules = this->grammar.get_rules();
	
	for (size_t i=0; i< rules.size(); i++)
	{
		res += rule_to_http(rules[i]) + "\n";
	}
	res = res.substr(0, res.size()-1);
	
	return res;
}

bool Http_grammar_adapter::has_errors() const
{
	return this->errors.size()!=0;
}