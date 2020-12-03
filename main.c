#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "VigMod.h"
#include "Alpha.h"

int main(int argc,char **args)
{
    alpha myalp = create_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZéèà !?1234567890");
    char *result = encode_vigmod("je suis un test","poulpe",myalp);
    printf("%s\n",result);

    

    return 0;
}