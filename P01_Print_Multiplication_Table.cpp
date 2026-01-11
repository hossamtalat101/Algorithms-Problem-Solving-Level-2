#include <iostream>
using namespace std;

// Prints the header of the multiplication table
void PrintTableHeader()
{
    cout << "\n\n\t\tMultiplication Table from 1 to 10\n\n\t";

    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }

    cout << "\n----------------------------------------------------------------------------------\n";
}

// Returns proper column separator formatting
string ColumnSeparator(int number)
{
    return (number < 10) ? "   |" : "  |";
}

// Prints the full multiplication table
void PrintMultiplicationTable()
{
    PrintTableHeader();

    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << ColumnSeparator(i) << "\t";

        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }

        cout << endl;
    }
}

int main()
{
    PrintMultiplicationTable();
    return 0;
}
