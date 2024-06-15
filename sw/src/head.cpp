#include "head.h"

Head::Head(const std::string & _head)
{
	symbol.symbol = _head;}
	
void Head::check_errors(
	const Non_terminals & terminals,
	const Non_terminals & nonterminals
)
{

	if (!nonterminals.contains(this->symbol))
	{
		this->add_error(HEAD_NOT_IN_NONTERMINALS);

		if (!terminals.contains(this->symbol))
		{
			this->symbol.add_error(UNKNOWN_SYMBOL);
		}	}}
bool Head::has_errors() const
{
	return this->symbol.has_errors() || this->errors.size() != 0;}

std::string Head::to_string() const
{
	return this->symbol.symbol;
}