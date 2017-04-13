#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define sz size()
#define pb push_back
#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define lint __int64

int main() {
	FILE *fp, *fp1;
	fp = fopen("D-small.in","r");
	fp1 = fopen("D-small.out","w");
	int t,tt,k;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		char buf[2000];
		fscanf(fp,"%d%s",&k,buf);
		string s(buf),s1(buf);
		int i,j;
		vector<int> A;
		FOR(i,k) A.pb(i);
		int t1, ans = 100000;
		do {
			FOR(i,s.sz/k) FOR(j,k) s1[i*k+j] = s[i*k+A[j]];
			t1 = 0;
			FOR(i,s.sz-1) if (s1[i] != s1[i+1]) t1++;
			if (ans > t1) ans = t1;
		} while (next_permutation(A.begin(),A.end()));
		fprintf(fp1,"Case #%d: %d\n",t+1,ans+1);
	}
	fclose(fp);
	fclose(fp1);
}