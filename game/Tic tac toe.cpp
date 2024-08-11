#include<iostream>
using namespace std;


char crew[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char turn = 'X';
int row, column;
bool draw = false;

void display_crew(){
	system("cls");
	cout << "\n\n\t\t\tTIC TAC TOE Game\n\n\n";
	cout << "\tPlayer1 [X] \n \tPlayer2 [0]\n\n"; 

	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << crew[0][0] << "  | " << crew[0][1] << "   | " << crew[0][2] << "  \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << crew[1][0] << "  | " << crew[1][1] << "   | " << crew[1][2] << "  \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << crew[2][0] << "  | " << crew[2][1] << "   | " << crew[2][2] << "  \n";
	cout << "\t\t     |     |     \n";
}

void player_turn() {
	int choice;

	if(turn == 'X')
	cout << "\n\n\tPlayer1 [X] turn:";

	if (turn == 'O')
	cout << "\n\n\tPlayer2 [O] turn:";

	cin >> choice;

	switch (choice) {
	
	case 1:row = 0;column = 0;
		break;
	case 2:row = 0;column = 1;
		break;
	case 3:row = 0;column = 2;
		break;
	case 4:row = 1;column = 0;
		break;
	case 5:row = 1;column = 1;
		break;
	case 6:row = 1;column = 2;
		break;
	case 7:row = 2;column = 0;
		break;
	case 8:row = 2;column = 1;
		break;
	case 9:row = 2;column = 2;
		break;

	default:
		cout << "Invalid Choice\n";
		break;
	}
	
	if (turn == 'X' && crew[row][column]!='X' && crew[row][column] != 'O'){
		crew[row][column] = 'X';
		turn = 'O';
	}
	
	else if (turn == 'O' && crew[row][column] != 'X' && crew[row][column] != 'O'){
		crew[row][column] = 'O';
		turn = 'X';
	}

	else {
		cout <<"  Box alreay failed!\n  Please try again!!\n\n";
		player_turn();
	}
display_crew();
}

bool gameover() {
//check win
	for (int i = 0; i < 3; i++) 
		if (crew[i][0] == crew[i][1] && crew[i][0] == crew[i][2] || crew[0][i] == crew[1][i] && crew[0][i] == crew[2][i])
			return false;
	    if (crew[0][0] == crew[1][1] && crew[0][0] == crew[2][2] || crew[0][2] == crew[1][1] && crew[0][0] == crew[2][0])
			return false;
	


//if there is empty box
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		if (crew[i][j] != 'X' && crew[i][j] != 'O')
			return true;

//game draw
	draw = true;
	return false;
}

int main() {

	while (gameover()){
	display_crew();
	player_turn();
	gameover();
}
	if (turn == 'X' && draw == false)
		cout << "Player2 [O] Win!! Congratulations\n";
	else if (turn == 'O' && draw == false)
		cout << "Player1 [X] Win!! Congratulations\n";
	else
		cout << "GAME DRAW!! \n";
}