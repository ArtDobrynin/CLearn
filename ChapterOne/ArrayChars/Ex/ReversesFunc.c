#include<stdio.h>
#define MAX_LENGTH 10

int getline(char chars[]);
void reverse(char chars[], char revchars[], int lim);

int main()
{
    char chars[MAX_LENGTH];
    char revchars[MAX_LENGTH];
    int c;

    int lim = getline(chars);
    reverse(chars, revchars, lim);

    printf("%s", revchars);

    return 0;
}

int getline(char chars[])
{
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i > MAX_LENGTH - 1)
        {
            break;
        }

        chars[i] = c;
    }

    chars[i] = '\0';
    return i;
}

void reverse(char chars[], char revchars[], int lim)
{
    int i;
    for(i = 0; i < lim ; i++)
    {
        revchars[lim - i - 1] = chars[i];
    }

    revchars[lim] = '\0';
}