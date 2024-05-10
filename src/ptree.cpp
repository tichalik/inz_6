#include "ptree.h"



std::string PNode::toString() const
{
	if (children.size() == 0 )
		return tag;
	else
		return tag + "[" + children[0].toString() + " " + children[1].toString() + "]";
}
std::string PNode::to_http() const
{
	if (children.size() == 0 )
		return tag;
	else
		return tag + "<div class=\"expandable\">" + children[0].to_http() + "<BR>" + children[1].to_http() + "</div>";
}

std::string PTree::toString() const
{
	return root.toString();
}
std::string PTree::to_http() const
{
	return "<div class=\"tree\">" + root.to_http() + "</div>";
}

// typedef std::vector<PTree> PTrees;


std::string PTrees::to_string()
{
	std::string res;
	for (size_t i=0; i<this->size(); i++)
	{
		res += this->at(i).toString() + "\n";
	}
	res = res.substr(0, res.size()-1);
	return res;
}

std::string PTrees::to_http()
{
	std::string res;
	for (size_t i=0; i<this->size(); i++)
	{
		res += this->at(i).to_http() + "\n<BR>\n";
	}
	return res;
}

