#include "rules.h"

std::string Rule::to_string() const 
{
	return "<" + left.to_string() 
		+ "> -> <" + right1.to_string()  + "> <" + right2.to_string()  +">";
}


Errors Rule::get_errors() const
{
	Errors res;
	res.insert(res.end(), this->errors.begin(), this->errors.end());
	
	Errors left_errors = this->left.get_errors();
	Errors right1_errors = this->right1.get_errors();
	Errors right2_errors = this->right2.get_errors();
	
	res.insert(res.end(), left_errors.begin(), left_errors.end());
	res.insert(res.end(), right1_errors.begin(), right1_errors.end());
	res.insert(res.end(), right2_errors.begin(), right2_errors.end());
	
	for (size_t i=0; i<res.size(); i++)
	{
		res[i].source.push_back("rule "+this->to_string());
	}
	
	
	return res;
}

//--------------------------RuleSSSSSSS---------------------------


Errors Rules::get_errors() const
{
	Errors res;
	
	for (size_t i=0; i<this->size(); i++)
	{
		Errors tmp = this->at(i).get_errors();
		res.insert(res.end(), tmp.begin(), tmp.end());		
	}
	
	return res;
}