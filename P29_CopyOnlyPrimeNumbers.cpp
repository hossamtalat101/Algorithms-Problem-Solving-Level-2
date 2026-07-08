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

void CopyOnlyPrimeNumbers(int ArraySource[100], int ArrayDestination[100], int arrLength, int &Length2)
{
    int Counter = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(ArraySource[i]) == enPrimeNotPrime::Prime)
        {
            ArrayDestination[Counter] = ArraySource[i];
            Counter++;
        }
    }
    Length2 = --Counter;
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

    int Array[100], ArrayLength = ReadPositiveNumber("Enter Number of elements: ");

    FillArrayWithRandomNumbers(Array, ArrayLength);

    int Array2[100], Array2Length = 0;

    CopyOnlyPrimeNumbers(Array, Array2, ArrayLength, Array2Length);

    cout << "\nArray 1 Elements:\n";
    PrintArray(Array, ArrayLength);

    cout << "\nPrime Numbers in Array2:\n";
    PrintArray(Array2, Array2Length);

    return 0;
}