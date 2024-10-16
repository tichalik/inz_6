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
		add_error(UNKNOWN_SYMBOL, parent_source + " symbol <" + s+ ">:");
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
				parent_source + " symbol <" + s+ ">:");			
		}
		
		if (nonterminals.contains(s))
		{
			add_error(SYMBOL_IN_NONTERMINALS, 
				 parent_source + " symbol <" + s+ ">:");			
		}
		
	}
}


void Mod_check_errors::grammar_check_errors(
	const std::string & parent_source,
	const Grammar &input
)
{
	non_terminals_check_errors("terminals:",
		input.terminals, input.nonterminals);	
	non_terminals_check_errors("nonterminals:",
		input.nonterminals, input.terminals);	
	head_check_errors("head:",
		input.head, input.terminals, input.nonterminals);
	rules_check_errors("rules:",
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
	std::string source = parent_source + " rule <" + input.to_string() + ">:";
	
	check_symbol_errors(source,
		input.LHS, terminals, nonterminals);
			
	if(input.RHS.size() == 1)
	{
		add_error(SINGLE_RHS, source+ " symbol <" + input.RHS[0] + ">:");	
	}
		
	for (size_t i=0; i<input.RHS.size(); i++)
	{
		check_symbol_errors(source, input.RHS[i], terminals, nonterminals);
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
		rule_check_errors(parent_source, 
			input[i], terminals, nonterminals);
	}
}

void Mod_check_errors::non_terminals_check_errors(
	const std::string & parent_source,
	const Non_terminals& input,
	const Non_terminals & other
)
{
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
