#ifndef _PARSER_H_
#define _PARSER_H_

#include <vector>
#include <string>
#include <map>

#include "parsing_grammar_adapter.h"
#include "word.h"
#include "ptree.h"



class Parser
{
    public:

    PTrees parse(const Word & input, const Parsing_grammar_adapter & g);

};

#endif // _PARSER_H_

