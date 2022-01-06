#include <cs50.h>
#include <stdio.h>

void print_bricks(int n, int lev);

int main(void)
{
    // Prompt user to type a value between 1 and 8 inclusive
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int lev = 1; lev <= n; lev++)
    {
        // Print spaces
        for (int j = n - lev; j > 0; j--)
        {
            printf(" ");
        }

        // Print the first set of bricks
        print_bricks(n, lev);

        // Print two spaces in between
        printf("  ");

        // Print the second set of bricks
        print_bricks(n, lev);

        // Move to next row
        printf("\n");
    }
}

// Supporting Function
void print_bricks(int n, int lev)
{
    // Print set of bricks
    for (int k = n - lev; n - k > 0; k++)
    {
        printf("#");
    }
}