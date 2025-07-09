#include<stdio.h>
#define MAXLINE 200

int getFullline(char line[], int maxline);
void copy(char to[], char from[]);
void trim(char chars[], int len);

void main ()
{
    int len;
    char line[MAXLINE];

    while ((len = getFullline(line, MAXLINE)) > 0)
    {
        trim(line, len);

        if (line[0] != '\0')
            printf("%s", line);
    }
}

int getFullline(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i > lim - 1)
        {
            break;
        }
        s[i] = c;
    }
    
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

void trim(char chars[], int len)
{
    int i;
    for (i = len - 1; i >= 0; --i)
    {
        if (chars[i] == ' ' || chars[i] == '\t'|| chars[i] == '\n')
        {
            chars[i] = '\0';
        }
        else
        {
            break;
        }
    }
}