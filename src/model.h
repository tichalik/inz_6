#ifndef MODEL_H
#define MODEL_H

#include "mod_from_http.h"
#include "mod_check_errors.h"
#include "mod_parser.h"
#include "mod_visualize_grammar.h"

class Model
{	
	Errors errors;
	SPPF sppf;
	VNode visualization;
	
public:
	Model(
		const std::string & http_terminals ,
		const std::string & http_nonterminals ,
		const std::string & http_head ,
		const std::string & http_rules ,
		const std::string & http_word,
		const bool simple_visualization
	);
	
	Errors get_errors() const;
	SPPF & get_sppf() ;
	VNode get_vnode() const;
};

#endif // SERVER_H_
