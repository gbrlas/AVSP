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
	char fi[300] = "D:\\Study\\Topcoder\\GCJ\\C-small-practice-Perfect Harmony1.in";	//1	smal
	char ouci[300] = {"results_C_small_Perfect Harmony.txt"};//large

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

	int T, N, L, H;
	ifs >> T;

	for(int i = 0; i < T; i++)	{
		int res = 1, flag = 0;
		ifs >> N >> L >> H;
		vector<int> others;

		for(int j = 0; j < N; j++)	{
			int temp;
			ifs >> temp;
			others.push_back(temp);
		}

		for(int j = L; j <= H; j++)	{
			if(L == 1)	{
				flag = 1;
				break;
			}
			else	{
				int flag1 = 1;
				for(int k = 0; k < others.size(); k++)	{
					if(j % others[k] != 0 && others[k] % j != 0)	{
						flag1 = 0;
						break;
					}
					else
						continue;
				}
				if(flag1 == 1)	{
					res = j;
					flag = 1;
					break;
				}
			}
		}

		if(flag == 0)	{
			ou << "Case #" << i + 1 <<": NO" << endl;
			cout << "NO" << endl;
		}
		else	{
			ou << "Case #" << i + 1 <<": " <<  res << endl;
			cout << res << endl;
		}
	}
}