#include <iostream>
#include <string>
using namespace std;

// Reads a positive number from the user
int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

int ReverseNumber(int num)
{
    int remainder = 0, reversedNumber = 0;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        reversedNumber = reversedNumber * 10 + remainder;
    }
    return reversedNumber;
}

bool IsPalindromeNumber(int number)
{
    return number == ReverseNumber(number);
}

int main()
{
    if (IsPalindromeNumber(ReadPositiveNumber("Enter a positive number : ")))
        cout << "Yes, it is a Palindrome Number\n";
    else
        cout << "No, it is not a Palindrome Number\n";

    return 0;
}