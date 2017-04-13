#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#define UPPER 1000000
#define ALL(x) x.begin(),x.end()
typedef long long num;

using namespace std;

template<typename T>
inline T read() {
    T res; cin >> res; cin.ignore();
    return res;
}

template<typename T>
inline void fill(vector<T> &v, int count) {
    while(count--) v.push_back(read<T>());
}

num freq[1001];
num key[1001];
num pad[1001];

num docase() {
	memset(freq,0,sizeof(freq));
	memset(pad,0,sizeof(pad));
	num P = read<num>();
	num K = read<num>();
	num L = read<num>();
	for (int i=0; i<L; i++) {
		freq[i] = read<num>();
	}
	sort(freq,freq+L);
	reverse(freq,freq+L);
	num k = 0;
	num res = 0;
	for (int i=0; i<L; i++) {
		key[i] = k;
		pad[k]++;
		res += pad[k]*freq[i];
		k = (k+1) % K;
	}
	return res;
}

void main() {
    int ncases = read<int>();
    for(int caseno = 1; caseno <= ncases; ++caseno) {
		cout << "Case #" << caseno << ": " << docase() << endl;
    }
}