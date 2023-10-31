#include <iostream>
using namespace std;

char space[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int row;
int column;
bool tie = false;
char token = 'X';
string n1 = " ";
string n2 = " ";



void functionOne()
{
    
    cout << n1 << " is player1 so he/she will play first.\n";
    cout << n2 << " is player2 so he/she will play second.\n";

    // Creating the layout
    cout << "   |   |   \n";
    cout << " " << space[0][0] <<" | " << space[0][1] <<" |  " << space[0][2] << " \n";
    cout << "___|___|___\n";
    cout << " " << space[1][0] <<" | " << space[1][1] <<" |  " << space[1][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[2][0] << " | " <<space[2][1] <<" | " << space[2][2] << "\n";
    cout << "   |   |  \n";
}

void functionTwo()
{
    int digit;

    if (token == 'X')
    {
        cout << n1 << ", please enter a digit (1-9): ";
        cin >> digit;
    }
    else if (token == 'O')
    {
        cout << n2 << ", please enter a digit (1-9): ";
        cin >> digit;
    }

    if (digit >= 1 && digit <= 9)
    {
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        if (space[row][column] != 'X' && space[row][column] != 'O')
        {
            space[row][column] = token;
            token = (token == 'X') ? 'O' : 'X';
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
            functionTwo();
        }
    }
    else
    {
        cout << "Invalid input. Please enter a digit between 1 and 9." << endl;
        functionTwo();
    }
}

bool functionThree()
{
    for (int i = 0; i < 3; i++)
    {
        // Horizontal check, then vertical
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
            return true;
    }

    // Diagonal elements check
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
        return true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != 'O')
            {
                return false;
            }
        }
    }

    tie = true;
    return true; // It's a tie
}

int main()
{
	cout << "Enter the name of first player:\n";
    cin >> n1;
    cout << "Enter the name of second player:\n";
    cin >> n2;
    functionOne();
    while (!functionThree())
    {
        functionTwo();
        functionOne();
    }

    if (token == 'X' && !tie)
    {
        cout << n2 << " WINS!!" << endl;
    }
    else if (token == 'O' && !tie)
    {
        cout << n1 << " WINS!!" << endl;
    }
    else
    {
        cout << "DRAW!!" << endl;
    }

    return 0;
}

