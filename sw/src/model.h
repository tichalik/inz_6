#ifndef MODEL_H
#define MODEL_H

#include "mod_from_http.h"
#include "mod_check_errors.h"
#include "mod_parser.h"
#include "mod_postprocess_trees.h"
#include "mod_visualize_grammar.h"

class Model
{	
	Errors errors;
	PTrees ptrees;
	VNode visualization;
	
public:
	Model(
		const std::string & http_terminals ,
		const std::string & http_nonterminals ,
		const std::string & http_head ,
		const std::string & http_rules ,
		const std::string & http_word 
	);
	
	Errors get_errors() const;
	PTrees get_ptrees() const;
	VNode get_vnode() const;
};

#endif // SERVER_H_
