#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");

    int c;
    int count = 0;
    int index = 0;
    int gistoGramm[10];
    for (int p = 0; p < 10; ++p)
    {
        gistoGramm[p] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            gistoGramm[index] = count;
            ++index;
            count = 0;
        }
        
        ++count;
    }

    printf("<=================Vertical Gistogramm=================>\n");
    for(int i = 1; i < 10; ++i)
    {
        for (int k = 0; k < 10; ++k)
        {
            if (gistoGramm[k] - i > 0)
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
}