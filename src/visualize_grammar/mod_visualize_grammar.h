#ifndef MOD_VISUALIZE_GRAMMAR_H_
#define MOD_VISUALIZE_GRAMMAR_H_

#include "vnode.h"
#include "grammar.h"

/// create visualization of the grammar 
class Mod_visualize_grammar
{
	/// create derrivation such that each possible rule is used once
	void simple_append_children(
		VNode & root,
		const Rules & rules,
		std::map<Symbol, std::vector<bool>> & was_used
	);
	
	/// create derrivation such that each possible rule is used once in every branch
	void append_children(
		VNode & root,
		const Rules & rules,
		const std::map<Symbol, std::vector<bool>> & was_used
	);
	
public:
	
	/// constructor -- provide all necessary data
	VNode visualize_grammar(
		const Grammar & grammar,
		const std::string & mode 
	);

};
#endif 
