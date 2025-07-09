#include <stdio.h>

int main()
{
    int inputChar;

    while ((inputChar = getchar()) != EOF)
    {
        if (inputChar == ' ' || inputChar == '\t')
        {
            inputChar = '\n';
        }

        putchar(inputChar);
    }

    return 0;
}
