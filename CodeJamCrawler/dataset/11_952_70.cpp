#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define _m(a,b) memset(a,b,sizeof(a))

#define MAX 102

int main(void) {
	int T; scanf("%d", &T);
	int N;
	char S[2];
	int IR[MAX], IP[MAX];
	int nP[2], P[2][MAX], FT[2][MAX];
	int iP[2], D[2], A, B, R;
	
	FOR(iT, 1, T) {
		scanf("%d", &N);

		P[0][0] = P[1][0]=1;
		nP[0] = nP[1]=0;
		FOR(i, 1, N) {
			scanf("%s", S);
			IR[i] = (S[0]=='O');
			scanf("%d", &IP[i]);
			P[IR[i]][++nP[IR[i]]] = IP[i];
		}
		
		REP(i, 2) {
			FT[i][0] = 0;
			FOR(j, 1, nP[i])
				FT[i][j] = FT[i][j-1] + abs(P[i][j-1]-P[i][j]) + 1;
		}

		iP[0] = iP[1] = 1; iP[IR[1]]++;
		_m(D,0);

		R = FT[IR[1]][1];
		FOR(i, 2, N) {
			A = IR[i - 1];
			B = IR[i];

			if(A != B && FT[B][iP[B]] + D[B] <= FT[A][iP[A] - 1] + D[A])
				D[B] += (FT[A][iP[A] - 1] + D[A]) - (FT[B][iP[B]] + D[B]) + 1;
			
			R = FT[B][iP[B]] + D[B];
			
			iP[B]++;
		}
		
		printf("Case #%d: %d\n", iT, R);
	}
	
	return 0;
}
