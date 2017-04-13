/*By Rahul Goutam*/
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<ios>
#include<iostream>
#include<iosfwd>
#include<iomanip>
#include<istream>
#include<ostream>
#include<sstream>
#include<complex>
#include<numeric>
#include<valarray>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	int t,cases=0;
	char str[500];
	gets(str);
	t=atoi(str);
	while(t--) {
		int base,len;
		set<char>s;
		map<char,int>m;
		gets(str);
		len=strlen(str);
		for(int i=0;i<len;i++)
			s.insert(str[i]);
		base=max(2,(int)s.size());
		m[str[0]]=1;
		int dig=0;
		for(int i=1;i<len;i++) {
			if(m.find(str[i])==m.end()) {
				m[str[i]]=dig++;
				if(dig==1)
					dig=2;
			}
		}
		long long int p=1,ans=0;
		for(int i=len-1;i>=0;i--) {
			ans+=m[str[i]]*p;
			p*=base;
		}
		printf("Case #%d: %lld\n",++cases,ans);
	}
	return 0;
}
