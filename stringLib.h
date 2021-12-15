#ifndef _STRINGLIB_H_
	#define _STRINGLIB_H_

    // a constant definition exported by library:
    #define TXT 1024
    #define WORD 30
//    #define UP_A 'A'
//    #define UP_Z 'Z'
//    #define LOW_A 'a'
//    #define LOW_Z 'z'

    int gimatricEquals(char* s1, char* s2);
    int atbashEquals(char* s1, char* s2);
    int anagramEquals(char* s1, char* s2);
    void inputWord(char* word);
    void inputTxt(char* text);
    
   
#endif