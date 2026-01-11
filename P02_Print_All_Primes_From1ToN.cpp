#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum enPrimeNotPrime
{
	prime = 1,
	notPrime = 2
};

int ReadPositiveNumber(string message)
{
	int num;
	do
	{
		cout << message;
		cin >> num;
	} while (num < 0);
	return num;
}
enPrimeNotPrime checkPrime(int num)
{
	int n = round(num / 2);
	for (int i = 2; i <= n; i++)
	{
		if (num % i == 0)
			return enPrimeNotPrime::notPrime;
	}
	return enPrimeNotPrime::prime;
}
void printPrimeNumbersFrom1ToN(int num)
{
	cout << "Prime numbers from 1 to " << num << endl;
	for (int i = 1; i <= num; i++)
	{
		if (checkPrime(i) == enPrimeNotPrime::prime)
			cout << i << endl;
	}
}
int main()
{
	printPrimeNumbersFrom1ToN(ReadPositiveNumber("Enter a positive number : "));
	system("pause");
}