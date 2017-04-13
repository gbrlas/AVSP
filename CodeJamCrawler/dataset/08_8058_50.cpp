#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define INT_INF 0x7FFFFFFF

main() {
        int N;
    scanf("%d", &N);
    int caso = 1;
    int a;
    int b;
    int turn;
    int numA;
    int numB;
    while(caso <= N) {
        scanf("%d", &turn);
        scanf("%d %d", &numA, &numB);
       
	    vector<int > leaveA(numA);
	    vector<int > leaveB(numB);
	    vector<int > arrA(numB);
	    vector<int > arrB(numA);
        rep(i,numA) {
            int h;
            int m;
            scanf("%d:%d", &h, &m);
            leaveA[i] = h*60 + m;
         //  printf("h=%d, m=%d\n",h ,m);
            scanf("%d:%d", &h, &m);
            arrB[i] = h*60 + m + turn;
        }
		//printf("cabou a");
        rep(i,numB) {
            int h;
            int m;
            scanf("%d:%d", &h, &m);
            leaveB[i] = h*60 + m;
           
          // printf("h=%d, m=%d\n",h ,m);
            scanf("%d:%d", &h, &m);
            arrA[i] = h*60 + m + turn;
        }
      // printf("leave: %d", leaveB[0]);
        rep(i, leaveA.size()) {
            int min = INT_INF;
            int minI = 0;
            int j;
            for(j = i; j < leaveA.size(); j++) {
                if (min > leaveA[j]){
                    minI = j;
                    min = leaveA[j];
                }
            }
            int aux = leaveA[i];
            leaveA[i] = leaveA[minI];
            leaveA[minI] = aux;
           
            aux = arrB[i];
            arrB[i] = arrB[minI];
            arrB[minI] = aux;
        }
		//printf("\n\nleaveB\n\n");
		//rep(i, leaveB.size()) {
		//		printf("%d = %d ,,", i, leaveB[i]);
		//}
		
        rep(i, leaveB.size()) {
            int min = INT_INF;
            int minI = 0;
            int j;
            for(j = i; j < leaveB.size(); j++) {
                if (min > leaveB[j]){
                    minI = j;
                    min = leaveB[j];
                }
            }
            int aux = leaveB[i];
            leaveB[i] = leaveB[minI];
            leaveB[minI] = aux;
           
            aux = arrA[i];
            arrA[i] = arrA[minI];
            arrA[minI] = aux;
        }
       
		//printf("\n\nleaveB\n\n");
		//rep(i, leaveB.size()) {
		//		printf("%d = %d ,,", i, leaveB[i]);
		//}
        int numTrensA = leaveA.size();
        int numTrensB = leaveB.size();
        int validoA[leaveA.size()];
        int validoB[leaveB.size()];
       
        int usadoA[leaveA.size()];
        int usadoB[leaveB.size()];
		
        rep(i, leaveA.size()) {
            validoA[i] = 1;
			usadoA[i] = 0;
        }
        rep(i, leaveB.size()) {
            validoB[i] = 1;
			usadoB[i] = 0;
        }
       
        int modificado = 1;
        while(modificado) {
            modificado = 0;
            rep(i,arrB.size()) {
				if (!usadoA[i]) {
	                rep(j,leaveB.size()) {
	                    if (arrB[i] <= leaveB[j] && validoB[j]) {
							//printf("trem A %d no trilho B %d\n", i, j);
							//printf("arrB[%d] %d\n",i,arrB[i]);
							//printf("leaveB[%d] %d\n\n",j, leaveB[j]);
	                        numTrensB--;
	                        modificado = 1;
	                        validoB[j] = 0;
							usadoA[i] = 1;
	                        break;
	                    }
	                }
				}
            }
            rep(i,arrA.size()) {
				if (!usadoB[i]) {
	                rep(j,leaveA.size()) {
	                    if (arrA[i] <= leaveA[j] && validoA[j]) {
							//printf("trem B %d no trilho A %d", i, j);
	                        numTrensA--;
	                        modificado = 1;
	                        validoA[j] = 0;
							usadoB[i] = 1;
	                        break;
	                    }
	                }
					
				}
            }
        }
        printf("Case #%d: %d %d\n", caso++, numTrensA, numTrensB);
    }
}


// Powered by FileEdit
// Powered by moj 4.1 [modified TZTester]
// Powered by CodeProcessor


