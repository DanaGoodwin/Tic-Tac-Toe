#include <iostream> 
#include <string> 

using namespace std;

// Looked back at string lecture to see how this code should be structured. 

// Varibales 
const int g_KiSize = 3; //Size of tic tac toe board 
char g_acBoard[g_KiSize][g_KiSize] = { { ' ', ' ', ' ', },{ ' ', ' ', ' ' },{ ' ', ' ', ' ', } };

// Functions 
void resetBoard();
bool setBoard(int iX, int iY, char cCharValue); 
void displayBoard();
void columnAndRow(int& iX, int& iY); // This function fetches the Row and Column for the board 
void playerTurn(char& cPlayer); // This function toggles player turn
void checkWin(); // This function checkes who the win is or if it is a tie

void resetBoard() // Reset the board Function 
{
	for (int i = 0; i < g_KiSize; i++)
	{
		for (int j = 0; j < g_KiSize; j++)
		{
			g_acBoard[i][j] = ' ';
		}
	}
}

bool setBoard(int iX, int iY, char cCharValue) // Setting the Board function 
{
	if (g_acBoard[iX][iY] == ' ')
	{
		g_acBoard[iX][iY] = cCharValue;
		return true;
	}
	else
	{
		return false;
	}
}

void displayBoard() // Displaying the board function 
{
	cout << "\n+---+-A-+-B-+-C-+" << endl; // This is the comlumn headings for the table
	cout << "+---+---+---+---+" << endl;
	for (int j = 0; j < g_KiSize; j++)
	{
		cout << "| " << j + 1 << " "; 
		for (int i = 0; i < g_KiSize; i++)
		{
			cout << "| " << g_acBoard[i][j] << " ";
		}
		cout << "| " << endl;
		cout << "+---+---+---+---+" << endl;
	}
	cout << endl;
}

void playerTurn(char & cPlayer) // The players turn function 
{
	if (cPlayer == 'X') { cPlayer = 'O'; }
	else { cPlayer = 'X'; }
}

void columnAndRow(int& iX, int& iY) // The row and column fetching function 
{
	char cColumn;
	int iRow;
	bool bExit = false;

	while (!bExit)
	{
		cout << "Enter a column and row value from the table to place your piece.\n(Example A 1 or B 2)" << endl; // Asking user for input
		cin >> cColumn >> iRow;
		if (cin.fail()) // If the user enters a set of values which to do not match the table the program will call this.
		{
			cin.clear(); // The program will clear the invaild values and ask for the values again.
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Used the lecture video for help on how to use the string.
			cout << endl << "The column and row entered is invalid. please try again" << endl << endl;
		}
		else
		{
			if (iRow > 0 && iRow < 4)
			{
				if (cColumn >= 'A' && cColumn <= 'C')
				{
					iX = cColumn - 'A'; 
					iY = iRow - 1;
					bExit = true;
				}
				else
				{
					cout << endl << "The table will only accept input values A, B and C.\nPlease try again" << endl << endl; // If a value other than A B or C is entered the program will print this message to the user.
				}
			}
			else
			{
				if (cColumn >= 'A' && cColumn <= 'C')
				{
					cout << endl << "The table can only accept inout values 1, 2 and 3.\nPlease try again" << endl << endl; // If a value other than 1 2 or 3 is entered the program will print this message to the user.
				}
				else
				{
					cout << endl << "The table will only accept input values A, B and C.\nPlease try again" << endl << endl;
				}
			}
		}
	}
}

