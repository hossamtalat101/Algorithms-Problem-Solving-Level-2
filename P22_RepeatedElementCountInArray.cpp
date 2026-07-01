#include <iostream>
#include <string>

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

void ReadArray(int Array[100], int &ArrLength)
{
    cout << "Enter Number of elements: ";
    cin >> ArrLength;

    cout << "Enter array elements:" << endl;
    for (int i = 0; i < ArrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> Array[i];
    }
    cout << endl;
}

void PrintArray(int Array[], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}

int TimesRepeated(int Array[], int ArrayLength, int NumToCheck)
{
    int Count = 0;

    for (int i = 0; i < ArrayLength; i++)
    {
        if (Array[i] == NumToCheck)
            Count++;
    }

    return Count;
}

int main()
{
    int Array[100], ArrayLength;

    ReadArray(Array, ArrayLength);

    int NumToCheck = ReadPositiveNumber("Enter the number you want to check: ");

    cout << "Original Array: ";
    PrintArray(Array, ArrayLength);

    cout << "Number " << NumToCheck << "is repeated ";
    cout << TimesRepeated(Array, ArrayLength, NumTocheck) << "time(s)" << endl;
    return 0;
}