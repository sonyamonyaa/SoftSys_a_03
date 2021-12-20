#include "stringLib.h"
#include <stdio.h>

int main() {
    char text[TXT];
    char word[WORD];

    //input
    inputWord(word);
    inputTxt(text);

    //program stuff
    printGematric(text);
    printf("\n");

    printAtbashEquals(text, word);
    printf("\n");
    printAnagramEquals(text, word);

    return 0;
}