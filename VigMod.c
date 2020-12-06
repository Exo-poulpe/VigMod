#include "VigMod.h"


int encode_char_from_alphabet(char orig_c,char pass_c,alpha alp)
{
    if (!is_in_alphabet(alp,orig_c)){return orig_c;} // If is not in alphabet struct return char

    int tmp_orig = alphabet_get_index_from_char(alp,orig_c);
    // printf("Value text : %c|%d\n",orig_c,tmp_orig);
    int tmp_pass = alphabet_get_index_from_char(alp,pass_c);
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

int decode_char_from_alphabet(char orig_c,char pass_c,alpha alp)
{
    if (!is_in_alphabet(alp,orig_c)){return orig_c;} // If is not in alphabet struct return char

    int tmp_orig = alphabet_get_index_from_char(alp,orig_c);
    // printf("Value text : %c|%d\n",orig_c,tmp_orig);
    int tmp_pass = alphabet_get_index_from_char(alp,pass_c);
    // printf("Value pass : %c|%d\n",pass_c,tmp_pass);
    int res = (tmp_orig - tmp_pass);
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

char* vigenere_encode_from_alphabet(char *text,char *password,alpha alp)
{
    int txt_len = strlen(text);
    char *value = (char *)malloc(txt_len * sizeof(char));
    for (int i = 0,j=0; i < (int)txt_len;i+=1,j+=1)
    {
        if(j > (int)strlen(password)){j=0;} // Reset J if is greater than password length
        int new_pos = encode_char_from_alphabet(text[i],password[j],alp);
        if (i%2 == 0)
        {
            new_pos = add_modulo_to_position(new_pos,password,alp);
        }else
        {
            new_pos = sub_modulo_to_position(new_pos,password,alp);
        }        
        value[i] = alphabet_get_index(new_pos,alp);
    }
    return value;
}

char* vigenere_decode_from_alphabet(char* text,char* password,alpha alp)
{
    int txt_len = strlen(text);
    char *value = (char *)malloc(txt_len * sizeof(char));
    for (int i = 0,j=0; i < (int)txt_len;i+=1,j+=1)
    {
        if(j > (int)strlen(password)){j=0;} // Reset J if is greater than password length
        int new_pos = alphabet_get_index_from_char(alp,text[i]);
        if (i%2 == 0)
        {
            new_pos = sub_modulo_to_position(new_pos,password,alp);
        }else
        {
            new_pos = add_modulo_to_position(new_pos,password,alp);
        }
        new_pos = decode_char_from_alphabet(alphabet_get_index(new_pos,alp),password[j],alp);
        value[i] = alphabet_get_index(new_pos,alp);
    }
    return value;
}


int add_modulo_to_position(int position,char *password,alpha alp)
{
    position += alphabet_modulo(alp,password);
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

int sub_modulo_to_position(int position,char *password,alpha alp)
{
    position -= alphabet_modulo(alp,password);
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
    return vigenere_encode_from_alphabet(text,password,alp);
}

char *decode_vigmod(char* text,char* password, alpha alp)
{
    return vigenere_decode_from_alphabet(text,password,alp);
}

void encode_file(char *file,char *output,char *password,alpha alp)
{
    int i = 0;
    int pass_len = strlen(password);
    FILE *fs;
    FILE *out;
    fs = fopen(file,"r");
    out = fopen(output,"w");
    if(fs == NULL || out == NULL) {
      printf("Error in opening file\n");
      exit(1);
   }
    while(1)
    {
        if(i > pass_len){i = 0;}
        char c = fgetc(fs);
        if(c == EOF){break;}
        if(!is_in_alphabet(alp,c)){fputc(c,out);continue;}
        int new_pos = encode_char_from_alphabet(c,password[i],alp);
        if (i%2 == 0)
        {
            new_pos = add_modulo_to_position(new_pos,password,alp);
        }else
        {
            new_pos = sub_modulo_to_position(new_pos,password,alp);
        }
        fputc(alphabet_get_index(new_pos,alp),out);
        i+=1;
    }

    fclose(fs);
    fclose(out);
}

void decode_file(char *file,char *output,char *password,alpha alp)
{
    int i = 0;
    int pass_len = strlen(password);
    FILE *fs;
    FILE *out;
    fs = fopen(file,"r");
    out = fopen(output,"w");
    if(fs == NULL || out == NULL) {
      printf("Error in opening file\n");
      exit(1);
   }
    while(1)
    {
        if(i > pass_len){i = 0;}
        char c = fgetc(fs);
        if(c == EOF){break;}
        if(!is_in_alphabet(alp,c)){fputc(c,out);continue;}
        int new_pos = alphabet_get_index_from_char(alp,c);
        if (i%2 == 0)
        {
            new_pos = sub_modulo_to_position(new_pos,password,alp);
        }else
        {
            new_pos = add_modulo_to_position(new_pos,password,alp);
        }     
        char new_char = alphabet_get_index(new_pos,alp); 
        char decoded = alphabet_get_index(decode_char_from_alphabet(new_char,password[i],alp),alp);
        fputc(decoded,out);
        i+=1;
    }

    fclose(fs);
    fclose(out);
}