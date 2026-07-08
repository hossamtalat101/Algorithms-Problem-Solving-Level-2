#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

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
        cout << Array[i] << " ";

    cout << endl;
}

void CopyArrayInReverseOrder(int ArraySource[100], int ArrayDestination[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        ArrayDestination[i] = ArraySource[ArrayLength - 1 - i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Array1[100], Array2[100];
    int ArrayLength = ReadPositiveNumber("\nEnter Number of elements: ");

    FillArrayWithRandomNumbers(Array1, ArrayLength);

    cout << "\nOriginal Array:\n";
    PrintArray(Array1, ArrayLength);

    CopyArrayInReverseOrder(Array1, Array2, ArrayLength);

    cout << "\nReversed Array:\n";
    PrintArray(Array2, ArrayLength);

    return 0;
}