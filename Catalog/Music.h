#pragma once
#ifndef MUSIC_H
#define MUSIC_H
// Music object definition.
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Music {
public:
	Music(){}
	// Music object has 4 fields.
	string title;
	string artist;
	string year;
	string genre;
};
#endif
