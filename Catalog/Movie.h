#pragma once
#ifndef MOVIE_H
#define MOVIE_H
// Movie object definition.
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Movie {
public:
	Movie(){}
	// Movie object has 5 fields.
	string title;
	string director;
	string year;
	string genre;
	string starring;
};
#endif