#include <iostream>
using namespace std;
typedef unsigned uint;
void solve_test(int test_num)
{
	int n;cin>>n;
	uint sum=0,xval=0,mval=4000000000u;
	for(int i=0;i<n;i++)
	{
		uint k;cin>>k;
		xval^=k;
		sum+=k;
		mval=min(mval,k);
	}
	cout<<"Case #"<<test_num<<": ";
	if(xval!=0)cout<<"NO\n";
	else cout<<sum-mval<<"\n";
}
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
		solve_test(i+1);
	return 0;
}
