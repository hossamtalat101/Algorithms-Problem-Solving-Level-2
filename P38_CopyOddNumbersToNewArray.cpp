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

void FillArrayWithRandomNumbers(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = RandomNumber(1, 100);
    }
}

void AddArrayElements(int Number, int Array[100], int &ArrayLength)
{
    ArrayLength++;
    Array[ArrayLength - 1] = Number;
}

void CopyOddNumbers(int ArraySource[100], int ArrayDestination[100], int Length, int &Length2)
{
    for (int i = 0; i < Length; i++)
    {
        if (ArraySource[i] % 2 != 0)
            AddArrayElements(ArraySource[i], ArrayDestination, Length2);
    }
}

void PrintArray(int Array[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << Array[i] << " ";

    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int Array[100], Array2[100];

    int ArrayLength = ReadPositiveNumber("Enter Number of elements: ");
    int ArrayLength2 = 0;

    FillArrayWithRandomNumbers(Array, ArrayLength);

    cout << "\nArray 1 Elements:\n";
    PrintArray(Array, ArrayLength);

    CopyOddNumbers(
        Array,
        Array2,
        ArrayLength,
        ArrayLength2);

    cout << "\nArray Odd Numbers:\n";
    PrintArray(Array2, ArrayLength2);

    return 0;
}