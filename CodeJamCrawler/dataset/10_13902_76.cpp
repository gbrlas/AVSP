#include <stdio.h>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    int rem = 0;
    while(a) {
        rem = b % a;
        b = a;
        a = rem;
    }
    return b;
}
int gcdofall(vector<int> &diffs)
{
    int g = diffs[0];
    for (int i=1; i<diffs.size(); ++i) {
        g = gcd(g, diffs[i]);
        if (g == 1) {
            break;
        }
    }

    return g;
}
int input[3];
int main()
{
    int C;
    scanf("%d",&C);
    for(int test = 1; test<=C; ++test) {
        int N;
        scanf("%d",&N);

        for (int n = 0; n< N; ++n) {
            scanf("%d", &input[n]);
        }

        vector<int> diffs;
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                diffs.push_back(abs(input[i] - input[j]));
            }
        }

        int g = gcdofall(diffs);
        int ans = g - (input[0] % g);
        if ( g == ans) {
            ans = 0;
        }

        printf("Case #%d: %d\n", test, ans);
    }
    return 0;
}