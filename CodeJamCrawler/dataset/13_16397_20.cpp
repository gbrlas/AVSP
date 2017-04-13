#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define BOARD_SIZE 4 

enum RESULT
{
	X,
	O,
	DRAW,
	NOT_FINISHED
};

class Game {
public:
	Game(){};
	~Game(){};
	char board[BOARD_SIZE][BOARD_SIZE];

	void printBoard();
	RESULT checkBoard();
};

void Game::printBoard(){
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
};

RESULT Game::checkBoard(){
	char pivot;
	bool getWinner;
	bool hasDot = false;
	//check horizontal
	for(int i=0; i<BOARD_SIZE; i++){
		getWinner = true;
		if(board[i][0] == 'T'){
			pivot = board[i][1];
		} else {
			pivot = board[i][0];
		}
		for(int j=1; j<BOARD_SIZE; j++){
			if(pivot=='.' || board[i][j]=='.'){
				getWinner = false;
				hasDot = true;
				break;
			}else if(board[i][j]!=pivot && board[i][j]!='T'){
				getWinner = false;
				break;
			}
		}
		if(getWinner == true){
			return (pivot=='X') ? X : O;
		}
	}

	//check vertical
	for(int i=0; i<BOARD_SIZE; i++){
		getWinner = true;
		if(board[0][i] == 'T'){
			pivot = board[1][i];
		} else {
			pivot = board[0][i];
		}
		for(int j=1; j<BOARD_SIZE; j++){
			if(pivot=='.' || board[j][i]=='.' || board[j][i]!=pivot && board[j][i]!='T'){
				getWinner = false;
				break;
			}
		}
		if(getWinner == true){
			return (pivot=='X') ? X : O;
		}
	}

	//Check Cross "\"
	getWinner = true;
	if(board[0][0] == 'T'){
		pivot = board[1][1];
	} else {
		pivot = board[0][0];
	}
	for(int i=1; i<BOARD_SIZE; i++){
		if(pivot=='.' || board[i][i]=='.' || board[i][i]!=pivot && board[i][i]!='T'){
			getWinner = false;
			break;
		}
	}
	if(getWinner == true){
		return (pivot=='X') ? X : O;
	}

	//Check Cross "/"
	getWinner = true;
	if(board[0][BOARD_SIZE-1] == 'T'){
		pivot = board[1][BOARD_SIZE-2];
	} else {
		pivot = board[0][BOARD_SIZE-1];
	}
	for(int i=1; i<BOARD_SIZE; i++){
		if(pivot=='.' || board[i][BOARD_SIZE-i-1]=='.' || board[i][BOARD_SIZE-1-i]!=pivot && board[i][BOARD_SIZE-1-i]!='T'){
			getWinner = false;
			break;
		}
	}
	if(getWinner == true){
		return (pivot=='X') ? X : O;
	}

	//Get result
	return (hasDot) ? NOT_FINISHED : DRAW;
};

int main() {
	ifstream myFile;
	ofstream outFile("output.txt");
	string input;
	string output;
	Game g;
	myFile.open("A-small-attempt0.in");
	
	if(myFile.is_open()&&outFile.is_open()){
		getline(myFile, input);
		int size = atoi(input.c_str());
		for(int i=0; i<size; i++){
			for(int k=0; k<BOARD_SIZE; k++){
				getline(myFile, input);
				for(int j=0; j<BOARD_SIZE; j++){
					g.board[k][j] = input[j];
				}
			}
			switch (g.checkBoard()){
			case X: 
				outFile <<  "Case #"; outFile << i+1; outFile << ": X won\n";
				break;
			case O:
				outFile <<  "Case #"; outFile << i+1; outFile << ": O won\n";
				break;
			case NOT_FINISHED:
				outFile << "Case #"; outFile << i+1; outFile << ": Game has not completed\n";
				break;
			case DRAW:
				outFile <<  "Case #"; outFile << i+1; outFile << ": Draw\n";
				break;
			}
			//outFile << output;
			getline(myFile, input);
		}
	}
	myFile.close();
	system("PAUSE");
}