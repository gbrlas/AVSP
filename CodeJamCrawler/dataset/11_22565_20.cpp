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
	char fi[300] = "D:\\Study\\Topcoder\\GCJ\\A-large-practice-FreeCellStatistics.in";	//1	smal
	char ouci[300] = {"results_A-large-practice-FreeCellStatistics.txt"};//large

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

	int T, pd, pg;
	long long N;
	ifs >> T;

	for(int i = 0; i < T; i++)	{
		ifs >> N >> pd >> pg;
		
		if((pd != 100 && pg == 100) || (pd != 0 && pg == 0))	{
			ou << "Case #" << i + 1 <<": Broken" << endl;
			cout << "Case #" << i + 1 <<": Broken" << endl;
		}
		else	{
			int flag = 1;
			for(int j = 1; j <= N; j++)	{
				double temp = (double)j * pd / 100;
				if(temp - (int)temp == 0)	{// no rounding
					flag = 0;
					break;
				}
			}

			if(flag == 0)	{
				ou << "Case #" << i + 1 <<": Possible" << endl;
				cout << "Case #" << i + 1 <<": Possible" << endl;
			}
			else	{
				ou << "Case #" << i + 1 <<": Broken" << endl;
				cout << "Case #" << i + 1 <<": Broken" << endl;
			}
		}
	}
}