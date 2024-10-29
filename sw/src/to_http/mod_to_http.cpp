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


std::string Mod_to_http::node_to_string(const PNode & node) const
{
	if (node.children.size() == 0 )
		return node.tag;
	else
		return node.tag + "[" 
			+ node_to_string(node.children[0]) + " " 
			+ node_to_string(node.children[1]) + "]";
}

std::string Mod_to_http::node_to_http(const PNode & node) const
{
	std::string res;
	if (node.children.size()!= 0)
	{
		res += "<div class=\"node\">\n";
		res += "  <div class=\"node-head\">\n";
		res += "    <button class=\"expand\" type=\"button\" onclick=\"fold_expand(this)\"> - </button>\n";
		
		res += "    <span class=\"node-head-expanded\">"
			+ str_to_http(node.tag) + "\n" + "</span>";
		
		res += "    <span class=\"node-folded\">"
			+ str_to_http(node_to_string(node)) +  "</span>\n";

		res += "  </div>\n";

		res += "  <div class=\"node-body\">\n";
		for (size_t i=0; i<node.children.size(); i++)
		{
			res += node_to_http(node.children[i]);
		}
		
		res += "  </div>\n";
		res += "</div>\n";
	}
	else
	{
		res += "<div class=\"leaf-node\">\n";
		res += str_to_http(node.tag) + "\n";
		res += "</div>\n";

	}
	return res;
}

std::string Mod_to_http::tree_to_string(const PTree & tree) const
{
	return node_to_string(tree.root);
}

std::string Mod_to_http::tree_to_http(const PTree & tree) const
{
	std::string info;
	std::string parse_type;

	if (tree.is_complete)
	{
		info += "complete ";
		parse_type = "Parsing";
	}
	else
	{
		parse_type = "Incomplete parsing";
	}

	if (tree.is_head_ok)
	{
		info += "head_ok";
	}
	
	return "<div class=\"tree " + info + "  \">" 
		+ "<div class=\"tree-head\">" + parse_type + "</div>\n"
		+ "<div class=\"tree-body\">" + node_to_http(tree.root) + "</div>\n"
		+ "</div>";
}


std::string Mod_to_http::trees_to_string(const PTrees & trees) const
{
	std::string res;
	for (size_t i=0; i<trees.size(); i++)
	{
		res += tree_to_string(trees[i]) + "\n";
	}
	res = res.substr(0, res.size()-1);
	return res;
}

std::string Mod_to_http::trees_to_http(const PTrees & trees) const
{
	std::string res;
	for (size_t i=0; i<trees.size(); i++)
	{
		res += tree_to_http(trees[i]) + "\n<BR>\n";
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



std::string Mod_to_http::node_to_string(const VNode & node) const
{
	std::string tag = str_to_http(Utils::vector2str(node.tag, " "));
	if (node.children.size() == 0 )
		return tag;
	else
	{
		std::string body;
		for (size_t i=0; i<node.children.size(); i++)
		{
			body += node_to_string(node.children[i]) + " ";
		}
		return tag + "[" + body +"]";
	}
}


std::string Mod_to_http::node_to_http(const VNode & node) const
{
	std::string res;
	std::string tag = str_to_http(Utils::vector2str(node.tag, " "));
	if (node.children.size()!= 0)
	{
		res += "<div class=\"node\">\n";
		res += "  <div class=\"node-head\">\n";
		res += "    <button class=\"expand\" type=\"button\" onclick=\"fold_expand(this)\"> - </button>\n";
		
		res += "    <span class=\"node-head-expanded\">"
			+ tag + "\n" + "</span>";
		
		res += "    <span class=\"node-folded\">"
			+ node_to_string(node) +  "</span>\n";

		res += "  </div>\n";

		res += "  <div class=\"node-body\">\n";
		for (size_t i=0; i<node.children.size(); i++)
		{
			res += node_to_http(node.children[i]);
		}
		
		res += "  </div>\n";
		res += "</div>\n";
	}
	else
	{
		res += "<div class=\"leaf-node\">\n";
		res += tag + "\n";
		res += "</div>\n";

	}
	return res;
} 


std::string Mod_to_http::tree_to_http(const VNode & tree) const
{
	return node_to_http(tree);
}


Mod_to_http::Mod_to_http(
	const Errors & errors, 
	const PTrees & trees, 
	const VNode & node,
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
		std::string http_visualization = tree_to_http(node);
		response.fill_response(RESP_FIELDS::VISUALIZATION, http_visualization);
		
		//fill results
		std::string http_parse_trees = trees_to_http(trees);
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
