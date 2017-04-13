#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<ctype.h>

using namespace std;

int main()
{

	long L,D,N,i,j,k,res;
	char t;
	string pat[5002];
	
	//freopen("a.txt","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small.out","w",stdout);
	cin>>L>>D>>N;

	for(i=0;i<D;i++)
		cin>>pat[i];

	for(i=0;i<N;i++)
	{
		set<char> s[20];
		for(j=0;j<L;j++)
		{
			cin>>t;
			if(t!='(') s[j].insert(t);
			else 
			{
				for(k=0;k<10000;k++)
				{	
					cin>>t;
					if(t==')') break;
					s[j].insert(t);
				}
			}
		}

		for(res=k=0;k<D;k++)
		{
			for(j=0;j<L;j++)
			{
				t = pat[k][j];
				if(!s[j].count(pat[k][j])) break;
			}
			if(j==L) res++;
		}

		printf("Case #%ld: %ld\n",i+1,res);
		
	}

	return 0;
}