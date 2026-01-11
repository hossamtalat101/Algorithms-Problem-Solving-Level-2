#include <iostream>
#include <string>
using namespace std;

// Reads a positive number from the user
int ReadPositiveNumber(const string &message)
{
	int num;
	do
	{
		cout << message;
		cin >> num;
	} while (num <= 0); // 0 or negative not allowed
	return num;
}

int SumOfDigits(int num)
{
	int remainder = 0, sum = 0;
	while (num > 0)
	{
		remainder = num % 10;
		num /= 10;
		sum += remainder;
	}
	return sum;
}

void PrintResult(int sum)
{
	cout << "Sum of digits = " << sum << endl;
}

int main()
{
	PrintResult(SumOfDigits(ReadPositiveNumber("Enter a positive number : ")));

	return 0;
}