#include <stdio.h>

int main()
{
    int c, spec;
 
    while((c = getchar()) != EOF)
    {
        spec = 0;
        if(c == '\t'){
            printf("\\t");
            spec = 1;
        }
        if(c == '\\'){
            printf("\\\\");
            spec = 1;
        }
        if(c == '\b'){
            printf("\\b");
            spec = 1;
        }
        if(spec == 0)
            putchar(c);
    }
}
