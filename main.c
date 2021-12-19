#include "stringLib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *text;
    char *word;
    // calloc() allocate the memory and set 0 to all of them
    text = (char *)calloc(TXT, sizeof(char));
    word = (char *)calloc(WORD, sizeof(char));
    //input
    inputWord(word);
    inputTxt(text);
   
    //print inputs
    puts(word);
    puts(text);
    //program stuff
    printf("Atbash Sequences: ");
    printAbatashEquals(text, word);
    printf("\n");

    

    //free the memory at the end of the program
    free(text);
    free(word);
    return 0;
}
