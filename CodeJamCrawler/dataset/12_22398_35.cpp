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
	char fi[300] = "D:\\Study\\Topcoder\\GCJ\\A-small-practice-Speaking in Tongues0.in";	//1	smal
	char ouci[300] = {"results_A_small_Speaking in Tongues0.txt"};//large

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

	map<char, char> dict;
	dict['a'] = 'y';
	dict['b'] = 'h';
	dict['c'] = 'e';
	dict['d'] = 's';
	dict['e'] = 'o';
	dict['f'] = 'c';
	dict['g'] = 'v';
	dict['h'] = 'x';
	dict['i'] = 'd';
	dict['j'] = 'u';
	dict['k'] = 'i';
	dict['l'] = 'g';
	dict['m'] = 'l';
	dict['n'] = 'b';
	dict['o'] = 'k';
	dict['p'] = 'r';
	dict['q'] = 'z';
	dict['r'] = 't';
	dict['s'] = 'n';
	dict['t'] = 'w';
	dict['u'] = 'j';
	dict['v'] = 'p';
	dict['w'] = 'f';
	dict['x'] = 'm';
	dict['y'] = 'a';
	dict['z'] = 'q';

	int T;
	ifs >> T;
	string S;
	getline(ifs, S);

	for(int i = 0; i < T; i++)	{
		string G;
		/*char c;
		ifs >> c;

		while(c != '\n')	{
			G.push_back(c);
			ifs >> c;
		}*/

		getline(ifs, G);

		for(int j = 0; j < G.length(); j++)
			if(G[j] != ' ')
				G[j] = dict[G[j]];


		ou << "Case #" << i + 1 << ": " << G << endl;
		cout << "Case #" << i + 1 << ": " << G << endl;

		//cout << G << endl;
		
		/*if(flag == 0)	{
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
		}*/
	}
}