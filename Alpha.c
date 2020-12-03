#include "Alpha.h"

alpha create_alphabet(char *myalpha)
{
    alpha alp;
    alp.length = strlen(myalpha);
    alp.alphabet = myalpha;
    return alp;
}

int char_index_from_alphabet(alpha alp, char c)
{
    for (int i = 0; i < alp.length;i+=1)
    {
        if(alp.alphabet[i] == c)
        {
            return i;
        }
    }
    return -1;
}

bool is_in_alphabet(alpha alp,char c)
{
    for (int i = 0; i < alp.length;i+=1)
    {
        if(alp.alphabet[i] == c)
        {
            return true;
        }
    }
    return false;
}

int modulo_alphabet(alpha alp,int password_length)
{
    return (alp.length % password_length);
}

void print_alphabet(alpha alp)
{
    printf("Length : %d\n",alp.length);
    for (int i = 0; i < alp.length; i+=1)
    {
        printf("%c",alp.alphabet[i]);
    }
    printf("\n");
}

int char_to_code(char car)
{
    return (int)car;
}

char alphabet_get_index(int index,alpha alp)
{
    if(index < 0 || index > alp.length){return -1;} 

    return alp.alphabet[index];
}