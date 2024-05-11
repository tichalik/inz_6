#include "ptree.h"



std::string PNode::to_string() const
{
	if (children.size() == 0 )
		return tag;
	else
		return tag + "[" + children[0].to_string() + " " + children[1].to_string() + "]";
}
std::string PNode::to_http() const
{
	if (children.size() == 0 )
		return tag;
	else
		return tag + "<div class=\"expandable\">" + children[0].to_http() + "<BR>" + children[1].to_http() + "</div>";
}

std::string PTree::to_string() const
{
	return root.to_string();
}
std::string PTree::to_http() const
{
	return "<div class=\"tree\">" + root.to_http() + "</div>";
}


std::string PTrees::to_string() const
{
	std::string res;
	for (size_t i=0; i<this->size(); i++)
	{
		res += this->at(i).to_string() + "\n";
	}
	res = res.substr(0, res.size()-1);
	return res;
}

std::string PTrees::to_http() const
{
	std::string res;
	for (size_t i=0; i<this->size(); i++)
	{
		res += this->at(i).to_http() + "\n<BR>\n";
	}
	return res;
}

