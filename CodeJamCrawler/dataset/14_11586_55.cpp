#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

ifstream in("d.in");
ofstream out("d.out");

double a[1010];
double b[1010];

int main()
{
	int k, i, j, t, n;
	in>>t;
	for (k=1; k<=t; k++)
	{
		in>>n;
		for (i=0; i<n; i++)
			in>>a[i];
		for (i=0; i<n; i++)
			in>>b[i];
		sort(a, a+n);
		sort(b, b+n);
		int ans1, ans2;
		for (i=0; i<=n; i++)
		{
			bool flag=true;
			for (j=0; j<n-i; j++)
				if (a[j+i]<b[j])
				{
					flag=false;
					break;
				}
			if (flag)
			{
				ans1=n-i;
				break;
			}
		}
		for (i=0; i<=n; i++)
		{
			bool flag=true;
			for (j=0; j<n-i; j++)
				if (b[j+i]<a[j])
				{
					flag=false;
					break;
				}
			if (flag)
			{
				ans2=i;
				break;
			}
		}
		out<<"Case #"<<k<<": ";
		out<<ans1<<' '<<ans2<<endl;
	}

}