#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int tn=1;tn<=t;tn++) {
		int n;
		cin>>n;
		int xo=0;
		int mini=10000000;
		int sum=0;
		for(int i=0;i<n;i++) {
			int ci;
			cin>>ci;
			xo ^= ci;
			sum+=ci;
			if(ci<mini)
				mini = ci;
		}
		cout<<"Case #"<<tn<<": ";
		if(xo)
			cout<<"NO"<<endl;
		else
			cout<<sum-mini<<endl;

	}

}
