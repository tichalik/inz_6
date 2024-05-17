#include "grammar.h"


Non_terminals Grammar::get_nonterminals() const {return nonterminals;}
Non_terminals Grammar::get_terminals() const {return terminals;}


void Grammar::set_nonterminals(const Non_terminals & _nonterminals)
{
	nonterminals = _nonterminals;
}


void Grammar::set_terminals(const Non_terminals & _terminals)
{
	terminals = _terminals;
}
