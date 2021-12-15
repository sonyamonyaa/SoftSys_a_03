#include "stringLib.h"
#include <stdio.h>
#include <string.h>

void inputTxt(char *text)
{
    int i = 0;
    char ch = getchar();

    while ((ch != '\n' || ch != ' ' || ch != '\t') && i < TXT)
    {
        text[i] = ch;
        i++;
        ch = getchar();
    }
    text[i] = '\0';
}

void inputWord(char *word)
{
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
}

int abatashEquals(char *s1, char *s2)
{
    // get new word in atbash and its reverse

    // scan the text and print any similiar ones
}

int anagramEquals(char *s1, char *s2)
{
    // sort both strings to temps

    // if equals print
}