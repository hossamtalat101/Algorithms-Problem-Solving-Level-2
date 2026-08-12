#include <iostream>
#include <cmath>

using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyRound(float Number)
{
    int IntPart = int(Number);

    float FractionsPart = GetFractionPart(Number);

    if (abs(FractionsPart) >= 0.5)
    {
        if (Number > 0)
            return ++IntPart;
        else
            return --IntPart;
    }

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

    cout << "MY Round: " << MyRound(Number) << endl;
    cout << "C++ Round: " << round(Number) << endl;

    return 0;
}