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

void SumOf2Arrays(int Array1[100], int Array2[100], int ArraySum[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        ArraySum[i] = Array1[i] + Array2[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Array1[100], Array2[100], ArraySum[100];
    int ArrayLength = ReadPositiveNumber("\nHow Many Elements: ");

    FillArrayWithRandomNumbers(Array1, ArrayLength);
    cout << "\nArray 1 Elements:";
    PrintArray(Array1, ArrayLength);

    FillArrayWithRandomNumbers(Array2, ArrayLength);
    cout << "\nArray 2 Elements:";
    PrintArray(Array2, ArrayLength);

    SumOf2Arrays(Array1, Array2, ArraySum, ArrayLength);

    cout << "\nSum of array1 and array2 Elements: ";
    PrintArray(ArraySum, ArrayLength);

    return 0;
}