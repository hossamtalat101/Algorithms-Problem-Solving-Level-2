#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

enum enPrimeNotPrime
{
    Prime = 1,
    NotPrime = 2
};

enPrimeNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);

    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
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

void CopyPrimeNumbers(int ArraySource[100], int ArrayDestination[100], int Length, int &Length2)
{
    for (int i = 0; i < Length; i++)
    {
        if (CheckPrime(ArraySource[i]) == enPrimeNotPrime::Prime)
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

    CopyPrimeNumbers(
        Array,
        Array2,
        ArrayLength,
        ArrayLength2);

    cout << "\nArray Prime Numbers:\n";
    PrintArray(Array2, ArrayLength2);

    return 0;
}