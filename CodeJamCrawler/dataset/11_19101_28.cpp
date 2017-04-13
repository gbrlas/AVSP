#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void  testtile(char ** map,  int a ,int  b, int R, int C);
int main () {
	ifstream fin ("A.in");
	ofstream fout ("A.out");

	int T,R,C;
	char **map;
	fin >> T;
	for( int i=1; i <=T; i++) {
		fin>> R >> C;
		map= new char*[R];
		for( int r=0; r< R; r++){
			map[r]= new char[C];
			for(int c= 0; c< C; c++) {
				fin >> map[r][c];
			}
		}

		for( int a= 0 ;  a < R; a++) {
			for( int b=0; b< C; b++) {
				switch (map[a][b]){
					case '#':
						 testtile(map,  a , b, R,C);
				};
			}
		}
		bool X=true;
		for( int a= 0 ;  a < R; a++) {
			for( int b=0; b< C; b++) {
				switch (map[a][b]){
					case '#':
						 X=false;
				};
			}
		}
		fout<<"Case #"<<i<<":\n";
		if(X){
			for( int a= 0 ;  a < R; a++) {
				for( int b=0; b< C; b++) {
					fout<<map[a][b];
				}
				fout<<endl;
			}
		}else {
			fout<<"Impossible\n";
		}
	}
	
	return 0;
}

void  testtile(char ** map,  int a ,int  b, int R, int C){
	int B =a+1,D = b+1;
	if( B < R && D <C) {
		if( map[a][b] == '#' && map [B][b] == '#' && map[a][D] =='#' && map[B][D] =='#') {
			map[a][b] = '/'; map[B][D] ='/'; map[B][b] = '\\' ; map[a][D] = '\\';
		}
	}
}

