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
	char fi[300] = "D:\\Study\\Topcoder\\GCJ\\A-small-practice-BotTrust0.in";	//1	smal
	char ouci[300] = {"results_A_small_BotTrust.txt"};//large

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

	int T, N;
	ifs >> T;

	for(int i = 0; i < T; i++)	{
		ifs >> N;
		vector< vector< pair<int, int> > > buttons(2);
		for(int j = 1; j <= N; j++)	{
			char player;
			int num;
			ifs >> player >> num;
			if(player == 'B')
				buttons[0].push_back(make_pair(j, num));
			else
				buttons[1].push_back(make_pair(j, num));
		}

		/*for(int k = 0; k < 2; k++)	{
			for(int j = 0; j < buttons[k].size(); j++)	
				cout << buttons[k][j].first << "," << buttons[k][j].second << " ";
			cout << endl;
		}*/

		long long res = 0;
		int dB = 1, dO = 1, iB = 0, iO = 0;
		if(buttons[0].size() == 0)	{
			res += buttons[1][0].second - dO + 1;
			for(int j = 1; j < buttons[1].size(); j++)
				res += abs(buttons[1][j].second - buttons[1][j - 1].second) + 1;
		}
		else if(buttons[1].size() == 0)	{
			res += buttons[0][0].second - dB + 1;
			for(int j = 1; j < buttons[0].size(); j++)
				res += abs(buttons[0][j].second - buttons[0][j - 1].second) + 1;
		}
		else	{
			res = 0;
			int j = 1;
			while(j <= N)	{
				if(buttons[0][iB].first != j)	{	// O's turn
					if(dB < buttons[0][iB].second)
						dB++;
					else if(dB > buttons[0][iB].second)
						dB--;

					if(dO < buttons[1][iO].second)
						dO++;
					else if(dO > buttons[1][iO].second)
						dO--;
					else	{
						j++;
						if(iO < buttons[1].size() - 1)
							iO++;
					}
					//cout << "O: " << dO << " B: " << dB << endl;
				}
				else	{							// B's turn
					if(dO < buttons[1][iO].second)
						dO++;
					else if(dO > buttons[1][iO].second)
						dO--;

					if(dB < buttons[0][iB].second)
						dB++;
					else if(dB > buttons[0][iB].second)
						dB--;
					else	{
						j++;
						if(iB < buttons[0].size() - 1)
							iB++;
					}
					//cout << "O: " << dO << " B: " << dB << endl;
				}

				res++;
			}
		}

		ou << "Case #" << i + 1 <<": " << res << endl;
		//cout << res << endl;
	}
}