#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
string arr[50];
int main() 
{
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	int T;
	cin>>T;
	int ind=0;
	while(T--)
	{
		ind++;
		double res;
		int n;
		cin>>n;
		int x[100],y[100],r[100];
		for(int i=0;i<n;i++)cin>>x[i]>>y[i]>>r[i];
		if(n==1)res=r[0];
		if(n==2)res=MAX(r[0],r[1]);
		if(n==3)
		{
			res=MAX(MAX(r[0],r[1]),r[2]);
			double l12=sqrt(0.+(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]))+r[1]+r[2];
			double l02=sqrt(0.+(x[0]-x[2])*(x[0]-x[2])+(y[0]-y[2])*(y[0]-y[2]))+r[0]+r[2];
			double l01=sqrt(0.+(x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]))+r[1]+r[0];
			l12/=2.;
			l01/=2.;
			l02/=2.;
			res=MAX(r[0],l12);
			res=MIN(res,MAX(r[1],l02));
			res=MIN(res,MAX(r[2],l01));
		}
		cout<<"Case #"<<ind<<": ";
		printf("%.6lf\n",res);
		
	}
	return 0;
}