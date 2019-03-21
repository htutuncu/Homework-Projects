#include "Driver.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

Driver::Driver()
{
	head = NULL;		// Default NULL pointers.
	curr = NULL;
	root = NULL;
}

void Driver::Printer()
{
	ofstream output("output.txt");	// Creates output file .
	Component* iter = NULL;			// iterators for the loops.
	Component* iter2 = NULL;
	Component* iter3 = NULL;
	for (iter = head; iter != NULL; iter = iter->down)	// from head to the directories and files.
	{
		if (iter == head )	// if the iter is root.
			output << iter->name << endl;
		else
		{
			if (iter->right != NULL)	// if there is directory or file in the same directory.
			{
				for (iter2 = iter; iter2 != NULL; iter2 = iter2->right)
				{	// iter2 means nodes has same parent.
					for (iter3 = head; iter3 != iter; iter3 = iter3->down) // the directories have same parent.
						output << iter3->name << "/";
					output << iter2->name << endl;	// Printing 
				}
			}
			else  // If there is no directory or file in the same directory.
				output << iter->name << endl;
		}
	}
	output.close(); // close the output file.
}

bool Driver::Search(string n)
{
	Component* iter = NULL;
	Component* iter2 = NULL;	// Iterators for the loops.
	for (iter = head; iter != NULL; iter = iter->down)
	{
		if (iter->name == n )	// If the string found in the linked list.
		{
			curr = iter;	// current is the founded directory.
			return true;
		}
		else if (iter->right != NULL )	// If there is directory same parent.
		{
			for (iter2 = iter->right; iter2 != NULL; iter2 = iter2->right)
			{
				if ( n == iter2->name )
				{
					curr = iter2;	// Current directory update.
					return true;
				}
			}
		}
	}
	return false;	// If there is no file or directory with given string. return false.
}

void Driver::Add(string n)
{
	if (head == NULL)	// If there is no directory or file in the linked list.
	{
		Component* temp = new Component;
		temp->name = n;
		temp->right = NULL;
		temp->down = NULL;
		temp->prev = NULL;
		head = temp;	// head is creating with given string.
		curr = head;
		root = head;	// default root is the first item.
	}
	else if (curr->down == NULL)	// If there is no directory same directory.
	{
		Component* temp = new Component;
		temp->name = n;
		temp->right = NULL;
		temp->down = NULL;
		temp->prev = curr;	// Creating a new Node.
		curr->down = temp;
		curr = temp;
	}
	else
	{
		Component* temp = new Component;
		temp->name = n;
		temp->right = NULL;
		temp->down = NULL;
		temp->prev = curr;
		curr->down->right = temp;
		curr = temp;
	}
}

void Driver::AddRoot(string n)
{
	Component* temp = new Component;	
	temp->name = n;
	temp->right = NULL;
	temp->down = head;
	temp->prev = NULL;
	head->prev = temp;
	head = temp;
	curr = head;
	root = head;	// Update the root.
}

void Driver::AddFile(string n)
{
	Component* temp = new Component;
	temp->name = n;
	temp->right = NULL;
	temp->down = NULL;
	if (curr->down == NULL)	// If there is no directory or file in the current directory.
	{
		temp->prev = curr;
		curr->down = temp;	// Adding the new file to the current directory.
		temp = curr;
	}
	else
	{
		curr = curr->down;
		Component* iter = NULL;
		for (iter = curr; iter->right != NULL; iter = iter->right);
		temp->prev = curr->prev;	// Finding last item of current directory.
		iter->right = temp;			// And add to the last items right link.
		temp = curr;
	}
}

bool Driver::SearchLib(string n, Component* c)
{
	if (n == c->name)
		return true;
	return false;
} 

void Driver::SetCurrent(string n)
{
	this->Search(n);	// Search function sets current directory with given string.
}

void Driver::SetCurrentRoot()
{
	this->curr = this->root;	// Sets current directory is root.
}

void Driver::CopyTo(string n1,string n2)
{
	Component* from = new Component;
	Component* to = new Component;
	vector<string>v;
	this->Search(n1);	// For set curr directory.
	from = curr;
	this->Search(n2);	// For set curr directory.
	to = curr;
	if (from->down != NULL)	// If there is a directory in current directory.
	{
		Component* temp = new Component;
		temp = from;
		AddFile(temp->name);	// Adding a new link.
		v.clear();
			
	}
	else
		AddFile(from->name);	// Adding a new link if there is no child in current directory.
}

void Driver::MoveTo(string n1, string n2)
{
	Component* from = new Component;
	Component* to = new Component;
	Component* temp = new Component;
	this->Search(n1);		// Set current that string n1
	from = curr;			// current assign to from 
	this->Search(n2);		// set current that string n2
	to = curr;				// current assign to to.
	if (to->down->right != NULL)// if there is one more child.
	{
		Component* iter = NULL;
		for (iter = to->down; iter->right != NULL; iter = iter->right);
		iter->right = from;		// move to parent data's right .
		from->prev->down = NULL; // delete another data because it is move.
	}
	else
	{
		to->down = from;	// if there is no child
		from->prev->down = NULL;	// delete another data.
	}
}

void Driver::Cleaner(string n)
{
	curr = curr->prev;	// set current, equal to SetCurrentBack member function.
	if (curr->down->right != NULL)// if there is one more child
	{
		curr->down = curr->down->right;// delete all the  directory.
	}
	else
		curr->down = NULL;	// delete directory.
}

void Driver::SetCurrentBack(string n)
{
	this->Search(n);
	if (curr->prev == NULL)	// if there is no parent 
	{}
	else // if there is a parent.
		curr = curr->prev; // set current directory to parent of the directory.
}