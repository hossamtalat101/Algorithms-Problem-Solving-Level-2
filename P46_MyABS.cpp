#include <iostream>
#include <cmath>

using namespace std;

float MYAbc(float Number)
{
    if (Number < 0)
        return Number * -1;

    return Number;
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

    cout << "MY ABC: " << MYAbc(Number) << endl;
    cout << "C++ ABC: " << fabs(Number) << endl;

    return 0;
}