#include <iostream>
#include <string>

using namespace std;

int ReadNumber()
{
    int Number = 0;
    cout << "\nPlease enter a number: ";
    cin >> Number;

    return Number;
}

void AddArrayElements(int Number, int Array[100], int &ArrayLength)
{
    ArrayLength++;
    Array[ArrayLength - 1] = Number;
}

void InputUserNumberElements(int Array[100], int &ArrayLength)
{
    bool AddMore = true;

    do
    {
        AddArrayElements(ReadNumber(), Array, ArrayLength);
        cout << "\nDo you want to add more numbers..? [0] No, [1] Yes!";
        cin >> AddMore;
    } while (AddMore);
}

void PrintArray(int Array[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << Array[i] << " ";

    cout << endl;
}

int main()
{
    int Array[100], ArrayLength = 0;
    InputUserNumberElements(Array, ArrayLength);

    cout << "\nArray Length: " << ArrayLength << endl;

    cout << "\nArray Elements: ";
    PrintArray(Array, ArrayLength);

    return 0;
}