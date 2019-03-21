#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Catalog.h"
#include "Book.h"
#include "Music.h"
#include "Movie.h"

template <class T>
Catalog<T>::~Catalog()
{	this->sets.clear();		}

template <class T>
void Catalog<T>::ifBook(ifstream& data1, string n)
{	
	ofstream out("output.txt");				// Creating an output file.
	out << "Catalog Read: " << n << endl;
	string line,line1;						// temp strings for reading txt file.
	while (getline(data1, line1))			// Read txt file line by line.
	{	// If there is no line which means end of file. Loop will be break.
		istringstream tokenizer(line1);		// For parsing string.
		Book b;								// Creating a book object.
		try {
			getline(tokenizer, line, '"');	
			getline(tokenizer, line, '"'); // Get string between ".
			b.title = line;			// If there is no error, title assign to a new book object.
			
			getline(tokenizer, line, '"');
			getline(tokenizer, line, '"');// Get string between ". 
			b.authors = line;		// new author assign to book.
			
			getline(tokenizer, line, '"');
			getline(tokenizer, line, '"');// get string between ".
			b.year = line;			// new year assign to book.
			
			if (getline(tokenizer, line, '"') && getline(tokenizer, line, '"'))
			{	// if there is a string at last, assign to new tags.
				b.tags = line;
				vector <Book> ::iterator i;	   // Iterator for seek the existing vector.	
			for (i = this->sets.begin(); i != this->sets.end(); ++i)
			{	// If there is the same title in objects, it means duplicate error.
				if (strcmp(b.title.c_str(), i->title.c_str()) == 0)
					throw 3.2;
			}
				this->sets.push_back(b);	// Then, new book object push to Catalog vector,sets.
			}
			else			// If there is no new string at last, it means missing field exception.
				throw 1;
		}
		catch (int x)		// If the throw data is int, it means missing field.
		{
			out << "Exception: missing field" << endl;
			out << line1 << endl;
		}
		catch (double x)    // If the throw data is double, it means duplicate entry.
		{
			out << "Exception: duplicate entry" << endl;
			out << line1 << endl;
		}
	}
	out << this->sets.size() << " unique entries" << endl;	// How many unique entries prints.
	readCommandsBook(out);	// Calling function that commands operating in.
	// Parameter is "out", this is ofstream. New function continues printing this output file. 
}

template <class T>
void Catalog<T>::ifMusic(ifstream& data1, string n)
{	
	ofstream out("output.txt");				// Create an output file.
	out << "Catalog Read: " << n << endl;
	string line, line1;						// Temp strings.
	while (getline(data1, line1))
	{	// If there is no line which means end of file. Loop will be break.
		istringstream tokenizer(line1);		// For parsing string.
		Music b;							// Creating a new Music object.
		try {
			getline(tokenizer, line, '"');
			getline(tokenizer, line, '"');	// get string between ".
			b.title = line;			// If there is no error, title assign to a new music object.
			
			getline(tokenizer, line, '"');
			getline(tokenizer, line, '"');	// get string between ".
			b.artist = line;				// new artist assign to object.

			getline(tokenizer, line, '"');
			getline(tokenizer, line, '"');	// get string between ".
			b.year = line;					// new year assign to object.

			if (getline(tokenizer, line, '"') && getline(tokenizer, line, '"'))
			{	// if there is a string at last, assign to new genre.
				b.genre = line;
				vector <Music> ::iterator i;	// Iterator for seek the existing vector. 
				for (i = this->sets.begin(); i != this->sets.end(); ++i)
				{	// If there is the same title in objects, it means duplicate error.
					if (strcmp(b.title.c_str(), i->title.c_str()) == 0)
						throw 3.2;
				}
				this->sets.push_back(b);	// Then, new music object push to Catalog vector,sets.
			}
			else			// If there is no new string at last, it means missing field exception.
				throw 1;
		}
		catch (int x)		// If the throw data is int, it means missing field.
		{
			out << "Exception: missing field" << endl;
			out << line1 << endl;
		}
		catch (double x)	// If the throw data is double, it means duplicate entry.
		{
			out << "Exception: duplicate entry" << endl;
			out << line1 << endl;
		}
	}
	out << this->sets.size() << " unique entries" << endl;	// How many unique entries prints.
	readCommandsMusic(out);	// Calling function that commands operating in.
	// Parameter is "out", this is ofstream. New function continues printing this output file.
}

