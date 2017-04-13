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


int main(){
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int caseNum;
	cin >> caseNum;
	
	REP(cs, caseNum){
		int N, K;
		cin >> N >> K;
		char board[64][64];
		REP(i, N){
			cin >> board[i];
		}
		char after[64][64];
		REP(r, N) REP(c, N) after[r][c] = '.';
		int idx[64];
		REP(r, N) idx[r] = N - 1;
		for(int c = N - 1; c >= 0; c--){
			REP(r, N){
				if(board[r][c] != '.') after[r][idx[r]--] = board[r][c]; 
			}
		}
		bool flagR = false, flagB = false;
		REP(r, N){
			int mR = 0, mB = 0;
			int cntR = 0;
			int cntB = 0;
			REP(c, N){
				if(after[r][c] == 'R'){
					cntR++, cntB = 0;
				}else if(after[r][c] == 'B'){
					cntB++, cntR = 0;
				}else cntB = 0, cntR = 0;
				mR = mR > cntR ? mR : cntR;
				mB = mB > cntB ? mB : cntB;
			}
			if(mR >= K) flagR = true;
			if(mB >= K) flagB = true;
		}
		REP(c, N){
			int mR = 0, mB = 0;
			int cntR = 0;
			int cntB = 0;
			REP(r, N){
				if(after[r][c] == 'R'){
					cntR++, cntB = 0;
				}else if(after[r][c] == 'B'){
					cntB++, cntR = 0;
				}else cntB = 0, cntR = 0;
				mR = mR > cntR ? mR : cntR;
				mB = mB > cntB ? mB : cntB;
			}
			if(mR >= K) flagR = true;
			if(mB >= K) flagB = true;
		}
		for(int delta = 3 - N; delta <= N - 3; delta++){
			int mR = 0, mB = 0;
			int cntR = 0;
			int cntB = 0;
			REP(i, N) if(i - delta >= 0 && i - delta < N){
				int j = i - delta;
				if(after[i][j] == 'R'){
					cntR++, cntB = 0;
				}else if(after[i][j] == 'B'){
					cntB++, cntR = 0;
				}else cntB = 0, cntR = 0;
				mR = mR > cntR ? mR : cntR;
				mB = mB > cntB ? mB : cntB;
			}
			if(mR >= K) flagR = true;
			if(mB >= K) flagB = true;
		}

		for(int sum = 0; sum <= 2*N - 2; ++sum){
			int mR = 0, mB = 0;
			int cntR = 0;
			int cntB = 0;
			REP(i, N) if(sum - i >= 0 && sum - i < N){
				int j = sum - i;
				if(after[i][j] == 'R'){
					cntR++, cntB = 0;
				}else if(after[i][j] == 'B'){
					cntB++, cntR = 0;
				}else cntB = 0, cntR = 0;
				mR = mR > cntR ? mR : cntR;
				mB = mB > cntB ? mB : cntB;
			}
			if(mR >= K) flagR = true;
			if(mB >= K) flagB = true;
		}
		string res;
		if(!flagR && !flagB) res = "Neither";
		else if(flagR && !flagB) res = "Red";
		else if(!flagR && flagB) res = "Blue";
		else res = "Both";
		PrintResult(cs + 1, res);
	}
	return 0;
}