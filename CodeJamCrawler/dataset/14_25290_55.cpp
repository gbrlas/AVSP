#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int a[5][5];
int b[5][5];


int main()
{
	int t;
	int row1, row2;

	ifstream fin;
	ofstream fout;
	fin.open("A-small-attempt2.in");
	fout.open("ans.txt");

	fin >> t;
		for(int cas = 1; cas <= t; ++cas) {
			//scanf("%d", &row1);
			fin >> row1;
			for(int i = 1; i <= 4; ++i)
				for(int j = 1; j <= 4; ++j)
					fin >> a[i][j];

			fin >> row2;

			for(int i = 1; i <= 4; ++i)
				for(int j = 1; j <= 4; ++j)
					fin >> b[i][j];

			int cnt = 0;
			int ans = 0;

			for(int i = 1; i <= 4; ++i) {
				for(int j = 1; j <= 4; ++j) {
					if(a[row1][i] == b[row2][j]) {
						++cnt;
						ans = a[row1][i];
					}
				}
			}

			if(cnt == 1)
				fout <<"Case #" <<cas <<": "<< ans<<endl;
			else if(cnt > 1)
				fout <<"Case #" <<cas <<": Bad magician!"<<endl;
			else
				fout <<"Case #" <<cas <<": Volunteer cheated!"<<endl;

		}

	return 0;

}