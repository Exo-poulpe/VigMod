#ifndef ALPHA_HEADER
#define ALPHA_HEADER

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct _alpha{
    int length;
    char *alphabet;
} alpha;


int char_to_code(char car);
void print_alphabet(alpha alp);
alpha create_alphabet(char *myalpha);
bool is_in_alphabet(alpha alp,char c);
char alphabet_get_index(int index,alpha alp);
int char_index_from_alphabet(alpha alp, char c);
int modulo_alphabet(alpha alp,int password_length);
void indentify_char_from_alphabet(char *text,alpha alp);

#endif