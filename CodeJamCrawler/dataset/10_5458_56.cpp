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

#define PROBLEM B
#define SMALL 1
#define ATTEMPT 2

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
     
    unsigned long long n;
    cin >> n;
    
    unsigned long long N, K, B, T;
    
    for (int i=0; i < n; i++) {
        cin >> N >> K >> B >> T;
        vector<unsigned long long> X;
        for (int j=0; j < N; j++) {
            unsigned long long next;
            cin >> next;
            X.push_back(next);
        }
        vector<unsigned long long> V;
        for (int j=0; j < N; j++) {
            unsigned long long next;
            cin >> next;    
            V.push_back(next);
        }
        int possible = 0;
        for (int j=0; j < N; j++) {
            if (X[j] + T*V[j] >= B) possible++;
        }
        
        if (possible < K) {
           printf("Case #%d: %s\n", i+1, "IMPOSSIBLE");
           continue;          
        }
        
        int finishes = 0;
        int curCantFinish=0;
        int swaps = 0;
        int j = N-1;
        while (true) {
            for (; j >= 0; j--) {
                if (X[j] + T*V[j] >= B) {
                         finishes++;
                         curCantFinish = 0;
                }
                else break;
            }
            if (finishes >= K) break;
            curCantFinish++;
            swaps++;
            
            unsigned long long tX = X[j-curCantFinish];
            X.erase(X.begin()+j-curCantFinish);
            X.insert(X.begin()+j, tX);
            
            unsigned long long tV = V[j-curCantFinish];
            V.erase(V.begin()+j-curCantFinish);
            V.insert(V.begin()+j, tV);
            
            /*
            for (int k=0; k < X.size(); k++) {
                cout << X[k] << " ";    
            }
            cout << endl;
            for (int k=0; k < V.size(); k++) {
                cout << V[k] << " ";    
            }
            cout << endl;
            */
        }
        
        printf("Case #%d: %d\n", i+1, swaps);
    }
 
    return 0;   
}