template <class T>
void Catalog<T>::ifMovie(ifstream& data1, string n)
{
	ofstream out("output.txt");		// creating an output file.
	out << "Catalog Read: " << n << endl;
	string line, line1;				// Temp strings.
	while (getline(data1, line1))
	{	// If there is no line which means end of file. Loop will be break.
		istringstream tokenizer(line1);		// For parsing string.
		Movie b;							// Creating a new Movie object.
		try {
			getline(tokenizer, line, '"');
			getline(tokenizer, line, '"');	// get string between ".
			b.title = line;			// If there is no error, title assign to a new movie object.
			
			getline(tokenizer, line, '"');	
			getline(tokenizer, line, '"');	// get string between ".
			b.director = line;				// new director assign to object Movie.

			getline(tokenizer, line, '"');
			getline(tokenizer, line, '"');	// get string between ".
			b.year = line;					// new year assign to object Movie.

			getline(tokenizer, line, '"');
			getline(tokenizer, line, '"');	// get string between ".
			b.genre = line;					// new genre assign to object Movie.

			if (getline(tokenizer, line, '"') && getline(tokenizer, line, '"'))
			{	// if there is a string at last, assign to new starring.
				b.starring = line;
				vector <Movie> ::iterator i;	// Iterator for seek the existing vector.
				for (i = this->sets.begin(); i != this->sets.end(); ++i)
				{	// If there is the same title in objects, it means duplicate error.
					if (strcmp(b.title.c_str(), i->title.c_str()) == 0)
						throw 3.2;
				}
				this->sets.push_back(b);	// Then, new music object push to Catalog vector,sets.	
			}
			else			// If there is no new string at last, it means missing field exception.
				throw 1;
		}
		catch (int x)		// If the throw data is int, it means missing field.
		{
			out << "Exception: missing field" << endl;
			out << line1 << endl;
		}
		catch (double x)	// If the throw data is double, it means duplicate entry.
		{
			out << "Exception: duplicate entry" << endl;
			out << line1 << endl;
		}
	}
	out << this->sets.size() << " unique entries" << endl;	// How many unique entries prints.
	readCommandsMovie(out);		// Calling function that commands operating in.
	// Parameter is "out", this is ofstream. New function continues printing this output file.
}

