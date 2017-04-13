// GCJ10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

#define SWAP(a,b,t) (t)=(a);(a)=(b);(b)=(t);
#define MAX(a,b)	((a)>(b))?(a):(b)
#define MIN(a,b)	((a)<(b))?(a):(b)
#define FR(i,a,b)	for(int ( i)=(a); ( i)<(b); ++( i))
#define FRE(i,a,b)	for(int ( i)=(a); ( i)<=(b); ++( i))
#define FRD(i,a,b)	for(( i)=(a); ( i)<(b); ++( i))
#define FRI(i,a)	for(( i)=(a).begin(); ( i)!=(a).end(); ++( i))
#define SWAP(a,b,t) (t)=(a);(a)=(b);(b)=(t);

#define I __int64
#define VI vector<int>
#define VL vector<I>
#define VD vector<double>
#define VLD vector<long double>
#define VS vector<string>
#define LI list<int>
#define LL list<I>
#define LD list<double>
#define LLD list<long double>
#define LS list<string>
#define SI set<int>
#define SL set<I>
#define SD set<double>
#define SLD set<long double>
#define SS set<string>
#define MII map<int,int>
#define MIL map<int,I>
#define MID map<int,double>
#define MIS map<int,string>
#define MLL map<I,I>
#define MLI map<I, int>
#define MLD map<I,double>
#define IT iterator

#define MMS(a) memset(a,0,sizeof(a))

fstream fin, fout;

