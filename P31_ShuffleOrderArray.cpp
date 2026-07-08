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

void Swap(int &A, int &B)
{
    int Temp;

    Temp = A;
    A = B;
    B = Temp;
}

void FillArrayWith1ToN(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = i + 1;
    }
}

void ShuffleArray(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        int index1 = RandomNumber(1, ArrayLength) - 1;
        int index2 = RandomNumber(1, ArrayLength) - 1;

        Swap(Array[index1], Array[index2]);
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

    int Array[100];
    int ArrayLength = ReadPositiveNumber("\nEnter Number of elements: ");

    FillArrayWith1ToN(Array, ArrayLength);

    cout << "\nArray Elements Before Shuffle:";
    PrintArray(Array, ArrayLength);

    ShuffleArray(Array, ArrayLength);

    cout << "\nArray Elements After Shuffle:";
    PrintArray(Array, ArrayLength);

    return 0;
}