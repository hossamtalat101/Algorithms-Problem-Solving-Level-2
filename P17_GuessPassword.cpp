#include <iostream>
#include <string>

using namespace std;

string ReadPassword()
{
    string password;

    cout << "Please enter a 3-letter password (ALL CAPS): ";
    cin >> password;

    return password;
}

bool GuessPassword(const string &originalPassword)
{
    int counter = 0;

    cout << "\n";

    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            for (char k = 'A'; k <= 'Z'; k++)
            {
                string word = "";
                word += i;
                word += j;
                word += k;

                counter++;

                cout << "Trial [" << counter << "] : " << word << endl;

                if (word == originalPassword)
                {
                    cout << "\nPassword is " << word << endl;
                    cout << "Found after " << counter << " trial(s)\n";

                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    GuessPassword(ReadPassword());
    return 0;
}