// =====================================================
//   Online Qualifier 1, A : void.parallax
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

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef short s16;
typedef char s8;
typedef unsigned char u8;

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
std::vector<int> vec1;
std::vector<int> vec2;

// --===========================================================--

int main()
{
    //NOTE: To see correct output, redirect stdout to a file and 
    // ignore stderr

    u32 numProblems = 0;

    cin >> numProblems;
    For(probNum, 1, numProblems)
    {
        vec1.clear();
        vec2.clear();
        u32 VectorLen;
        cin >> VectorLen;
        For (pos, 0, VectorLen-1)
        {
            int input;
            cin >> input;

            vec1.push_back(input);
        }

        For (pos2, 0, VectorLen-1)
        {
            int input;
            cin >> input;

            vec2.push_back(input);
        }

        std::sort(vec1.begin(), vec1.end());
        std::sort(vec2.begin(), vec2.end());

        long long accum = 0;
        For (sumPos, 0, VectorLen-1)
        {
            accum += vec1[sumPos] * vec2[VectorLen - sumPos - 1];
        }

        cout << "Case #" << probNum <<": " << accum << endl;
        cerr << "Case #" << probNum <<": " << accum << endl;
    }
}