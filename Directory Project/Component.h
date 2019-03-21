/*
			Base class of the linked list.
*/
#include <iostream>
#include <string>
using namespace std;

class Component
{
public:
	Component(); 
	string name;	// Name of the node.
	string type;	// Type of the node, file or directory
	Component* right;	// Right means nodes that in the same directory. They are connects each other with right. 
	Component* down;    // Down means child directory.
	Component* prev;	// Prev means parent directory of Node.
};

