#ifndef _STRINGLIB_H_
	#define _STRINGLIB_H_
    #include <stdbool.h>
    // a constant definition exported by library:
    #define TXT 1024
    #define WORD 30
//    #define UP_A 'A'
//    #define UP_Z 'Z'
//    #define LOW_A 'a'
//    #define LOW_Z 'z'
    void printGematric(char txt[]);
    // bool gimatricEquals(char* s1, char* s2);
    //void printAtbashEquals(char txt[], char word[]);
    //bool anagramEquals(char* s1, char* s2);
    void inputWord(char* word);
    void inputTxt(char* text);
    
   
#endif