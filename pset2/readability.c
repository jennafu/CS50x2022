#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
    string input = get_string("Text: ");
    float num_letters = count_letters(input);
    float num_words = count_words(input);
    float num_sentences = count_sentences(input);

    // Calculate the average number of letters per words
    float L = (num_letters / num_words) * 100;

    // Calculate the average number of sentences per 100 words
    float S = (num_sentences / num_words) * 100;

    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Count number of letters in the string
float count_letters(string text)
{
    int num_letter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Find characters considered as alphabetical
        if (isalpha(text[i]))
        {
            num_letter += 1;
        }
    }
    return num_letter;
}

// Count number of words in the string
float count_words(string text)
{
    // Initiate number of words at 1, as counting whitespaces between words
    int num_word = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Find characters considered as whitespaces
        if (isspace(text[i]))
        {
            num_word += 1;
        }
    }
    return num_word;
}

// Count number of sentences in the string
float count_sentences(string text)
{
    int num_sentence = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Find characters considered as ".","?","!"
        if (text[i] == '.' | text[i] == '?' | text[i] == '!')
        {
            num_sentence += 1;
        }
    }
    return num_sentence;
}