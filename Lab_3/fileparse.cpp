#include <iostream>
#include "fileparse.h"

using namespace std;

char* get_first_line(FILE* in, int bufsize)
{
	char* buffer = new char[bufsize];
	fgets(buffer, bufsize, in);
	rewind(in);
	return buffer;
}

char* get_next_line(FILE* in, int bufsize)
{
	char* buffer = new char[bufsize];
	if (fgets(buffer, bufsize, in) == NULL)
	{
		return NULL;
	}
	return buffer;
}

char* get_last_line(FILE* in, int bufsize)
{
	char* buffer = new char[bufsize];
	while (fgets(buffer, bufsize, in))
	{
		continue;
	}
	return buffer;
}