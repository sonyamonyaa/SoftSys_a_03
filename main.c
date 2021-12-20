#include "stringLib.h"
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int main() {
    char text[TXT];
    char word[WORD];
    // calloc() allocate the memory and set 0 to all of them
    // text = (char *)calloc(TXT, sizeof(char));
    // word = (char *)calloc(WORD, sizeof(char));
    //input
    inputWord(word);
    inputTxt(text);
    //print inputs
    // puts(word);
    // puts(text);
    printf("\n");
    printf("%s\n", word);
    printf("%s", text);
    printf("\n");

    //program stuff
//    printf("Atbash Sequences: ");
//    printAtbashEquals(text, word);

    printAnagramEquals(text, word);
    printf("\n");
//    works
//    printGematric(text);
//    printf("\n");



    //free the memory at the end of the program
    // free(text);
    // free(word);
    return 0;
}
