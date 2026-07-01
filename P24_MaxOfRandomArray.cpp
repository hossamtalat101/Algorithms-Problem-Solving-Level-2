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

void FillArrayWithRandomNumbers(int arry[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        arry[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int Array[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << Array[i] << " ";

    cout << endl;
}

int MaxNumberInArray(int Array[100], int Length)
{
    int Max = Array[0];

    for (int i = 1; i < Length; i++)
    {
        if (Array[i] > Max)
            Max = Array[i];
    }

    return Max;
}

int main()
{
    srand((unsigned)time(NULL));

    int Array[100];
    int ArrayLength = ReadPositiveNumber("Enter number of elements: ");

    FillArrayWithRandomNumbers(Array, ArrayLength);

    cout << "\nArray Elements:\n";
    PrintArray(Array, ArrayLength);

    cout << "\nMax Of Arrary is: ";
    cout << MaxNumberInArray(Array, ArrayLength);

    return 0;
}