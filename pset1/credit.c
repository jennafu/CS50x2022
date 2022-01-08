#include <cs50.h>
#include <stdio.h>

int first_digit(long num);
int second_digit(long num);
int find_length(long num);
int checksum(long num);

// Main Function
int main(void)
{
    // Prompt user to enter a credit card number
    long n = get_long("Number: ");

    // Find the first and second digits of entered number
    int digit_1 = first_digit(n);
    int digit_2 = second_digit(n);

    // Find the length of the credit card number
    int count = find_length(n);

    // Apply checksum to credit card
    int is_valid = checksum(n);

    // Check for credit card types (American Express, MasterCard, Visa
    if ((is_valid == 1) & (digit_2 == 34 || digit_2 == 37) & (count == 15))
    {
        printf("AMEX\n");
    }
    else if ((is_valid == 1) & (digit_2 == 51 | digit_2 == 52 | digit_2 == 53 | digit_2 == 54 | digit_2 == 55) & (count == 16))
    {
        printf("MASTERCARD\n");
    }
    else if ((is_valid == 1) & (digit_1 == 4) & (count == 13 | count == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Supporting Functions
int first_digit(long num)
{
    while (num >= 10)
    {
        num = num / 10;
    }
    return num;
}

int second_digit(long num)
{
    while (num >= 100)
    {
        num = num / 10;
    }
    return num;
}

int find_length(long num)
{
    int count = 0;
    do
    {
        num /= 10;
        ++count;
    }
    while (num != 0);
    return count;
}

int checksum(long num)
{
    // Set the variables used in calculation
    int count = 0;
    int even_sum = 0;
    int odd_sum = 0;
    int num_digit;

    // Loop through the digits in long variable, in reverse order
    do
    {
        num_digit = num % 10;
        num /= 10;
        ++count;
        // Sum even digits multiplied by 2 & Sum odd digits
        if (count % 2 == 0)
        {
            int multiplied = (num_digit * 2);
            int sum = 0;
            while (multiplied > 0)
            {
                sum = sum + (multiplied % 10);
                multiplied /= 10;
            }
            even_sum = even_sum + sum;

        }
        else if (count % 2 == 1)
        {
            odd_sum = odd_sum + num_digit;
        }
    }
    while (num != 0);

    int is_valid;
    // Add up the two sums and see if last digit is 0
    if ((even_sum + odd_sum) % 10 == 0)
    {
        is_valid = 1;
    }
    else
    {
        is_valid = 0;
    }
    return is_valid;
}