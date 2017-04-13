#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stdio.h"

using namespace std;

#define cin fin
ifstream cin("B-large.in");
#define cout fout
ofstream cout("b1-large.out");
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

int st_a;
int st_b;
bool ua[200],ub[200];
int na,nb;
int ab[200][2];
int ba[200][2];

void addb(int ta,int tb);

void adda(int ta,int tb)
{
	ua[ta]=false;
	int tt=ab[ta][1];
	while (tb<nb)
	{
		if( ba[tb][0]>=tt && ub[tb] ) {
			addb(ta+1,tb);
			break;
		}
		tb++;
	}
}


void addb(int ta,int tb)
{
	ub[tb]=false;
	int tt=ba[tb][1];
	while (ta<na)
	{
		if( ab[ta][0]>=tt && ua[ta] ) {
			adda(ta,tb+1);
			break;
		}
		ta++;
	}
}


void work()
{
	int t;

	cin>>t;

	cin>>na>>nb;

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

	st_a=0;
	st_b=0;
	

	
	memset(ua,true,sizeof(ua));
	memset(ub,true,sizeof(ub));
	
	a1=0;
	a2=0;

	while (st_a<na || st_b<nb )
	{
		while (st_a<na && !ua[st_a] ) st_a++;
		while (st_b<nb && !ub[st_b] ) st_b++;
		if( st_a<na && st_b<nb )
		{
			if(ab[st_a][0]<ba[st_b][0])
			{
				adda(st_a,st_b);
				a1++;
			}else
			{
				addb(st_a,st_b);
				a2++;
			}
		}else
		if( st_a<na )
		{
			adda(st_a,st_b);
			a1++;
		}else
		if( st_b<nb )
		{
			addb(st_a,st_b);
			a2++;
		}
	}
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
