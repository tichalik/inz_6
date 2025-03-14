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

const std::string html_tree_beg = 
"<div class=\"tree\">    \n"
" <div class=\"tree-head\">   \n "
"   Parsing   \n "
" </div>  <!-- tree-head --> \n "
" <div class=\"tree-body\">   \n ";

const std::string html_tree_end = 
" </div>  <!-- tree-body --> \n "
"</div>  <!-- tree --> \n ";


const std::string html_node_beg1 = 
"     <div class=\"node\">   \n "
"      <div class=\"node-head\">   \n "
"       <button class=\"expand\" onclick=\"fold_expand(this)\" type=\"button\">   \n "
"        -   \n "
"       </button>   \n "
"       <span class=\"node-head-expanded\" style=\"display: inline;\">   \n ";

const std::string html_node_beg2 = 
	//here goes the tag
"       </span> <!-- node-head-expanded-->  \n "
"       <span class=\"node-folded\" style=\"display: none;\">   \n ";
const std::string html_node_beg3 = 
"       </span>  <!-- node-folded --> \n "
"      </div>  <!-- node-head --> \n "
"      <div class=\"node-body\" style=\"display: block;\">   \n ";

const std::string html_node_end = 
"      </div>  <!-- node-body--> \n "
"     </div>   <!-- node -->\n ";

const std::string html_leaf_beg = 
"       <div class=\"leaf-node\">   \n "; //here goes the tag

const std::string html_leaf_end = 
"       </div> <!-- leaf-node -->  \n ";

const std::string html_loop_node_beg = 
"     <div class=\"node loop\">   \n "
"       <div class=\"node-head\">   \n "
"         <span class=\"node-head-expanded\" style=\"display: inline;\">   \n ";

const std::string html_loop_node_end = 
	//here goes the tag
"           </span> <!-- node-head-expanded-->  \n "
"         </div>  <!-- node-head --> \n "
"       <div class=\"node-body\" style=\"display: block;\">   \n "
"         Infinite derrivation: this node represents a loop back into higher parts of the tree. This derrivation can be extended infinitely; see other trees for finite derrivations.\n"
"       </div>  <!-- node-body--> \n "
"     </div>   <!-- node loop-->\n ";


std::string Mod_to_http::sppf_tree_to_string(SPPF & sppf)
{
	std::string str_res = " ";
	std::vector<size_t> str_res_beginnings;
	std::vector<size_t> html_res_beginnings;

 
	std::string html_res = html_tree_beg;

	if (sppf.current_node() != nullptr)
 	{
		str_res += str_to_http(sppf.current_node()->tag);

		if (sppf.is_leaf(sppf.current_node()))
		{
			html_res += html_leaf_beg + str_to_http(sppf.current_node()->tag);
 		}
		else
 		{
			html_res += html_node_beg1 + str_to_http(sppf.current_node()->tag) + html_node_beg2;
			html_res_beginnings.push_back(html_res.size());
			html_res += html_node_beg3;
		}
	}

	bool prev_up = false;
	bool prev_loop = false;
	
	SPPF::EN_ITERATION_MOVE move = sppf.next_node();
	while (move != SPPF::EN_ITERATION_MOVE::END)
	{
		if (move == SPPF::EN_ITERATION_MOVE::DOWN
			|| move == SPPF::EN_ITERATION_MOVE::DOWN_AND_LOOP)
		{
			//descenced to new level
			if (!prev_up)
			{
				str_res += "[";
			}
			else //moved up then down -- went to a sibling
			{
				str_res += " ";
			}
			
			if (move == SPPF::EN_ITERATION_MOVE::DOWN_AND_LOOP)
			{
				str_res += "*";
				prev_loop = true;
			}
			else
			{
				prev_loop = false;
			}
			
			str_res_beginnings.push_back(str_res.size());
			str_res += str_to_http(sppf.current_node()->tag);
			prev_up = false;


			if (sppf.is_leaf(sppf.current_node()))
			{
				html_res += html_leaf_beg + str_to_http(sppf.current_node()->tag);
			}
			else if (move == SPPF::EN_ITERATION_MOVE::DOWN_AND_LOOP)
			{
				html_res += html_loop_node_beg + str_to_http(sppf.current_node()->tag);
			}
			else
			{
				html_res += html_node_beg1 + str_to_http(sppf.current_node()->tag) + html_node_beg2;
				html_res_beginnings.push_back(html_res.size());
				html_res += html_node_beg3;
			}
		}
		else //moved up tree
		{
			if (prev_up) //moved up then up -- finished a (non leaf) node
			{
				str_res += "]";
				std::string cache = str_res.substr(str_res_beginnings.back());

				html_res.insert(html_res_beginnings.back(), cache);
				html_res_beginnings.pop_back();
				html_res += html_node_end;
			}
			else //moved down then up -- was a leaf or a loop
			{
				if (prev_loop)
				{
					html_res += html_loop_node_end;
				}
				else
				{
					html_res += html_leaf_end;
				}
			}
			str_res_beginnings.pop_back();
			prev_up = true;
		}
		move = sppf.next_node();
	
 	}

	//this means the tree is something more than just a leaf
	if (prev_up)
	{
		str_res += "]";
		html_res.insert(html_res_beginnings.back(), str_res);
		html_res += html_node_end;
	}
	else //the only node was a leaf  
	{
		html_res += html_leaf_end;
	}

	html_res += html_tree_end;


	return html_res;
} 

std::string Mod_to_http::sppf_to_string(SPPF & sppf)
{
	std::string res;
	sppf.start_iteration();
	do 
	{
		res += sppf_tree_to_string(sppf);
	} while (sppf.next_tree() == true);
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
