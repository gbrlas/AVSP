#include<iostream>
#include<map>
#include<algorithm>
#include<limits>
using namespace std;

#define MAXLEN 8
char *ar[MAXLEN + 2];
int rownum[MAXLEN + 2];
int realmin = numeric_limits<int>::max();

#define TSWAP(i,j) if(!swapped[rownum[i]][rownum[j]]&&!swapped[rownum[j]][rownum[i]]){/*cerr<<"trying swap" << i << " and " << j << endl;*/swap(ar[i],ar[j]);swap(rownum[i],rownum[j]);swapped[rownum[i]][rownum[j]] = 1;bf(n+1,N,swapped);swap(ar[i],ar[j]);swap(rownum[i],rownum[j]);swapped[rownum[i]][rownum[j]]=0;}

int bf(int n, int N, map<int, map<int, int> > swapped)
{
	// check if we're okay
	bool inv = false;
	//cerr << "## n == " << n << endl;
	for(int i = 0; i < N; i++)
	{
		//cerr << ar[i] << endl;
		for(int j = 0; j < N; j++)
		{
			if(ar[i][j] == '1' and j > i)
				inv = true;
		}
	}
	if(!inv)
	{
		//cerr << "OK!!";
		realmin = min(realmin, n);
	}
	//cerr << "#### end" << endl;
	// should I bother with this?
	if((n + 1) >= realmin)
	{
		return 0;
	}
	for(int i = 0; i < N; i++)
	{
		if(i > 0)
		{
			TSWAP((i-1), i);
		}
		if((i+1) < N)
		{
			TSWAP(i, (i+1));
		}
	}
	/*for(int i = 0; i < N; i++)
	{
		for(int j = 1; j < N; j++)
		{
			if(i == j) continue;
			if(swapped[i][j]||swapped[j][i]) continue;
			// try this swap
			//cerr << "trying swap " << i << " and " << j << endl;
			swap(ar[i], ar[j]);
			swapped[i][j] = 1;
			// recurse
			bf(n + 1, N, swapped);
			// unswap
			swap(ar[i], ar[j]);
			swapped[i][j] = 0;
		}
	}*/
}

int main()
{
	for(int i = 0; i < (MAXLEN + 2); i++)
	{
		ar[i] = new char[MAXLEN + 2];
		rownum[i] = i;
	}
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		realmin=numeric_limits<int>::max();
		int N;
		cin >> N;
		for(int n = 0; n < N; n++)
		{
			cin >> ar[n];
		}
		bf(0, N, map<int, map<int, int> >());
		cout << "Case #" << (t+1) << ": " << realmin << endl;
	}
	
}
