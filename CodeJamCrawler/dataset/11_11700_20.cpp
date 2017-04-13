#include<iostream>
#include<vector>

using namespace std;

vector<string> board;
int R, C; 

bool outside(int x, int y){
	return (x<0||x>=C||y<0||y>=R);
}

bool find_first(int& x, int& y){
	for(int c=0;c<C;++c){
		for(int r=0;r<R;++r){
			if(board[r][c]=='#'){
				x=c;y=r;
				return true;
			}
		}
	}
	return false;

}

bool possible(){
	int x,y;

	while(find_first(x,y)){
		board[y][x]='/';
		if(!outside(x+1,y) && board[y][x+1]=='#')
			board[y][x+1]='\\';
		else 
			return false;

		if(!outside(x,y+1) && board[y+1][x]=='#')
			board[y+1][x]='\\';
		else return false;

		if(!outside(x+1,y+1) && board[y+1][x+1]=='#')
			board[y+1][x+1]='/';
		else return false;
	}
	return true;
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;++t){
		cin >> R >> C;
		board = vector<string>(R,"");
		for(int r=0;r<R;++r)
			cin >> board[r];

		cout <<"Case #" << t << ":" << endl;
		if(possible())
			for(int r=0;r<R;++r)
				cout << board[r]<<endl;

		else
			cout << "Impossible" << endl;



	}


}