template <class T>
void Catalog<T>::readCommandsBook(ofstream& out)
{
	ifstream command("commands.txt");	// Open commands.txt file. 
	string line1;						// Temp string.
	string cmd, word="thisisatemp", in="thisisatemp",category="thisisatemp",temps="thisisatemp";// Strings for Book fields.
	// cmd = command(search or sort), word = word to find, in=in, category = field.
	while (getline(command, line1))
	{	// Read line from file. If there is no line, loop will be ended.
		try {
			istringstream tokenizer(line1);		// For parsing line.
			getline(tokenizer, cmd,' ');		// get string until whitespace,it's command.
			getline(tokenizer, word,' ');		// get string until whitespace,it's word.
			if ( word.length() >= 3 ) {
				word.erase(word.begin());	// word is between "". So '"' delete here.			
				word.erase(word.end()-1);	// delete last ".
			}
			if ( cmd == "search" )
			{	// If the command is search
				getline(tokenizer, in, ' ');	// get string until whitespace,it's in.
				getline(tokenizer, category, ' '); // get string until whitespace,it's category.
				category.erase(category.begin());	// category is between "".So '"' delete here.
				category.erase(category.end() - 1);	// delete last ".
				if ( in != "in" )	throw "Exception: command is wrong";
				if ( getline(tokenizer,temps) )	throw "Exception: command is wrong";
				if (category == "title" || category == "authors" || category == "year" || category == "tags")
					out << line1 << endl;	// If category is valid, prints the command line.
				else	// If it is invalid, throw an exception.
					throw "Exception: command is wrong";

				vector <Book> ::iterator i;		// Iterator for seek existing vector,sets.
				for (i = this->sets.begin(); i != this->sets.end(); ++i)
				{
					if ( category == "title" )
					{	// If category is title.
						size_t found = i->title.find(word); // string find function for search command.
						if (found != std::string::npos)
						{	// If word is found, prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->authors << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->tags << '"' << endl;
						}
					}
					else if ( category == "authors" )
					{	// If category is authors.
						size_t found = i->authors.find(word);  // string find function for search command.
						if (found != std::string::npos)
						{	// If word is found, prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->authors << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->tags << '"' << endl;
						}
					}
					else if ( category == "year" )
					{	// If category is year.
						size_t found = i->year.find(word);	// string find function for search command.
						if (found != std::string::npos)
						{	// If word is found, prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->authors << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->tags << '"' << endl;
						}
					}
					else if ( category == "tags" )
					{	// If category is tags.
						size_t found = i->tags.find(word); // string find function for search command.
						if (found != std::string::npos)
						{	// If word is found, prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->authors << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->tags << '"' << endl;
						}
					}
				}
			}
			else if ( cmd == "sort" )
			{	// If command is sort.
				if ( getline(tokenizer,temps) )	throw "Exception: command is wrong";
				if ( word == "title" )			// sort for title.
					sort(this->sets.begin(), this->sets.end(), sortingTitle);
				else if ( word == "authors" )	// sort for authors.
					sort(this->sets.begin(), this->sets.end(), sortingAuthors);
				else if ( word == "year" )		// sort for year.
					sort(this->sets.begin(), this->sets.end(), sortingYear);
				else if ( word == "tags" )		// sort for tags.
					sort(this->sets.begin(), this->sets.end(), sortingTags);
				else
					throw "Exception: command is wrong";	// If word isn't title,authors,year or tags. Exception wrong error.
				
				out << line1 << endl;
				vector <Book> ::iterator i;	// Iterator for seeking the vector,sets.
				for (i = this->sets.begin(); i != this->sets.end(); ++i)
				{	// Printing sorted data to the output file.
					out << '"' << i->title << '"' << " ";
					out << '"' << i->authors << '"' << " ";
					out << '"' << i->year << '"' << " ";
					out << '"' << i->tags << '"' << endl;
				}
			}	
			else	// If command is not search or sort, Exception: wrong error.
				throw "Exception: command is wrong";
		}
		catch (const char* n) // If there is a problem in commands, prints to file wrong error.
		{
			out << n << endl;
			out << line1 << endl;
		}
	}
	out.close();
	command.close();
}

