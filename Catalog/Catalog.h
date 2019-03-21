#pragma once
/*	
*	Definition of Catalog object.
*	This object operates every operations with another classes.
*/
#ifndef _CATALOG_H_
#define _CATALOG_H_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// Class is must be template,because there are 3 type for Catalog.
// It can be Book,Music or Movie type.
template <class T>
class Catalog {
public:
	Catalog(){}				// Constructor of Catalog object. Does nothing.
	~Catalog();				// Deletes the vector of objects.
	string type;			// Type of Catalog object. Book,Music or Movie.
	void ifBook(ifstream&,string);
	void ifMusic(ifstream&,string);
	void ifMovie(ifstream&,string);
	vector <T> sets;		// This vector stores objects. Each line in data.txt is a new object.
	
	// Functions for reading commands.txt file for each data type.
	void readCommandsBook(ofstream&);
	void readCommandsMusic(ofstream&);
	void readCommandsMovie(ofstream&);

	// Functions for sorting for each different types of field.
	static bool sortingTitle(const T&, const T&);
	static bool sortingAuthors(const T&, const T&);
	static bool sortingYear(const T&, const T&);
	static bool sortingTags(const T&, const T&);
	static bool sortingArtist(const T&, const T&);
	static bool sortingGenre(const T&, const T&);
	static bool sortingDirector(const T&, const T&);
	static bool sortingStarring(const T&, const T&);
};
#endif



