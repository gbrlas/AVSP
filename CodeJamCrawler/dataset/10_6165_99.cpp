#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

int main()	{

	freopen("a_large.in","r",stdin);
	freopen("a_large.out","w",stdout);

	int n,k,t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)	{
		cin>>n>>k;
		cout<<"Case #"<<tt<<": ";
		if((1<<n)-1==k%(1<<n)) cout<<"ON"<<endl;
		else cout<<"OFF"<<endl;
	}

	return 0;
}
