#include <stdio.h>
#include <stdbool.h>

#define SPACE 32
#define TABUL 9
#define NEXT 10

//Здесь стоит явно сменить условие в цикле for в будущем ;)
int specialSymbols[3] = { SPACE, TABUL, NEXT};

bool CheckSymbols(char inputChar)
{
    int index;
    bool result = false;

    for(index = 0; index < sizeof(specialSymbols); index++)
    {
        if (inputChar == specialSymbols[index])
        {
            result = true;
            return result;
        }
    }

    return result;
}

int main()
{
    int countChar = 0;
    int inputChar;

    while ((inputChar = getchar()) != EOF)
    {
        if (CheckSymbols(inputChar))
        {
            ++countChar;
        }
    }    

    printf("Count special chars: %d\n", countChar);

    return 0;
}
