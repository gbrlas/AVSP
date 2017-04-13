#include <iostream>
#include <queue>

struct OPER
{
	char who;
	int pos;

	OPER (char _who, int _pos) : who(_who), pos(_pos) {};
};

typedef OPER ROB;

int T, N;
int dB, dBs, dO, dOs, dALL, Bz, Oz;
bool P;

int main()
{
	std::cin >> T;
	for (int Case = 1; Case <= T; ++Case) {
		std::cin >> N;
		dB = dO = dALL = 0;
		std::deque<OPER> test;
		ROB O('O', 1), B('B', 1);
		char r1; int r2;
		for (int i = 0; i < N; ++i) {
			std::cin >> r1 >> r2;
			test.push_back (OPER (r1, r2));
		}

		Oz = Bz = 0;
		while (!test.empty()) {
			OPER now = test.front();
			test.pop_front();
			if (now.who == O.who) {
				P = 0;
				dOs = abs (now.pos - O.pos);
				O.pos = now.pos; ++dOs;
				if (dOs <= dB) { dO += 1; dALL += 1; }
				else { dO += (dOs - dB); dALL += (dOs - dB); }				
			}
			else {
				P = 1;
				dBs = abs (now.pos - B.pos);
				B.pos = now.pos; ++dBs;
				if (dBs <= dO) { dB += 1; dALL += 1; }
				else { dB += (dBs - dO); dALL += (dBs - dO); }
			}
			if (!P) dB = 0; else dO = 0;
		}
		std::cout << "Case #" << Case << ": " << dALL << '\n';
	}
}