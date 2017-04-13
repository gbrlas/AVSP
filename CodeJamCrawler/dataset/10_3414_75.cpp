#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

#define FOR(i, s, e) for(int i = (s); i < (e); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SQR(x) ((x)*(x))
#define CLR(x) memset(x, 0, sizeof(x))
typedef long long int64;

template<class T>
inline void PrintResult(int caseNum, T res){
	cout <<"Case #" << caseNum << ": " << res << endl;
}
bool win(int A, int B);

bool lose(int A, int B){
	if(A > B) swap(A, B);
	if(A == B) return true;
	if(B / A == 1){
		return win(B % A, A);
	}
	return false;
}

bool win(int A, int B){
	if(A > B) swap(A, B);
	if(A != B && B % A == 0) return true;
	if(A == B) return false;

	bool res = lose(B % A, A);

	if(B / A == 1){
		return res;
	}
	return res || win(B % A, A);
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int caseNum;
	cin >> caseNum;
	
	REP(cs, caseNum){
		int A1, A2, B1, B2;
		int res = 0;
		cin >> A1 >> A2 >> B1 >> B2;
		FOR(A, A1, A2 + 1) FOR(B, B1, B2 + 1){
			res += win(A, B) ? 1 : 0;
		}
		PrintResult(cs + 1, res);
		cerr << cs + 1 << endl;
	}
	return 0;
}