#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int na,nb;
int t;


int Time(string& s)
{
	return ((s[0]-'0')*10+(s[1]-'0'))*60 + (s[3]-'0')*10+(s[4]-'0');
}

vector <int> a[1500];
vector <int> b[1500];
int A[1500];
int B[1500];

int resa,resb;

int main()
{
	int n,N;
	string u,v;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);

	scanf("%d",&N);
	for (n=1;n<=N;n++)
	{
		scanf("%d",&t);
		scanf("%d %d",&na,&nb);
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		for (int i=0;i<1500;i++)
		{
			a[i].resize(0);
			b[i].resize(0);
		}
		for (int i=0;i<na;i++)
		{
			cin >>u>>v;
			a[Time(u)].push_back(Time(v)+t);
		}
		for (int i=0;i<nb;i++)
		{
			cin >>u>>v;
			b[Time(u)].push_back(Time(v)+t);
		}
		resa=resb=0;
		int cura=0,curb=0;
		for (int t0=0;t0<1500;t0++)
		{
			cura+=A[t0];
			for (int i=0;i<a[t0].size();i++)
			{
				cura--;
				if (cura<0)
				{
					resa++;
					cura=0;
				}
				B[a[t0][i]]++;
			}

			curb+=B[t0];
			for (int i=0;i<b[t0].size();i++)
			{
				curb--;
				if (curb<0)
				{
					resb++;
					curb=0;
				}
				A[b[t0][i]]++;
			}
		}
		printf("Case #%d: %d %d\n",n,resa,resb);

	}



	return 0;
}