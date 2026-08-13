#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enGameChoice
{
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

enum enWinner
{
    Player = 1,
    Computer = 2,
    Draw = 3
};


int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int ReadNumberOfRounds()
{
    int NumberOfRounds=1;

    do
    {
        cout << "How many rounds do you want to play? ";
        cin >> NumberOfRounds;

    } while (NumberOfRounds <1 || NumberOfRounds >10);
    
    return NumberOfRounds;
}


enGameChoice ReadPlayerChoice()
{
    int YourChoice=1;

    do
    {
        cout << "\nEnter Your Choice: [1] Rock ,[2] Paper ,[3] Scissors ..?: ";
        cin >> YourChoice;

    } while (YourChoice < 1 || YourChoice >3);
    
    return (enGameChoice)YourChoice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

int PlayerWinCount = 0;
int ComputerWinCount = 0;
int DrawCount = 0; 

void ResetGame()
{
    PlayerWinCount = 0;
    ComputerWinCount = 0;
    DrawCount = 0;
}


enWinner WhoWonTheRound(enGameChoice PlayerChoice, enGameChoice ComputerChoice)
{
    if (PlayerChoice == ComputerChoice)
        return enWinner::Draw;

    else if (PlayerChoice == enGameChoice::Rock && ComputerChoice == enGameChoice::Paper)
        return  enWinner::Computer;

    else if (PlayerChoice == enGameChoice::Rock && ComputerChoice == enGameChoice::Scissors)
        return  enWinner::Player;

    else if (PlayerChoice == enGameChoice::Paper && ComputerChoice == enGameChoice::Rock)
        return  enWinner::Player;

    else if (PlayerChoice == enGameChoice::Paper && ComputerChoice == enGameChoice::Scissors)
        return  enWinner::Computer;

    else if (PlayerChoice == enGameChoice::Scissors && ComputerChoice == enGameChoice::Rock)
        return  enWinner::Computer;

    else if (PlayerChoice == enGameChoice::Scissors && ComputerChoice == enGameChoice::Paper)
        return  enWinner::Player;

}

void UpdateGameResults(enWinner Winner)
{
    if (Winner == enWinner::Player)
        PlayerWinCount++;
    else if (Winner == enWinner::Computer)
        ComputerWinCount++;
    else
        DrawCount++;
}

string  ToStringChoice(enGameChoice Choice)
{
    switch (Choice)
    {
    case enGameChoice::Rock:
        return "Rock";
    case enGameChoice::Paper:
        return "Paper";
    case enGameChoice::Scissors:
        return "Scissors";
    }
}

string ToStringWinnder(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player: 
        return "Player";
    case enWinner::Computer:
        return "Computer";
    case enWinner::Draw:
        return "Draw";
    }
}

void PrintRoundResult(enGameChoice PlayerChoice, enGameChoice ComputerChoice, enWinner Winer, int NumberOfRounds)
{
    cout << "\n-----------Round[" << NumberOfRounds + 1 << "]-------- - \n";
    cout << "Player Choice: " << ToStringChoice(PlayerChoice) << endl;
    cout << "Computer Choice: " << ToStringChoice(ComputerChoice) << endl;
    cout << "Round Winer: " << ToStringWinnder(Winer) << endl;
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player:
        system("color 2F"); //Green
        break;
    case enWinner::Computer:
        system("color 4F"); //Red
        cout << "\a";
        break;
    case enWinner::Draw:
        system("color 6F"); //Yeleow
        break;
    }
}

void PlayRound(int NumberOfRounds)
{
    enGameChoice PlayerChoice = ReadPlayerChoice();
    enGameChoice ComputerChoice = GetComputerChoice();
    enWinner Winner = WhoWonTheRound(PlayerChoice, ComputerChoice);

    UpdateGameResults(Winner);

    SetWinnerScreenColor(Winner);
        
    PrintRoundResult(PlayerChoice, ComputerChoice, Winner, NumberOfRounds);
}

void ShowFinalResults(int NumberOfRounds)
{
    cout << "\n\n==========================================\n";
    cout << "\t\tGame Over\n";
    cout << "==========================================\n";

    cout << "Game Rounds        : " << NumberOfRounds << endl;
    cout << "Player Won Times   : " << PlayerWinCount << endl;
    cout << "Computer Won Times : " << ComputerWinCount << endl;
    cout << "Draw Times         : " << DrawCount << endl;

    if (PlayerWinCount > ComputerWinCount)
    {
        cout << "Final Winner       : Player\n";
    }
    else if (ComputerWinCount > PlayerWinCount)
    {
        cout << "Final Winner       : Computer\n";
    }
    else
    {
        cout << "Final Winner       : Draw\n";
    }

    cout << "==========================================\n";

    system("color 0F");
}

void StartGame()
{
    ResetGame();

    int NumberOfRounds = ReadNumberOfRounds();

    for (int i = 0; i < NumberOfRounds; i++)
    {
        PlayRound(i);
    }

    ShowFinalResults(NumberOfRounds);
}

void PlayGame()
{
    char PlayAgain = 'y';

    while (PlayAgain == 'y' || PlayAgain == 'Y')
    {
        system("cls");

        StartGame();

        cout << "\nDo you want to play again? Y/N? ";
        cin >> PlayAgain;
    }

    cout << "\nThanks for playing! Goodbye.\n";
}

int main() 
{
    srand((unsigned)time(NULL));

    PlayGame();

    return 0;
}