#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

#define MIN(a,b) (a>b)?(b):(a)
int arrMap[102][102][2];
int basin;
char getBasin (int i, int j)
{
	//cout << i << " " << j <<endl;
	if (arrMap[i][j][1] != -1)
		return (char)arrMap[i][j][1];
	int n, w, e, s;
	n = arrMap[i-1][j][0];
	w = arrMap[i][j-1][0];
	e = arrMap[i][j+1][0];
	s = arrMap[i+1][j][0];
	int min = MIN(n,w);
	min = MIN(e,min);
	min = MIN(s,min);
//	cout << "n = " <<n <<" s = " << s << "w = " <<w <<" e = "<< e << endl;
	if (arrMap[i][j][0] <= min)
	{
		arrMap[i][j][1] = basin;
		basin++;
		return (char)arrMap[i][j][1];
	}
	if (n == min)
	{
		arrMap[i][j][1] = getBasin (i-1, j);
	}
	else if (w == min)
	{
		arrMap[i][j][1] = getBasin (i,j-1);
	}
	else if (e == min)
	{
		arrMap[i][j][1] = getBasin(i, j+1);
	}
	else if (s == min)
	{
		arrMap[i][j][1] = getBasin(i+1, j);
	}
	return (char)arrMap[i][j][1];
}
int main()
{
	ifstream fin ("a.in");
	ofstream fout ("a.txt");
	int T, H, W;
	//Initialize arrMap to 0;
	//memset(arrMap, 1,sizeof(arrMap));
	for (int i = 0; i < 102; i++)
		for (int j = 0; j < 102; j++)
			for (int k = 0 ; k < 2; k++)
				arrMap[i][j][k] = 0;
	fin >> T;

	for (int i = 0 ; i < T; i ++)
	{
		fin >> H >> W;
		//Taking input and Build a boundary on all 4 sides...
		for (int j = 1; j <= H; j++)
		{
			for (int k = 1; k <= W; k ++)
			{
				fin >> arrMap[j][k][0];
				arrMap[j][k][1] = -1;
			}
		}

		for (int j = 0; j < W + 2; j ++)
		{
			arrMap[0][j][0] = 10001;
			arrMap[H+1][j][0] = 10001;
		}

		for (int j = 0; j < H + 2; j ++)
		{
			arrMap[j][0][0] = 10001;
			arrMap[j][W+1][0] = 10001;
		}
		//Debugging purposes... printing the map with boundary
/*		for (int j = 0; j < H +2; j++)
		{
			for (int k = 0; k < W + 2; k++)
			{
				cout << arrMap[j][k][0] << " ";
			}
			cout << endl;
		}
		*/

		basin = 0;
		cout << "Case #" << i + 1 << ":" << endl;
		fout << "Case #" << i + 1 << ":" << endl;

		for (int j = 1; j <= H; j++)
		{
			for (int k = 1; k <= W; k++)
			{
				char tmp = 'a' + getBasin(j,k);
				cout << tmp;
				fout << tmp;
				if (k !=W)
				{
					cout << " ";
					fout << " ";
				}
			}
			cout << endl;
			fout << endl;
		}
				
	}
	return 0;
				
}
