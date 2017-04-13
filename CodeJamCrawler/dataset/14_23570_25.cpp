#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

#define min(x,y) (((x) < (y)) ? (x) : (y))
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define abs(x) (((x) > 0) ? (x) : -(x))
#define INF 1e9

using namespace std;

void readBoard(vector<vector<int> > &board){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cin >> board[i][j];
		}
	}
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	int t;
	cin >> t;
	
	
	for(int i = 0; i < t; i++){
		vector<vector<int> > firstBoard(4, vector<int>(4));
		vector<vector<int> > secondBoard(4, vector<int>(4));
		int firstAns, secondAns;
		
		cin >> firstAns;
		readBoard(firstBoard);
		cin >> secondAns;
		readBoard(secondBoard);
	
		int cant = 0;
		int card = 0;
		for(int j = 0; j < 4; j++){
			int x = firstBoard[firstAns - 1][j];
			for(int k = 0; k < 4; k++){
				if(secondBoard[secondAns - 1][k] == x){
					card = x;
					cant++;
				}
			}
		}
		
		cout << "Case #" << (i + 1) << ": ";
		if(cant == 0){
			cout << "Volunteer cheated!" << endl;
		}else if(cant == 1){
			cout << card << endl;
		}else{
			cout << "Bad magician!" << endl;
		}
	}
	

	return 0;
}
