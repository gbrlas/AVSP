#include <bits/stdc++.h>
using namespace std;

#ifdef ILIKEGENTOO
#   define Eo(x) { cerr << #x << " = " << (x) << endl; }
#   define E(x) { cerr << #x << " = " << (x) << "   "; }
#   define FREOPEN(x)
#else
#   define Eo(x)
#   define E(x)
#   define FREOPEN(x) (void)freopen(x ".in", "r", stdin);(void)freopen(x ".out", "w", stdout);
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<class A, class B> ostream &operator<<(ostream &os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<class C> void operator<<(vector<C> &v, const C &x){v.push_back(x);}
template<class D> void operator>>(vector<D> &v, D &x){assert(!v.empty()); x=v.back(); v.pop_back();}
template<class E> void operator<<(set<E> &v, const E &x){v.insert(x);}
template<class F> void operator<<(queue<F> &c, const F& v){v.push(v);}
template<class G> void operator>>(queue<G> &c, const G& v){const G r=v.front();v.pop();return r;}

typedef double flt;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pip;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const flt eps = 1e-8;
const flt pi = acos(-1.0);
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

const int maxn = 1010;
int arr[maxn];
int ia[maxn], ja[maxn];

int main() {
    ios_base::sync_with_stdio(false);

    int TS; cin >> TS;
    for (int T = 1; T <= TS; ++T) {
        int n; cin >> n;
        int mid = -1;
        for (int i =0 ; i < n; ++i) {
            cin >> arr[i];
            if (i == 0 || arr[i] > arr[mid]) mid = i;
        }
        memcpy(ia, arr, sizeof(arr));
        memcpy(ja, arr, sizeof(arr));
        int bestres = inf;
#if 1
        sort(ia, ia + n);
        do {
            memcpy(arr, ja, sizeof(arr));
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                if (ia[i] == arr[mid]) {
                    for (int j = i; j > 0; --j)
                        if (ia[j] < ia[j - 1]) ok = false;
                    for (int j = i; j < n-1; ++j)
                        if (ia[j] < ia[j + 1]) ok = false;
                }
            }
            if (!ok) continue;

            int res = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                    if (ia[i] == arr[j]) {
                        for (int q = j; q > i; --q) {
                            ++res;
                            swap(arr[q], arr[q-1]);
                        }
                        break;
                    }
            }
            bestres = min(bestres, res);
        } while (next_permutation(ia, ia + n));
#else
        for (int k = 0; k < n; ++k) {
            int up = inf, pos = 0;
            int left, right;
            int res = 0;
            memcpy(arr, ia, sizeof(arr));

            if (k < mid) {
                res += mid - k;
                for (int q = 0; q < res; ++q)
                    swap(arr[mid-q], arr[mid-q-1]);
            } else if (k > mid) {
                res += k - mid;
                for (int q = 0; q < res; ++q)
                    swap(arr[mid+q], arr[mid+q+1]);
            }

            for (int _ = 0; _ < n; ++_) {
                pos = -1;
                for (int i = 0; i < n; ++i)
                    if (arr[i] < up && (pos == -1 || arr[i] > arr[pos]))
                        pos = i;

                //E(_); E(up); E(arr[pos]); Eo(pos);
                up = arr[pos];
                if (_ == 0) {
                    left = right = pos;
                } else {
                    while (pos < left - 1) {
                        swap(arr[pos], arr[pos + 1]);
                        ++pos;
                        ++res;
                    }
                    while (pos > right + 1) {
                        swap(arr[pos], arr[pos - 1]);
                        --pos;
                        ++res;
                    }
                    if (pos == left - 1) --left;
                    if (pos == right + 1) ++right;
                }
            }
            bestres = min(bestres, res);
        }
#endif
        cout << "Case #" << T << ": " << bestres << endl;
    }

    return 0;
}
