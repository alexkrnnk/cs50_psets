
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    char c;
    if (argc != 2)
    {
        printf("Должен быть только один ключ\n");
        return 1;
    }
    int key = atoi(argv[1]);
    for(int i = 0; i < strlen(argv[1]); i++)
    {
        if(isalpha(argv[1][i]))
        {
            return 1;
        }
    }
    if (key < 0)
    {
        printf("Ключ должен быть больше 0\n");
        return 1;
    }
    else
    {
        string str = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(str); i++)
            {
                if(islower(str[i]))
                {
                    c = (((str[i] + key) - 97) % 26) + 97;
                    printf("%c", c);
                }
                else if(isupper(str[i]))
                {
                    c = (((str[i] + key) - 65) % 26) + 65;
                    printf("%c", c);
                }
                else
                {
                    c = str[i];
                    printf("%c", c);
                }
            }
            printf("\n");
    }
    return 0;
}