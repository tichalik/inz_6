#ifndef MODEL_H
#define MODEL_H

#include "mod_from_http.h"
#include "mod_check_errors.h"
#include "mod_parser.h"
#include "mod_visualize_grammar.h"

/**
 *	\brief the bussiness logic of the application
 *
 * The model:
 * - reads data from its http representation
 * - checks data for errors
 * - if no errors are present produces SPPF parsing and visualization
 **/
class Model
{	
	/// errors detected during checking
	Errors errors;
	/// result of parsing
	SPPF sppf;
	/// result of visualization
	VNode visualization;
	
public:
	
	/// constructor - provides all data necessary for processing
	Model(
		const std::string & http_terminals ,
		const std::string & http_nonterminals ,
		const std::string & http_head ,
		const std::string & http_rules ,
		const std::string & http_word,
		const std::string & vis_mode
	);
	
	/// returns errors detected during checking
	Errors get_errors() const;
	/// \brief returns result of parsing
	/// non-const reference, since iteration alters SPPF 
	SPPF & get_sppf() ;
	/// returns result of visualization
	VNode get_vnode() const;
};

#endif // SERVER_H_
