#include <cstdio>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#define Eo(x) { std::cerr << #x << " = " << x << std::endl; }
#define shift (1 << 10)
#define maxn (20 * 20 * (shift + shift))

typedef long long int64;
typedef double real;

using namespace std;

string last[maxn];

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
char im[1 << 10][1 << 10];

int w;
inline bool onbrd(int x, int y){
	return x >= 0 && x < w && y >= 0 && y < w;
}


int q[maxn];
int fi;
int main(){
	int ferlon;
	scanf("%d", &ferlon);
	for (int _ = 0; _ < ferlon; ++_){
		Eo(_);
		printf("Case #%d:\n", _ + 1);
		int Q;
		scanf("%d%d", &w, &Q);
		for (int i = 0; i < w; i++){
			scanf("%s", im[i]);
		}
		fi = 0;
		for (int i = 0; i < maxn; i++) last[i] = "";
		for (int i = 0; i < w; i++)
			for (int j = 0; j < w; j++) if (isdigit(im[i][j])){
				int st = ((im[i][j] - '0' + shift) * 20 + i) * 20 + j;
				assert(st < maxn);
				last[st] = im[i][j];
				q[fi++] = st;
			}
		for (int st = 0; st < fi; st++){
			int currstate = q[st];
			int num = q[st];
			int j = num % 20;
			num /= 20;
			int i = num % 20;
			num /= 20;
			for (int d = 0; d < 4; d++)
				for (int d1 = 0; d1 < 4; d1++){
					int ni = i + di[d];
					int nj = j + dj[d];
					if (!(onbrd(ni, nj))) continue;
					char oper = im[ni][nj];
					ni += di[d1];
					nj += dj[d1];
					if (!(onbrd(ni, nj))) continue;

					int nextstate = (oper == '+' ? im[ni][nj] - '0' : - (im[ni][nj] - '0')); 
					nextstate += num;
					if (nextstate <= 0 || nextstate >= shift + shift) continue;

					nextstate = (nextstate * 20 + ni) * 20 + nj;
					string gy = last[currstate];
					assert(oper == '+' || oper == '-');
					assert(isdigit(im[ni][nj]));
					gy += oper;
					gy += im[ni][nj];
					if (last[nextstate] == ""){
						last[nextstate] = gy;
						q[fi++] = nextstate;
					}else if (gy.size() < last[nextstate].size() || (gy.size() == last[nextstate].size() && gy < last[nextstate])){
						last[nextstate] = gy;
					}
				}
		}
		for (int oO = 0; oO < Q; oO++){
			int n;
			scanf("%d", &n);
			n += shift;
			string ans;
			string can;
			for (int i = 0; i < w; i++)
				for (int j = 0; j < w; j++) if (isdigit(im[i][j]) && (can = last[(n * 20 + i) * 20 + j]) != ""){
					if (ans == "" || can.size() < ans.size())
						ans = can;
					else if (can.size() == ans.size() && can < ans)
						ans = can;
				}
			printf("%s\n", ans.c_str());
		}
	}
	return 0;
}