template <class T>
void Catalog<T>::readCommandsMusic(ofstream& out)
{
	ifstream command("commands.txt");	// open commands.txt file.
	string line1;						// temp string for parsing line.
	string cmd, word="thisisatemp", in="thisisatemp",category="thisisatemp",temps="thisisatemp";// Strings for Music fields.
	// cmd = command(search or sort), word = word to find, in=in, category = field.
	while (getline(command, line1))
	{	// Read line from file. If there is no line, loop will be ended.
		try {
			istringstream tokenizer(line1);		// For parsing line.
			getline(tokenizer, cmd, ' ');		// get string until whitespace,it's command.
			getline(tokenizer, word, ' ');		// get string until whitespace,it's word.
			if ( word.length() >= 3 ) {
				word.erase(word.begin());	// word is between "". So '"' delete here.			
				word.erase(word.end()-1);	// delete last ".
			}

			if ( cmd == "search" )
			{	// If the command is search
				getline(tokenizer, in, ' ');	// get string until whitespace,it's in.
				getline(tokenizer, category, ' ');	// get string until whitespace,it's category.
				category.erase(category.begin());	// category is between "".So '"' delete here.
				category.erase(category.end() - 1);	// delete last ".
				if ( in != "in" )	throw "Exception: command is wrong";
				if ( getline(tokenizer,temps) )	throw "Exception: command is wrong";
				if (category == "title" || category == "artist" || category == "year" || category == "genre")
					out << line1 << endl;	// If category is valid, prints the command line.
				else	// If it is invalid, throw an exception.
					throw "Exception: command is wrong";

				vector <Music> ::iterator i;		// Iterator for seek existing vector,sets.
				for (i = this->sets.begin(); i != this->sets.end(); ++i)
				{	// Search in iteration.
					if ( category == "title" )
					{	// If category is title.
						size_t found = i->title.find(word);	// string find function for search command.
						if (found != std::string::npos)
						{	// If word is found, prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->artist << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->genre << '"' << endl;
						}
					}
					else if ( category == "artist" )
					{	// If category is artist.
						size_t found = i->artist.find(word);	// string find function for search command.
						if (found != std::string::npos)
						{	// If word is found, prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->artist << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->genre << '"' << endl;
						}
					}
					else if ( category == "year" )
					{
						size_t found = i->year.find(word);	// string find function for search command.
						if (found != std::string::npos)
						{	// If word is found, prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->artist << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->genre << '"' << endl;
						}
					}
					else if ( category == "genre" )
					{
						size_t found = i->genre.find(word);		// string find function for search command.
						if (found != std::string::npos)
						{	// If word is found, prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->artist << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->genre << '"' << endl;
						}
					}
				}
			}
			else if ( cmd == "sort" )
			{	// If command is sort.
				if ( getline(tokenizer,temps) )	throw "Exception: command is wrong";
				if ( word == "title" )		// sort for title.
					sort(this->sets.begin(), this->sets.end(), sortingTitle);
				else if ( word == "artist" ) // sort for artist.
					sort(this->sets.begin(), this->sets.end(), sortingArtist);
				else if ( word == "year" )   // sort for year.
					sort(this->sets.begin(), this->sets.end(), sortingYear);
				else if ( word == "genre" )  // sort for genre.
					sort(this->sets.begin(), this->sets.end(), sortingGenre);
				else	// If word isn't title,artist,year or genre. Exception wrong error.
					throw "Exception: command is wrong";
				
				out << line1 << endl;
				vector <Music> ::iterator i;
				for (i = this->sets.begin(); i != this->sets.end(); ++i)
				{	// Printing sorted data to the output file.
					out << '"' << i->title << '"' << " ";
					out << '"' << i->artist << '"' << " ";
					out << '"' << i->year << '"' << " ";
					out << '"' << i->genre << '"' << endl;
				}
			}
			else  // If command is not search or sort, Exception: wrong error.
				throw "Exception: command is wrong";
		}
		catch (const char* n)
		{   // If there is a problem in commands, prints to file wrong error.
			out << n << endl;
			out << line1 << endl;
		}
	}
	out.close();
	command.close();
}

