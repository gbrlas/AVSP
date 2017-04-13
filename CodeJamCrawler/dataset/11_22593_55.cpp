#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
	int T;
	ifstream fin("C.txt");
	fin >> T;
	ofstream fout("C.out");
	for(int i = 1; i <= T; i++)
	{
		int res = -1;
		int N;
		fin >> N;
		int num[1000];
		for(int j = 0; j < N; j++)
		{
			fin >> num[j];
		}
		int max = (1<<(N-1)) -1;
		for(int trav = 1; trav <= max; trav++)
		{
			int check = trav;
			int w0 = 0, w1 = 0, t0 = 0, t1 = 0;
			for(int b = 0; b < N; b++)
			{
				//if(trav == 1)
				//	fout << b <<" "<<check<<" ---- " <<(check&1)<<'\n';
				if((check & 1) == 0)
				{
					t0 += num[b];
					w0 = w0 ^ num[b];
					//if(trav == 1) fout << num[b]<<" "<<t0 <<'\n';
				}
				else
				{
					t1 += num[b];
					w1 = w1 ^ num[b];
					//if(trav == 1) fout << num[b]<<" "<<t1 <<'\n';
				}
				check >>= 1;
				//fout << check<<'\n';
			}
			//if(trav == 1)
			//	fout << w0 << " " << w1<<endl;
			if(w0 == w1)
			{
				int tempres;
				if(t0 > t1)
					tempres = t0;
				else tempres = t1;
				if(tempres > res)
					res = tempres;
			}
		}
		if(res == -1)
			fout <<"Case #"<<i<<": NO"<<'\n';
		else fout << "Case #"<<i << ": "<<res<<'\n';
	}
	return 0;
}