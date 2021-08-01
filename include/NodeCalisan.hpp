#ifndef NODECALISAN_HPP
#define NODECALISAN_HPP

#include <string>

class NodeCalisan
{
public:
	int time;
	int year;
	std::string id;
	int height;
	NodeCalisan *left;
	NodeCalisan *right;
	
	NodeCalisan(int year, std::string id, NodeCalisan *left, NodeCalisan *right);
};

#endif