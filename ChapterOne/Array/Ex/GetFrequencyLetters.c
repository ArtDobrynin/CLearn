#include <stdio.h>

int main()
{
    int c;
    int index = 0;
    int count = 0;
    int codesLetter[10];
    int countLetter[10];

    for (int code = 0; code < 10; ++code)
    {
        codesLetter[code] = 0;
        countLetter[code] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\n' && c != '\t')
        {
            for (int i = 0; i < 10; ++i)
            {
                if (codesLetter[i] == c )
                {
                    ++countLetter[i];
                    printf("Counter letters in if: Index--%d Codes--%c Counter--%d\n", i, codesLetter[i], countLetter[i]);
                    ++count;
                }
            }

            if (count == 0 && index != 10)
            {
                codesLetter[index] = c;
                ++countLetter[index];
                printf("After Add: Index--%d Codes--%c Counter--%d\n", index, codesLetter[index], codesLetter[index]);
                count = 0;
            }

            count = 0;
            ++index;
        }
    }

    printf("<=================Letters Gistogramm=================>\n");

    for (int i = 0; i < 10; ++i)
    {
        if (codesLetter[i] > 0)
        {
            printf(" %c ", codesLetter[i]);
        }
        else
        {
            printf("   ");
        }
    }

    printf("\n");

    for(int i = 0; i < 10; ++i)
    {
        for (int k = 0; k < 10; ++k)
        {
            if (countLetter[k] - i > 0)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }

        printf("\n");
    }

    return 0;
}