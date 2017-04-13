#include <iostream>
#include <vector>

struct Com
{
	char F, L;
	char Rep;
	int w;
	int pos1, pos2;

	Com() : F('1'), L('1'), Rep('1'), pos1(-1), pos2(-1) {};
	Com (char _F, char _L, char _Rep = 0) : F(_F), L(_L), Rep(_Rep), pos1(-1), pos2(-1) {};
	char operator[] (int x) { return (x == 0 ? F : L); }
};
typedef Com Opo;
int T, D, N, C;
bool H;

int main()
{
	std::cin >> T;
	for (int Case = 1; Case <= T; ++Case) {
		char a, b, c;
		Opo R; Com Q;
		std::cin >> C;
		if (C != 0) {
			std::cin >> a >> b >> c;
			Q = Com (a, b, c);
		}
		std::cin >> D;
		if (D != 0) {
			std::cin >> a >> b;
			R = Opo (a, b);
		}
		std::cin >> N;
		std::vector<char> l(N);
		std::vector<char> res;
		for (int i = 0; i < N; ++i) 
			std::cin >> l[i];
		for (int i = 0; i < N; ++i) {
			if (l[i] == R.F) { 
				if (R.w == 1) {
					res.clear();
					R.w = R.pos1 = R.pos2 = -1;
					continue;
				}
				else R.w = 0;
				if (R.pos1 == -1) R.pos1 = i;
			}
			else if (l[i] == R.L) { 
				if (R.w == 0) {
					res.clear();
					R.w = R.pos1 = R.pos2 = -1;
					continue;
				}
				else R.w = 1;
				if (R.pos2 == -1) R.pos2 = i;
			}	
			if ((i + 1 < N) && (l[i] == Q.F && l[i+1] == Q.L) || 
				(l[i] == Q.L && l[i+1] == Q.F)) {
				res.push_back (Q.Rep);
				if (R.pos1 == i || R.pos1 == i + 1) {
					if (R.w == 0) R.w = -1;
					R.pos1 = -1; }
				else if (R.pos2 == i || R.pos2 == i + 1) {
					if (R.w == 1) R.w = -1;
					R.pos2 = -1; }
				++i;
			} else res.push_back (l[i]);
		}

		std::cout << "Case #" << Case << ": [";
		if (res.size() != 0) std::cout << res[0];
		for (int i = 1; i < res.size(); ++i)
			std::cout << ", " << res[i];
		std::cout << "]\n";
	}
}