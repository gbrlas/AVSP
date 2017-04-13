#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

#define mkstr(a) # a
#define in_between(a) mkstr(a)

#define PROBLEM C
#define SMALL 1
#define ATTEMPT 0

#if (SMALL)
    #define SIZE small
#else
    #define SIZE large
#endif

int main() {
    
    #if (SMALL)
    freopen(in_between(PROBLEM) "-" in_between(SIZE) "-attempt" in_between(ATTEMPT) ".in", "r", stdin);
    #else 
    freopen(in_between(PROBLEM) "-" in_between(SIZE) ".in", "r", stdin);
    #endif
    freopen(in_between(PROBLEM) "-" in_between(SIZE) ".out", "w", stdout);
 
    long long n, R, N, K;
    cin >> n;
    
    for (int i=0; i < n; i++) {
        cin >> R >> K >> N;
        
        queue<int> q;
        queue<int> q2;
        int t;
        for (int j=0; j < N; j++) {
            cin >> t;
            q.push(t);
        }
        
        int count = 0;
        for (int k=0; k < R; k++) {
            int sum=0;
            while(q.size()) {
                int next = q.front();
                if (sum + next <= K)  {
                 sum += next;
                 q.pop();
                 q2.push(next);
                } else {
                    break;
                }
            }
            while(q2.size()) {
              q.push(q2.front()); 
              q2.pop(); 
            }
            count += sum;
        }
        
        printf("Case #%d: %d\n", i+1, count);
    }
 
    return 0;   
}
