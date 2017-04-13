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

#define MAXL 20

int main() {
	int l,d,n,cases=0;
	char words[5010][MAXL],str[5010];
	cin>>l>>d;
	gets(str);
	n=atoi(str);
	for(int i=0;i<d;gets(words[i++]));
	while(n--) {
		int ans=0;
		set<char>s[MAXL];
		gets(str);
		int len=strlen(str);
		int j=0;
		for(int i=0;i<len;i++)
			if(str[i]=='(') {
				for(i+=1;str[i]!=')';i++)
					s[j].insert(str[i]);
				j++;
			}
			else 
				s[j++].insert(str[i]);
		for(int i=0;i<d;i++) {
			for(j=0;j<l;j++)
				if(s[j].find(words[i][j])==s[j].end())
					break;
			if(j==l)
				ans++;
		}
		printf("Case #%d: %d\n",++cases,ans);
	}
	return 0;
}
