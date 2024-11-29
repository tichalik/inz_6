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
			+ tag +  "</span>\n";

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

std::string Mod_to_http::sppf_to_string(SPPF & sppf)
{
	std::string res = " ";

	sppf.start_iteration();
	if (sppf.current_node() != nullptr)
	{
		res += sppf.current_node()->tag;
	}

	bool prev_up = false;
	
	SPPF::EN_ITERATION_MOVE move = sppf.next_node();
	while (move != SPPF::EN_ITERATION_MOVE::END)
	{
		if (move == SPPF::EN_ITERATION_MOVE::DOWN)
		{
			if (!prev_up)
			{
				res += "[";
			}
			else
			{
				res += " ";
			}
			res += sppf.current_node()->tag;
			prev_up = false;
		}
		else
		{
			if (prev_up)
			{
				res += "]";
			}
			prev_up = true;
		}
		move = sppf.next_node();
	
 	}

	if (prev_up)
	{
		res += "]";
	}
	return res;
}


Mod_to_http::Mod_to_http(
	const Errors & errors, 
	SPPF & sppf, 
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
		std::string http_parse_trees = sppf_to_string(sppf);
		response.fill_response(RESP_FIELDS::RESULTS, http_parse_trees);
		
		//twice, the call only fills one field
		response.fill_response(RESP_FIELDS::VISUALIZATION_AND_RESULTS_DISPLAY, "block");
		response.fill_response(RESP_FIELDS::VISUALIZATION_AND_RESULTS_DISPLAY, "block");
		response.fill_response(RESP_FIELDS::ERRORS_DISPLAY, "none");
		
	}
	else
	{
		std::string http_errors = errors_to_http(errors);
		response.fill_response(RESP_FIELDS::ERRORS, http_errors);
		//twice, the call only fills one field
		response.fill_response(RESP_FIELDS::VISUALIZATION_AND_RESULTS_DISPLAY, "none");
		response.fill_response(RESP_FIELDS::VISUALIZATION_AND_RESULTS_DISPLAY, "none");
		response.fill_response(RESP_FIELDS::ERRORS_DISPLAY, "block");
	}
}

std::string Mod_to_http::get_http()
{
	return response.get_response();
}
