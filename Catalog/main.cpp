/*
*	HIKMET TUTUNCU	141044054
*	CSE 241 OBJECT ORIENTED PROGRAMMING
*	ASSIGNMENT-6	19.05.2018
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Catalog.h"
#include "Catalog.cpp"

using namespace std;

void setDataType();	// Driver function that every operation doing here.
//	Creating object and get catalog type. Calls another member functions in there.

int main()
{
	setDataType();	// Calling driver function in main.
	//system("pause");
	return 0;
}

void setDataType()
{
	ifstream data("data.txt",ios::in);	// Opening data.txt file.
	string line1 = "samet";				// Using for getline function, temp string.
	getline(data, line1);		// Read from file a line. The line is catalog type.
	if ( line1 == "book" )// If catalog type is book
	{
		Catalog<Book> c;	// Creating a Catalog object with book type. 
		c.type = line1;		// Object type is book.
		c.ifBook(data, line1);// Calling member function of Catalog object.
		// ifBook function operating another operations according to Movie.
	}
	else if ( line1 == "music" )// If catalog type is music
	{
		Catalog<Music> c;		// Creating a Catalog object with music type.
		c.type = line1;			// Object type is music.
		c.ifMusic(data, line1);	// Calling member function of Catalog object.
		//	ifMusic function operating another operations according to Music.
	}
	else if ( line1 == "movie" )// If catalog type is movie.
	{
		Catalog<Movie> c;		// Creating a Catalog object with movie type.
		c.type = line1;			// Object type is movie.
		c.ifMovie(data, line1); // Calling member function of Catalog object.
		//	ifMovie function operating another operations according to Movie.
	}
	data.close();
}

