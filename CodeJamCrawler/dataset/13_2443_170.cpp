/*
 * GCC version:			4.6
 * Command line:		g++ -std=c++0x -m64 -02 -fno-strict-aliasing -Wl,--stack=268435456 Solution.cpp
 */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for(int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define CL(a, b)		memset(a, b, sizeof a)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define parallelize if (hocus pokus = true)

void norm(vi &a)
{
    int d = 0;
    for (int &x : a)
    {
        d += x;
        x = d % 10;
        d /= 10;
    }
    for (; d; d /= 10)
    {
        a.push_back(d % 10);
    }
    for (; a.size() && a.back() == 0; a.pop_back());
}

vi& operator += (vi &a, const vi &b)
{
    a.resize(max(sz(a), sz(b)));
    REP (i, sz(b)) a[i] += b[i];
    norm(a);
    return a;
}

vi operator + (vi a, const vi &b)
{
    return (a += b);
}

vi operator * (const vi &a, const vi &b)
{
    vi c(sz(a) + sz(b));
    REP (i, sz(a)) REP (j, sz(b)) c[i + j] += a[i] * b[j];
    norm(c);
    return c;
}

bool operator < (const vi &a, const vi &b)
{
    if (sz(a) != sz(b)) return sz(a) < sz(b);
    for (int i = sz(a); i --> 0; )
        if (a[i] != b[i]) 
            return a[i] < b[i];
    return false;
}

istream& operator >> (istream &in, vi &a)
{
    string s;
    in >> s;
    reverse(all(s));
    a.resize(sz(s));
    REP (i, sz(s)) a[i] = s[i] - '0';
    norm(a);
    return in;
}

ostream& operator << (ostream& out, const vi &a)
{
    if (sz(a) == 0) return out << 0;
    for (int i = sz(a); i --> 0; out << a[i]);
    return out;
}

template <class hocus = bool> struct Solver {
	
    bool palinc(vi &a, int i)
    {
        if (a[i] == 9) return false;
        ++a[i];
        if (2 * i != sz(a) - 1) ++a[sz(a) - 1 - i];
        return true;
    }
    
    bool paldec(vi &a, int i)
    {
        if (a[i] == 0) return false;
        --a[i];
        if (2 * i != sz(a) - 1) --a[sz(a) - 1 - i];
        return true;
    }
    
    vi F[2][2][10][30];
    bool u[2][2][10][30];
    
    const vi& f(int *a, int *b, int n, int i, bool greater, bool less, int s2)
    {
        if (i == (n + 1) / 2) {
            static vi one(1, 1);
            return one;
        }
        if (u[less][greater][s2][i]) return F[less][greater][s2][i];
        u[less][greater][s2][i] = true;
        vi &res = F[less][greater][s2][i];
        res.clear();
        REP (d, 4)
        {
            if (i + d == 0) continue;
            int ns2 = s2 + d * d;
            if (i < n - 1 - i) ns2 += d * d;
            if (ns2 > 9) break;
            if ((greater || d >= a[i]) && (less || d <= b[i]))
            {
                res += f(a, b, n, i + 1, greater || d > a[i], less || d < b[i], ns2);
            }
        }
        return res;
    }
    
	void run() {
		vi a, b, res;
        cin >> a >> b;
        parallelize
        {
            for (int n = 1; ; ++n)
            {
                vi low(n), high(n, 9);
                low.front() = low.back() = 1;
                if (low * low < a)
                {
                    fill(all(low), 9);
                    for (int i = n - 1; i >= n - 1 - i; --i)
                    {
                        for (; paldec(low, i); )
                        {
                            if (low * low < a)
                            {
                                palinc(low, i);
                                break;
                            }
                        }
                    }
                }
                bool last = false;
                if (b < high * high)
                {
                    last = true;
                    high = vi(n);
                    for (int i = n - 1; i >= n - 1 - i; --i)
                    {
                        high[i] = high[n - 1 - i] = 9;
                        if (b < high * high)
                            for (; paldec(high, i); )
                            {
                                if (!(b < high * high))
                                {
                                    break;
                                }
                            }
                    }
                }
                CL(u, 0);
                res += f(&low[0], &high[0], n, 0, false, false, 0);
                if (last) break;
            }
        }
        cout << res << endl;
	}
};

int main() {
	freopen("C-large-2.in", "r", stdin);
	freopen("C-large-2.out", "w", stdout);
	cout.precision(12);	
	cout.setf(ios::fixed);
	int i = 0, n;
	for (cin >> n; i < n; ) {
		printf("Case #%d: ", ++i);
		Solver<> *s = new Solver<>;
		s->run();
		delete s;
	}
	return 0;
}
