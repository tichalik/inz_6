
#ifndef PROCESS_SPPF_H_
#define PROCESS_SPPF_H_

#include "sppf.h"
#include "pnode.h"
#include <vector>


class Process_SPPF 
{

	std::vector<std::vector<PNode*>> combine2(
		std::vector<std::vector<PNode*>> & list, 
		SPPF_node* sppf_node
	);

	std::vector<std::vector<PNode*>> all_combinations(
		const std::vector<SPPF_node *> & sppf_children
	);

    public:
	
    void process_sppf(
		SPPF & _sppf
	);
};

#endif // PROCESS_SPPF_H_

