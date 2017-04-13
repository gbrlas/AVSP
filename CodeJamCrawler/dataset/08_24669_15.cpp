#include <string>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <complex>
#include <numeric>
#include <ext/hash_map>
#include <ext/hash_set>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<double> vd;

template<class T> inline int Size(const T& c) { return (int)c.size(); }
ll s2i(string s) { istringstream i(s); ll x; i>>x; return x; }
template<class T> string i2s(T x) { ostringstream o; o << x; return o.str(); }
template<class T, class S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}
template<class T> inline T sqr(T a) { return a*a; }

#define For(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ForD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define Rep(i,n) For(i,0,(n)-1)
#define ForA(i,c) Rep(i,size(c))
#define itype(c) __typeof((c).begin())
#define ForI(e,c) for(itype(c) e=(c).begin();e!=(c).end();e++)
#define pb push_back
#define Fill(a,c) memset(&a, c, sizeof(a))
#define Mp(x, y) make_pair((x), (y))
#define All(x) (x).begin(),(x).end()
#define Sort(x) sort(All(x))
#define Reverse(x) reverse(All(x))

#define PI acos(-1.)
#define EPS 1e-9
#define INF 1000000000

ll nCr(ll n, ll r) {
        unsigned long long result = 1L;

        cout << "n " << n << " r " << r << endl;

        ll limit = min(r, n-r);
        cout << "limit nCr = " << limit << endl;
        unsigned long long count = 1L;
        while(count <= limit) {
                result *= n;
                result /= count;
                if (result > (unsigned long long)LONG_LONG_MAX) {
                        return -1L;
                }
                count++;
                n--;
        }
        return ll(result);
}



bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(int argc, char **argv) {
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	int numberOfTestcases = 0;

	fin >> numberOfTestcases;

	int i = 0;

	for (i = 0; i < numberOfTestcases; i++) {
		int P, K, L;
		fin >> P >> K >> L;

		list<long long> freq;

		long long cur;
		for (int j = 0; j < L; j++) {
			fin >> cur;
			freq.pb(cur);
		}

		freq.sort();
		freq.reverse();

		int count = 0, mult;
		long long result = 0L;
		ForI(iter1, freq) {
			cout << *iter1;
			mult = (count / K) + 1;
			count++;
			cout << mult << endl;;

			result += mult * (*iter1);
		}

		fout << "Case #" << i+1 << ": "<< result << endl;
	}

	fout.close();
	fin.close();

	return 0;
}
