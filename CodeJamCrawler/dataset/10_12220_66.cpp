#include<iostream>
using namespace std;
int arr[10000];
long long a[2000];
int nxt[2000];
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("Cout.txt","wt",stdout);
	int TC,i,j;
	int r,k,n;
	cin>>TC;
	for(int tc=1;tc<=TC;tc++)
	{
		cout<<"Case #"<<tc<<": ";
		cerr<<tc<<endl;
		cin>>r>>k>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		memset( a,0,sizeof(a) );
		memset( nxt,-1,sizeof(nxt) );
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(a[i] + arr[(i+j)%n] <= k)
					a[i] += arr[(i+j)%n];
				else break;
				nxt[i] = (i+j)%n;
		}

		int cur = 0;
		long long tot = 0;
		while(r--)
		{
			tot+=a[cur];
			cur = nxt[cur];
		}
		cout<<tot<<endl;
		cerr<<tc<<endl;
		
	}
}