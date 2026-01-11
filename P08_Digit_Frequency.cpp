#include <iostream>
#include <string>
using namespace std;

// Reads a positive number from the user
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

int CountDigitFrequency(short digitToCheck, int num)
{
	int fCount = 0;
	int remainder = 0;
	while (num > 0)
	{
		remainder = num % 10;
		num /= 10;
		if (digitToCheck == remainder)
			fCount++;
	}
	return fCount;
}

int main()
{
	int num = ReadPositiveNumber("Enter a positive number: ");
	short digitToCheck = ReadPositiveNumber("Enter one digit to check: ");
	cout << "Digit " << digitToCheck << " Frequency is " << CountDigitFrequency(digitToCheck, num) << endl;

	return 0;
}