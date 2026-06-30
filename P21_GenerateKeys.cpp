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
        return char(RandomNumber(97, 122));

    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90));

    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47));

    case enCharType::Digit:
        return char(RandomNumber(48, 57));

    default:
        return '\0';
    }
}

int ReadPositeveNum(string Message)
{
    int Num;
    do
    {
        cout << Message;
        cin >> Num;
    } while (Num < 0);
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

void GenerateKeys(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
        cout << "key[" << i << "] : " << GenerateKey() << endl;
}

int main()
{
    // srand(time(NULL));
    srand((unsigned)time(NULL));

    GenerateKeys(ReadPositeveNum("Enter how many keys to generate: "));

    return 0;
}