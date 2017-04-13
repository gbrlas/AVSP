#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define lint long long

#define sz size()
#define pb push_back

#define FOR(i,n) SFOR(i,0,n)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define FORD(i,n) for(i=n-1;i>=0;i--)

vector<int> A;

int main() {
	FILE* fp = fopen("B.in","r");
	FILE* fout = fopen("B.out","w");
	int NN,i,t,k,K,j;
	char buf[100];
	fscanf(fp,"%d",&NN);
	FOR(t,NN) {
		fscanf(fp,"%s",buf);
		A.clear();
		FOR(i,strlen(buf)) A.pb((int)(buf[i]-'0'));
		FORD(i,A.sz-1) if (A[i+1] > A[i]) break;
		if (i >= 0) {
			k = i+1;
		} else {
			A.pb(0);
			FORD(i,A.sz-1) A[i+1] = A[i];
			A[0] = 0;
			k = 1;
			i = 0;
		}
		SFOR(j,i+1,A.sz) if ((A[j] < A[k]) && (A[j] > A[i])) k = j;
		swap(A[i],A[k]);
		sort(A.begin()+i+1,A.end());
		fprintf(fout,"Case #%d: ",t+1);
		FOR(i,A.sz) fprintf(fout,"%d",A[i]);
		fprintf(fout,"\n");
	}
	fclose(fp);
	fclose(fout);
	return 0;
}