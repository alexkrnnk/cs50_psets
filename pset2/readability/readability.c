

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int get_index(string s);

int main(void)
{
    string text = get_string("Text: ");
    int index = get_index(text);

    if (index < 1)
    {
        printf("Before Grade 1\n");

    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}

int get_index(string s)
{
    int letters = 0, sentences = 0, words = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        char ch = s[i];
        if (isalpha(ch))
        {
            letters++;
        }
        if (isspace(ch))
        {
            words++;
        }
        if (ch == '.' || ch == '?' || ch == '!')
        {
            sentences++;
        }
    }
    words++;
    return round(0.0588 * 100 * (float)letters / (float)words - 0.296 * 100 * (float)sentences / (float)words - 15.8);
}
