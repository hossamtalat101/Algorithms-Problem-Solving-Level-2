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
    int remainder = 0, num2 = 0;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        num2 = num2 * 10 + remainder;
    }
    return num2;
}

void PrintDigits(int num)
{
    int remainder = 0;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        cout << remainder << endl;
    }
}

int main()
{
    PrintDigits(ReverseNumber(ReadPositiveNumber("Enter a positive number : ")));

    return 0;
}