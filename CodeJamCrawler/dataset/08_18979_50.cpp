#include <iostream>
using namespace std;

const int  max = 1000;

struct tnode {
       int start;
       int end;
       int id;
};

tnode a[1441];

int ans[3];
int sum = 0;
int ti[1001], v[1001], id[1001];
int na, nb;
int N, T;

bool cmp(const tnode & i, const tnode & j)
{
     if (i.start < j.start) return 1;
     if (i.start > j.start) return 0;
     return (i.end < j.end);
}

void solve()
{
     sum = 0; ans[1] = ans[2] = 0;
     memset(v, 0, sizeof(v));
     for (int i = 1; i <= na + nb; i++) {
         int have = 0;
         for (int j = 1; j <= sum; j++) if (v[j] == 0 && id[j] == a[i].id && ti[j] <= a[i].start) {
             v[j] = 1;
             sum++;
             id[sum] = 3 - a[i].id;
             ti[sum] = a[i].end + T;
             have = 1; break;
         }
         if (!have) {
                    ans[a[i].id]++;
                    sum++;
                    id[sum] = 3 - a[i].id;
                    ti[sum] = a[i].end + T;
                    have = 1; 
         }
     }
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> N;
    for (int ca = 1; ca <= N; ca++) {
        cin >> T;        
        cin >> na >> nb;
        for (int i = 1; i <= na; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            a[i].start = ((s1[0] - '0') * 10 + (s1[1] - '0')) * 60 + (s1[3] - '0') * 10 + s1[4] - '0';            
            a[i].end = ((s2[0] - '0') * 10 + (s2[1] - '0')) * 60 + (s2[3] - '0') * 10 + s2[4] - '0';
            a[i].id = 1;
        //    cout << a[i].start << " " << a[i].end << endl;
        }
        for (int i = na + 1; i <= na + nb; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            a[i].start = ((s1[0] - '0') * 10 + (s1[1] - '0')) * 60 + (s1[3] - '0') * 10 + s1[4] - '0';            
            a[i].end = ((s2[0] - '0') * 10 + (s2[1] - '0')) * 60 + (s2[3] - '0') * 10 + s2[4] - '0';
            a[i].id = 2;
          //  cout << a[i].start << " " << a[i].end << endl;
        }
        sort(a + 1, a + na + nb + 1, cmp);
        solve();
        cout << "Case #" << ca << ": ";
        cout << ans[1] << " " << ans[2] << endl;
    }
//    while (1);
    return 0;
}