/* Utilities */
void parseInt(VI &v)
{
	char s[500];
	fin.getline(s,500);
	memset(s,0,sizeof(char)*500);
	fin.getline(s,500);
	string str(s);
	for(int i=0; i != string::npos;)
	{
		string sub;
		int pos = str.find_first_of(' ',i);
		if(pos!=string::npos)
		{
			sub = str.substr(i, pos-i);
			i = pos+1;
			int val;
			sscanf(sub.c_str(),"%d ",&val);
			v.push_back(val);
		}
		else
		{
			sub = str.substr(i, str.length()-i);
			i = string::npos;
			int val;
			sscanf(sub.c_str(),"%d ",&val);
			v.push_back(val);
		}
	}
}
void parseString(VS &v,string str)
{
	/*char s[500];
	memset(s,0,sizeof(char)*500);
	fin.getline(s,500);
	string str(s);
	string str;
	fin>>str;*/

	for(int i=0; i != string::npos;)
	{
		string sub;
		int pos = str.find_first_of('/',i);
		if(pos!=string::npos)
		{
			sub = str.substr(i, pos-i);
			i = pos+1;
			v.push_back(sub);
		}
		else
		{
			sub = str.substr(i, str.length()-i);
			i = string::npos;
			v.push_back(sub);
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("F:\\Preparation\\GCJ\\A-small-attempt1.in",ios::in);
	fout.open("F:\\Preparation\\GCJ\\A-small-attempt1.out",ios::out);
	if(!fin.good())
	{
		cout<<"Input file not opened"<<endl;
		exit(-1);
	}
	if(!fout.good())
	{
		cout<<"Output file not opened"<<endl;
		exit(-1);
	}
	fin>>casecnt;
	FRE(e,1,casecnt)
	{
		int n,M;
		fin>>n>>M;
		set<string> ss;
		FR(i,0,n)
		{
			string str;
			fin>>str;
			VS vs1;
			parseString(vs1,str);
			string s1="/";
			FR(i,1,vs1.size())
			{
				s1+=vs1[i];
				ss.insert(s1);
				s1+="/";
			}
		}
		int ret=0;
		FR(i,0,M)
		{
			string str;
			fin>>str;
			if(ss.find(str)!=ss.end())
				continue;
			VS vs1;
			parseString(vs1,str);
			string s1="/";
			FR(i,1,vs1.size())
			{
				s1+=vs1[i];
				if(ss.find(s1)==ss.end())
				{
					ss.insert(s1);
					ret++;
				}
				s1+="/";
			}
		}
		fout<<"Case #"<<e<<": "<<ret<<endl;
		cout<<"Case #"<<e<<": "<<ret<<endl;
	}
	return 0;
}


/*
int _tmain(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("F:\\Preparation\\GCJ\\B-large.in",ios::in);
	fout.open("F:\\Preparation\\GCJ\\B-large.out",ios::out);
	if(!fin.good())
	{
		cout<<"Input file not opened"<<endl;
		exit(-1);
	}
	if(!fout.good())
	{
		cout<<"Output file not opened"<<endl;
		exit(-1);
	}
	fin>>casecnt;
	I a[50],s[50];
	FRE(e,1,casecnt)
	{
		I N,K,B,T;
		fin>>N>>K>>B>>T;
		I i;
		FRD(i,0,N)
			fin>>a[i];
		FRD(i,0,N)
			fin>>s[i];
		I pos=0;
		I swp=0;
		for(i=(N-1);i>=0;i--)
		{
			if((a[i]+T*s[i])>=B)
			{
				pos++;
				for(I j=i+1;j<N;j++)
				{
					if(s[j]<s[i] && (a[j]*s[i]-a[i]*s[j])<B*(s[i]-s[j]))
					{
						if((a[j]+T*s[j])<B)
							swp++;
					}
				}
			}
			if(pos==K)
				break;
		}
		if(i<0)
		{
			fout<<"Case #"<<e<<": IMPOSSIBLE"<<endl;
			cout<<"Case #"<<e<<": IMPOSSIBLE"<<endl;
		}
		else
		{
			fout<<"Case #"<<e<<": "<<swp<<endl;
			cout<<"Case #"<<e<<": "<<swp<<endl;
		}
	}
	return 0;
}*/

/*
int _tmain(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("F:\\Preparation\\GCJ\\B-small.in",ios::in);
	fout.open("F:\\Preparation\\GCJ\\B-small.out",ios::out);
	if(!fin.good())
	{
		cout<<"Input file not opened"<<endl;
		exit(-1);
	}
	if(!fout.good())
	{
		cout<<"Output file not opened"<<endl;
		exit(-1);
	}

	fin>>casecnt;
	int D,IN,M,N;
	int a[2][257];
	int color;
	int in1=0,in2=1;
	FRE(e,1,casecnt)
	{
		FR(i,0,257)
		{
			a[0][i]=99999999;
			a[1][i]=99999999;
		}
		fin>>D>>IN>>M>>N;
		FR(i,0,N)
		{
			fin>>color;
			FR(j,0,256)
			{
				// Insertion
				if(a[in1][j]!=99999999 && M)
					a[in2][color]=min(a[in2][color],a[in1][j]+abs((abs(color-j)-1))/M*IN);

				// Deletion
				if(a[in1][j]!=99999999)
					a[in2][j]=min(a[in2][j],a[in1][j]+D);

				// Change
				for(int k=max((j-M),0);k<min(256,(j+M+1));k++)
				{
					if(a[in1][k]!=99999999)
						a[in2][j]=min(a[in2][j],a[in1][k]+abs(color-j));
					else
					{
						a[in2][j]=min(a[in2][j],abs(color-j));
					}
				}
			}
			if(i==0)
				a[in2][256]=D;
			else
				a[in2][256]+=D;
			a[in2][color]=min(a[in2][color],a[in1][256]);

			in1=(in1+1)%2;
			in2=(in2+1)%2;
			FR(i,0,257)
				a[in2][i]=99999999;
		}
		int ret=99999999;
		FR(i,0,257)
			ret=min(a[in1][i],ret);
		fout<<"Case #"<<e<<": "<<ret<<endl;
		cout<<"Case #"<<e<<": "<<ret<<endl;
	}
	return 0;
}*/
/*
int _tmain(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("F:\\Preparation\\GCJ\\A-large.in",ios::in);
	fout.open("F:\\Preparation\\GCJ\\A-large.out",ios::out);
	if(!fin.good())
	{
		cout<<"Input file not opened"<<endl;
		exit(-1);
	}
	if(!fout.good())
	{
		cout<<"Output file not opened"<<endl;
		exit(-1);
	}
	fin>>casecnt;
	char a[50][50];
	FRE(e,1,casecnt)
	{
		MMS(a);
		int n,k;
		fin>>n>>k;
		string str;
		FR(i,0,n)
		{
			fin>>str;
			int r=n-1;
			for(int j=(n-1);j>=0;j--)
			{
				if(str[j]!='.')
				{
					a[i][r]=str[j];
					r--;
				}
			}
			for(;r>=0;r--)
				a[i][r]='.';
		}
		int maxr=0,maxb=0;
		FR(i,0,n)
		{
			int rcnt=0,rcnt1=0,bcnt=0,bcnt1=0;
			FR(j,0,n)
			{
				if(a[i][j]=='R')
				{
					rcnt++;
					maxr=max(maxr,rcnt);
				}
				else
				{
					rcnt=0;
				}
				if(a[i][j]=='B')
				{
					bcnt++;
					maxb=max(maxb,bcnt);
				}
				else
				{
					bcnt=0;
				}

				if(a[j][i]=='R')
				{
					rcnt1++;
					maxr=max(maxr,rcnt1);
				}
				else
				{
					rcnt1=0;
				}
				if(a[j][i]=='B')
				{
					bcnt1++;
					maxb=max(maxb,bcnt1);
				}
				else
				{
					bcnt1=0;
				}
			}
		}
		FR(i,0,n)
		{
			int rcnt=0,rcnt1=0,bcnt=0,bcnt1=0;
			int rcnt2=0,rcnt3=0,bcnt2=0,bcnt3=0;
			for(int j=i,k=0;j>=0;k++,j--)
			{
				if(a[j][k]=='R')
				{
					rcnt++;
					maxr=max(maxr,rcnt);
				}
				else
				{
					
					rcnt=0;
				}
				if(a[j][k]=='B')
				{
					bcnt++;
					maxb=max(maxb,bcnt);
				}
				else
				{
					
					bcnt=0;
				}
			}
			for(int j=(n-i-1),k=n-1;j<n;j++,k--)
			{
				if(a[j][k]=='R')
				{
					rcnt1++;
					maxr=max(maxr,rcnt1);
				}
				else
				{
					
					rcnt1=0;
				}
				if(a[j][k]=='B')
				{
					bcnt1++;
					maxb=max(maxb,bcnt1);
				}
				else
				{
					
					bcnt1=0;
				}
			}
			for(int j=0,k=(n-i-1);j<=i;j++,k++)
			{
				if(a[j][k]=='R')
				{
					rcnt2++;
					maxr=max(maxr,rcnt2);
				}
				else
				{
					
					rcnt2=0;
				}
				if(a[j][k]=='B')
				{
					bcnt2++;
					maxb=max(maxb,bcnt2);
				}
				else
				{
				
					bcnt2=0;
				}
			}
			for(int j=(n-1),k=i;k>=0;j--,k--)
			{
				if(a[j][k]=='R')
				{
					rcnt3++;
					maxr=max(maxr,rcnt3);
				}
				else
				{
					
					rcnt3=0;
				}
				if(a[j][k]=='B')
				{
					bcnt3++;
					maxb=max(maxb,bcnt3);
				}
				else
				{
					
					bcnt3=0;
				}
			}
		}
		string st;
		if(maxb<k && maxr<k)
			st="Neither";
		else if(maxb>=k && maxr<k)
			st="Blue";
		else if(maxb<k && maxr>=k)
			st="Red";
		else
			st="Both";
		fout<<"Case #"<<e<<": "<<st<<endl;
		cout<<"Case #"<<e<<": "<<st<<endl;
	}
	return 0;
}*/

/*
int _tmain(int argc, _TCHAR* argv[])
{
	fin.open("F:\\Preparation\\GCJ\\C-large.in",ios::in);
	fout.open("F:\\Preparation\\GCJ\\C-large.out",ios::out);
	if(!fin.good())
	{
		cout<<"Input file not opened"<<endl;
		exit(-1);
	}
	if(!fout.good())
	{
		cout<<"Output file not opened"<<endl;
		exit(-1);
	}
	int input[1001],order[1001],groups[1001];
	I amount[1001];
	int casecnt;
	fin>>casecnt;
	FRE(e,1,casecnt)
	{
		MMS(order);MMS(groups);MMS(amount);MMS(input);
		int r,k,n,g,cap;
		I ret=0;
		fin>>r>>k>>n;
		
		FR(i,0,n)
			fin>>input[i];

		int curStart=0;
		int next=0;
		int r1=0;
		int num=0;
		bool done=false;
		while(r1<r)
		{
			order[curStart]=++num;
			cap = k;
			int cnt=0;
			I a=0;
			int i=0;
			for(i=0;i<n;i++)
			{
				int in=(curStart+i)%n;
				if(input[in]>k)
				{
					done = true;
					break;
				}
				if(input[in]>cap)
					break;
				a += input[in];
				cap -= input[in];
				cnt++;
			}
			groups[curStart]=cnt;
			amount[curStart]=a;
			ret += a;
			r1++;
			if(order[(curStart+i)%n]>0)
			{
				next=(curStart+i)%n;
				break;
			}
			curStart=(curStart+i)%n;
		}
		if(done || (r1==r))
		{
			fout<<"Case #"<<e<<": "<<ret<<endl;
			cout<<"Case #"<<e<<": "<<ret<<endl;
			continue;
		}
		I cyclicnum=amount[curStart];
		int cyclicgroups=1;
		for(int j=next;j!=curStart;j=(j+groups[j])%n)
		{
			cyclicgroups++;
			cyclicnum += amount[j];
		}
		ret += (r-r1)/cyclicgroups*cyclicnum;
		r1 = (r-r1)%cyclicgroups;

		int l=next;
		while(r1)
		{
			ret += amount[l];
			l=(l+groups[l])%n;
			r1--;
		}

		fout<<"Case #"<<e<<": "<<ret<<endl;
		cout<<"Case #"<<e<<": "<<ret<<endl;
	}
	return 0;
}
*/

/*int _tmain(int argc, _TCHAR* argv[])
{
	fin.open("F:\\Preparation\\GCJ\\C-small-attempt3.in",ios::in);
	fout.open("F:\\Preparation\\GCJ\\C-small-attempt3.out",ios::out);
	if(!fin.good())
	{
		cout<<"Input file not opened"<<endl;
		exit(-1);
	}
	if(!fout.good())
	{
		cout<<"Output file not opened"<<endl;
		exit(-1);
	}
	int casecnt;
	fin>>casecnt;
	FRE(e,1,casecnt)
	{
		int r,k,n,g,cap;
		I ret=0;
		fin>>r>>k>>n;
		list<int> l;
		cap = k;
		int i=0;
		bool done=false;
		I result[1001];
		MMS(result);
		int r1=0;
		int cnt=0;
		FRD(i,0,n)
		{
			fin>>g;
			if(!done)
			{
				if(g>k)
					done = true;
					
				if(g>cap)
				{
					result[r1]=ret;
					r1++;
					cnt=0;
					cap=k;
					if(r1==r)
						done=true;
				}
				if(!done)
				{
					ret += g;
					l.push_back(g);
					cap -= g;
					cnt++;
				}
			}
		}
		if(!done)
		{
			while(!l.empty())
			{
				if(cnt==n)
				{
					result[r1]=ret;
					r1++;
					cnt=0;
					cap=k;
					if(r1==r)
						break;
				}
				g=l.front();
				l.pop_front();
				if(g>cap)
				{
					result[r1]=ret;
					r1++;
					cnt=0;
					cap=k;
					if(r1==r)
						break;
				}
				ret += g;
				l.push_back(g);
				cap -= g;
				cnt++;
			}
		}
		
		fout<<"Case #"<<e<<": "<<ret<<endl;
		cout<<"Case #"<<e<<": "<<ret<<endl;
	}
	return 0;
}*/

/*int _tmain(int argc, _TCHAR* argv[])
{
	fin.open("F:\\Preparation\\GCJ\\A-large.in",ios::in);
	fout.open("F:\\Preparation\\GCJ\\A-large.out",ios::out);
	if(!fin.good())
	{
		cout<<"Input file not opened"<<endl;
		exit(-1);
	}
	if(!fout.good())
	{
		cout<<"Output file not opened"<<endl;
		exit(-1);
	}
	int casecnt;
	fin>>casecnt;
	FRE(e,1,casecnt)
	{
		I n,k;
		fin>>n>>k;
		int val=(1<<n)-1;
		if(k<val)
		{
			fout<<"Case #"<<e<<": OFF"<<endl;
			cout<<"Case #"<<e<<": OFF"<<endl;
		}
		else
		{
			if(!((k-val)%(val+1)))
			{
				fout<<"Case #"<<e<<": ON"<<endl;
				cout<<"Case #"<<e<<": ON"<<endl;
			}
			else
			{
				fout<<"Case #"<<e<<": OFF"<<endl;
				cout<<"Case #"<<e<<": OFF"<<endl;
			}
		}
	}
	return 0;
}*/

