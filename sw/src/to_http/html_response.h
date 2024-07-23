#ifndef _HTML_RESPONSE_
#define _HTML_RESPONSE_

#include "utils.h"

#include <string>



namespace RESP_FIELDS
{
/**
 * \brief configurable fields in the Html_response
 *
 * they are used as array indexes so have to start from 0
 */
enum EN_RESPONSE_FIELDS
{
	TERMINALS = 0,
	NONTERMINALS, 
	HEAD, 
	RULES, 
	ERRORS, 
	INPUT, 
	RESULTS,
	ERRORS_OR_RESULTS
} ;
}; //namespace RESP_FIELDS

/**
 * \brief configurable HTML text
 */
class Html_response
{
	/**
	 * \brief number of configurable fields in the response
	 */
	const static int NO_RESPONSE_FIELDS = 8;

	/**
	 * \brief translation from EN_RESPONSE_FIELDS to string present in the template form 
	 *
	 * in the template the field XXX is represented as {{XXX}}
	 */
	const static std::string RESPONSE_FIELDS_DICT[NO_RESPONSE_FIELDS];

	/**
	 * \brief clear html template
	 */	
	std::string RESPONSE_TEMPLATE;
	
	/**
	 * \brief html document being updated with each field filled
	 */
    std::string response;
	
	/**
	 * \brief path to the html template's source
	 */
	const std::string FILEPATH = "./src/html_templates/post_form.html";
	
public:
	
	/**
	 * \brief constructor 
	 */
	Html_response();
	
	/**
	 * \brief fill given field of the template 
	 */
	void fill_response(const RESP_FIELDS::EN_RESPONSE_FIELDS & field, const std::string & content);
	
	/**
	 * \brief get the filled template. Unfilled fields are turned to empty strings
	 */
	std::string get_response();
	
	/**
	 * \brief clear all filled fields
	 */
	void reset();
};

#endif //_HTML_RESPONSE_