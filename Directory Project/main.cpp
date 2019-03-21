/*
*					OBJECT ORIENTED PROGRAMMING
*						ASSIGNMENT-5
*						11.05.2018
*				   	      HIKMET TUTUNCU
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Driver.h"

using namespace std;

void Commands(Driver& dir);
void Copy(Driver& dir, string dir1, string dir2);
void Move(Driver& dir, string dir1, string dir2);
void Delete(Driver& dir, string dir1);
void cd(Driver& dir, string dir1);

int main()
{
	ifstream myfile("files.txt"); // Opening files.txt file.
	Driver dir;					  // Class of Driver, can be called file manager.
	string line,line2;			  
	vector<string>v;
	int k = 0;
	size_t c = 0;	// Iterator for vectors.
	while (getline(myfile, line) )	// reading from files.txt line by line .
	{
		istringstream tokenizer(line);	// using for split strings
		while (getline(tokenizer, line2, '/')) // splitting strings
			v.push_back(line2);  // string that read, assigning to a string vector.
		for (size_t i = 0; i < v.size(); i++)
		{
			c = (v.size() - 1); // c means last element of vector.
			if (!dir.Search(v[i]) && i == 0 && k == 0) // first element of file.
				dir.Add(v[i]);
			else if (!dir.Search(v[i]) && i == 0) // if there is a root
				dir.AddRoot(v[i]);
			else if (!dir.Search(v[i]) && i != 0 && i != c ) // other directories
				dir.Add(v[i]);
			else if (i == c) // if there is a file.
				dir.AddFile(v[i]);
		}
		v.clear();
		k++;
	}
	Commands(dir); // Link list going to commands function. There will be commands.
	dir.Printer(); // Printing link list to the output.txt
	myfile.close();
	system("pause");
	return 0;
}

void Commands(Driver& dir)
{
	ifstream commands("commands.txt"); // opening file commands.txt
	string line1, line2;			   // temp strings
	vector<string>v;				   // vector for split strings
	while (getline(commands, line1))	// read from file line by line 
	{
		istringstream tokenizer(line1); // for tokenize string 
		while (getline(tokenizer, line2, ' '))  // splitting strings, for link.
			v.push_back(line2);
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] == "copy")			// if the keyword is Copy
			{
				Copy(dir, v[i + 1], v[i + 2]); // call the function copy
				i = v.size();				// for ending loop.
			}
			else if (v[i] == "move")     // if the keyword is Move
			{
				Move(dir, v[i + 1], v[i + 2]); // function move
				i = v.size();			// ending loop
			}
			else if (v[i] == "delete")	// if the keyword is delete
			{
				Delete(dir, v[i + 1]); // function delete
				i = v.size();		   // ending loop;
			}
			else if (v[i] == "cd")	  // if the keyword is cd
			{
				cd(dir, v[i + 1]);	// function cd
				i = v.size();		// ending loop
			}
		}
		v.clear(); // cleaning vector.
	}
	commands.close(); // close the file commands.txt
}

void Copy(Driver& dir,string dir1,string dir2)
{
	string line1, line2;	// temp strings.
	istringstream tokenizer1(dir1);	// 
	istringstream tokenizer2(dir2); //for the splitting strings
	vector<string>v1; // temp vectors.
	vector<string>v2;
	while (getline(tokenizer1, line1, '/')) // read the file links and split
		v1.push_back(line1);				// assign to vector
	string from = v1.back();				// the last element of vector is going to from.

	while (getline(tokenizer2, line2, '/'))
		v2.push_back(line2);
	string to = v2.back();
	dir.CopyTo(from, to); // call the member function CopyTo.
}

void Move(Driver& dir, string dir1, string dir2)
{
	string line1, line2;   // temp strings 
	istringstream tokenizer1(dir1);
	istringstream tokenizer2(dir2);   // for splitting directory and file  links
	vector<string>v1;
	vector<string>v2;   // vectors of directory links.
	while (getline(tokenizer1, line1, '/'))  // like the copy operation 
		v1.push_back(line1);
	string from = v1.back();

	while (getline(tokenizer2, line2, '/'))
		v2.push_back(line2);
	string to = v2.back();
	dir.MoveTo(from, to); // call member function MoveTo.
}

void Delete(Driver& dir, string dir1)
{
	dir.Search(dir1); // Current directory finding.
	dir.Cleaner(dir1); // And delete the link.
}

void cd(Driver& dir, string dir1)
{
	if (dir1[0] == '/' && dir1[1] == '\0')	// if there is just '/' character
		dir.SetCurrentRoot();				// Current is going to Root
	else if (dir1 == "..")					// If there is a ".." 
		dir.SetCurrentBack(dir1);			// Current directory is the previous one
	else
	{
		istringstream tokenizer1(dir1);		// splitting the directory link.
		vector<string>v1;
		string line1;
		while (getline(tokenizer1, line1, '/'))	// assigning to vector. Like copy or move.
			v1.push_back(line1);
		line1 = v1.back();	// the last element of vector is the current directory.
		dir.SetCurrent(line1); // update the current directory.
	}
}
