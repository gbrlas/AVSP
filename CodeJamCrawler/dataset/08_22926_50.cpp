#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#define sz size()
#define pb push_back
#define FOR(i,n) for(i=0;i<n;i++)

int main() {
	FILE *fp = fopen("A-large.in","r");
	FILE *fp1 = fopen("A-large.out","w");
	int t,tt,i,j;
	fscanf(fp,"%d\n",&tt);
	int S,Q;
	FOR(t,tt) {
		fscanf(fp,"%d\n",&S);
		vector<string> A;
		FOR(i,S) {
			char b[1010];
			fgets(b,1000,fp);
			A.pb(string(b));
		}
		fscanf(fp,"%d\n",&Q);
		vector<int> V(A.sz,0);
		int k = V.sz;
		int ans = 0;
		FOR(i,Q) {
			char b[1010];
			fgets(b,1000,fp);
			string s(b);
			FOR(j,A.sz) if (A[j] == s) break;
			if (V[j] == 0) { 
				if (k == 1) {
					k = V.sz-1;
					ans++;
					FOR(j,V.sz) V[j] = 1-V[j];
				} else {
					V[j] = 1;
					k--;
				}
			}
		}
		fprintf(fp1,"Case #%d: %d\n",t+1,ans);
	}
	fclose(fp1);
	fclose(fp);
	return 0;
}