#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXH 105
#define INF 100000

using namespace std;

int map[MAXH][MAXH];
int raide[MAXH][MAXH];
int maxr;


int einam(int a, int b)
{
	//cout << endl << "- " << a << " " << b << ": ";
	if (raide[a][b] > 0) { /*cout << "1" << endl; */return raide[a][b]; }
	int mini = min(min(map[a-1][b], map[a][b+1]), min(map[a+1][b], map[a][b-1]));
	if (mini >= map[a][b]) { /*cout << "2" << endl;*/ maxr++; raide[a][b] = maxr; return maxr; }
	if (mini == map[a-1][b]) { raide[a][b] = einam(a-1, b); }
		else if (mini == map[a][b-1]) { raide[a][b] = einam(a, b-1); }
			else if (mini == map[a][b+1]) { raide[a][b] = einam(a, b+1); }
				else if (mini == map[a+1][b]) { raide[a][b] = einam(a+1, b); }
					else { cout << "----------- BROKEN -------------" << endl; };
//	cout << "3 " << raide[a][b] << endl; 
	return raide[a][b];
}

int main ()
{
	ifstream fin("B.in");
	ofstream fout("B.out");
	int T;
	int h, w;
	int H, W;
	fin >> T;
	for (int t=1; t<=T; t++)
	{
		maxr = 0;
		fin >> H >> W;
		
		// Apibrëþiam þemëlapá
		for (int h=0; h<=H+1; h++)
		{
			map[h][0] = INF;
			map[h][W+1] = INF;
		}
		for (int w=0; w<=W+1; w++)
		{
			map[0][w] = INF;
			map[H+1][w] = INF;
		}
		
		
		// Skaitom
		for (int h=1; h<=H; h++)
		{
			for (int w=1; w<=W; w++)
			{
				fin >> map[h][w];
				raide[h][w] = 0;
				//cout << map[h][w] << " ";
			}
			//cout << endl;
		}
		
		// Skaièiuojam
		for (int h=1; h<=H; h++)
		{
			for (int w=1; w<=W; w++)
			{
				raide[h][w] = einam(h, w);
			}
		}
		
		//cout << endl;
		fout << "Case #" << t << ":" << endl;
		for (int h=1; h<=H; h++)
		{
			for (int w=1; w<=W; w++)
			{
				fout << char(int('a')+raide[h][w]-1) << " ";
			}
			fout << endl;
		}
	}
	fout.close();
	cin.get();
	return 0;
}
