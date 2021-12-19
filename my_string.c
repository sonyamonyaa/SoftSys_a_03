#include "stringLib.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int alphabetic(char ch)
{
    return (ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a');
}

void inputTxt(char *text)
{
    //printf("please enter your txt"); // will fuck up the tester so delete after dbg

    int i = 0;
    char ch;
    scanf("%c" , &ch);

    while ((ch != '~') && i < TXT-1)
    {
        text[i] = ch;
        i++;
        scanf("%c" , &ch);;
    }
    text[i] = '\0';
}

void inputWord(char *word)
{
    //printf("please enter a word"); // will fuck up the tester so delete after dbg

    int i = 0;
    char ch;
    scanf("%c" , &ch);

    while ((ch != '\n' && ch != ' ' && ch != '\t') && i < WORD-1)
    {
        word[i] = ch;
        i++;
        scanf("%c" , &ch);
    }
    word[i] = '\0';
}

int gimatricVal(char ch)
{
    int val = 0;
    if (ch >= 'a' && ch <= 'z')
    {
        val = ch - 'a' + 1;
    }
    if (ch >= 'A' && ch <= 'Z')
    {
        val = ch - 'A' + 1;
    }
    return val;
}

bool gotGim = false;
int sumWord = 0;

bool gimatricEquals(char *s1, char *s2)
{
    // get the words gimatric Value
    // scan the text, print when there's an equal word
    int sum;
    if (!gotGim)
    {
        for (int i = 0; s1[i] != '\0'; i++)
        {
            sumWord += gimatricVal(s1[i]);
        }
        gotGim = true;
    }
    sum = sumWord;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        sum -= gimatricVal(s2[i]);
    }

    return sum == 0;
}

char atbashChar(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        ch = ('z' - ch) + 'a';
    if (ch >= 'A' && ch <= 'Z')
        ch = ('Z' - ch) + 'A';
    return ch;
}

void abtash(char* word){
    int l = strlen(word);

    for (short i = 0; i < l; i++)
    {
        word[i] = atbashChar(word[i]);
    }

}

void invertedAbatash(char* word){
    int l = strlen(word);
    for (short i = 0; i < l; i++)
    {
        word[l-1 -i] = atbashChar(word[i]);
    }    
}

// char *cleanWord(char *str)
// {
//     if (strlen(str) == 0)
//     {
//         return str;
//     }
//     int len = 1, i = 0;
//     while ((str[i] != '\n' && str[i] != ' ' && str[i] != '\t') && str[i] != '\0')
//     {
//         i++;
//     }
//     int j = i;
//     while (str[j] != '\0')
//     {
//         if (str[j] != ' ')
//         {
//             len++;
//         }
//         j++;
//     }
//     char new[len];
//     for (j = 0; j < len - 1; j++)
//     {
//         if (alphabetic(str[i]))
//         {
//             new[j] = str[i];
//             i++;
//         }
//     }
//     new[len] = '\0';
//     return &new[0];
// }

void printAbatashEquals(char *txt, char *word)
{
    // get new word in atbash and its reverse
    // scan the text and print any similiar ones
    // ASUMES CLEAN WORDS! (we wrote a function for it)

    
    if (txt == NULL || txt[0] == '\0'){return;}

    int i = 0, j = 0, l = strlen(txt);
    char abword[WORD] ,  inv_abword[WORD];
    strcpy(abword,word);
    strcpy(inv_abword,word);
    abtash(abword); 
    invertedAbatash(inv_abword);
    int wl = strlen(abword);
    bool first = true;
    while (j < l)
    {
        int currl = 0;
        while (currl != wl)
        {
            if(alphabetic(txt[j])){

                if (txt[j] == abword[currl]){
                    j++;
                    currl++;
                }else{i = j; break;}

            }else{
                j++;
            }
        }
        if (i != j){
            if(!first)
                printf("%c", '~');
            for (short k = i; k <= j; k++)
            {
                printf("%c", txt[k]);
            }
            if(first)
                first = false;
        }

        i = j;
    }
}
//anagram
bool isSorted = false;
char *sortedWord;

void sort(char *s)
{
    int temperory = 0, k, l;
    for (k = 0; k < strlen(s) - 1; k++)
    {
        if (s[k] >= 'A' && s[k] <= 'Z')
            s[k] = s[k] - 'A' + 'a';
        for (l = k + 1; l < strlen(s); l++)
        {
            if (s[l] >= 'A' && s[l] <= 'Z')
                s[k] = s[k] - 'A' + 'a';
            if (s[k] > s[l])
            {
                temperory = s[k];
                s[k] = s[l];
                s[l] = temperory;
            }
        }
    }
}

bool anagramEquals(char *s1, char *s2)
{
    // sort both strings to temps
    if (!isSorted)
    {
        strcpy(sortedWord,s1);
        sort(sortedWord);
        isSorted = true;
    }
    char temp [sizeof(s2)];
    strcpy(temp,s2);
    sort(temp);

    // if equals
    return strcmp(sortedWord, temp) == 0;
}
