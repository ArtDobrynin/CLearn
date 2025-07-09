#include <stdio.h>

int main()
{
    int inputChar;
    int previousChar = ' ';

    while ((inputChar = getchar()) != EOF)
    {

        if (inputChar == ' ' && previousChar == ' ')
        {
            previousChar = inputChar;
            inputChar = '\0';
        }
        else
        {
            previousChar = inputChar;
        }
        putchar(inputChar);
    }

    return 0;
}
