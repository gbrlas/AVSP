#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int A[107][107];
int N,M,NT,t;

bool Put(int i, int j)
{
	if(A[i][j]==1 && A[i][j+1]==1 && A[i+1][j]==1 && A[i+1][j+1]==1)
	{
		A[i][j] = 3;
		A[i][j+1] = 4;
		A[i+1][j] = 5;
		A[i+1][j+1] = 6;
		return true;
	}
	return false;
}

void Solve()
{
	int i,j;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			if(A[i][j]==1) 
			{
				if(Put(i,j))
				{
				}
				else 
				{
					cout<<"Impossible"<<endl;
					return;
				}
			}

	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			if(A[i][j]==1)
			{
				cout<<"Impossible"<<endl;
				return;
			}

			
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			if(A[i][j]==0) cout<<'.';
			if(A[i][j]==3) cout<<'/';
			if(A[i][j]==4) cout<<'\\';
			if(A[i][j]==5) cout<<'\\';
			if(A[i][j]==6) cout<<'/';
		}
		cout<<endl;
	}
}

int main()
{
	int i,j;
	char c;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin>>NT;
	for(t=1;t<=NT;t++)
	{
		cout<<"Case #"<<t<<":"<<endl;
		cin>>N>>M;
		for(i=1;i<=N;i++)
			for(j=1;j<=M;j++)
			{
				cin>>c;
				if(c=='.') A[i][j] = 0;
				else A[i][j] = 1;
			}
		Solve();
	}

	return 0;
}

