#include <iostream>
#include "strlib.h"
#include "fileparse.h"

using namespace std;

void main()
{
	FILE *in, *out;
	int bufsize = 255;
	
	fopen_s(&in, "in.txt", "r");
	fopen_s(&out, "out.txt", "w");

	char* first_word = get_first_word(get_first_line(in, bufsize), bufsize);
	char* buffer = new char[bufsize];
	while (true)
	{
		buffer = get_next_line(in, bufsize);
		if (buffer == NULL)
		{
			break;
		}
		if (contains_word(buffer, first_word, bufsize))
		{
			fputs(buffer, out);
		}
	}

	fclose(in);
	freopen_s(&out, "out.txt", "r", out);

	buffer = get_last_line(out, bufsize);
	printf("Number of consonants in last line: %d\n", count_consonants(buffer));
	fclose(out);

	system("PAUSE");
}