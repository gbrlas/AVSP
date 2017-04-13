#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void main()	{
	char fi[300] = "D:\\Study\\Topcoder\\GCJ\\A-large-practice-Square Tiles.in";	//1	smal
	char ouci[300] = {"results_A_large_Square Tiles.txt"};//large

	ifstream ifs(fi);
	if(!ifs) {
		cout << "File open error!" << endl;
		return;
	}
	ofstream ou(ouci);  
    if(!ou)	{
		cout << "file open error!\n";
		return;
	}

	int T, R, C;
	ifs >> T;

	for(int i = 0; i < T; i++)	{
		ifs >> R >> C;
		vector<string> picture(R);

		for(int j = 0; j < R; j++)
			for(int k = 0; k < C; k++)	{
				char ch;
				ifs >> ch;
				picture[j].push_back(ch);
			}

		int flag = 1;

		for(int j = 0; j < R; j++)
			for(int k = 0; k < C; k++)	{
				if(picture[j][k] == '.' || picture[j][k] == '\\' || picture[j][k] == '/')
					continue;
				else	{
					if(j == R - 1 || k == C - 1)	{
						flag = 0;
						break;
					}
					else if(picture[j][k + 1] != '#' || picture[j + 1][k] != '#' || picture[j + 1][k + 1] != '#')	{
						flag = 0;
						break;
					}
					else	{
						picture[j][k] = '/';
						picture[j][k + 1] = '\\';
						picture[j + 1][k] = '\\';
						picture[j + 1][k + 1] = '/';	  
					}
				}
			}
		
		if(flag == 0)	{
			ou << "Case #" << i + 1 <<":" << endl << "Impossible" << endl;
			cout <<  "Impossible" << endl;
		}
		else	{
			ou << "Case #" << i + 1 <<":" << endl;
			for(int j = 0; j < R; j++)	{
				for(int k = 0; k < C; k++)	{
					ou << picture[j][k];
					cout << picture[j][k];
				}
				ou << endl;
				cout << endl;
			}
		}
	}
}