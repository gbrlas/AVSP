#include<iostream>
using namespace std;

const int maxn = 1010;

int in[maxn];

int main()
{
	int t;
	cin >> t;
	for(int	tn = 1; tn<=t;tn++) {
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>in[i];
		int num=0;
		for(int i=0;i<n;i++)
			num += in[i]!=i+1;
		cout<<"Case #"<<tn<<": "<<num<<".000000"<<endl;
	}
}
