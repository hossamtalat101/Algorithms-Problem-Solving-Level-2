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

void PrintArray(int Array[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << Array[i] << " ";

    cout << endl;
}

void CopyArray(int ArraySource[100], int ArrayDestination[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        ArrayDestination[i] = ArraySource[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Array[100], Array2[100];
    int ArrayLength = ReadPositiveNumber("Enter Number of elements: ");

    FillArrayWithRandomNumbers(Array, ArrayLength);

    cout << "\nArray 1 Elements:\n";
    PrintArray(Array, ArrayLength);

    CopyArray(Array, Array2, ArrayLength);

    cout << "\nArrary 2 Elements:\n";
    PrintArray(Array2, ArrayLength);

    return 0;
}