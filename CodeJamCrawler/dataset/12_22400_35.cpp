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
	char fi[300] = "D:\\Study\\Topcoder\\GCJ\\B-small-practice-Dancing With the Googlers0.in";	//1	smal
	char ouci[300] = {"results_B_small_Dancing With the Googlers0.txt"};//large

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

	int T;
	ifs >> T;

	for(int i = 0; i < T; i++)	{
		int N, S, p, res = 0;
		ifs >> N >> S >> p;

		for(int j = 0; j < N; j++)	{
			int sum;
			ifs >> sum;

			if(sum == 0)	{
				if(p == 0)	{
					res++;
				}
			}
			else if(sum == 1)	{
				if(p <= 1)
					res++;
			}
			else	{
				int x = sum / 3;

				if(sum % 3 == 0)	{
					if(x >= p)
						res++;
					else if(x + 1 >= p && S > 0)	{
						res++;
						S--;
					}
				}
				else if(sum % 3 == 1)	{
					if(x + 1 >= p)
						res++;
				}
				else if(sum % 3 == 2)	{
					if(x + 1 >= p)
						res++;
					else if(x + 2 >= p && S > 0)	{
						res++;
						S--;
					}
				}
			}
		}

		ou << "Case #" << i + 1 << ": " << res << endl;
		cout << "Case #" << i + 1 << ": " << res << endl;
	}
}