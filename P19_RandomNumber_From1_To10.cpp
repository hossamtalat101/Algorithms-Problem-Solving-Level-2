#include <iostream>
#include <cstdlib>
// #include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int main()
{
    // srand(time(NULL));
    srand((unsigned)time(NULL));

    for (int i = 0; i < 3; i++)
    {
        cout << RandomNumber(1, 10) << endl;
    }

    return 0;
}