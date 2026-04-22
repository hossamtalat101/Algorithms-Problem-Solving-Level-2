#include <iostream>
#include <string>
using namespace std;

// Reads a positive number from the user
int ReadPositiveNumber(string message)
{
	int num;
	do
	{
		cout << message;
		cin >> num;
	} while (num <= 0);
	return num;
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

void PrintAllDigitsFrequency(int num)
{
	for (int i = 0; i < 10; i++)
	{
		short digitFrequency = 0;
		digitFrequency = CountDigitFrequency(i, num);
		if (digitFrequency > 0)
			cout << "Digit " << i << " Frequency is " << digitFrequency << endl;
	}
}

int main()
{
	int num = ReadPositiveNumber("Enter a positive number : ");

	PrintAllDigitsFrequency(num);

	return 0;
}