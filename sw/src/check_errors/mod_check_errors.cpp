#include "mod_check_errors.h"



void Mod_check_errors::check_symbol_errors(
	Symbol &s,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{
	if (!terminals.contains(s) && !nonterminals.contains(s) && s.symbol != "")
	{
		s.add_error(UNKNOWN_SYMBOL);
	}
}

void Mod_check_errors::word_check_errors(
	Word &input,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{
	for (size_t i=0; i<input.symbols.size(); i++)
	{
		if (!terminals.contains(input.symbols[i])
			&& !nonterminals.contains(input.symbols[i]))
		{
			input.symbols[i].add_error(UNKNOWN_SYMBOL);			
		}
		
		if (nonterminals.contains(input.symbols[i]))
		{
			input.symbols[i].add_error(SYMBOL_IN_NONTERMINALS);			
		}
		
	}
}


void Mod_check_errors::grammar_check_errors(Grammar &input)
{
	non_terminals_check_errors(input.terminals, input.nonterminals);	
	non_terminals_check_errors(input.nonterminals, input.terminals);	
	head_check_errors(input.head, input.terminals, input.nonterminals);
	rules_check_errors(input.rules, input.terminals, input.nonterminals);
}


void Mod_check_errors::head_check_errors(
	Head &input,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{

	if (!nonterminals.contains(input.symbol))
	{
		input.add_error(HEAD_NOT_IN_NONTERMINALS);

		if (!terminals.contains(input.symbol))
		{
			input.symbol.add_error(UNKNOWN_SYMBOL);
		}
	}
}


void Mod_check_errors::rule_check_errors(
	Rule &input,
	const Non_terminals& terminals,
	const Non_terminals& nonterminals
)
{
	
	check_symbol_errors(input.left, terminals, nonterminals);
	check_symbol_errors(input.right1, terminals, nonterminals);
	check_symbol_errors(input.right2, terminals, nonterminals);
	
	if (terminals.contains(input.left))
	{
		input.add_error(TERMINAL_AS_LHS);
	}
	
}

void Mod_check_errors::rules_check_errors(
	Rules &input,
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{
	for (size_t i=0; i<input.size(); i++)
	{
		rule_check_errors(input[i], terminals, nonterminals);
	}
}

void Mod_check_errors::non_terminals_check_errors(
	Non_terminals& input,
	const Non_terminals & other
)
{
	for (size_t i=0; i<input.symbols.size(); i++)
	{
		//possible optimization?? 
		// for (size_t j=i; j<symbols.size(); j++)
			
		for (size_t j=0; j<input.symbols.size(); j++)
		{
			//OPTIMIZE!! ADD ERROR TO BOTH SYMBOLS, SKIP OTHER FROM 
			// ITERATION
			if (i != j && input.symbols[i].symbol == input.symbols[j].symbol)
			{
				input.symbols[i].add_error(REPEATING_SYMBOL);
				break;
			}
		}
		
		
		if (other.contains(input.symbols[i]))
		{
			input.symbols[i].add_error(IN_BOTH_TERMINALS_AND_NONTERMINALS);			
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
	
	grammar_check_errors(_grammar);
	word_check_errors(_word, grammar.terminals, grammar.nonterminals);
	
	Errors grammar_errors = _grammar.get_errors();
	Errors word_errors = _word.get_errors();
	
	this->errors.insert(this->errors.end(), grammar_errors.begin(), grammar_errors.end());
	this->errors.insert(this->errors.end(), word_errors.begin(), word_errors.end());
}


Errors Mod_check_errors::get_errors() const
{
	return this->errors;
}