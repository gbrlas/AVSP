#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<iterator>
#include<complex>

#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif
using namespace std;

int N;

//string a = "ynficwlbkuomxsevzpdrjgthaq";
  string a = "yhesocvxduiglbkrztnwjpfmaq";
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","rt",stdin);
	freopen("GCJ_A.txt","wt",stdout);

#endif 
	int tc=1;
	string s;
	cin>>N;
	getline(cin,s);
	while( N--)
	{
		getline(cin,s);
		for(int i=0;i<s.size();i++)
			if(s[i]!=' ')
				s[i] = a[s[i]-'a'];
		printf("Case #%d: %s\n",tc++,s.c_str());
	}
	return 0;
}