#include <iostream>
#include "strlib.h"
#include <string.h>

using namespace std;

bool contains_word(char* string, char* word, int bufsize)
{
	char* tokenstring = new char[bufsize];
	strcpy_s(tokenstring, bufsize, string);
	char* buffer = new char[bufsize];
	char* token = strtok_s(tokenstring, " \n", &buffer);

	while (token != NULL)
	{
		if (strcmp(word, token) == 0)
		{
			return true;
		}
		token = strtok_s(NULL, " \n", &buffer);
	}
	return false;
}

char* get_first_word(char* string, int bufsize)
{
	char* word = new char[bufsize];
	sscanf_s(string, "%s", word, (unsigned)bufsize);
	return word;
}

int count_consonants(char* string)
{
	char cons_la[] = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	char cons_cyr[] = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
	int pos = 0;
	int result = 0;

	while (true)
	{
		if (string[pos] == '\0')
		{
			break;
		}
		if ((strchr(cons_la , string[pos]) != NULL) || (strchr(cons_cyr, string[pos]) != NULL))
		{
			result++;
		}
		pos++;
	}
	return result;
}

