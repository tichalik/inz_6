#include "mod_from_http.h"

void Mod_from_http::nonterminals_from_http(const std::string & param)
{	
	std::vector<std::string> str_nonterminals = Utils::vector_from_str(param);
	if (str_nonterminals.size() == 0)
	{
		this->add_error(EMPTY_FIELD, "empty nonterminals");
	}
	else 
	{
		Non_terminals nonterminals(str_nonterminals);
		this->grammar.set_nonterminals(nonterminals);
	}
}

void Mod_from_http::terminals_from_http(const std::string & param)
{
	std::vector<std::string> str_terminals = Utils::vector_from_str(param);
	if (str_terminals.size() == 0)
	{
		this->add_error(EMPTY_FIELD, "empty terminals");
	}
	else 
	{
		Non_terminals terminals(str_terminals);
		this->grammar.set_terminals(terminals);
	}
}

void Mod_from_http::head_from_http(const std::string & param)
{
	std::vector<std::string> head = Utils::vector_from_str(param);
	if (head.size() == 0)
	{
		this->add_error(EMPTY_FIELD, "empty head");
	}
	else if (head.size() >1)
	{
		this->add_error(MULTIPLE_HEADS);
	}
	else 
	{
		Head _head(head[0]);
		this->grammar.set_head(_head);
	}
}

void Mod_from_http::rules_from_http(const std::string & param)
{
	Rules _tules;
	//whether the field is all whitechars 
	bool all_empty = true;
	
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
		
		//add an artificial whitespace at the end of the line
		// to trigger behavior for completing the string
		line += " ";
		
		//THE ARROW HAS TO BE SURROUNDED BY WHITESPACE!!!
		for (size_t i=0; i<line.size(); i++)
		{
					// std::cout << "<<" << line[i]  << ">>" << std::endl;

			switch(line[i])
			{
				case ' ':
				case '\t':
				{
					//whitespace character
					if (tmp != "")
					{
						//if there was some input 
						if (tmp == "->")
						{
							//last parsed item was an arrow
							if (is_LHS == false)
							{
								//there already has been an arrow
								rule.add_error(MULTIPLE_ARROWS);
							}
							else
							{
								//we are on LHS and encounter the arrow -- 
								//  -- we switch to RHS
								is_LHS = false;
							}
						}
						else // if (tmp != "->")
						{
							//last parsed item was a token of the rule
							if (is_LHS == true)
							{
								//we are on the LHS
								if (str_LHS != "")
								{
									//the LHS was already filled! 
									rule.add_error(TOO_MANY_LHS);									
								}
								else
								{
									//it is the first LHS 
									str_LHS = tmp;
								}
							}
							else // if (is_LHS == false)
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
									rule.add_error(TOO_MANY_RHS);									
								}
							}
						}
						
						//clear tmp
						tmp = "";
					}// end if tmp!=""
					else 
					{
						//it's a sequence of whitespaces OR a leading one on the line
					}
				
					break;
				}
				default:
				{
					//non-whitespace character
					is_empty = false;
					all_empty = false;
					tmp += line[i];
					break;
				}
			} //end switch 
			
		// std::cout << "\tis_empty: " << is_empty << std::endl;
		// std::cout << "\tis_LHS: " << is_LHS << std::endl;
		// std::cout << "\tstr_LHS: <" << str_LHS << ">"<<  std::endl;
		// std::cout << "\tstr_RHS1: <" << str_RHS1 << ">"<<  std::endl;
		// std::cout << "\tstr_RHS2: <" << str_RHS2 << ">"<< std::endl;
		
		
		} //end for each character
		
		//skipping empty lines
		if (!is_empty)
		{
			//check if rule misses any pieces 
			
			if (str_LHS == "")
			{
				rule.add_error(MISSING_LHS);		
			}
			
			if (str_RHS1 == "" || str_RHS2 == "")
			{
				rule.add_error(TOO_FEW_RHS);									
			}
			
			rule.left.symbol = str_LHS;
			rule.right1.symbol = str_RHS1;
			rule.right2.symbol = str_RHS2;
			_tules.push_back(rule);
		}
		
	}
	
	
	if (all_empty)
	{
		this->add_error(EMPTY_FIELD, "empty rules");
	}
	
	this->grammar.set_rules(_tules);
}

void Mod_from_http::word_from_http(const std::string & param)
{
	std::vector<Symbol> res;
	
	std::stringstream ss;
	ss << param;
	
	std::string s; 
	while (ss >> s)
	{
		Symbol symbol;
		symbol.symbol = s;
		res.push_back(symbol);
	}
	
	if (res.size() == 0)
	{
		this->add_error(EMPTY_FIELD);
	}
	
	this->word = Word(res);
}

Mod_from_http::Mod_from_http(
	const std::string & http_terminals,
	const std::string & http_nonterminals,
	const std::string & http_head,
	const std::string & http_rules,
	const std::string & http_word
)
{
	terminals_from_http(http_terminals);
	nonterminals_from_http(http_nonterminals);
	head_from_http(http_head);
	rules_from_http(http_rules);
	word_from_http(http_word);
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