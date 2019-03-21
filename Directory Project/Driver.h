#include <iostream>
#include <string>
#include "Component.h"
using namespace std;

class Driver : public Component
{
public:
	Driver();
	bool Search(string);
	void Add(string);
	void AddRoot(string);
	void AddFile(string);
	bool SearchLib(string, Component*);
	void SetCurrent(string);
	void SetCurrentRoot();
	void CopyTo(string,string);
	void MoveTo(string, string);
	void Cleaner(string);
	void SetCurrentBack(string);
	void Printer();
private:
	Component* head;
	Component* curr;
	Component* root;
};

