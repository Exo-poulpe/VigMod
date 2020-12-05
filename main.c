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
    char *pass = NULL;
    alpha myalp = create_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZéèà !?1234567890");

    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Arguments"),
        OPT_BOOLEAN(0,"encode", &encode, "encode text", NULL, 0, 0),
        OPT_BOOLEAN(0,"decode", &decode, "decode text", NULL, 0, 0),
        OPT_STRING('t', "text", &text, "test only", NULL, 0, 0),
        OPT_STRING('p', "pass", &pass, "password", NULL, 0, 0),
        OPT_END(),
    };


    struct argparse argparse;
    argparse_init(&argparse, options, usages, 0);
    argparse_describe(&argparse, "\nA brief description of what the program does and how it works.", "\nAdditional description of the program after the description of the arguments.");
    argc = argparse_parse(&argparse, argc, argv);
    if ( (encode || decode) && text != NULL && pass != NULL)
    {
        char *result;
        if(encode)
        {
            // indentify_char_from_alphabet(text,myalp);
            result = encode_vigmod(text,pass,myalp);
        } else if(decode)
        {
            // indentify_char_from_alphabet(args[3],myalp);
            result = decode_vigmod(text,pass,myalp);
        }else{
        argparse_usage(&argparse);
        }
        printf("'%s'\n",result);
        free(result);
    }
    else if (argc == 0) {
        argparse_usage(&argparse);
    }
        return 0;
}