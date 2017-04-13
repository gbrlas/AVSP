#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

#define mkstr(a) # a
#define in_between(a) mkstr(a)

#define READFROMFILE 1

#define PROBLEM C
#define SMALL 1
#define ATTEMPT 0

#if (SMALL)
    #define SIZE small
#else
    #define SIZE large
#endif

int main() {
    
    #if (READFROMFILE)
        #if (SMALL)
        freopen(in_between(PROBLEM) "-" in_between(SIZE) "-attempt" in_between(ATTEMPT) ".in", "r", stdin);
        #else
        freopen(in_between(PROBLEM) "-" in_between(SIZE) ".in", "r", stdin);
        #endif
        freopen(in_between(PROBLEM) "-" in_between(SIZE) ".out", "w", stdout);
    #endif
     
    int n;
    cin >> n;
    
    for (int i=0; i < n; i++) {
        int N;
        cin >> N;
        bool bac[1000][1000];
        
        int maxx, maxy;
        for (int j =0; j < N; j++) {
            int x, y, X, Y;
            cin >> x >> y >> X >> Y;
            maxx = max(maxx, X);
            maxy = max(maxy, Y);
            for (int k=x-1; k <= X-1; k++) {
                for (int l=y-1; l<= Y-1; l++) {
                    bac[l][k] = 1;
                }    
            }
        }
        int count = 0;
        while(true) {
            bool good = false;
            count++;
            bool b[1000][1000];
            for (int k=1; k <= maxx; k++) {
                b[0][k] = bac[0][k-1] ? bac[0][k] : 0;
            }
            for (int j=1; j <= maxy; j++) {
                b[j][0] = bac[j-1][0] ? bac[j][0] : 0;
            }
            for (int j=1; j <= maxy+1; j++) {
                for (int k=1; k <= maxx+1; k++) {
                    if (bac[j][k]) {
                       good = true;
                       b[j][k] = 1;
                       if (bac[j-1][k] == 0 && bac[j][k-1] == 0)
                          b[j][k] = 0;               
                    } else {
                       if (bac[j-1][k] == 1 && bac[j][k-1] == 1) {
                          b[j][k] = 1;
                          maxx = max(k, maxx);
                          maxy = max(j, maxy);
                       }
                    }    
                }
            }
            for (int j=0; j < 1000; j++) {
                for (int k=0; k < 1000; k++) {
                    bac[j][k] = b[j][k];
                }    
            }
            if (!good) break;
        }
      
        printf("Case #%d: %d\n", i+1, count-1);
    }
 
    return 0;   
}
