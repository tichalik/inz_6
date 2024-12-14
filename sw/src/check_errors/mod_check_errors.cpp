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
		add_error(UNKNOWN_SYMBOL, parent_source + " symbol \"" + s+ "\":");
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
				parent_source + " symbol \"" + s+ "\":");			
		}
		
		if (nonterminals.contains(s))
		{
			add_error(SYMBOL_IN_NONTERMINALS, 
				 parent_source + " symbol \"" + s+ "\":");			
		}
		
	}
}


void Mod_check_errors::grammar_check_errors(
	const std::string & parent_source,
	const Grammar &input
)
{
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

std::string Mod_check_errors::rule_to_error_source(
	const std::string& parent_source,
	const Symbol& LHS,
	const std::vector<Symbols>& RHSs
)
{
	std::string res = parent_source + " rule \"" + LHS + " ::= ";

	for (size_t i=0; i<RHSs.size(); i++)
	{
		for (size_t j=0; j<RHSs[i].size(); j++)
		{
			res +=  RHSs[i][j] + " ";
		}
		res += "| ";
	}
	res.pop_back();
	res.pop_back();

	return res + "\":";
}


void Mod_check_errors::rules_check_errors(
	const std::string & parent_source,
	const Rules &input,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{
	for (Rules::const_iterator i = input.cbegin(); i!= input.cend(); i++)
	{
		const Symbol& LHS = i->first;
		const std::vector<Symbols> & RHSs = i->second;
		const std::string source = rule_to_error_source(parent_source, LHS, RHSs);

		check_symbol_errors(
			source,
			LHS,
			terminals,
			nonterminals
		);
		
		for (size_t j=0; j<i->second.size(); j++)
		{
			const Symbols& RHS = i->second[j];
			for (size_t k=0; k<RHS.size(); k++)
			{
				check_symbol_errors(
					source, 
					RHS[k],
					terminals,
					nonterminals
				);
			}
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
