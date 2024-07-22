#include "html_response.h"

Html_response::Html_response()
{
	Utils::read_file( FILEPATH, RESPONSE_TEMPLATE);
	reset();
}


void Html_response::fill_response(
	const RESP_FIELDS::EN_RESPONSE_FIELDS & field, 
	const std::string & content)
{
	int beg = response.find(RESPONSE_FIELDS_DICT[field]);
	
	if (beg != std::string::npos)
	{
		//string::replace(initial_pos, length, replacement_string);
		response.replace( beg, RESPONSE_FIELDS_DICT[field].size(), content);
	}
}

std::string Html_response::get_response()
{
	//fill all unfilled fields with empty strings
	for (int i=0; i<NO_RESPONSE_FIELDS; i++)
	{
		fill_response((RESP_FIELDS::EN_RESPONSE_FIELDS)i, "");
	}
	
	std::string tmp = response;
	reset();
	return tmp;
}

void Html_response::reset()
{
	response = RESPONSE_TEMPLATE;
}


const std::string Html_response::RESPONSE_FIELDS_DICT[Html_response::NO_RESPONSE_FIELDS] = {
	"[[TERMINALS]]",
	"[[NONTERMINALS]]",
	"[[HEAD]]",
	"[[RULES]]",
	"[[ERRORS]]",
	"[[INPUT]]",
	"[[RESULTS]]"
};
