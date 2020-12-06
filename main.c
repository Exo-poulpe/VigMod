#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "VigMod.h"
#include "Alpha.h"
#include "argparse.h"

static const char *const usages[] = {
    "VigMod [options] [[--] args]",
    "VigMod [options]",
    NULL,
};


int main(int argc,const char **argv)
{
    bool encode = false;
    bool decode = false;
    char *text = NULL;
    char *file = NULL;
    char *output = "output.txt";
    char *pass = NULL;
    alpha myalp = create_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!? ");

    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Arguments"),
        OPT_BOOLEAN(0,"encode", &encode, "encode text", NULL, 0, 0),
        OPT_BOOLEAN(0,"decode", &decode, "decode text", NULL, 0, 0),
        OPT_STRING('t', "text", &text, "text to encode", NULL, 0, 0),
        OPT_STRING('f', "file", &file, "filepath to use for encoding", NULL, 0, 0),
        OPT_STRING('o', "output", &output, "output filename (default: output.txt)", NULL, 0, 0),
        OPT_STRING('p', "pass", &pass, "password to use", NULL, 0, 0),
        OPT_END(),
    };


    struct argparse argparse;
    argparse_init(&argparse, options, usages, 0);
    argparse_describe(&argparse, "\nThis is a program for Vigenere but with somes modification", "\nAuthor : Exo-poulpe 2020.12.06");
    argc = argparse_parse(&argparse, argc, argv);
    if ( (encode || decode) && text != NULL && pass != NULL)
    {
        char *result;
        if(encode)
        {
            result = encode_vigmod(text,pass,myalp);
        } else if(decode)
        {
            result = decode_vigmod(text,pass,myalp);
        }else{
        argparse_usage(&argparse);
        }
        printf("'%s'\n",result);
        free(result);
    }else if((encode || decode) && file != NULL && pass != NULL)
    {
        if(encode)
        {
            encode_file(file,output,pass,myalp);
        } else if(decode)
        {
            decode_file(file,output,pass,myalp);
        }else{
        argparse_usage(&argparse);
        }
    }
    else if (argc == 0) {
        argparse_usage(&argparse);
    }
        return 0;
}