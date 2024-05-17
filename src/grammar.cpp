#include "grammar.h"


Non_terminals Grammar::get_nonterminals() const {return nonterminals;}


void Grammar::set_nonterminals(const Non_terminals & _nonterminals)
{
	nonterminals = _nonterminals;
}
