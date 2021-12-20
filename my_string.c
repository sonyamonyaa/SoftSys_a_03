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

void atbash(char word[]) {
    int len = (int)strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = atbashChar(word[i]);
    }
}

void invertedAtbash(char word[]) {
    int l = (int)strlen(word);
    for (int i = 0; i < l; i++) {
        word[l - 1 - i] = atbashChar(word[i]);
    }
}

void printAtbashEquals(char txt[], char word[]) {

    if (txt == NULL || txt[0] == '\0') {
        return;
    }

    int i = 0, j = 0, len = strlen(txt);

    // get new word in atbash and its reverse
    char abword[WORD];
    char inv_abword[WORD];

    strcpy(abword, word);
    strcpy(inv_abword, word);
    atbash(abword);
    invertedAtbash(inv_abword);

    int wl = strlen(abword);
    bool flag = false;

    // scan the text and print any similar ones
    while (j < len) {
        int currl = 0;
        while (currl != wl) {
            if (alphabetic(txt[j])) {
                if (txt[j] == abword[currl]) {
                    j++;
                    currl++;
                } else {
                    i = j;
                    break;
                }
            } else {
                j++;
            }
        }
        if (i != j) {
            if (flag)
                printf("%c", '~');
            for (int k = i; k <= j; k++) {
                printf("%c", txt[k]);
            }
            if (!flag)
                flag = true;
        }
        i = j;
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

void printAnagramEquals(char txt[], char word[]) {
    printf("Anagram Sequences: ");
    bool flag = false;
    int wordLen = strlen(word);
    int len = strlen(txt);

    char sortedWord[wordLen];
    strcpy(sortedWord,word);
    sort(sortedWord);

    int count = 0;
    int f = 0, l = 0;

    while (l + wordLen <= len) {
        while (count < wordLen) {
            if(!isBlank(txt[l]))
                count++;
            l++;
        }
        if (count == wordLen) {
            if (anagramEquals(sortedWord,&(txt[f]), l-f)) {
                if (flag) {
                    printf("~");
                    for (int i = f; i < l; i++) {
                        printf("%c", txt[i]);
                    }
                } else {
                    for (int i = f; i < l; i++) {
                        printf("%c", txt[i]);
                    }
                    flag = true;
                }
            }
        }
        count=0;
        f++;
        l=f;
    }
}


