#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    //freopen("in.txt","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output-small.txt","w",stdout);
    int T;
    cin >> T;
    for(int t=0; t<T; ++t){
        int n, curo=1,
			curb=1, timeA=0,timeB=0;
        cin >> n;
        char c;
        int cur;
        int time=0;
        for(int i=0; i<n; ++i){
            cin >> c >> cur;
            if (c=='O') {
                timeA += abs(curo-cur)+1;
                if (timeA <= timeB) timeA=timeB+1;
                curo=cur;
            } else {
                timeB += abs(curb-cur)+1;
                if (timeA>=timeB) timeB=timeA+1;
                curb=cur;
            }
        }
        printf("Case #%d: %d\n", t+1, max(timeA,timeB));
    }
    return 0;
}
