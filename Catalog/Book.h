#pragma once
#ifndef BOOK_H
#define BOOK_H
// Book object definition.
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Book {
public:
	Book(){}
	// Book object has 4 fields.
	string title;
	string authors;
	string year;
	string tags;
};
#endif