void checkWin() // Checking for the winning player by checking each winning move.
{
	// Vertical checks
	// Checking row 1
	if ((g_acBoard[0][0] == ' ') && (g_acBoard[0][1] == ' ') && (g_acBoard[0][2] == ' '))// Checking the square is empty
	{
		return;
	}
	else if ((g_acBoard[0][0] == 'X') && (g_acBoard[0][1] == 'X') && (g_acBoard[0][2] == 'X')) // Checking for X
	{
		cout << "The winner is X" << endl;
		resetBoard();
		return;
	}
	else if ((g_acBoard[0][0] == 'O') && (g_acBoard[0][1] == 'O') && (g_acBoard[0][2] == 'O')) // Checking for O
	{
		cout << "The winner is O" << endl;
		resetBoard();
		return;
	}

	// Checking row 2
	if ((g_acBoard[0][1] == ' ') && (g_acBoard[1][1] == ' ') && (g_acBoard[2][1] == ' '))// Checking the square is empty
	{
		return;
	}
	else if ((g_acBoard[0][1] == 'X') && (g_acBoard[1][1] == 'X') && (g_acBoard[2][1] == 'X')) // Checking for X
	{
		cout << "The winner is X" << endl;
		resetBoard();
		return;
	}
	else if ((g_acBoard[0][1] == 'O') && (g_acBoard[1][1] == 'O') && (g_acBoard[2][1] == 'O')) // Checking for O
	{
		cout << "The winner is O" << endl;
		resetBoard();
		return;
	}

	// Checking row 3
	if ((g_acBoard[0][2] == ' ') && (g_acBoard[1][2] == ' ') && (g_acBoard[2][2] == ' '))// Checking the square is empty
	{
		return;
	}
	else if ((g_acBoard[0][2] == 'X') && (g_acBoard[1][2] == 'X') && (g_acBoard[2][2] == 'X')) // Checking for X
	{
		cout << "The winner is X" << endl;
		resetBoard();
		return;
	}
	else if ((g_acBoard[0][2] == 'O') && (g_acBoard[1][2] == 'O') && (g_acBoard[2][2] == 'O')) // Checking for O
	{
		cout << "The winner is O" << endl;
		resetBoard();
		return;
	}

	// Horizontial checks
	// Checking column A
	if ((g_acBoard[0][0] == ' ') && (g_acBoard[1][0] == ' ') && (g_acBoard[2][0] == ' '))// Checking the square is empty
	{
		return;
	}
	else if ((g_acBoard[0][0] == 'X') && (g_acBoard[1][0] == 'X') && (g_acBoard[2][0] == 'X')) // Checking for X
	{
		cout << "The winner is X" << endl;
		resetBoard();
		return;
	}
	else if ((g_acBoard[0][0] == 'O') && (g_acBoard[1][0] == 'O') && (g_acBoard[2][0] == 'O')) // Checking for O
	{
		cout << "The winner is O" << endl;
		resetBoard();
		return;
	}

	// Checking column B
	if ((g_acBoard[0][1] == ' ') && (g_acBoard[1][1] == ' ') && (g_acBoard[2][1] == ' ')) // Checking the square is empty
	{
		return;
	}
	else if ((g_acBoard[0][1] == 'X') && (g_acBoard[1][1] == 'X') && (g_acBoard[2][1] == 'X')) // Checking for X
	{
		cout << "The winner is X" << endl;
		resetBoard();
		return;
	}
	else if ((g_acBoard[0][1] == 'O') && (g_acBoard[1][1] == 'O') && (g_acBoard[2][1] == 'O')) // Checking for O
	{
		cout << "The winner is O" << endl;
		resetBoard();
		return;
	}

	// Checking column C
	if ((g_acBoard[0][2] == ' ') && (g_acBoard[1][2] == ' ') && (g_acBoard[2][2] == ' ')) // Checking the square is empty
	{
		return;
	}
	else if ((g_acBoard[0][2] == 'X') && (g_acBoard[1][2] == 'X') && (g_acBoard[2][2] == 'X')) // Checking for X
	{
		cout << "The winner is X" << endl;
		resetBoard();
		return;
	}
	else if ((g_acBoard[0][2] == 'O') && (g_acBoard[1][2] == 'O') && (g_acBoard[2][2] == 'O')) // Checking for O
	{
		cout << "The winner is O" << endl;
		resetBoard();
		return;
	}

	// Diagonal
	// Checking diagonal A1 to C2
	if ((g_acBoard[0][0] == ' ') && (g_acBoard[1][1] == ' ') && (g_acBoard[2][2] == ' ')) // Checking the square is empty
	{
		return;
	}
	else if ((g_acBoard[0][0] == 'X') && (g_acBoard[1][1] == 'X') && (g_acBoard[2][2] == 'X')) // Checking for X
	{
		cout << "The winner is X" << endl;
		resetBoard();
		return;
	}
	else if ((g_acBoard[0][0] == 'O') && (g_acBoard[1][1] == 'O') && (g_acBoard[2][2] == 'O')) // Checking for O
	{
		cout << "The winner is O" << endl;
		resetBoard();
		return;
	}

	// Checking diagonal A2 to C1
	if ((g_acBoard[0][2] == ' ') && (g_acBoard[1][1] == ' ') && (g_acBoard[2][0] == ' ')) // Checking the square is empty
	{
		return;
	}
	else if ((g_acBoard[0][2] == 'X') && (g_acBoard[1][1] == 'X') && (g_acBoard[2][0] == 'X')) // Checking to see if the diagonal has any X in the squares
	{
		cout << "The winner is X" << endl;
		resetBoard();
		return;
	}
	else if ((g_acBoard[0][2] == 'O') && (g_acBoard[1][1] == 'O') && (g_acBoard[2][0] == 'O')) // Checking to see if the diagonal has any O in the sqaures.
	{
		cout << "The winner is O" << endl;
		resetBoard();
		return;
	}

	// Checking for tie by making sure all the 9 squares are not empty.
	if ((g_acBoard[0][0] != ' ') && (g_acBoard[0][1] != ' ') && (g_acBoard[0][2] != ' ') && (g_acBoard[1][0] != ' ') && (g_acBoard[1][1] != ' ') && (g_acBoard[1][2] != ' ') && (g_acBoard[2][0] != ' ') && (g_acBoard[2][1] != ' ') && (g_acBoard[2][2] != ' '))
	{
		cout << "This game is a tie." << endl;
		resetBoard();
		return;
	}
}

int main()
{
	int iColumn;
	int iRow;
	char cPlayer = 'X';

	cout << "Tic - Tac - Toe game." << endl; // Title of the program 
	cout << "This game requires you the player to enter a value from the table below such as A 1 or B 3.\nThe first player will be X and the second player will be O." << endl;
	cout << "The first player to have three of their pieces in a row in the table will win. (XXX or OOO)" << endl;
	cout << "Once one game has been won or tied the board will be reset to play again." << endl; // Baic rule on how to play the game.

	while (true)
	{
		displayBoard(); // Display the baord function call
		columnAndRow(iColumn, iRow); // Display the Column and Row function call
		if (!setBoard(iColumn, iRow, cPlayer))
		{
			cout << "\nThis square has already been taken. You forgeite your turn." << endl; // This will inform the player that sqaure values they entered have already been used.
		}

		checkWin(); // Checking for player wins function

		playerTurn(cPlayer); // If no player has won the program will continue with the player function
	}

	system("pause");

	return 0;
}