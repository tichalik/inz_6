#include "mod_to_http.h"



std::string Mod_to_http::pnode_to_string(const PNode & pnode) const
{
	if (pnode.children.size() == 0 )
		return pnode.tag;
	else
		return pnode.tag + "[" 
			+ pnode.children[0].to_string() + " " 
			+ pnode.children[1].to_string() + "]";
}

std::string Mod_to_http::pnode_to_http(const PNode & pnode) const
{
	if (pnode.children.size() == 0 )
		return pnode.tag;
	else
		return pnode.tag 
			+ "<div class=\"expandable\">" 
			+ pnode.children[0].to_http() + "<BR>" 
			+ pnode.children[1].to_http() + "</div>";
}

std::string Mod_to_http::ptree_to_string(const PTree & ptree) const
{
	return ptree.root.to_string();
}

std::string Mod_to_http::ptree_to_http(const PTree & ptree) const
{
	return "<div class=\"tree\">" + ptree.root.to_http() + "</div>";
}


std::string Mod_to_http::ptrees_to_string(const PTrees & ptrees) const
{
	std::string res;
	for (size_t i=0; i<ptrees.size(); i++)
	{
		res += ptree_to_string(ptrees[i]) + "\n";
	}
	res = res.substr(0, res.size()-1);
	return res;
}

std::string Mod_to_http::ptrees_to_http(const PTrees & ptrees) const
{
	std::string res;
	for (size_t i=0; i<ptrees.size(); i++)
	{
		res += ptree_to_http(ptrees[i]) + "\n<BR>\n";
	}
	return res;
}




std::string Mod_to_http::EN_ERROR_TYPE2str(const EN_ERROR_TYPE &error) const
{
	std::string res;
	switch (error)
	{
		case EMPTY_FIELD:
			res=""; //when the field is empty, the source is in Error::description
			break;
		case UNKNOWN_SYMBOL:
			res="unknown symbol";
			break;
		case REPEATING_SYMBOL:
			res="symbol repeating within a set";
			break;
		case IN_BOTH_TERMINALS_AND_NONTERMINALS:
			res="symbol cannot be in both terminals and nonterminals";
			break;
		case MISSING_LHS:
			res="no LHS in the rule";
			break;
		case TOO_MANY_LHS:
			res="only single symbol on LHS is permitted (for context free parsing)";
			break;
		case TOO_FEW_RHS:
			res="only rules with 2 symbols on RHS are permitted";
			break;
		case TOO_MANY_RHS:
			res="only rules with 2 symbols on RHS are permitted";
			break;
		case MISSING_ARROW:
			res="no arrown separating LHS and RHS";
			break;
		case MULTIPLE_ARROWS:
			res="only one arrow (between LHS and RHS) is permitted";
			break;
		case TERMINAL_AS_LHS:
			res="terminal symbol not permitted on rule LHS";
			break;
		case HEAD_NOT_IN_NONTERMINALS:
			res="head has to belong to nonterminals";
			break;
		case MULTIPLE_HEADS:
			res="head must be a single symbol";
			break;
		case SYMBOL_IN_NONTERMINALS:
			res="input must consist of terminals only";
			break;
		default:
			res = "UNKNOWN ERROR";
			break;
	}
	
	return res;
}

std::string Mod_to_http::error_to_http(const Error & error) const
{
	std::string res;
	
	for (size_t i=0; i<error.source.size(); i++)
	{
		res += error.source[i] + ":\t";
	}
	
	res +=  EN_ERROR_TYPE2str(error.type) + "\t" + error.description;
	
	return res;
	
}

std::string Mod_to_http::errors_to_http(const Errors & _errors) const
{
	std::string res;
	
	for (size_t i=0; i< _errors.size(); i++)
	{
		res += error_to_http(_errors[i]) + "\n<BR>\n";
	}
	
	return res;
	
}


Mod_to_http::Mod_to_http(
	const Errors & errors, 
	const PTrees & ptrees
)
{
	this->http_errors = errors_to_http(errors);
	
}

std::string Mod_to_http::get_http_errors() const
{
	return this->http_errors;
}

std::string Mod_to_http::get_http_parse_trees() const
{
	return this->http_parse_trees;
}