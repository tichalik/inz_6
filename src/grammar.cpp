#include "grammar.h"

std::string vector2str(const std::vector<std::string> & vect, const std::string& sep)
{
	std::string res; 
	for (size_t i=0; i<vect.size(); i++)
	{
		res += vect[i] + sep;
	}
	res = res.substr(0, res.size()-sep.size());
	
	return res;
}

void vector_from_str(const std::string & input, std::vector<std::string> & output)
{
	std::stringstream ss;
	ss << input;
	
	Symbol s; 
	while (ss >> s)
	{
		output.push_back(s);
	}

}


bool Grammar::has_rule(const Symbol & r1, const Symbol & r2) const
{
	std::string key = r1 + RULE_MAP_SEPARATOR + r2;
	if ( rule_map.find(key) == rule_map.end())
		return false;
	else
		return true;
}

std::vector<Symbol> Grammar::get_rule_head(const Symbol & r1, const Symbol & r2) const
{
	std::string key = r1 + RULE_MAP_SEPARATOR + r2;
	return rule_map.at(key);
}

std::string Rule::to_http()
{
	return left + " -> " + right1 + " " + right2;
}


std::string Rule::to_string()
{
	return "<" + left + "> -> <" + right1 + "> <" + right2 +">";
}


Nonterminals Grammar::get_nonterminals() {return nonterminals;}
Terminals Grammar::get_terminals() {return terminals;}
Head Grammar::get_head() {return head;}
Rules Grammar::get_rules() {return rules;}


void Grammar::set_nonterminals(const Nonterminals & _nonterminals)
{
	nonterminals = _nonterminals;
}


void Grammar::set_terminals(const Terminals & _terminals)
{
	terminals = _terminals;
}


void Grammar::set_head(const Head & _head)
{
	head = _head;
}


void Grammar::set_rules(const Rules & _rules)
{
	rules = _rules;

	for (size_t i=0; i<rules.size(); i++)
	{
		std::string key = rules[i].right1 + RULE_MAP_SEPARATOR + rules[i].right2;
		rule_map[key].push_back(rules[i].left);
	}
}

void Grammar::nonterminals_from_http(const std::string & param)
{	
	vector_from_str(param, this->nonterminals);
}
void Grammar::terminals_from_http(const std::string & param)
{
	vector_from_str(param, this->terminals);
}
void Grammar::head_from_http(const std::string & param)
{
	std::stringstream ss;
	ss << param;
	ss >> this->head;
}
void Grammar::rules_from_http(const std::string & param)
{
	std::vector<Rule> _tules;
	
	std::stringstream ss;
	ss << param;

	std::string line;
	while(std::getline(ss, line))
	{
		std::string tmp;
		Rule r; 
		std::stringstream sss; 
		sss << line;
		sss >> r.left >> tmp >> r.right1 >> r.right2;
		_tules.push_back(r);
	}
	
	set_rules(_tules);
}

std::string Grammar::nonterminals_to_http()
{
	return vector2str(this->nonterminals, " ");
}
std::string Grammar::terminals_to_http()
{
	return vector2str(this->terminals, " ");
}
std::string Grammar::head_to_http()
{
	return head;
}
std::string Grammar::rules_to_http()
{
	std::string res; 
	for (size_t i=0; i<this->rules.size(); i++)
	{
		res += rules[i].to_http() +"\n";
	}
	res = res.substr(0, res.size()-1);
	
	return res;
}

std::string Grammar::to_string()
{
	std::string res;
	
	res += "TERMINALS\n";
	res += "<" + vector2str(terminals, "> <") + ">\n";
	res += "NONTERMINALS\n";
	res += "<" + vector2str(nonterminals, "> <") + ">\n";
	res += "HEAD\n";
	res += "<" + head + ">\n";
	
	std::string str_rules;
	for (size_t i=0; i<rules.size(); i++)
	{
		str_rules += rules[i].to_string() + "\n";
	}
	
	res += "RULES\n";
	res += str_rules + "\n";
	
	return res;
}
