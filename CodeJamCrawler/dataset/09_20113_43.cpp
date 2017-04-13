#include<iostream>
#include<string>
using namespace std;

string s[5001];
string now;
int hash[1<<4];

int calc(int &j)
{
	if(now[j]!='(')
		return 1<<(now[j]-'a');
	int ret=0;
	for(j++;now[j]!=')';j++)
	{
		ret+=(1<<(now[j]-'a'));
	}
	return ret;
}

int main()
{
	int i,j,k,L,D,N,tot;
	scanf("%d%d%d",&L,&D,&N);
	for(i=0;i<D;i++)
	{
		cin>>s[i];
	}

	for(i=0;i<N;i++)
	{
		cin>>now;
		k=0;
		for(j=0;j<now.size();j++)
		{
			hash[k++]=calc(j);
		}
		tot=0;
		for(j=0;j<D;j++)
		{
			for(k=0;k<L;k++)
			{
				if(((1<<(s[j][k]-'a')) & hash[k]) == 0)
					break;
			}
			if(k==L)
				tot++;
		}
		printf("Case #%d: %d\n",i+1,tot);
	}

	return 0;
}