#include <iostream>
#include <cmath>

using namespace std;

int MySqrt(float Number)
{
    return pow(Number, 0.5);
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

    cout << "MY Sqrt: " << MySqrt(Number) << endl;
    cout << "C++ Sqrt: " << sqrt(Number) << endl;

    return 0;
}