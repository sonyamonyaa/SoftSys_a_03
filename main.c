#include "stringLib.h"
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int main() {
    char text[TXT];
    char word[WORD];

    //input
    inputWord(word);
    inputTxt(text);

    //program stuff
    printGematric(text);
    printf("\n");

//    printf("Atbash Sequences: ");
//    printAtbashEquals(text, word);
    printf("\n");
    printAnagramEquals(text, word);

    return 0;
}
