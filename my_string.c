#include "stringLib.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include <stdlib.h>

int alphabetic(char ch) {
    return (ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a');
}

//char *substring(char *string, int position, int length)
//{
//    char *p;
//    int c;
//    p = malloc(length + 1);
//    if (p == NULL)
//    {
//        printf("Unable to allocate memory.\n");
//        exit(1);
//    }
//    for (c = 0; c < length; c++)
//    {
//        *(p + c) = *(string + position - 1);
//        string++;
//    }
//    *(p + c) = '\0';
//    return p;
//}

int gimatricVal(char ch) {
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

    while ((ch != '\n' && ch != ' ' && ch != '\t') && i < WORD - 1) {
        word[i] = ch;
        i++;
        sumWord += gimatricVal(ch);
        scanf("%c", &ch);
    }
    word[i] = '\0';
}


void printGematric(char txt[]) {
    printf("Gematria Sequences: ");
    int sum = 0; //, i = 0;
    int f = 0, l=0;
    int len = (int)strlen(txt);
    //char ans[TXT] = "";
    bool flag = false;
    while (f < len) {
        sum += gimatricVal(txt[l]);
        f=l;
        while (l < len) {
            if (sum < sumWord) {
                l++;
                sum += gimatricVal(txt[l]);
            }
            if (sum > sumWord) {
                sum -= gimatricVal(txt[f]);
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
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = atbashChar(word[i]);
    }
}

void invertedAtbash(char word[]) {
    int l = strlen(word);
    for (short i = 0; i < l; i++) {
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
bool isSorted = false;
char *sortedWord;
//this function sorts and converts to smaller case a given str
void sort(char s[]) {
    int temp, k, l;
    for (k = 0; k < strlen(s) - 1; k++) {
        if (s[k] >= 'A' && s[k] <= 'Z')
            s[k] = s[k] - 'A' + 'a';
        for (l = k + 1; l < strlen(s); l++) {
            if (s[l] >= 'A' && s[l] <= 'Z')
                s[k] = s[k] - 'A' + 'a';
            if (s[k] > s[l]) {
                temp = s[k];
                s[k] = s[l];
                s[l] = temp;
            }
        }
    }
}

bool anagramEquals(char *s1, char *s2) {
    // sort both strings to temps
    if (!isSorted) {
        strcpy(sortedWord, s1);
        sort(sortedWord);
        isSorted = true;
    }
    char temp[sizeof(s2)];
    strcpy(temp, s2);
    sort(temp);

    // if equals
    return strcmp(sortedWord, temp) == 0;
}
