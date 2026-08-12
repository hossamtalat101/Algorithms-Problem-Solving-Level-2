#include <iostream>
#include <cmath>

using namespace std;

int MyFloor(float Number)
{
    int IntPart = int(Number);

    if (Number < 0 && Number != IntPart)
        return IntPart - 1;

    return IntPart;
}

float ReadNumber()
{
    float Number;

    cout << "Enter Number: ";
    cin >> Number;

    return Number;
}

int main()
{
    float Number = ReadNumber();

    cout << "MY Floor: " << MyFloor(Number) << endl;
    cout << "C++ Floor: " << floor(Number) << endl;

    return 0;
}