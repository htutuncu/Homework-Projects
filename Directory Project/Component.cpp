#include "Component.h"
#include <iostream>
#include <string>
using namespace std;

Component::Component()
{
	right = NULL;	// Assigning to NULL every pointer.
	down = NULL;
	prev = NULL;
}

