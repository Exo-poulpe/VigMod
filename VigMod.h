#ifndef VIGMOD_HEADER
#define VIGMOD_HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Alpha.h"

char* encode_vigmod(char* text,char *password,alpha alp);
char *decode_vigmod(char* text,char* password, alpha alp);
int encode_char_from_alphabet(char orig_c,char new_c,alpha alp);
int decode_char_from_alphabet(char orig_c,char pass_c,alpha alp);
int sub_modulo_to_position(int position,char *password,alpha alp);
int add_modulo_to_position(int position,char *password,alpha alp);
char* vigenere_decode_from_alphabet(char* text,char* password,alpha alp);
char* vigenere_encode_from_alphabet(char *text,char *password,alpha alp);

#endif