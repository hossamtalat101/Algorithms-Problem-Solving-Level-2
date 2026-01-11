#include <iostream>
#include <string>
using namespace std;

int readPositiveNumber(string message)
{
	int num;
	do
	{
		cout << message;
		cin >> num;
	} while (num < 0);
	return num;
}

void printDigits(int num)
{
	int remainder = 0;
	while (num > 0)
	{
		remainder = num % 10;
		num /= 10;
		cout << remainder << endl;
	}
}

int main()
{
	printDigits(readPositiveNumber("Enter a positive number? "));

	return 0;
}