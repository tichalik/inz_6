#include "mod_to_http.h"

std::string Mod_to_http::str_to_http(const std::string & str) const
{
	std::string res;
	
	for (size_t i=0; i<str.size(); i++)
	{
		if (str[i] == '>')
			res += "&gt;";
		else if (str[i] == '<')
			res += "&lt;";
		else if (str[i] == '&')
			res += "&amp;";
		else if (str[i] == '\'')
			res += "&apos;";
		else if (str[i] == '"')
			res += "&quot;";		
		else 
			res += str[i];
	}
	return res;
}


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
	if (pnode.children.size()!= 0)
	{
		res += "<div class=\"node\">\n";
		res += "  <div class=\"node-head\">\n";
		res += "    <button class=\"expand\" type=\"button\"> - </button>\n";
		
		res += "    <span class=\"node-head-expanded\">"
			+ str_to_http(pnode.tag) + "\n" + "</span>";
		
		res += "    <span class=\"node-folded\">"
			+ str_to_http(pnode_to_string(pnode)) +  "</span>\n";

		res += "  </div>\n";

		res += "  <div class=\"node-body\">\n";
		for (size_t i=0; i<pnode.children.size(); i++)
		{
			res += pnode_to_http(pnode.children[i]);
		}
		
		res += "  </div>\n";
		res += "</div>\n";
	}
	else
	{
		res += "<div class=\"leaf-node\">\n";
		res += str_to_http(pnode.tag) + "\n";
		res += "</div>\n";

	}
	return res;
}

std::string Mod_to_http::ptree_to_string(const PTree & ptree) const
{
	return pnode_to_string(ptree.root);
}

std::string Mod_to_http::ptree_to_http(const PTree & ptree) const
{
	std::string info;
	std::string parse_type;

	if (ptree.is_complete)
	{
		info += "complete ";
		parse_type = "Parsing";
	}
	else
	{
		parse_type = "Incomplete parsing";
	}

	if (ptree.is_head_ok)
	{
		info += "head_ok";
	}
	
	return "<div class=\"ptree " + info + "  \">" 
		+ "<div class=\"tree-head\">" + parse_type + "</div>\n"
		+ "<div class=\"tree-body\">" + pnode_to_http(ptree.root) + "</div>\n"
		+ "</div>";
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
		case STRAY_LB:
			res="stray line break";
			break;
		case STRAY_SEP:
			res="stray definition operator";
			break;
		case STRAY_OR:
			res="stray alternative operator";
			break;
		case TERM_IN_NTERMS:
			res="a terminal-like symbol in nonterminals. Please write your nonterminals <like_this>";
			break;
		case NTERM_IN_TERMS:
			res="a nonterminal-like symbol in terminals. Please write your terminals without the braces";
			break;
		case MISSING_LHS:
			res="no LHS in the rule";
			break;
		case MISSING_RHS:
			res="no RHS in the rule";
			break;
		case SINGLE_RHS:
			res="sorry, single RHS rules not supported yet";
			break;
		case TOO_MANY_LHS:
			res="only single symbol on LHS is permitted (for context free parsing)";
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
		case UNREMOVABLE_CHAIN:
			res="symbol is a head of chain of rules of nonterminals "
				"turning into single nonterminals without ever turning into a terminal";
			break;
		default:
			res = "UNKNOWN ERROR";
			break;
	}
	
	return res;
}

std::string Mod_to_http::error_to_http(const Error & error) const
{
	return "<div class=\"error\">\n" 
		+ str_to_http(error.source) +" " 
		+ str_to_http(EN_ERROR_TYPE2str(error.type))
		+ "</div>";
}

std::string Mod_to_http::errors_to_http(const Errors & _errors) const
{
	std::string res;
	
	for (size_t i=0; i< _errors.size(); i++)
	{
		res += error_to_http(_errors[i]) + "\n";
	}
	
	return res;
	
}

std::string Mod_to_http::vnode_to_http(const VNode & vnode) const
{
	std::string res;
	std::string tag = str_to_http(Utils::vector2str(vnode.tag, " "));
	
	res += "<div class=\"node\">\n";
	res += "<div class=\"node-expanded\">\n";
	res += " " + tag + "\n";
	
	for (size_t i=0; i<vnode.children.size(); i++)
	{
		res += vnode_to_http(vnode.children[i]);
	}
	
	res += "</div>\n";
	res += "<span class=\"node-folded\">";
	res += tag;
	res += "</span>\n";
	res += "</div>\n";
			
	return res;
}


std::string Mod_to_http::vtree_to_http(const VNode & vtree) const
{
	return "<div class=\"vtree\">\n"
		+ vnode_to_http(vtree) 
		+ "</div>";
}


Mod_to_http::Mod_to_http(
	const Errors & errors, 
	const PTrees & ptrees, 
	const VNode & vnode,
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
		//fill visualizatino
		std::string http_visualization = vtree_to_http(vnode);
		response.fill_response(RESP_FIELDS::VISUALIZATION, http_visualization);
		
		//fill results
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
