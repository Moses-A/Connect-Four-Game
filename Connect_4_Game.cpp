// Connect 4 with iterators
//Author is Moses Arocha
//computer playing as a player

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

//This game involves the inclusion of a random generator to act as the second player

using namespace std;


const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

//this starts from the highest numbers, then subtracts to place the item 
int i = 35;
int j = 36;
int k = 37;
int l = 38;
int m = 39;
int n = 40;
int o = 41;


void directions();
void connectBoard(vector<char>& GameBoard);
char conqueror(vector<char>& GameBoard);
void playerHuman(vector<char>& GameBoard);
void playerDrop(vector<char> & GameBoard, char playerChoice, char peasant);
void computerDrop(vector<char>& GameBoard, char droid);
void Winner(char conqueror, char peasant, char droid);


int main()
{	
    char playerChoice;
    const int table = 71;
    vector<char> GameBoard(table, EMPTY);

    directions(); // calls for the function directions
    char peasant = 'X';
    char droid = 'O';
    connectBoard(GameBoard);
	
    while (conqueror(GameBoard) == NO_ONE)
    {
	cout << "\n\n\n Human The Turn Is Yours. Please Choose A Column To Insert Your Piece: ";
	cin >> playerChoice;
	playerDrop(GameBoard, playerChoice, peasant);
	computerDrop(GameBoard, droid);
	cout << "\n";
	connectBoard(GameBoard);
    }

    Winner(conqueror(GameBoard), peasant, droid);

    return 0;
}

void playerDrop(vector<char> & GameBoard, char playerChoice, char peasant)
{
    playerChoice = toupper(playerChoice);

	if (playerChoice == 'A')
	{
	    GameBoard[i] = peasant;
	    i = i - 7;
	}

	else if (playerChoice == 'B')
	{
	    GameBoard[j] = peasant;
	    j = j - 7;
	}
	else if (playerChoice == 'C')
	{
	    GameBoard[k] = peasant;
	    k = k - 7;
	}
	else if (playerChoice == 'D')
	{
	    GameBoard[l] = peasant;
	    l = l - 7;
	}
	else if (playerChoice == 'E')
	{
	    GameBoard[m] = peasant;
	    m = m - 7;
	}
	else if (playerChoice == 'F')
	{
	    GameBoard[n] = peasant;
	    n = n - 7;
	}  
	else if (playerChoice == 'G')
	{
	    GameBoard[o] = peasant;
	    o = o - 7;
	}
}

void computerDrop(vector<char>& GameBoard, char droid)
{
	
    int randomNumber;
    srand(static_cast<unsigned int>(time(0)));  //seed random number generator
    randomNumber = rand() % 7 + 0;         // random number between 1 and 10

	if (randomNumber == 0)
	{
	    GameBoard[i] = droid;
	    i = i - 7;
	}

	else if (randomNumber == 1)
	{
	    GameBoard[j] = droid;
	    j = j - 7;
	}
	else if (randomNumber == 2)
	{
	    GameBoard[k] = droid;
	    k = k - 7;
	}
	else if (randomNumber == 3)
	{
	    GameBoard[l] = droid;
	    l = l - 7;
	}
	else if (randomNumber == 4)
	{
	    GameBoard[m] = droid;
	    m = m - 7;
	}
	else if (randomNumber == 5)
	{
	    GameBoard[n] = droid;
	    n = n - 7;
	}
	else if (randomNumber == 6)
	{
	    GameBoard[o] = droid;
	    o = o - 7;
	}

}

void directions()
{
    cout << "\t\tWelcome To The Wonderful Game of Connect Four.\n" << endl;
    cout << "\t The Objective Of The Game Is To Defeat Charlize The A.I. " << endl;
    cout << "\n\t Rules: Connect 4 In a Row And Win The Game!" << endl;
}

void connectBoard(vector<char>& GameBoard)
{
    cout << "\n\t"  << " " << "A" << " "  << " " << "B" << " "  << " "  << " " << "C" <<  " " << " " << " " << "D" << " " << " " << " " << "E" << " " << " " << " " << "F" << " " << " " << "G" ;
    cout << "\n\t" << GameBoard[0] << " | " << GameBoard[1] << " | " << GameBoard[2] << " | " << GameBoard[3] << " | " << GameBoard[4] << " | " << GameBoard[5] << " | " << GameBoard[6];
	cout << "\n\t" << "-------------------------";
    cout << "\n\t" << GameBoard[7] << " | " << GameBoard[8] << " | " << GameBoard[9] << " | " << GameBoard[10] << " | " << GameBoard[11] << " | " << GameBoard[12] << " | " << GameBoard[13];
	cout << "\n\t" << "-------------------------";
    cout << "\n\t" << GameBoard[14] << " | " << GameBoard[15] << " | " << GameBoard[16] << " | " << GameBoard[17] << " | " << GameBoard[18] << " | " << GameBoard[19] << " | " << GameBoard[20];
    cout << "\n\t" << "-------------------------";
    cout << "\n\t" << GameBoard[21] << " | " << GameBoard[22] << " | " << GameBoard[23] << " | " << GameBoard[24] << " | " << GameBoard[25] << " | " << GameBoard[26] << " | " << GameBoard[27];
	cout << "\n\t" << "-------------------------";
    cout << "\n\t" << GameBoard[28] << " | " << GameBoard[29] << " | " << GameBoard[30] << " | " << GameBoard[31] << " | " << GameBoard[32] << " | " << GameBoard[33] << " | " << GameBoard[34];
    	cout << "\n\t" << "-------------------------";
    cout << "\n\t" << GameBoard[35] << " | " << GameBoard[36] << " | " << GameBoard[37] << " | " << GameBoard[38] << " | " << GameBoard[39] << " | " << GameBoard[40] << " | " << GameBoard[41];
	 cout << "\n\t" << "-------------------------";
}

