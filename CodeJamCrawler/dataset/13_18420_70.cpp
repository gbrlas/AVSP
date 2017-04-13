//============================================================================
// Name        : Lawnmower.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int T;
	int N, M;
	int height[100][100];
	bool valid[100][100];
	cin >> T ;
	for (int t = 1; t <= T; ++t) {
		cin >> N >> M;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				cin >> height[i][j];
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				valid[i][j] = false;
		// check all the rows
		for(int i = 0; i < N; ++i){
			int max_height = 0;
			for (int j = 0; j < M; ++j){
				if(height[i][j] > max_height)
					max_height = height[i][j];
			}
			for (int j = 0; j < M; ++j){
				if(height[i][j] == max_height)
					valid[i][j] = true;
			}
		}
		// check all the columns
		for(int j = 0; j < M; ++j){
			int max_height = 0;
			for (int i = 0; i < N; ++i){
				if(height[i][j] > max_height)
					max_height = height[i][j];
			}
			for (int i = 0; i < N; ++i){
				if(height[i][j] == max_height)
					valid[i][j] = true;
			}
		}
		// check if valid
		bool possible = true;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j){
				if (!valid[i][j])
					possible = false;\
			}
		cout << "Case #" << t << ": ";
		if(possible)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}
