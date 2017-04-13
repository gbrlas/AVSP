#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

#ifdef ILIKEGENTOO
#define Eo(x) { cerr << #x << " = " << (x) << endl; }
#define E(x) { cerr << #x << " = " << (x) << "   "; }
#else
#define Eo(x)
#define E(x)
#endif
#if defined ILIKEGENTOO || !(defined __GNUC__ ) || (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 6))
template<typename T, size_t N> struct array { T val[N]; T& operator[](size_t n) { if(n >= N) assert(false); return val[n]; } T* begin() { return &val[0]; } T* end() { return &val[0]+N; } };
#else
#include <array>
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

typedef double real;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pip;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const real eps = 1e-8;


string from = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvqz";
string to   = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupzq";


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	map<char, char> conv;
	for(int i = 0; i < Sz(from); i++) conv[from[i]] = to[i];
	conv[' '] = ' ';

	for(char i = 'a' ; i <= 'z'; i++) cerr << i << ": " << conv[i] << endl;

	string tmp;
	getline(cin, tmp);
	for(int i = 1; ; i++) {
		tmp = "";
		getline(cin, tmp);
		if(!Sz(tmp)) break;
		cout << "Case #" << i << ": ";
		for(int i = 0; i < Sz(tmp); i++) {
			char c = tmp[i];
			cout << conv[c];
		}
		cout << endl;
	}


	return 0;
}

