#ifndef VIGMOD_HEADER
#define VIGMOD_HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Alpha.h"

char* encode_vigmod(char* text,char *password,alpha alp);
int rotate_char_from_alphabet(char orig_c,char new_c,alpha alp);
int add_modulo_to_position(int position,char *password,alpha alp);
char* vigenere_rotate_from_alphabet(char *text,char *password,alpha alp);

#endif