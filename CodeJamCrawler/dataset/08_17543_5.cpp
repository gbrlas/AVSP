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
typedef pair<int,int> pii;

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

bool comp (int i,int j) { 
    return (i<j); 
}


int main() {
    int t;
    int i, j, k;
    int temp;
    int n = 0;
    long soma = 0;
    
    int result[100];
    
    vector<int>::iterator it;
    vector<int>::iterator it2;
    
    vector <int> v1;
    vector <int> v2;
    
	freopen("input.in", "rt", stdin);
	freopen("output.out", "wt", stdout);
	
	cin >> t;
	for(i=0;i<t;i++){
        v1.clear();
        v2.clear();
        soma = 0;
        
        cin >> n;
        for(k=0; k<n; k++){
            cin >> temp;
            v1.push_back(temp);
        }
        for(k=0; k < n; k++){
            cin >> temp;
            v2.push_back(temp);
        }
    
	   sort(v1.begin(),v1.end(),comp);
	   sort(v2.begin(),v2.end(),comp);
	
	   reverse(v2.begin(),v2.end());
	
	   for(it=v1.begin(), it2=v2.begin(), k=0; it != v1.end() ; it++, it2++, k++){
            
            soma = soma + ((*it) * (*it2));
        }
        cout << "Case #" << i + 1 << ":" << " " << soma << endl;
	}
	

}
	

