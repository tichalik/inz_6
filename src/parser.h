#ifndef _PARSER_H_
#define _PARSER_H_

#include <vector>
#include <string>
#include <map>

#include "parsing_grammar_adapter.h"
#include "word.h"
#include "ptree.h"



/** 
 * \brief parses words into parse trees
 */
class Parser
{
    public:

    /** 
	 * \brief parse words into parse trees according to given grammar
	 *
	 * \param input word to be parsed
	 * \param g grammar's view suitable for parsing
	 * \returns vector of all possible successfull parsings
	 */
    PTrees parse(const Word & input, const Parsing_grammar_adapter & g);

};

#endif // _PARSER_H_

