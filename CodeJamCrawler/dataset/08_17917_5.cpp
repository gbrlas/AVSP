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
template<typename T> inline bool isSet(T number, int bit) { return (number&(T(1)<<bit)) != 0; }

//////////end common header 
int n;
char buffer[1024*1024];
int T;
long int x[800];
long int y[800];

//////////



int main (int argc, char * const argv[]) {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wr", stdout);

	scanf("%d",&T);
	scanf(" ");
	Rep(i,T)
	{
		scanf("%d",&n);
		scanf(" ");
	
		Rep(j,n)
		{
			scanf("%d",&x[j]);
		}
		scanf(" ");
		Rep(j,n)
		{
			scanf("%d",&y[j]);
		}
		scanf(" ");
		

		std::sort(x,x+n);
		std::sort(y,y+n);
		
		/*Rep(j,n)
			printf("%d ",x[j]);
			cout << endl;
		Rep(j,n)
			printf("%d ",y[j]);
			cout << endl;*/
		//long int test = 100000*100000;
		//cout << endl << test << endl;
		long int total = 0;
		Rep(j,n)
		{
			total += (x[j]*y[n-j-1]);
		}
		printf("Case #%d: %d\n",i+1,total);
	}
	
    return 0;
}
