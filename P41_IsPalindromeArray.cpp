#include <iostream>

using namespace std;

void FillArray(int Array[100], int &Length)
{
    Length = 6;

    Array[0] = 10;
    Array[1] = 20;
    Array[2] = 30;
    Array[3] = 30;
    Array[4] = 20;
    Array[5] = 10;
}

bool IsPalindromeArray(int Array[100], int Length)
{
    int Left = 0, Right = Length - 1;

    while (Left < Right)
    {
        if (Array[Left] != Array[Right])
        {
            return false;
        }

        Left++;
        Right--;
    }

    return true;
}

bool IsPalindromeArray2(int Array[100], int Length)
{
    for (int i = 0; i < Length / 2; i++)
    {
        if (Array[i] != Array[Length - i - 1])
        {
            return false;
        }
    }

    return true;
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
    int Array[100], Length = 0;

    FillArray(Array, Length);

    if (IsPalindromeArray(Array, Length))
        cout << "\nYes array is Palindrome\n";
    else
        cout << "\nNO array is NOT Palindrome\n";

    if (IsPalindromeArray2(Array, Length))
        cout << "\nYes array is Palindrome\n";
    else
        cout << "\nNO array is NOT Palindrome\n";

    return 0;
}