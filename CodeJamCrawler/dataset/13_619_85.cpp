//shivi..coding is adictive!!
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<functional>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<fstream>
using namespace std;
bool perfectsquare(int i)
{
	int p=sqrt(i);
	return (i==p*p);
}

bool ispalli(int i)
{
	int n=i,p,l;
	vector<int> vi;
	while(n)
	{
		p=n%10;
		vi.push_back(p);
		n-=p;
		n/=10;
	}
	l=vi.size();
	for(int i=0,j=l-1;i<l && j>=0;++i,--j)
	{
		if(vi[i]!=vi[j])
		return 0;
	}
	return 1;
}

bool palli(int i)
{
	int k=sqrt(i);
	return ispalli(k)&&ispalli(i);
}
int ans=0,a,b;
void work()
{
	ans=0;
	for(int i=a;i<=b;++i)
	{
		if(perfectsquare(i))
			{
				if(palli(i))++ans;
			}
	}
	
	
}
int main()
{
	fstream f,m;
	f.open("C:\\Users\\shivendra\\Desktop\\fair_square.txt",ios::out|ios::binary);
	m.open("C:\\Users\\shivendra\\Desktop\\kkk.txt",ios::in|ios::binary);
	int t,i=1;
	m>>t;
	while(t--)
	{
		m>>a>>b;
		f<<"Case #"<<i++<<": ";
		work();
		f<<ans<<endl;
	}
	f.close();
	m.close();
}
