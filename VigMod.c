#include "VigMod.h"


int rotate_char_from_alphabet(char orig_c,char pass_c,alpha alp)
{
    if (!is_in_alphabet(alp,orig_c)){return orig_c;} // If is not in alphabet struct return char

    int tmp_orig = char_index_from_alphabet(alp,orig_c);
    // printf("Value text : %c|%d\n",orig_c,tmp_orig);
    int tmp_pass = char_index_from_alphabet(alp,pass_c);
    // printf("Value pass : %c|%d\n",pass_c,tmp_pass);
    int res = (tmp_orig + tmp_pass);
    if (res > alp.length)
    {
        res -= alp.length;
    } 
    else if (res < 0)
    {
        res += alp.length;
    }
    return res;
}

char* vigenere_rotate_from_alphabet(char *text,char *password,alpha alp)
{
    int txt_len = strlen(text);
    char *value = (char *)malloc(txt_len * sizeof(char));
    for (int i = 0,j=0; i < (int)txt_len;i+=1,j+=1)
    {
        if(j > (int)strlen(password)){j=0;} // Reset J if is greater than password length
        int new_pos = rotate_char_from_alphabet(text[i],password[j],alp);
        new_pos = add_modulo_to_position(new_pos,password,alp);
        value[i] = alphabet_get_index(new_pos,alp);
    }
    return value;
}


int add_modulo_to_position(int position,char *password,alpha alp)
{
    position += modulo_alphabet(alp,strlen(password));
    if (position > alp.length)
    {
        position -= alp.length;
    } 
    else if (position < 0)
    {
        position += alp.length;
    }
    return position;
}


char* encode_vigmod(char* text,char *password,alpha alp)
{
    return vigenere_rotate_from_alphabet(text,password,alp);
}