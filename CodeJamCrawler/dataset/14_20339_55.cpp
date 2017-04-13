#include<cstdio>
#include <fstream>
#include<string>
#include<cstring>
#include<cmath>
#include <iomanip>
#define mod 20100501

using namespace std;
double a[1005],b[1005],c[1005],sw; 
int i,o,j,k,l,m,t,n,p,l1,l2,l3;
int main()
{
	
	ifstream fin ("1.in");
	ofstream fout ("1.out");
	fin>>t;
	l3=0;
	for (;t;t--)
		{
			fin>>n;
			for (i=1;i<=n;i++)
			fin>>a[i];
			for (i=1;i<=n;i++)
			fin>>b[i];
			for (i=1;i<n;i++)
				for (j=i+1;j<=n;j++)
				if (a[i]>a[j]){sw=a[i];a[i]=a[j];a[j]=sw;}
			for (i=1;i<n;i++)
				for (j=i+1;j<=n;j++)
				if (b[i]>b[j]){sw=b[i];b[i]=b[j];b[j]=sw;}
			k=m=0;
			
			memset(c,0,sizeof(c));
			for (i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				if ((a[j]>b[i])&&(!c[j])){++k;c[j]=1;break;}
			}
			memset(c,0,sizeof(c));
			for (i=1;i<=n;i++)
			{
			p=0;
				for(j=1;j<=n;j++) if (a[i]<b[j]&&(!c[j])){p=j;break;}
			if (p==0)for(j=1;j<=n;j++) if ((!c[j])){p=j;break;}
			c[p]=1;
			if (a[i]>b[p]) ++m;
			}
			fout<<"Case #"<<++l3<<": "<<k<<" "<<m<<endl;
		}
    return 0;
}
