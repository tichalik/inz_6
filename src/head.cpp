#include "head.h"

Head::Head(const std::string & _head)
{
	symbol.symbol = _head;}
	
void Head::check_for_terminals_errors(const Non_terminals & terminals)
{
	if (terminals.contains(this->symbol))
	{
		this->errors.push_back(HEAD_IN_TERMINALS);
	}}
void Head::check_for_nonterminals_errors(const Non_terminals & nonterminals)
{
	if (!nonterminals.contains(this->symbol))
	{
		this->errors.push_back(HEAD_NOT_IN_NONTERMINALS);
	}}
bool Head::has_errors() const
{
	return this->errors.size() != 0;}

std::string Head::to_string() const
{
	return this->symbol.symbol;
}