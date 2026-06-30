#include <iostream>
#include <cstdlib>
#include <ctime>
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
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
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

int main()
{
    // srand(time(NULL));
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(enCharType::CapitalLetter);
    cout << GetRandomCharacter(enCharType::SmallLetter);
    cout << GetRandomCharacter(enCharType::SpecialCharacter);
    cout << GetRandomCharacter(enCharType::Digit);

    return 0;
}