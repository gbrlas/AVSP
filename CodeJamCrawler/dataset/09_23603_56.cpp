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

char ch;

bool ID() {
	if ((ch == '.') || (ch == '(') || (ch == ')') || ((ch >= '0') && (ch <= '9')) || ((ch >= 'a') && (ch <= 'z'))) return true;
	return false;
}

int GI;

int A[100000], B[100000];
double W[100000];
string N[100000];

FILE* fp;

int ScanTree() {
	int q = GI;
	GI++;
	do { fscanf(fp,"%c",&ch); } while (ch != '(');
	fscanf(fp,"%lf",&W[q]);
	ch = ' ';
	do { fscanf(fp,"%c",&ch); } while (!ID());
	if (ch == ')') return q;
	N[q] = "";
	while ((ch >= 'a') && (ch <= 'z')) { N[q] += " "; N[q][N[q].sz-1] = ch; fscanf(fp,"%c",&ch); }
	A[q] = ScanTree();
	B[q] = ScanTree();
	do { fscanf(fp,"%c",&ch); } while (ch != ')');
	return q;
}

char buf[1000];
vector<string> C;

int main() {
	fp = fopen("A.in","r");
	FILE* fout = fopen("A.out","w");
	int NN,i,t,k,K,j;
	fscanf(fp,"%d",&NN);
	FOR(t,NN) {
		GI = 0;
		fscanf(fp,"%d",&i);
		memset(A,0xFF,sizeof(A));
		ScanTree();
		fscanf(fp,"%d\n",&K);
		fprintf(fout,"Case #%d:\n",t+1);
		FOR(k,K) {
			fscanf(fp,"%s%d",buf,&j);
			C.clear();
			FOR(i,j) { fscanf(fp,"%s",buf); C.pb(string(buf)); }
			sort(C.begin(),C.end());
			double p = W[0];
			int q = 0,l,r,m;
			while (A[q] != -1) {
				l = 0;
				r = C.sz-1;
				while (r >= l) {
					m = (r+l)/2;
					if (C[m] == N[q]) break;
					if (C[m] > N[q]) r = m-1; else l = m+1;
				}
				if (r >= l) q = A[q]; else q = B[q];
				p *= W[q];
			}
			fprintf(fout,"%.8lf\n",p);
		}
	}
	fclose(fp);
	fclose(fout);
	return 0;
}