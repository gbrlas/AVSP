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

int main()
{
    //NOTE: To see correct output, redirect stdout to a file and 
    // ignore stderr
    u32 numProblems = 0;

    cin >> numProblems;
    For(probNum, 1, numProblems)
    {
        u32 seqLen, genArrayLen;
        cin >> seqLen >> genArrayLen;
        
        vector <long long> genArray;
        vector <long long> sequence;

        genArray.reserve(genArrayLen);
        sequence.reserve(seqLen);
        long long X, Y, Z;
        cin >> X >> Y >> Z;

        For(i, 0, genArrayLen - 1)
        {
            long long seed;
            cin >> seed;
            genArray.push_back(seed);
        }

        cerr << "Seq ";

        For(i, 0, seqLen - 1)
        {
            long long value = genArray[i % genArrayLen];
            sequence.push_back(value);

            genArray[i % genArrayLen] = (X * genArray[i%genArrayLen] + Y * (i + 1)) % Z;
            cerr << value << " " ;
        }
        cerr << endl;

        long long result = 0;

//        std::vector<double> subsequences_f;
        std::vector<long long> subsequences;

//        subsequences_f.resize(seqLen);
        subsequences.resize(seqLen);

        cerr << "Result ";
        For(i, 0, seqLen - 1)
        {
            long long accum = 1; // We are the first subsequence
            
            For(j, 0, i - 1)
            {
                if (sequence[i] > sequence[j])
                {
                    accum += subsequences[j];
                    accum %= 1000000007;
                }
            }
            subsequences[i] = accum;
            result += accum;
            result %= 1000000007;
            cerr << result << " " ;
        }
        cerr << endl;

        result %= 1000000007;
        
        cout << "Case #" << probNum <<": " << result << endl;
        cerr << "Case #" << probNum <<": " << result << endl;
    }
}
