#include "mod_check_errors.h"



void Mod_check_errors::check_symbol_errors(
	const std::string & parent_source,
	const Symbol &s,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{
	if (!terminals.contains(s) && !nonterminals.contains(s) && s != "")
	{
		add_error(UNKNOWN_SYMBOL, parent_source + " <" + s+ ">:");
	}
}

void Mod_check_errors::word_check_errors(
	const std::string & parent_source,
	const Word &input,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{
	for (size_t i=0; i<input.size(); i++)
	{
		Symbol s = input[i];
		
		if (!terminals.contains(s) && !nonterminals.contains(s))
		{
			add_error(UNKNOWN_SYMBOL, 
				parent_source + " <" + s+ ">:");			
		}
		
		if (nonterminals.contains(s))
		{
			add_error(SYMBOL_IN_NONTERMINALS, 
				 parent_source + " <" + s+ ">:");			
		}
		
	}
}


void Mod_check_errors::grammar_check_errors(
	const std::string & parent_source,
	const Grammar &input
)
{
	non_terminals_check_errors(parent_source + "terminals:",
		input.terminals, input.nonterminals);	
	non_terminals_check_errors(parent_source +"nonterminals:",
		input.nonterminals, input.terminals);	
	head_check_errors(parent_source +"head:",
		input.head, input.terminals, input.nonterminals);
	rules_check_errors(parent_source +"rules:",
		input.rules, input.terminals, input.nonterminals);
}


void Mod_check_errors::head_check_errors(
	const std::string & parent_source,
	const Head &input,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{

	if (!nonterminals.contains(input))
	{
		add_error(HEAD_NOT_IN_NONTERMINALS, parent_source);

		if (!terminals.contains(input))
		{
			add_error(UNKNOWN_SYMBOL, parent_source);
		}
	}
}


void Mod_check_errors::rule_check_errors(
	const std::string & parent_source,
	const Rule &input,
	const Non_terminals& terminals,
	const Non_terminals& nonterminals
)
{
	std::string error_source = parent_source + " rule < <" + input.left
		+ "> -> <" + input.right1 + "> <" + input.right2 +"> >:";
	
	check_symbol_errors(error_source, input.left, terminals, nonterminals);
	check_symbol_errors(error_source, input.right1, terminals, nonterminals);
	check_symbol_errors(error_source, input.right2, terminals, nonterminals);
	
	if (terminals.contains(input.left))
	{
		add_error(TERMINAL_AS_LHS, error_source);
	}
	
}

void Mod_check_errors::rules_check_errors(
	const std::string & parent_source,
	const Rules &input,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{
	for (size_t i=0; i<input.size(); i++)
	{
		rule_check_errors(parent_source + " rules:", 
			input[i], terminals, nonterminals);
	}
}

void Mod_check_errors::non_terminals_check_errors(
	const std::string & parent_source,
	const Non_terminals& input,
	const Non_terminals & other
)
{
	for (size_t i=0; i<input.symbols.size(); i++)
	{
		Symbol s = input.symbols[i];
		//possible optimization?? 
		// for (size_t j=i; j<symbols.size(); j++)
			
		for (size_t j=0; j<input.symbols.size(); j++)
		{
			//OPTIMIZE!! ADD ERROR TO BOTH SYMBOLS, SKIP OTHER FROM 
			// ITERATION
			if (i != j && s == input.symbols[j])
			{
				add_error(REPEATING_SYMBOL,
					parent_source + " <" + s+ ">:");
				break;
			}
		}
		
		
		if (other.contains(s))
		{
			add_error(IN_BOTH_TERMINALS_AND_NONTERMINALS, 
				parent_source + " <" + s+ ">:");			
		}
	}
}



Mod_check_errors::Mod_check_errors(
	const Grammar & grammar, 
	const Word & word
)
{
	Grammar _grammar = grammar;
	Word _word = word;
	
	grammar_check_errors("grammar: ",_grammar);
	word_check_errors("word: ",_word, grammar.terminals, grammar.nonterminals);
}


Errors Mod_check_errors::get_errors() const
{
	return this->errors;
}


void Mod_check_errors::add_error(
	const EN_ERROR_TYPE & type,
	const std::string & source
)
{
	Error error;
	error.type = type;
	error.source = source;
	
	this->errors.push_back(error);
}