char conqueror(vector<char>& GameBoard)
{
	const int WINNINGS[71][4] =	{{ 41, 40, 39, 38}, { 35, 36, 37, 38}, {1, 2, 3 ,4},
					{ 41, 34, 27, 20}, { 40, 33, 26, 19}, { 2, 3, 4, 5},
					{ 39, 32, 25, 18}, { 38, 31, 24, 17}, {3, 4, 5, 6},
					{ 37, 30, 23, 16}, { 36, 29, 22, 15}, { 8, 9, 10, 11},
					{ 35, 28, 21, 14}, { 0, 7, 14, 21 }, { 9, 10, 11, 12},
					{ 1, 8, 15, 22 },  { 2, 9, 16, 23 }, {10, 11, 12, 13},
					{ 3, 10, 17, 24},  { 4, 11, 18, 25}, {15, 16, 17, 18},
					{ 5, 12, 19, 26}, { 6, 13, 20, 27}, {16, 17, 18, 19},
					{ 0, 1, 2, 3},    { 6, 5, 4, 3}, {17, 18, 19, 20},
					{7, 8, 9, 10},    {13, 12, 11, 10}, {22, 23, 24, 25},
					{14, 15, 16, 17}, {20, 19, 18, 17}, {23, 24, 25, 26},
					{21, 22, 23, 24}, {27, 26, 25, 24}, {24, 25, 26, 27},
					{28, 29, 30, 31}, {34, 33, 32, 31}, {29, 30, 31, 32},
					{35, 36, 37, 38}, {41, 40, 39, 38}, {36, 37, 38, 39},
					{ 0, 8, 16, 24}, {1, 9, 17, 25}, {37, 38, 39, 40},
					{ 2, 10, 18, 26}, {3, 11, 19, 27}, {38, 39, 40, 41},
					{ 7, 15, 23, 31}, {14, 22, 30, 38}, { 8, 16, 24, 32}, 
					{9, 17, 25, 33},{10, 18, 26, 34}, {13, 19, 25, 31}, 
					{12, 18, 24, 30}, {11, 17, 23, 29},{10, 16, 22, 28}, 
					{35,29, 23, 17},  {41, 33, 25, 17}, {29, 22, 15, 8},
					{36, 30, 24, 18}, {37, 31, 25, 19}, {30, 23, 16, 9},
					{38, 30, 22, 14}, {38, 32, 26, 20}, {31, 24, 17, 10},
					{39, 31, 23, 15}, {40, 32, 24, 16}, {32, 25, 18, 11},
					{33, 26,19,12}, {34, 27, 20, 14}};

	const int totalWins = 71;

	
	for (int i = 0; i < totalWins; ++i)
	{
	    if ( (GameBoard[WINNINGS[i][0]] != EMPTY) &&
		 (GameBoard[WINNINGS[i][0]] == GameBoard[WINNINGS[i][1]]) &&
		 (GameBoard[WINNINGS[i][1]] == GameBoard[WINNINGS[i][2]]) &&
		 (GameBoard[WINNINGS[i][2]] == GameBoard[WINNINGS[i][3]]))

	    {
		return GameBoard[WINNINGS[i][0]];
	    }
	}

	if (count(GameBoard.begin(), GameBoard.end(), EMPTY) ==0)
	{
	    return TIE;
	}
	else
	{
	    return NO_ONE;
	}
}

void Winner(char conqueror, char peasant, char droid)
{
	if (conqueror == peasant)
	{
	    cout << "\n\n The winner is the Human. Great job player,  " <<  peasant << ".\n " << endl;
	}
	else if (conqueror == droid)
	{
	    cout << "\n\n The winner is Charlize The Artifical Intelligence. Try Again Loser. \n " << endl;
	}
	else
	{
	    cout << "\n\n The score seems that no one has one, but in reality, Charlize has won. \n " << endl;
	}
}
