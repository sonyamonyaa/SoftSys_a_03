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
    printf("please enter your txt"); // will fuck up the tester so delete after dbg

    int i = 0;
    char ch = getchar();

    while ((ch != '~') && i < TXT)
    {
        text[i] = ch;
        i++;
        ch = getchar();
    }
    text[i] = '\0';
}

void inputWord(char *word)
{
    printf("please enter a word"); // will fuck up the tester so delete after dbg

    int i = 0;
    char ch = getchar();

    while ((ch != '\n' || ch != ' ' || ch != '\t') && i < WORD)
    {
        word[i] = ch;
        i++;
        ch = getchar();
    }
    word[i] = '\0';
}

char atbashChar(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        ch = ('z' - ch) + 'a';
    if (ch >= 'A' && ch <= 'Z')
        ch = ('Z' - ch) + 'A';
    return ch;
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

int gimatricEquals(char *s1, char *s2)
{
    // get the words gimatric Value
    // scan the text, print when there's an equal word
    int sum = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        sum += gimatricVal(s1[i]);
    }
    for (int i = 0; s2[i] != '\0'; i++)
    {
        sum -= gimatricVal(s2[i]);
    }

    return sum == 0;
}

int abatashEquals(char *s1, char *s2)
{
    // get new word in atbash and its reverse
    // scan the text and print any similiar ones
    // ASUMES CLEAN WORDS! (we wrote a function for it)

    int belongedChars = 0, i, j;

    for (i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; j++)
    {
        if (s1[i] == atbashChar(s2[i]))
        {

            belongedChars++;
            i++;
        }
        else
        {
            return 0;
        }
    }

    return belongedChars == i - 1;
}

char *cleanWord(char *str)
{
    if (strlen(str) == 0)
    {
        return;
    }

    int len = 1, i = 0;

    while ((str[i] != '\n' && str[i] != ' ' && str[i] != '\t') && str[i] != '\0')
    {
        i++;
    }
    int j = i;
    while (str[j] != '\0')
    {
        if (str[j] != ' ')
        {
            len++;
        }
        j++;
    }

    char new[len];
    for (j = 0; j < len - 1; j++)
    {
        if (alphabetic(str[i]))
        {
            new[j] = str[i];
            i++;
        }
    }
    new[len] = '\0';

    return &new[0];
}

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
        strcpy(s1,sortedWord);
        sort(sortedWord);
        isSorted = true;
    }
    char* temp;
    strcpy(s2,temp);
    sort(temp);
    
    // if equals
    return strcmp(sortedWord,temp) == 0;
}
