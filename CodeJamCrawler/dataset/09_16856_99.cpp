#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

vector<vector<int> >m;
int mm[110][110];
vector<int> v;
int num;
int t,h,w;

int dfs(int i,int j)
{
	if(mm[i][j]!=-1)return mm[i][j];
	int mmm=1000000000,mi,mj;
	if(i>0&&m[i-1][j]<mmm)
	{
		mmm=m[i-1][j];
		mi=i-1;mj=j;
	}
	if(j>0&&m[i][j-1]<mmm)
	{
		mmm=m[i][j-1];
		mi=i;mj=j-1;
	}		
	if(j<w-1&&m[i][j+1]<mmm)
	{
		mmm=m[i][j+1];
		mi=i;mj=j+1;
	}
	if(i<h-1&&m[i+1][j]<mmm)
	{
		mmm=m[i+1][j];
		mi=i+1;mj=j;
	}
	if(m[i][j]>mmm)
	{
		mm[i][j]=dfs(mi,mj);
		return mm[i][j];
	}else
	{
		num++;
		mm[i][j]=num;
		return num;
	}
}

int main()
{
	int r,i,j,k;
	cin>>t;
	for(r=0;r<t;r++)
	{
		m.clear();
		num=0;
		cin>>h>>w;
		for(i=0;i<h;i++)
		{
			v.clear();
			for(j=0;j<w;j++)
			{
				cin>>k;
				v.pb(k);
			}
			m.pb(v);
		}
		for(i=0;i<110;i++)for(j=0;j<110;j++)mm[i][j]=-1;
		cout<<"Case #"<<r+1<<":"<<endl;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				cout<<(char)('a'+dfs(i,j)-1);
				if(j<w-1)cout<<" ";
			}
			cout<<endl;
		}
		
	}
}
