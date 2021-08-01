#ifndef NODESIRKET_HPP
#define NODESIRKET_HPP

#include <string>
#include "CalisanAVL.hpp"

class NodeSirket
{
public:
	CalisanAVL *calisanlar = new CalisanAVL();
	int employeeNo = 0;
	std::string id;
	int height;
	NodeSirket *left;
	NodeSirket *right;
	
	NodeSirket(std::string id, NodeSirket *left, NodeSirket *right);
};

#endif