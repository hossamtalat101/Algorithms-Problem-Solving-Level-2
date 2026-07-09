#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

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

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumbers(int Array[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        Array[i] = RandomNumber(1, 100);
    }
}

int FindNumberPositionInArray(int Array[100], int ArrayLength, int NumberCheck)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (Array[i] == NumberCheck)
            return i;
    }
    return -1;
}

bool IsNumberInArray(int Number, int Array[100], int ArrayLength)
{
    return FindNumberPositionInArray(Array, ArrayLength, Number) != -1;
}

void PrintArray(int Array[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int Array[100];
    int ArrayLength = ReadPositiveNumber("\nEnter Number of elements: ");

    FillArrayWithRandomNumbers(Array, ArrayLength);

    cout << "\nArray Elements:";
    PrintArray(Array, ArrayLength);

    int Number = ReadPositiveNumber("\nPlease enter a number to search for: ");

    cout << "\nNumber you are looking for is: " << Number << endl;

    if (IsNumberInArray(Number, Array, ArrayLength))
        cout << "Yes, The number is found :-)\n";
    else
        cout << "No, The number is not found :-( \n";

    return 0;
}