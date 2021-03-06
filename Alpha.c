#include "Alpha.h"

alpha create_alphabet(char *myalpha)
{
    alpha alp;
    alp.length = strlen(myalpha);
    alp.alphabet = myalpha;
    return alp;
}

int alphabet_get_index_from_char(alpha alp, char c)
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

int alphabet_modulo(alpha alp,char *password)
{
    int res = 0;
    for (unsigned int i=0;i < strlen(password);i+=1)
    {
        res += alphabet_get_index_from_char(alp,password[i]);
    }
    return (res % alp.length);
}

void alphabet_identify_text_by_index(char *text,alpha alp)
{
    printf("%s : \n",text);
    for (unsigned int i = 0; i < strlen(text); i+=1)
    {
        printf("%c : %d\n",text[i],alphabet_get_index_from_char(alp,text[i]));
    }
    printf("\n");
}

void alphabet_print(alpha alp)
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