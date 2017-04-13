#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stdio.h"

using namespace std;

#define cin fin
ifstream cin("a.in");
#define cout fout
ofstream cout("a.out");


bool notsame(const string & a,const string & b)
{
	if( a.length()!=b.length() ) return true;
	int i;
	for(i=0;i<a.length();i++)
		if( a[i]!=b[i]) return true;
	return false;
}


int work()
{
	int s,q;
	int qq;
	string ss;
	char tmp[200];
	vector<string> eng;
	vector<string> list;
	int i;
	int ans=0;
	cin>>s;
	cin.getline(tmp,200);
	for( i=0;i<s;i++)
	{
		cin.getline(tmp,200);
		ss=tmp;
		eng.push_back(ss);
	}
	cin>>q;
	qq=q+q;
	cin.getline(tmp,200);
	for( i=0;i<q;i++)
	{
		cin.getline(tmp,200);
		ss=tmp;
		list.push_back(ss);
	}
	int f[100][100];
	memset(f,255,sizeof(f));
	int last=-1;
	int new_last;

	if( q>0 )
	for( i=0;i<s;i++)
		if( notsame(list[0],eng[i]) )
		{	
			f[0][i]=0;
			if( last==-1 ) last=0;
		}
		else f[0][i]=-1;
	
	int j;

	for( i=1;i<q;i++)
	{
		new_last=-1;
		for( j=0;j<s;j++)
			if( notsame(list[i],eng[j]) )
			{
				f[i][j]=qq;

				if( f[i-1][j]!=-1 && f[i-1][j]<f[i][j] )
				{
					f[i][j]=f[i-1][j];
				}
				if( last!=-1 && last+1<f[i][j] ) f[i][j]=last+1;
				if( new_last==-1 || f[i][j]<new_last) new_last=f[i][j];
			}
		last=new_last;
		
	}
	if( q>1 ) ans=last;
	return ans;

}

int main()
{
	int test_num;
	cin>>test_num;
	int ti;
	int ans=0;
	for( ti=1; ti<=test_num;ti++)
	{
		ans=work();
		cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
	return 0;
}
