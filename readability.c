#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (letters * 100.0) / words;
    float S = (sentences * 100.0) / words;

    int cl_index = round(0.0588 * L - 0.296 * S - 15.8);

    if (cl_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (cl_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", cl_index);
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }

    if (text[strlen(text) - 1] != ' ')
    {
        count++;
    }

    if (text[0] == ' ')
    {
        count--;
    }

    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            count++;
        }
    }
    return count;
}
