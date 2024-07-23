#include "mod_to_http.h"



std::string Mod_to_http::pnode_to_string(const PNode & pnode) const
{
	if (pnode.children.size() == 0 )
		return pnode.tag;
	else
		return pnode.tag + "[" 
			+ pnode_to_string(pnode.children[0]) + " " 
			+ pnode_to_string(pnode.children[1]) + "]";
}

std::string Mod_to_http::pnode_to_http(const PNode & pnode) const
{
	std::string res;
	res += "<div class=\"node\">\n";
	res += "<div class=\"node-expanded\">\n";
	res += " "+pnode.tag+"\n";
	if (pnode.children.size() != 0 )
	{
		res += pnode_to_http(pnode.children[0]);
		res += pnode_to_http(pnode.children[1]);
	}
	res += "</div>\n";
	res += "<span class=\"node-folded\">";
	res += pnode_to_string(pnode);
	res += "</span>\n";
	res += "</div>\n";
			
	return res;
}

std::string Mod_to_http::ptree_to_string(const PTree & ptree) const
{
	return pnode_to_string(ptree.root);
}

std::string Mod_to_http::ptree_to_http(const PTree & ptree) const
{
	return "<div class=\"tree\">" + pnode_to_http(ptree.root) + "</div>";
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
		case EMPTY_NONTERMINALS:
			res="no nonterminals provided";
			break;
		case EMPTY_TERMINALS:
			res="no terminals provided";
			break;
		case EMPTY_HEAD:
			res="no head provided";
			break;
		case EMPTY_RULES:
			res="no rules provided";
			break;
		case EMPTY_WORD:
			res="no word provided";
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
	return error.source +":\t" + EN_ERROR_TYPE2str(error.type);
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
	const PTrees & ptrees, 
	const std::string & http_nonterminals,
	const std::string & http_terminals,
	const std::string & http_head,
	const std::string & http_rules,
	const std::string & http_word
)
{
	
	//directly pass the http values into the result form 
	response.fill_response(RESP_FIELDS::TERMINALS, http_terminals);
	response.fill_response(RESP_FIELDS::NONTERMINALS, http_nonterminals);
	response.fill_response(RESP_FIELDS::HEAD, http_head);
	response.fill_response(RESP_FIELDS::RULES, http_rules);
	response.fill_response(RESP_FIELDS::INPUT, http_word);
	
	//either errors or results are given and visible
	if (errors.size() == 0)
	{
		std::string http_parse_trees = ptrees_to_http(ptrees);
		response.fill_response(RESP_FIELDS::RESULTS, http_parse_trees);
		response.fill_response(RESP_FIELDS::ERRORS_OR_RESULTS, "errors");
	}
	else
	{
		std::string http_errors = errors_to_http(errors);
		response.fill_response(RESP_FIELDS::ERRORS, http_errors);
		response.fill_response(RESP_FIELDS::ERRORS_OR_RESULTS, "results");
	}
}

std::string Mod_to_http::get_http()
{
	return response.get_response();
}
