#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long
#define MAXN 1010

double A[MAXN],B[MAXN];
bool us[MAXN];

int main() {
    int nt,n,x,y,nteste=1;
    scanf("%d",&nt);
    while (nt--) {
        scanf("%d",&n);
        for (int i=0; i<n; i++)
            scanf("%lf",&A[i]);
        for (int i=0; i<n; i++)
            scanf("%lf",&B[i]);
        
        sort(A,A+n);
        sort(B,B+n);
        y = 0;
        for (int i=0; i<n; i++)
            us[i] = false;
        
        for (int i=0; i<n; i++) {
            int ind = -1;
            for (int j=0; j<n; j++)
                if (!us[j] && B[j]>A[i]) { ind = j; break; }
            if (ind != -1) us[ind] = true;
            else {
                y++;
                for (int j=0; j<n; j++)
                    if (!us[j]) { us[j] = true; break; }
            }
        }
        
        x = 0;
        for (int i=0,j=0; i<n; i++) {
            if (A[i] > B[j]) x++,j++;
        }
        
        printf("Case #%d: %d %d\n",nteste++,x,y);
    }
    
    return 0;
}
