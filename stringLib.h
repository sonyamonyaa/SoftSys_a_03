#ifndef _STRINGLIB_H_
	#define _STRINGLIB_H_
    #include <stdbool.h>
    // a constant definition exported by library:
    #define TXT 1024
    #define WORD 30

    void printGematric(char txt[]);
    void printAtbashEquals(char txt[], char word[]);
    void printAnagramEquals(char txt[], char word[]);
    void inputWord(char* word);
    void inputTxt(char* text);
    
   
#endif
