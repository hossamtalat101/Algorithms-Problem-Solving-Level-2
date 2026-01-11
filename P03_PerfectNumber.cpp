#include <iostream>
using namespace std;

enum PerfectStatus
{
	Perfect = 1,
	NotPerfect = 2
};

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

// Checks if a number is perfect
PerfectStatus CheckPerfectNumber(int num)
{
	int sum = 0;
	for (int i = 1; i < num; i++)
	{
		if (num % i == 0)
			sum += i;
	}
	return (sum == num) ? Perfect : NotPerfect;
}

// Prints if a number is perfect or not
void PrintPerfectNumber(int num)
{
	if (CheckPerfectNumber(num) == Perfect)
		cout << num << " is perfect" << endl;
	else
		cout << num << " is not perfect" << endl;
}

int main()
{
	PrintPerfectNumber(ReadPositiveNumber("Enter a positive number: "));
	return 0;
}
