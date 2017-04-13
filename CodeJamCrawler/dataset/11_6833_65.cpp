#include <iostream>
using namespace std;
void solve(int num)
{
	int n;
	cin>>n;
	int l,h;
	cin>>l>>h;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int res=-1;
	for(int i=l;i<=h;i++)
	{
		bool broken=false;
		for(int j=0;j<n;j++)
			if(a[j]%i!=0 && i%a[j]!=0)
			{
				broken=true;
				break;
			}
		if(!broken)
		{
			res=i;
			break;
		}
	}
	cout<<"Case #"<<num<<": ";
	if(res==-1)cout<<"NO\n";
	else cout<<res<<'\n';
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)solve(i+1);
	return 0;
}
