#ifndef _PARSER_H_
#define _PARSER_H_

#include <vector>
#include <string>
#include <map>

#include "grammar.h"
#include "word.h"
#include "ptree.h"



class Parser
{
    public:

    PTrees parse(const Word & input, const Grammar & g);

};

#endif // _PARSER_H_

