// =====================================================
//   Online Qualifier 2, B : void.parallax
// =====================================================
// Parallax : a member of team Void at the ACM ICPC contest

// --- With thanks to 'rem'
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef short s16;
typedef char s8;
typedef unsigned char u8;
typedef long long ll;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<ll> vl;

#define _CRT_SECURE_NO_WARNINGS
#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

// --===========================================================--
bool IsArea(ll area, int x1, int y1, int x2, int y2)
{
    //Actually compute area / 2
    ll desiredAreaSq = area * 2;
    desiredAreaSq *= desiredAreaSq;

    // all squared side lengths
    ll a = x1*x1 + y1*y1;
    ll b = x2*x2 + y2*y2;
    ll c = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

    ll diff = (a + b - c);
    ll result = 4*a*b - diff * diff ;

    return desiredAreaSq == result; 
}

// --===========================================================--

int main()
{
    //NOTE: To see correct output, redirect stdout to a file and 
    // ignore stderr


    assert(IsArea(1, 0, 1, 1, 1));
    
    u32 numProblems = 0;

    cin >> numProblems;
    For(probNum, 1, numProblems)
    {
        int N, M;
        ll A;

        cin >> N >> M >> A;
        For (x1Scan, 0, N)
        {
            For (y1Scan, 0, M)
            {
                For (x2Scan, x1Scan, N)
                {
                    For (y2Scan, 0, M)
                    {
                        if (IsArea(A, x1Scan, y1Scan, x2Scan, y2Scan) )
                        {
                            cout << "Case #" << probNum <<": 0 0 " << x1Scan <<" " << y1Scan << " " << x2Scan <<" " << y2Scan <<" " <<endl;
                            cerr << "Case #" << probNum <<": 0 0 " << x1Scan <<" " << y1Scan << " " << x2Scan <<" " << y2Scan <<" " <<endl;
                            goto done;
                        }
                    }
                }
            }
        }

        cout << "Case #" << probNum <<": IMPOSSIBLE" << endl;
        cerr << "Case #" << probNum <<": IMPOSSIBLE" << endl;
done:
        u32 nothing = 0;
    }
}