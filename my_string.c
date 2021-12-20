#include "stringLib.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include <stdlib.h>

//checks if char is alphabetic
bool alphabetic(char ch) {
    return (ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a');
}

bool isBlank(char ch) {
    return (ch == ' ' || ch == '\n' || ch == '\t');
}

//this function sorts and converts to smaller case a given str
void sort(char s[]) {
    int temp, k, l;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }
    for (k = 0; k < strlen(s) - 1; k++) {
        for (l = k + 1; l < strlen(s); l++) {
            if (s[k] > s[l]) {
                temp = s[k];
                s[k] = s[l];
                s[l] = temp;
            }
        }
    }
}

//gematric value of a char
int gematricVal(char ch) {
    int val = 0;
    if (ch >= 'a' && ch <= 'z') {
        val = ch - 'a' + 1;
    }
    if (ch >= 'A' && ch <= 'Z') {
        val = ch - 'A' + 1;
    }
    return val;
}

void inputTxt(char *text) {
    // printf("please enter your txt"); // will fuck up the tester so delete after dbg

    int i = 0;
    char ch;
    scanf("%c", &ch);

    while ((ch != '~') && i < TXT - 1) {
        text[i] = ch;
        i++;
        scanf("%c", &ch);
    }
    text[i] = '\0';
}

static int sumWord = 0;

void inputWord(char *word) {
    // printf("please enter a word"); // will fuck up the tester so delete after dbg

    int i = 0;
    char ch;
    scanf("%c", &ch);

    while ((!isBlank(ch)) && i < WORD - 1) {
        word[i] = ch;
        i++;
        sumWord += gematricVal(ch);
        scanf("%c", &ch);
    }
    word[i] = '\0';
}


void printGematric(char txt[]) {
    printf("Gematria Sequences: ");
    int sum = 0; //, i = 0;
    int f = 0, l = 0;
    int len = (int) strlen(txt);
    //char ans[TXT] = "";
    bool flag = false;
    while (f < len) {
        sum += gematricVal(txt[l]);
        f = l;
        while (l < len) {
            if (sum < sumWord) {
                l++;
                sum += gematricVal(txt[l]);
            }
            if (sum > sumWord) {
                sum -= gematricVal(txt[f]);
                f++;
            }
            if (sum == sumWord) {
                sum = 0;
                //minimal sequence
                while (!alphabetic(txt[f]))
                    f++;
                while (!alphabetic(txt[l]))
                    l--;
                if (flag) {
                    printf("~");
                    for (int i = f; i < l + 1; i++) {
                        printf("%c", txt[i]);
                    }
                } else {
                    for (int i = f; i < l + 1; i++) {
                        printf("%c", txt[i]);
                    }
                    flag = true;
                }
                break;
            }
        }
    }
}

//atbash
char atbashChar(char ch) {
    if (ch >= 'a' && ch <= 'z')
        ch = ('z' - ch) + 'a';
    if (ch >= 'A' && ch <= 'Z')
        ch = ('Z' - ch) + 'A';
    return ch;
}

void atbash(char word[])
{
    int l = strlen(word), i = 0;
    
    while(i < l){
        word[i] = atbashChar(word[i]);
        i++;
    }
    word[i] = '\0';
}

void invertedAtbash(char word[])
{
    int l = strlen(word), i = 0;
    
    char word2[l];//char temp
    strcpy(word2, word);
    
    while(i < l){
        word[l -1 - i] = atbashChar(word2[i]);
        i++;
    }
    word[i] = '\0';
    
}

void printAtbashEquals(char txt[], char word[]) {
    printf("Atbash Sequences: ");
    if (txt == NULL || txt[0] == '\0') {
        return;
    }

    int txtLen = strlen(txt), wordLen = strlen(word);
    int f = 0, f2 = 0, l = 0, l2 = 0, loc = 0, loc2 = 0;

    // get new word in atbash and its reverse
    char abword[wordLen];
    char inv_abword[wordLen];

    strcpy(abword, word);
    strcpy(inv_abword, word);
    atbash(abword);
    invertedAtbash(inv_abword);
    bool flag2 = true;
    bool flag1 = true;

    // scan the text and print any similar ones
    while(l < txtLen){
        f2 = f;  // --->  both inner loops should check the same word

        l = f;
        while(loc < wordLen){

            if(alphabetic(txt[l])){
                if(txt[l] == abword[loc]){
                    loc++;
                }else{
                    f = l;
                    flag1 = false;
                    break;
                }
            }

            l++;
        }
        if(flag1){
            for (int k = f; k < l; k++) {
                printf("%c", txt[k]);
            }
        }

        l2 = f2;
        while(loc2 < wordLen){

            if(alphabetic(txt[l2])){
                if(txt[l2] == inv_abword[loc2]){
                    loc2++;
                }else{
                    f2 = l2;
                    flag2 = false;
                    break;
                }
            }

            l2++;
        }
        if(flag2){
            for (int k = f2; k < l2; k++) {
                printf("%c", txt[k]);
            }
        }

        f++;

        loc2 = 0;
        loc = 0;
        flag1 = true;
        flag2 = true;
    }
}
// anagram
bool anagramEquals(char sorted[],char* sub, int len) {
    // sort substring
    char temp[len];
    for(int i =0;i<len;i++)
        temp[i] = *(sub+i);
    sort(temp);

    // if equals
    int j = 0;
    while (isBlank(temp[j]))
        j++;
    int srLen = strlen(sorted);
    for (int i = 0; i < srLen; i++)
        if (sorted[i] != temp[i + j])
            return false;
    return true;
}

void printAtbashEquals(char txt[], char word[]) {
    printf("Atbash Sequences: ");
    if (txt == NULL || txt[0] == '\0') {
        return;
    }

    int txtLen = strlen(txt), wordLen = strlen(word);
    int f = 0, f2 = 0, l = 0, l2 = 0, loc = 0, loc2 = 0;

    // get new word in atbash and its reverse
    char abword[wordLen];
    char inv_abword[wordLen];

    strcpy(abword, word);
    strcpy(inv_abword, word);
    atbash(abword);
    invertedAtbash(inv_abword);
    bool flag2 = true;
    bool flag = true; //for printing

    // scan the text and print any similar ones
    while(l < txtLen){
        f2 = f;  // --->  both inner loops should check the same word

        l = f;
        while(loc < wordLen){
            
            if(alphabetic(txt[l])){
                if(txt[l] == abword[loc]){
                    loc++;
                }else{
                    flag = false;
                    break;
                }
            }
                
            l++;
        }
        if(flag){
            for (int k = f; k < l; k++) {
                    printf("%c", txt[k]);
                }
                
            printf("~");
        }

        l2 = f2;
        while(loc2 < wordLen){
            
            if(alphabetic(txt[l2])){
                if(txt[l2] == inv_abword[loc2]){
                    loc2++;
                }else{
                    flag2 = false;
                    break;
                }
            }
                
            l2++;
        }
        if(flag2){
            for (int k = f2; k < l2; k++) {
                    printf("%c", txt[k]);
                }
                
            printf("~");
        }

        f++;

        loc2 = 0;
        loc = 0;
        flag = true;
        flag2 = true;
    }
}
