#include <iostream>
#include <cmath>

using namespace std;

double MySqrt(double Number)
{
    return pow(Number, 0.5);
}

double ReadNumber()
{
    double Number;

    cout << "Enter Number: ";
    cin >> Number;

    return Number;
}

int main()
{
    double Number = ReadNumber();

    cout << "MY Sqrt: " << MySqrt(Number) << endl;
    cout << "C++ Sqrt: " << sqrt(Number) << endl;

    return 0;
}