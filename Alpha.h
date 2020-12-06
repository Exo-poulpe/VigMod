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
void alphabet_print(alpha alp);
alpha create_alphabet(char *myalpha);
bool is_in_alphabet(alpha alp,char c);
char alphabet_get_index(int index,alpha alp);
int alphabet_modulo(alpha alp,char *password);
int alphabet_get_index_from_char(alpha alp, char c);
void alphabet_identify_text_by_index(char *text,alpha alp);

#endif