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

/*    w e l c o m e   t o    c  o  d   e       j    a   m 
 *    0 1 2 3 4 5 6 7 8 9 10 11 12 13  14 15  16    17  18  */

#define MOD 10000

int solve( char *str) {
	int ccount[20],len=strlen(str);
	memset(ccount,0,sizeof ccount);
	string s="welcome to code jam";
	int l=s.length();
	for(int i=0;i<len;i++)
		for(int j=0;j<l;j++)
			if(s[j]==str[i])
				j==0?ccount[j]=(ccount[j]+1)%MOD:ccount[j]=(ccount[j]+ccount[j-1])%MOD;
	return ccount[18];
}

int main() {
	int N,cases=0;
	char str[1000];
	gets(str);
	N=atoi(str);
	while(N--) {
		gets(str);
		printf("Case #%d: %04d\n",++cases,solve(str));
	}
	return 0;
}
