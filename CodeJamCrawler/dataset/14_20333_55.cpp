#include<cstdio>
#include <fstream>
#include<string>
#include<cstring>
#include<cmath>
#include <iomanip>
#define mod 20100501

using namespace std;
double  a[20];
int i,o,j,k,l,m,t,sum,p,l1,l2,l3;
double c,f,be,n,x;
int main()
{
	
	ifstream fin ("1.in");
	ofstream fout ("1.out");
	fin>>t;
	l3=0;
	fout.setf(ios::fixed);
	fout.precision(7); 
	for (;t;t--)
		{
			fin>>c>>f>>x;
			be=0;
			n=0;
			while ((x/(n*f+2.0))>(x/((n+1)*f+2.0)+c/(n*f+2.0)))
			{
				be+=c/(n*f+2.0);
				n+=1;
			}
			be+=x/(n*f+2.0);
			fout<<"Case #"<<++l3<<": "<<be<<endl;
		}
		
    return 0;
}
