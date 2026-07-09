#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
    {
        return char(RandomNumber(97, 122));
        break;
    }
    case enCharType::CapitalLetter:
    {
        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {
        return char(RandomNumber(33, 47));
        break;
    }
    case enCharType::Digit:
    {
        return char(RandomNumber(48, 57));
        break;
    }
    }
}

int ReadPositiveNumber(string Message)
{
    int Num;
    do
    {
        cout << Message;
        cin >> Num;
    } while (Num <= 0);
    return Num;
}

string GenerateWord(enCharType CharType, int Length)
{
    string Word;
    for (int i = 0; i < Length; i++)
    {
        Word += GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey()
{
    string key = "";

    for (int i = 0; i < 4; i++)
    {
        key += GenerateWord(enCharType::CapitalLetter, 4);

        if (i != 3)
            key += "-";
    }

    return key;
}

void FillArrayWithKeys(string Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateKey();
    }
}

void PrintStringArray(string Array[100], int Length)
{
    cout << "\nArray Elements:\n";
    for (int i = 0; i < Length; i++)
    {
        cout << "Array[" << i << "]: ";
        cout << Array[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    string Array[100];
    int ArrayLength = ReadPositiveNumber("\nHow many keys do you want to generate..?: ");

    FillArrayWithKeys(Array, ArrayLength);

    PrintStringArray(Array, ArrayLength);

    return 0;
}