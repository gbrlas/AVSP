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
typedef long double ld;
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
template <class T> T ABS(const T &x) {return x>0? x:-x;}

#define For(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ForD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define Rep(i,n) For(i,0,(n)-1)
#define Rep1(i,n) For(i,1,(n)-1)
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


bool isEqual(ld v1, ld v2) {return ABS(v1-v2)<EPS;}
bool isLess(ld v1, ld v2) {return v1-v2<-EPS;}
ll gcd(ll n1, ll n2) {return n2==0? ABS(n1) : gcd(n2,n1%n2);}
ll lcm(ll n1, ll n2) {return n1==0 && n2==0? 0 : ABS(n1*n2)/gcd(n1,n2);}

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


void insertionSort(int arrayToBeSorted[], const int &lowerLimit, const int &upperLimit) {
        int index = 0;
        int currentValue = 0;
        for (int pass = lowerLimit+1; pass <= upperLimit; pass++) {
                index = pass;
                currentValue = arrayToBeSorted[pass];
                while ((currentValue < arrayToBeSorted[index-1]) && (index > lowerLimit)) {
                        arrayToBeSorted[index] = arrayToBeSorted[index-1];
                        index--;
                }
                arrayToBeSorted[index] = currentValue;
        }
}


int main(int argc, char **argv) {
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	int numberOfTestcases = 0;

	fin >> numberOfTestcases;

	int i = 0;

	int N, M;
	long long A;

	long abx, aby, acx, acy, cross;

	bool end = false;
	for (i = 0; i < numberOfTestcases; i++) {
		fin >> N >> M >> A;
		end = false;

		for (int i1 = 0; ((i1 <=N) && !end); i1++) {
		for (int j1 = 0; ((j1 <=M) && !end); j1++) {
		for (int i2 = 0; ((i2 <=N) && !end); i2++) {
		for (int j2 = 0; ((j2 <=M) && !end); j2++) {
			if (abs(i1*j2 - i2*j1) == A) {
					if (((i1 == 0) && (j1 == 0)) || ((i2==0) && (j2==0)) || ((i1 == i2) && (j1 == j2))) continue;
					fout << "Case #" << i+1 << ": " << "0 0 " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
					end = true;
			}
		}}}}
			if (!end) {
						fout << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
			}
	}

	fout.close();
	fin.close();

	return 0;
}
