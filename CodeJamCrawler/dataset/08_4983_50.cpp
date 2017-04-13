#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stdio.h"

using namespace std;

#define cin fin
ifstream cin("b1.in");
#define cout fout
ofstream cout("b.out");
int a1;
int a2;

int gettime()
{
	char ch;
	int time=0;
	int a=0;
	int b=0;
	cin>>ch;
	a=ch-'0';
	cin>>ch;
	a=a*10+ch-'0';
	cin>>ch>>ch;
	b=ch-'0';
	cin>>ch;
	b=b*10+ch-'0';
	time=a*60+b;
	return time;
}

void work()
{
	int t;
	int na,nb;
	cin>>t;

	cin>>na>>nb;
	int ab[200][2];
	int ba[200][2];
	int i,j;
	for(i=0;i<na;i++)
	{
		ab[i][0]=gettime();
		ab[i][1]=gettime()+t;
	}
	
	for(i=0;i<nb;i++)
	{
		ba[i][0]=gettime();
		ba[i][1]=gettime()+t;
	}
	for(i=0;i<na;i++)
		for(j=i+1;j<na;j++)
		{
			if(ab[i][0]>ab[j][0])
			{
				swap(ab[i][0],ab[j][0]);
				swap(ab[i][1],ab[j][1]);
			}
		}

	
	for(i=0;i<nb;i++)
		for(j=i+1;j<nb;j++)
		{
			if(ba[i][0]>ba[j][0])
			{
				swap(ba[i][0],ba[j][0]);
				swap(ba[i][1],ba[j][1]);
			}
		}
	int cara[6000];
	int carb[6000];
	memset(cara,0,sizeof(cara));
	memset(carb,0,sizeof(carb));

	int pa=0;
	int pb=0;

	int max_a=0;
	int max_b=0;
	for( i=0;i<1500;i++)
	{
		if( pa<na && ab[pa][0]==i )
		{
			cara[i]++;
			carb[ab[pa][1]]--;
			pa++;
		}
		if( pb<nb  && ba[pb][0]==i )
		{
			carb[i]++;
			cara[ ba[pb][1] ]--;
			pb++;
		}
		if( cara[i] > max_a ) max_a=cara[i];
		if( carb[i] > max_b ) max_b=carb[i];
		cara[i+1]+=cara[i];
		carb[i+1]+=carb[i];
	}
	a1=max_a;
	a2=max_b;
}

int main()
{
	int test_num;
	cin>>test_num;
	int ti;
	for( ti=1; ti<=test_num;ti++)
	{
		work();
		cout<<"Case #"<<ti<<": "<<a1<<" "<<a2<<endl;
	}
	return 0;
}
