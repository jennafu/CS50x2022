#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check to see if only one key is entered
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Check to see if the key contains 26 characters
    else if ((argc == 2) && (strlen(argv[1]) != 26))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Loop through the key to check for invalid, duplicate or multiple duplicate characters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        for (int j = i + 1, m = strlen(argv[1]); j < m; j++)
        {
            // Checo for invalid characters
            if (isalpha(argv[1][i]) == 0)
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
            // Check for duplicate or multiple duplicate characters
            else if (argv[1][i] == argv[1][j])
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
        }
    }

    // Define constant, input and output variables
    string original = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string text = get_string("plaintext: ");
    int len = strlen(text);
    char *cipher = malloc(len);

    // Loop through the original sequence of alphabet
    for (int i = 0, n = strlen(original); i < n; i++)
    {
        // Loop through the input text
        for (int j = 0, m = strlen(text); j < m; j++)
        {
            // If the input character is uppercase, map the key to the original sequence by index/position
            if ((isupper(text[j])) && (text[j] == original[i]))
            {
                cipher[j] = toupper(argv[1][i]);
            }
            // If the input character is lowercase, map the key to the original sequence by index/position
            else if ((islower(text[j])) && (text[j] == tolower(original[i])))
            {
                cipher[j] = tolower(argv[1][i]);
            }
            // If the input character is non-alphabetic, return the symbol/whitespaces
            else if (isalpha(text[j]) == 0)
            {
                cipher[j] = text[j];
            }
        }
    }
    printf("ciphertext: %s\n", (string) cipher);
    return 0;
}