#include <cstdio>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define FORD(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define REPD(i,a) FORD(i,a-1,0)
#define _m(a,b) memset(a,b,sizeof(a))

#define MAX 200

int main (void) {
	int T; scanf("%d", &T);
	int C, D, N;
	char CS[5], DS[5], NS[102];
	char MC[MAX][MAX], MD[MAX][MAX];
	char iS, S[102], A, B, F;
	
	FOR(iT, 1, T) {
		_m(MC, -1);
		scanf("%d", &C);
		REP(i, C) {
			scanf("%s", &CS);
			MC[CS[0]][CS[1]] = MC[CS[1]][CS[0]] = CS[2];
		}

		_m(MD, 0);
		scanf("%d", &D);
		REP(i, D) {
			scanf("%s", &DS);
			MD[DS[0]][DS[1]] = MD[DS[1]][DS[0]] = 1;
		}
		
		scanf("%d %s\n", &N, &NS);
		
		iS=0;
		REP(i, N) {
			S[iS++] = NS[i];
			
			F = 1;
			while(iS > 1 && F) {
				F = 0;
				
				A = S[iS - 2];
				B = S[iS - 1];
				
				if(MC[A][B] != -1 || MC[B][A] != -1) {
					S[iS-2] = MC[A][B];
					iS--;
					
					F = 1;
				} else  {
					REPD(j, iS-1)
						if(MD[B][S[j]] || MD[S[j]][B]) {
							iS = 0;
							break;
						}
				}
			}
		}
		
		printf("Case #%d: [", iT);
		REP(i, iS) printf("%s%c", (i?", ":""), S[i]);
		printf("]\n");
	}
	
	return 0;
}
