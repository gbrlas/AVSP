// GCJ12.cpp : Defines the entry point for the console application.
//

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
#include <iomanip>
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

I gcd(I a, I b)
{
	if(a<2 || b<2)
		return 1;
	if(a>b)
	{
		I t=a;
		a=b;
		b=t;
	}
	while(b%a)
	{
		I t=a;
		a=b%a;
		b=t;
	}
	return a;
}

class Counting
{
	I arr[67][67];
public:
	Counting()
	{
		memset(arr,0,sizeof(I)*67*67);
		FR(i,0,67)
		{
			arr[i][0]=1;
			arr[i][i]=1;
		}
		FRE(i,1,66)
			FRE(j,1,i-1)
				arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
	}
	I ncr(int n, int r)
	{
		return arr[n][r];
	}
};

/*
int main(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\A-small-attempt0.in",ios::in);
	fout.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\A-small-attempt0.out",ios::out);
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
	char s[128];

	s['e']='o';
	s['j']='u';
	s['p']='r';
	s['m']='l';
	s['y']='a';
	s['s']='n';
	s['l']='g';
	s['c']='e';
	s['k']='i';
	s['d']='s';
	s['x']='m';
	s['v']='p';
	s['n']='b';
	s['r']='t';
	s['i']='d';
	s['b']='h';
	s['t']='w';
	s['a']='y';
	s['h']='x';
	s['w']='f';
	s['f']='c';
	s['o']='k';
	s['z']='q';
	s['g']='v';
	s['q']='z';
	s['u']='j';
	s[' ']=' ';

	char str[105];
	fin.getline(str,105);
	FRE(e,1,casecnt)
	{
		
		fin.getline(str,105);
		fout<<"Case #"<<e<<": ";
		cout<<"Case #"<<e<<": ";
		FR(i,0,strlen(str))
		{
			fout<<s[str[i]];
			cout<<s[str[i]];
		}
		fout<<endl;
		cout<<endl;
	}
	return 0;
}
*/

