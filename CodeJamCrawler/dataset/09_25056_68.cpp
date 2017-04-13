#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int T; cin>>T;
	for(int t=1;t<=T;t++)
	{
		string num; cin>>num;
		string copy = num;
		if(!next_permutation(copy.begin(), copy.end()))
		{
			copy = "0" + num;
			next_permutation(copy.begin(), copy.end());
		}
		cout<<"Case #"<<t<<": "<<copy<<endl;
	}
	return 0;
}
