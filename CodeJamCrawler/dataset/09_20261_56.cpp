#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int T;
	cin>>T;
	for(int run = 1; run <= T; ++run)
	{
		cout<<"Case #"<<run<<": ";
		cin>>s;
		string out;
		int nz = 0;
		for(unsigned i = 0; i < s.size(); ++i) if(s[i] == '0') ++nz; else out += s[i];
		bool p = true;
		for(unsigned i = 1; p && i < s.size(); ++i) if(s[i-1] < s[i]) p = false;
		if(p) reverse(out.begin(), out.end()), s = out.insert(1, string(nz+1, '0'));
		else if(!next_permutation(s.begin(), s.end())) cout<<"WTF?! "<<s<<' ';

		cout<<s<<endl;
	}
}
