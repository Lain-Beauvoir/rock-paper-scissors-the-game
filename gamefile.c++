//once again. comments to commit changes and outline my program, as it is programmed in visualbasics, not github.
//posted in github at @lain_beauvoir.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//summon when errors occur. ends program immediately.
void errorFunction () {
        system("CLS");
        cout << "User input invalid!..";
        exit (0);
}

//summon to ask how many rounds the player wants to play. returns the value of 'rounds' to playFunction.
int setFunction () {
    int rounds;

    cout << "How many rounds do you want to play with your opponent?.." << endl;
    cout << "ROUNDS: ";
    cin >> rounds;
    cout << endl;

    return (rounds);
}

//summon when play begins.
char playFunction () {
    char playerchoice, ynrestart, yngame;
    string playch, result;
    int playerscore = 0, computerscore = 0;
    int playre, compre, rounds, round = 0;

    rounds = setFunction ();

    do {
        round = (round + 1);

        cout << "Choose your move!.." << endl;
        cout << "[R] FOR ROCK || [P] FOR PAPER || [S] FOR SCISSORS" << endl;
        cout << "R/P/S: ";
        cin >> playerchoice;
        cout << endl;
        if (!(playerchoice == 'R' || playerchoice == 'P' || playerchoice == 'S' || playerchoice == 'r' || playerchoice == 'p' || playerchoice == 's')) {
            errorFunction ();
        }

        switch (playerchoice) {
            case 'R':
            case 'r':
                playch = "Rock";
                playre = 1;
                break;
            
            case 'P':
            case 'p':
                playch = "Paper";
                playre = 2;
                break;

            case 'S':
            case 's':
                playch = "Scissors";
                playre = 3;
                break;
        }

        srand(time(0));
        
        int computerchoice = (rand()%3);
        string compch;

        switch (computerchoice) {
            case 0:
                compch = "Rock";
                compre = 1;
                break;

            case 1:
                compch = "Paper";
                compre = 2;
                break;

            case 2:
                compch = "Scissors";
                compre = 3;
                break;
        }

        cout << "The computer chose: " << compch << endl;
        cout << "The player chose: " << playch << endl;
        cout << endl;

        if (playre == compre) {
            cout << "It is a tie!.." << endl;
        }
        else if (playre == 1 && compre == 3) {
            cout << "The player wins!.." << endl;
            playerscore = (playerscore + 1);
        }
        else if (playre == 2 && compre == 1) {
            cout << "The player wins!.." << endl;
            playerscore = (playerscore + 1);
        }
        else if (playre == 3 && compre == 2) {
            cout << "The player wins!.." << endl;
            playerscore = (playerscore + 1);
        }
        else {
            cout << "The player loses!.." << endl;
            computerscore = (computerscore + 1);
        }
        cout << endl;

        cout << "PLAYER [" << playerscore << "] || COMPUTER [" << computerscore << "] || ROUND [" << round << "]" << endl;
        cout << endl;

        cout << "Start a new game?.." << endl;
        cout << "Y/N: ";
        cin >> ynrestart;
        cout << endl;

        system("CLS");
    }
    while ((ynrestart == 'y' || ynrestart == 'Y') && !(round == rounds));
        if (ynrestart == 'n' || ynrestart == 'N') {
            system("CLS");
            cout << "Thanks for playing!..";
            exit (0);
        }
        else if (round == rounds) {
            if (playerscore > computerscore) {
                cout << "The player wins this game!.." << endl;
                cout << endl;
            }
            else if (playerscore == computerscore) {
                cout << "It is a tie!.." << endl;
                cout << endl;
            }
            else if (playerscore < computerscore) {
                cout << "The computer wins this game!.." << endl;
                cout << endl;
            }
            cout << "Do you want to play another game?.." << endl;
            cout << "Y/N: ";
            cin >> yngame;
            cout << endl;

            system ("CLS");
        }
    return (yngame);
}

//summon to display guide on how the game works. only appears in the first boot of the program. 
void guideFunction () {
    cout << "The game follows classic rock, paper, scissors rules. Nothing more, nothing less..." << endl;
    cout << "You can set-up how many win/s you and your opponent needs to acheive for victory..." << endl;
    cout << "You can ask for a rematch and change the required win/s based on your preference..." << endl;
    cout << endl;

    system("PAUSE");
    system("CLS");
}

//summon to welcome the player. only appears in the first boot of the program. summons the guideFunction.
void welcomeFunction () {
    char ynguide;

    cout << "Welcome to Rock, Paper, Scissors: The Game!.." << endl;
    cout << endl;

    cout << "Would you like a quick guide on how to navigate the game?.." << endl;
    cout << "Y/N: ";
    cin >> ynguide;
    cout << endl;

    switch (ynguide) {
        case 'y':
        case 'Y':
            guideFunction ();
            break;

        case 'n':
        case 'N':
            cout << "Okay then, good luck and have fun!.." << endl;
            cout << endl;

            system("PAUSE");
            system("CLS");
            break;

        default:
            errorFunction ();
            break;
    }
}

//summon to ask what the player wants to do. either play or end the program.
void chooseFunction () {
    char chchoose;

        cout << "What would you like to do today?.." << endl;
        cout << "[P] TO PLAY || [E] TO EXIT" << endl;
        cout << "P/E: ";
        cin >> chchoose;
        cout << endl;

        switch (chchoose) {
            case 'P':
            case 'p':
                playFunction ();
                break;

            case 'E':
            case 'e':
                system("CLS");
                cout << "Thanks for playing!..";
                exit (0);
                break;

            default:
                errorFunction ();
                break;
    }
}

//main game. used two functions so that looping is easier and makes my life easier when debugging this stupid hell of a code.
int main () {
    char yngame;

    welcomeFunction ();
    do {
        chooseFunction ();
        yngame = playFunction ();
    }
    while (yngame == 'y' || yngame == 'Y');
    cout << "Thanks for playing!.." << endl;
}
