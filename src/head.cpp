#include "head.h"

Head::Head(const std::string & _head)
{
	symbol.symbol = _head;}
	
void Head::check_for_terminals_errors(const Non_terminals & terminals)
{
	}
void Head::check_for_nonterminals_errors(const Non_terminals & nonterminals)
{
	}
bool Head::has_errors() const
{
	return this->errors.size() != 0;}

std::string Head::to_string() const
{
	return this->symbol.symbol;
}