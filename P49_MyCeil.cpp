#include <iostream>
#include <cmath>

using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyCeil(float Number)
{
    if (abs(GetFractionPart(Number)) > 0)
    {
        if (Number > 0)
            return int(Number) + 1;
        else
            return int(Number);
    }
    else
        return Number;
}

int MyCeil2(float Number)
{
    int IntPart = int(Number);

    if (abs(GetFractionPart(Number)) > 0 && Number > 0)
        return IntPart + 1;

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

    cout << "MY Ceil: " << MyCeil(Number) << endl;
    cout << "C++ Ceil: " << ceil(Number) << endl;

    return 0;
}