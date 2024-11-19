#include <cs50.h>
#include <stdio.h>

string get_operator(int start, int size);
int get_start(long cardNumber);
int get_size(long cardNumber);
bool validate_card(long cardNumber, int size);
int double_and_sum(int digit);

int main(void)
{
    long cardNumber = get_long("Insert you card number\n");
    int start = get_start(cardNumber);
    int size = get_size(cardNumber);
    string operator= get_operator(start, size);
    bool isValid = validate_card(cardNumber, size);

    if (isValid)
    {
        printf("%s", operator);
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_start(long cardNumber)
{
    long start = cardNumber;
    while (start >= 100)
    {
        start /= 10;
    }

    return start;
}

int get_size(long cardNumber)
{
    int size = 0;
    long start = cardNumber;

    while (start >= 1)
    {
        start /= 10;
        size++;
    }

    return size;
}

string get_operator(int start, int size)
{
    string operator;

    if ((start >= 40 && start < 50) && (size == 13 || size == 16))
    {
        operator= "VISA\n";
    }
    else if (start >= 51 && start <= 55 && size == 16)
    {
        operator= "MASTERCARD\n";
    }
    else if ((start == 34 || start == 37) && size == 15)
    {
        operator= "AMEX\n";
    }
    else
    {
        operator= "INVALID\n";
    }

    return operator;
}

bool validate_card(long cardNumber, int size)
{
    int every_other_digits = 0;
    int check_digits = 0;
    bool isEvery = false; // using boolean variable to keep track where we're at in our loop;

    while (size > 0)
    {
        int digit = cardNumber % 10; // remainder is the last digit;

        if (isEvery)
        {
            int sum = double_and_sum(digit);
            every_other_digits += sum;
            isEvery = false;
        }
        else
        {
            check_digits += digit;
            isEvery = true;
        }

        size--;           // decrease size variable to avoid infinite loop
        cardNumber /= 10; // move to the left
    }

    int sum = every_other_digits + check_digits;
    int lastNumber = sum % 10;

    return lastNumber == 0;
}

int double_and_sum(int digit) // double the digit and get its digits sum if bigger then 10;
{
    digit *= 2;

    if (digit >= 10)
    {
        int partial = digit % 10;
        return partial + 1;
    }
    else
    {
        return digit;
    }
}
