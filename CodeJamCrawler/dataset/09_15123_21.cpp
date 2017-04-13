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
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>arr[i];
		int res=0;
		for(int i=0;i<n;i++)
		{
			int j=0;
			for(j=i;j<n;j++)
			{
				bool f=true;
				for(int k=i+1;k<n;k++)
					if(arr[j][k]=='1')
					{
						f=false;
						break;
					}
				if(f)break;
			}
			for(int k=j;k>i;k--)
			{
				res++;
				swap(arr[k],arr[k-1]);
			}
		}
		cout<<"Case #"<<ind<<": "<<res<<endl;
		
	}
	return 0;
}