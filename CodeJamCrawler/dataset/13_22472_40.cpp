// TicTacToeTomeck.cpp : Defines the entry point for the console application.
//

#include <iostream>


int win(char* in);
char checkLines(char in[][4]);

using namespace std;

int main(){
	int cases;
	cin>>cases;
	for(int i=0;i<cases;i++){
		char board[4][4];
		char result;
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				cin>>board[j][k];
		result=checkLines(board);
		if(result=='X') cout<<"Case #"<<i+1<<": X won"<<endl;
		if(result=='O') cout<<"Case #"<<i+1<<": O won"<<endl;
		if(result=='I') cout<<"Case #"<<i+1<<": Game has not completed"<<endl;
		if(result=='N') cout<<"Case #"<<i+1<<": Draw"<<endl;

	}
}

int win(char in[]){
	if(in[0]=='.' || in[1]=='.' || in[2]=='.' || in[3]=='.') return 0;
	if(in[0]=='X' && in[1]=='X' && in[2]=='X' && in[3]=='X') return 1;
	if(in[0]=='O' && in[1]=='O' && in[2]=='O' && in[3]=='O') return 2;
	if(in[0]=='T' || in[1]=='T' || in[2]=='T' || in[3]=='T'){
		int x=0, o=0;
		for(int i=0;i<4;i++) if(in[i]=='X') x++;
		for(int i=0;i<4;i++) if(in[i]=='O') o++;
		if(x==3) return 1;
		if(o==3) return 2;
		return 0;
	}
}

char checkLines(char in[][4]){
	char test[4];
	for(int i=0;i<4;i++){
		test[0]=in[i][0];
		test[1]=in[i][1];
		test[2]=in[i][2];
		test[3]=in[i][3];
		if(win(test)==1) return 'X';
		if(win(test)==2) return 'O';
	}
	for(int i=0;i<4;i++){
		test[0]=in[0][i];
		test[1]=in[1][i];
		test[2]=in[2][i];
		test[3]=in[3][i];
		if(win(test)==1) return 'X';
		if(win(test)==2) return 'O';
	}
	test[0]=in[0][0];
	test[1]=in[1][1];
	test[2]=in[2][2];
	test[3]=in[3][3];
	if(win(test)==1) return 'X';
	if(win(test)==2) return 'O';

	test[0]=in[0][3];
	test[1]=in[1][2];
	test[2]=in[2][1];
	test[3]=in[3][0];
	if(win(test)==1) return 'X';
	if(win(test)==2) return 'O';

	for(int j=0;j<4;j++)
		for(int k=0;k<4;k++)
			if(in[j][k]=='.') return 'I';
	return 'N';
}