/*
int main(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\B-large.in",ios::in);
	fout.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\B-large.out",ios::out);
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
		int n,s,p;
		fin>>n>>s>>p;
		int c=0,t,ret=0;
		FR(i,0,n)
		{
			fin>>t;
			if(t<=1)
			{
				if(p<=t)
					ret++;
				continue;
			}
			int remainder = t%3;
			int quotient = t/3;
			if(remainder==0)
			{
				if(quotient >= p)
					ret++;
				else if(s>0 && quotient+1==p)
				{
					ret++;
					s--;
				}
			}
			else if(remainder==1)
			{
				if(quotient+1 >= p)
					ret++;
			}
			else if(remainder==2)
			{
				if(quotient+1 >= p)
					ret++;
				else if(s>0 && quotient+2==p)
				{
					ret++;
					s--;
				}
			}
		}
		fout<<"Case #"<<e<<": "<<ret;
		cout<<"Case #"<<e<<": "<<ret;
	
		cout<<endl;
		fout<<endl;
	}
	return 0;
}
*/
/*
int main(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\C-large.in",ios::in);
	fout.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\C-large.out",ios::out);
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
		int a,b,ret=0;
		fin>>a>>b;
		int len=1,prod=1;
		for(int i=a/10; i; i/=10)
		{
			prod*=10;
			len++;
		}

		FRE(i,a,b)
		{
			int right=i;
			int left=0;
			int mul=prod;
			set<int> s;
			FR(j,1,len)
			{
				left=(right%10)*prod+left/10;
				right/=10;
				int num = left+right;
				mul /= 10;
				if(num>i && num <=b)
					s.insert(num);
			}
			ret += s.size();
		}
		fout<<"Case #"<<e<<": "<<ret;
		cout<<"Case #"<<e<<": "<<ret;
		cout<<endl;
		fout<<endl;
	}
	return 0;
}
*/
/*
int gcd(int a, int b)
{
	if(a>b)
	{
		int c=a;
		a=b;
		b=c;
	}
	if(a==0)
		return b;
	if(b==0)
		return a;
	if(a==1 || b==1)
		return 1;

	while(b%a)
	{
		int c=a;
		a=b%a;
		b=c;
	}
	return a;
}

int add(int x, int y, int sx, int sy, int d, set<pair<int, int> > &myset)
{
	int dx=x-sx;
	int dy=y-sy;
	if(dx*dx+dy*dy > d*d)
		return 0;

	int g = gcd(abs(dx), abs(dy));
	dx /= g;
	dy /= g;
	
	if(myset.find(pair<int, int>(dx,dy)) != myset.end())
		return 0;
	myset.insert(pair<int, int>(dx,dy));
		
	return 1;
}

int main(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\D-small-practice.in",ios::in);
	fout.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\D-small-practice.out",ios::out);
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
		int h,w,d,ret=0,sx,sy;
		set<pair<int, int> > myset;
		fin>>h>>w>>d;

		FR(i,0,h)
		{
			char s[35];
			fin>>s;
			FR(j,0,w)
			{
				if(s[j]=='X')
				{
					sx=i, sy=j;
				}
			}
		}

		sx--, sy--;

		int x1=sx, x2=sx;
		FRE(i,0,(d+1))
		{
			if(i!=0)
			{
				if(i%2)
				{
					x1 = x1-(sx*2+1);
					x2 = x2+((h-3-sx)*2+1);
				}
				else
				{
					x1 = x1-((h-3-sx)*2+1);
					x2 = x2+(sx*2+1);
				}
			}
			
			int y1=sy, y2=sy;
			FRE(j,0,d)
			{
				if(i==0 && j==0)
					continue;
				if(j!=0)
				{
					if(j%2)
					{
						y1 = y1-(sy*2+1);
						y2 = y2+((w-3-sy)*2+1);
					}
					else
					{
						y1 = y1-((w-3-sy)*2+1);
						y2 = y2+(sy*2+1);
					}
				}

				ret += add(x1,y1,sx,sy,d,myset);
				ret += add(x1,y2,sx,sy,d,myset);
				ret += add(x2,y1,sx,sy,d,myset);
				ret += add(x2,y2,sx,sy,d,myset);
			}
		}
		
		fout<<"Case #"<<e<<": "<<ret;
		cout<<"Case #"<<e<<": "<<ret;
		cout<<endl;
		fout<<endl;
	}
	return 0;
}
*/

int main(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\A-large.in",ios::in);
	fout.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\A-large.out",ios::out);
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
		int A, B;
		fin>>A>>B;
		double t=1.0;
		double ret=1e100;
		FR(i,0,A)
		{
			double p;
			fin>>p;
			double cur = (A+B-2*i+1)*t + (A+2*B-2*i+2)*(1-t);
			ret = min(ret, cur);
			t *= p;
		}
		ret = min(ret, (A+B-2*A+1)*t + (A+2*B-2*A+2)*(1-t));
		ret = min(ret, (double)B+2);
		char r1[50];
		sprintf(r1, "%0.10f", ret);
		fout<<"Case #"<<e<<": "<<r1;
		cout<<"Case #"<<e<<": "<<r1;
	
		cout<<endl;
		fout<<endl;
	}
	return 0;
}

/*
int main(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\B-large.in",ios::in);
	fout.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\B-large.out",ios::out);
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
		fout<<"Case #"<<e<<": ";
		cout<<"Case #"<<e<<": ";
	
		cout<<endl;
		fout<<endl;
	}
	return 0;
}
*/

/*
int main(int argc, _TCHAR* argv[])
{
	int casecnt;
	fin.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\B-large.in",ios::in);
	fout.open("C:\\Users\\ravill\\Documents\\Visual Studio 2010\\Projects\\Algo\\GCJ\\GCJ12\\testfiles\\B-large.out",ios::out);
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
		fout<<"Case #"<<e<<": ";
		cout<<"Case #"<<e<<": ";
	
		cout<<endl;
		fout<<endl;
	}
	return 0;
}
*/