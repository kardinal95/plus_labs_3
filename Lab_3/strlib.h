#pragma once

void parse_file(FILE* in, FILE* out, int size);

char* get_first_word(char* string, int size);

bool contains_word(char* string, char* word, int bufsize);

int count_consonants(char* string);