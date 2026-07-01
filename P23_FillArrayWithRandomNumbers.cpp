#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

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

void FillArrayWithRandomNumbers(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = RandomNumber(1, 100);
    }
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
    int ArrayLength = ReadPositiveNumber("Enter number of elements: ");

    FillArrayWithRandomNumbers(Array, ArrayLength);

    cout << "\nArray Elements:\n";
    PrintArray(Array, ArrayLength);

    return 0;
}