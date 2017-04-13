#include<iostream>
using namespace std;
int main(void)
{
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		int N, K;
		cin>>N; cin>>K;
		cout<<"Case #"<<i<<": ";
		if ((K+1)%(1<<N))
			cout<<"OFF"<<endl;
		else
			cout<<"ON"<<endl;
	}
}
