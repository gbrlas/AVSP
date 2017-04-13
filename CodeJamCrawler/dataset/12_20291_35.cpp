#include <iostream>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		int m,s,p;
		int a[105];
		cin>>m>>s>>p;
		p=3*p-2;
		int k=0;
		for (j=1;j<=m;j++)
		{
			cin>>a[j];
			if (a[j]>=p) {k++; continue;}
			int l=p-2; if (l<1) {l=1;}
			if (s>0&&a[j]>=l) {s--; k++;}
		}
		cout<<"Case #"<<i<<": "<<k<<endl;
	}
}