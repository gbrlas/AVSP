#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>

#define ll long long

using namespace std;

int n;
vector<int> x;
//int x[1100];

int invs(const vector<int>& v) {
    int s=v.size(), c=0;
    for(int i=0; i<s; ++i) {
        for(int j=0; j<i; ++j) {
            if(v[i] < v[j]) ++c;
        }
    }
    return c;
}

int main() {
    int Cases;
    scanf("%d", &Cases);

    for(int Case=1; Case<=Cases; ++Case) {
        scanf("%d", &n);
        x.resize(n);
        int mi=-1;
        for(int i=0; i<n; ++i){
            scanf("%d", &x[i]);
            if(mi==-1 || x[i]>x[mi]) mi=i;
        }

        vector<pair<int,int> > p;
        for(int i=0; i<n; ++i) p.push_back(make_pair(x[i],i));

        sort(p.begin(), p.end());
        int ns=0, ne=0, Dist=0;
        for(int i=0; i<n; ++i) {
            int pos = p[i].second;

            int left = pos;
            int right = n-ne-ns-1 - pos;

            if(left < right) {
                ++ns;
                Dist += left;
            }
            else {
                ++ne;
                Dist += right;
            }

            for(int j=0; j<p.size(); ++j) {
                if(p[j].second > pos) --p[j].second;
            }
        }

        printf("Case #%d: %d\n", Case, Dist);
    }

    return 0;
}
