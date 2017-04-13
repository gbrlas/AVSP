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
	char fi[300] = "D:\\Study\\Topcoder\\GCJ\\C-small-practice-CandySplitting0.in";	//1	smal
	char ouci[300] = {"results_A_small_CandySplitting.txt"};//large

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
		vector<int> choice(N, 0);
		vector<int> weight;
		for(int j = 0; j < N; j++)	{
			int ci;
			ifs >> ci;
			weight.push_back(ci);
		}

		sort(weight.begin(), weight.end());

		int binW[1000][21];
		memset(binW, 0, sizeof(binW));

		for(int j = 0; j < N; j++)	{
			int temp = weight[j];
			int k = 20;
			while(temp != 0)	{
				binW[j][k] = temp % 2;
				temp /= 2;
				k--;
			}
		}

		/*for(int j = 0; j < N; j++)	{
			for(int k = 0; k < 21; k++)
				cout << binW[j][k] << " ";
			cout << endl;
		}*/
		int flag = 1;
		for(int j = 0; j < 21; j++)	{
			int count = 0;
			for(int k = 0; k < N; k++)	
				if(binW[k][j] == 1)
					count++;
			if(count % 2 != 0)	{ //odd
				flag = 0;
				break;
			}
		}

		if(flag == 0)	{
			ou << "Case #" << i + 1 <<": NO" << endl;
			cout << "NO" << endl; 
		}
		else	{
			long long res = 0;
			for(int j = 1; j < N; j++)
				res += weight[j];
			ou << "Case #" << i + 1 <<": " << res << endl;
			cout << res << endl;
		}
	}
}