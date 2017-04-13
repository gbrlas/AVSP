#include<cstdio>
#include <fstream>
#include<string>
#include<cstring>
#include<cmath>
#define mod 20100501

using namespace std;
double  a[20];
int i,o,j,k,l,n,m,t,sum,p,l1,l2,l3;
double q,tt,te,pl;
int main()
{
	
	ifstream fin ("1.in");
	ofstream fout ("1.out");
	fin>>t;
	l3=0;
	for (;t;t--)
		{
		fin>>l1;
		memset(a,0,sizeof(a));
		for (i=1;i<=4;i++)
			for (j=1;j<=4;j++)
			{
				fin>>l;
				if (i==l1) a[l]++;
			}
		fin>>l2;
		for (i=1;i<=4;i++)
			for (j=1;j<=4;j++)
			{
				fin>>l;
				if (i==l2) a[l]++;
			}
		p=0;
		for (i=1;i<=16;i++)
			if (a[i]==2) {++p;m=i;}
		fout<<"Case #"<<++l3<<": ";
		if (p==0) fout<<"Volunteer cheated!"<<endl;
		if (p==1) fout<<m<<endl;
		if (p>1) fout<<"Bad magician!"<<endl;
		}
		
    return 0;
}
