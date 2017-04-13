#include <iostream>
#include <vector>

int T, N, min, all, r;

struct Num
{
	int num;
	std::vector<int> bin;

	Num() : num(0) {};
	Num (int x) : num(x)
	{
		while (!(x == 0)) {
			if (x % 2 == 1)	bin.push_back (1);
			else bin.push_back (0);
			x /= 2;
		}
	}

	Num operator+ (Num x)
	{
		Num res;
		int n = std::max (x.bin.size(), bin.size());
		x.bin.resize (n, 0); bin.resize (n, 0);
		res.bin.resize (n, 0);
		for (int i = 0; i < n; ++i) {
			if (x.bin[i] == bin[i])	res.bin[i] = 0;
			else res.bin[i] = 1;
		}
		int two = 1;
		for (int i = 0; i < n; ++i) {
			res.num += res.bin[i] * two;
			two *= 2;
		}

		return res;
	}
};

int main()
{
	std::cin >> T;
	for (int Case = 1; Case <= T; ++Case) {
		min = 99999999; all = 0;
		std::cin >> N;
		std::vector<Num> C;
		C.resize (N);
		for (int i = 0; i < N; ++i) {
			std::cin >> r;
			C[i] = Num(r);
			all += r;
			if (r < min) min = r;
		}
		Num D = C[0];
		for (int i = 1; i < N; ++i)
			D = D + C[i];

		if (D.num != 0) {
			std::cout << "Case #" << Case << ": NO\n";
			continue;
		}
		
		std::cout << "Case #" << Case << ": " << all - min << '\n';
	}
}