template <class T>
void Catalog<T>::readCommandsMovie(ofstream& out)
{
	ifstream command("commands.txt");		// open commands.txt file.
	string line1;							// temp string for parsing line.
	string cmd, word="thisisatemp", in="thisisatemp",category="thisisatemp",temps="thisisatemp";// Strings for Movie fields.
	// cmd = command(search or sort), word = word to find, in=in, category = field.
	while (getline(command, line1))
	{	// Read line from file. If there is no line, loop will be ended.
		try {
			istringstream tokenizer(line1);	// For parsing line.
			getline(tokenizer, cmd, ' ');	// get string until whitespace,it's command.
			getline(tokenizer, word, ' ');	// get string until whitespace,it's word.
			if ( word.length() >= 3 ) {
				word.erase(word.begin());	// word is between "". So '"' delete here.			
				word.erase(word.end()-1);	// delete last ".
			}
			if ( cmd == "search" )
			{	// If the command is search
				getline(tokenizer, in, ' ');		// get string until whitespace,it's in.
				getline(tokenizer, category, ' ');	// get string until whitespace,it's category.
				category.erase(category.begin());	// category is between "".So '"' delete here.
				category.erase(category.end() - 1);	// delete last ".
				//search "Monkey" in "title"
				if ( in != "in" )	throw "Exception: command is wrong";
				if ( getline(tokenizer,temps) )	throw "Exception: command is wrong";
				if ( category == "title" || category == "director" || category == "year"
					|| category == "genre" || category == "starring")
					out << line1 << endl;
				else
					throw "Exception: command is wrong";
				
				vector <Movie> ::iterator i;		// Iterator for seek existing vector,sets.
				for (i = this->sets.begin(); i != this->sets.end(); ++i)
				{	// Search in iteration.
					if ( category == "title" )
					{	// If category is title.
						size_t found = i->title.find(word);
						if (found != std::string::npos)
						{	// prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->director << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->genre << '"';
							out << '"' << i->starring << '"' << endl;
						}
					}
					else if ( category == "director" )
					{	// If category is director.
						size_t found = i->director.find(word);
						if (found != std::string::npos)
						{	// prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->director << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->genre << '"';
							out << '"' << i->starring << '"' << endl;
						}
					}
					else if ( category == "year" )
					{	// If category is year.
						size_t found = i->year.find(word);
						if (found != std::string::npos)
						{	// prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->director << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->genre << '"';
							out << '"' << i->starring << '"' << endl;
						}
					}
					else if ( category == "genre" )
					{	// If category is genre.
						size_t found = i->genre.find(word);
						if (found != std::string::npos)
						{	// prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->director << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->genre << '"';
							out << '"' << i->starring << '"' << endl;
						}
					}
					else if ( category == "starring" )
					{	// If category is starring.
						size_t found = i->starring.find(word);
						if (found != std::string::npos)
						{	// prints result to the output file.
							out << '"' << i->title << '"' << " ";
							out << '"' << i->director << '"' << " ";
							out << '"' << i->year << '"' << " ";
							out << '"' << i->genre << '"';
							out << '"' << i->starring << '"' << endl;
						}
					}
				}
			}
			else if ( cmd == "sort" )
			{	// If command is sort.
				if ( getline(tokenizer,temps) )	throw "Exception: command is wrong";
				if ( word == "title" )				// sort for title.
					sort(this->sets.begin(), this->sets.end(), sortingTitle);
				else if ( word == "director" )		// sort for director. 
					sort(this->sets.begin(), this->sets.end(), sortingDirector);
				else if ( word == "year" )			// sort for year.
					sort(this->sets.begin(), this->sets.end(), sortingYear);
				else if ( word == "genre")		// sort for genre.
					sort(this->sets.begin(), this->sets.end(), sortingGenre);
				else if ( word == "starring" )		// sort for starring.
					sort(this->sets.begin(), this->sets.end(), sortingStarring);
				else	// If word isn't title,director,year,genre or starring. Exception wrong error.
					throw "Exception: command is wrong";

				out << line1 << endl;
				vector <Movie> ::iterator i;
				for (i = this->sets.begin(); i != this->sets.end(); ++i)
				{	// Printing sorted data to the output file.
					out << '"' << i->title << '"' << " ";
					out << '"' << i->director << '"' << " ";
					out << '"' << i->year << '"' << " ";
					out << '"' << i->genre << '"' << " ";
					out << '"' << i->starring << '"' << endl;
				}
			} 
			else	 // If command is not search or sort, Exception: wrong error.
				throw "Exception: command is wrong";
		}
		catch (const char* n)
		{	 // If there is a problem in commands, prints to file wrong error.
			out << n << endl;
			out << line1 << endl;
		}
	}
	out.close();
	command.close();
}

// Short sorting functions. These are using for sort function in "algorithm".
// There are 8 different field names in this Catalog.
template <class T>
bool Catalog<T>::sortingTitle(const T& t1, const T& t2)
{	return t1.title < t2.title;	}

template <class T>
bool Catalog<T>::sortingAuthors(const T& t1, const T& t2)
{	return t1.authors < t2.authors;	}

template <class T>
bool Catalog<T>::sortingYear(const T& t1, const T& t2)
{	return t1.year < t2.year;	}

template <class T>
bool Catalog<T>::sortingTags(const T& t1, const T& t2)
{	return t1.tags < t2.tags;	}

template <class T>
bool Catalog<T>::sortingArtist(const T& t1, const T& t2)
{	return t1.artist < t2.artist;	}

template <class T>
bool Catalog<T>::sortingGenre(const T& t1, const T& t2)
{	return t1.genre < t2.genre;	}

template <class T>
bool Catalog<T>::sortingDirector(const T& t1, const T& t2)
{	return t1.director < t2.director;	}

template <class T>
bool Catalog<T>::sortingStarring(const T& t1, const T& t2)
{	return t1.starring < t2.starring;	}