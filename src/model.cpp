#include "model.h"

Model::Model(
	const std::string & str_terminals ,
	const std::string & str_nonterminals ,
	const std::string & str_head ,
	const std::string & str_rules ,
	const std::string & str_word ,
	const std::string & vis_mode
)
{
	
	Mod_from_http mod_from_http(
		str_terminals,
		str_nonterminals,
		str_head,
		str_rules,
		str_word
	);
		
	const Errors str_errors = mod_from_http.get_errors();
	errors.insert(errors.end(), str_errors.begin(), str_errors.end());
	
	//if there are no http errors, proceed
	if (str_errors.size() == 0 )
	{
		const Grammar grammar = mod_from_http.get_grammar();
		const Word word = mod_from_http.get_word();
		
		//check errors
		Mod_check_errors mod_check_errors(
			grammar, 
			word
		);
		
		const Errors semantic_errors = mod_check_errors.get_errors();
		errors.insert(errors.end(), semantic_errors.begin(), semantic_errors.end());

		//parse if there are no errors
		if (semantic_errors.size() == 0)
		{
			Mod_visualize_grammar mod_visualize;
			visualization = mod_visualize.visualize_grammar(
				grammar,
				vis_mode	
			);
			
			Mod_parser mod_parser(grammar, word, this->sppf); 
		}
	}
	
}

Errors Model::get_errors() const
{
	return errors;
}


SPPF & Model::get_sppf() 
{
	return this->sppf;
}
VNode Model::get_vnode() const
{
	return visualization;
}
