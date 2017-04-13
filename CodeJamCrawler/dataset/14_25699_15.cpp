#include <iostream>
using namespace std;

int main() {
	int T, M, N, K, a, b, n, m, F, e1, e2, e3,e;
	cin >> T;

	for (int I; I<T;I++){
		cin >> N >> M >> K;
		n = min(N,M);
		m = max(N,M);
		if (n==1 or K <= 2){
			e1 = K;
			e2 = K;
			e3 = K;
		}else if (K >= n*m -4){
			e1 = 2*n + 2*(m-2) - (n*m - K);
			e2 = e1;
			e3 = e1;
		}else{
			e1 = 2;
			a = 3;
			F = 2;
			while (F < K and a < n){
				F += a;
				e1 += 2;
				if (F >= K)
					break;
				F += a;
				e1 += 2;
				a += 2;
			}
			while (F < K and a <= m){
				F += n;
				e1 += 2;
				++a;
			}
			if (F<K){
				e1 += K-F;
			}


			e2 = 0;
			a = 2;
			F = 0;
			while (F < K and a < n){
				F += a;
				e2 += 2;
				if (F >= K)
					break;
				F += a;
				e2 += 2;
				a += 2;
			}
			while (F < K and a <= m){
				F += n;
				e2 += 2;
				++a;
			}
			if (F<K){
				e2 += K-F;
			}

			e3 = 1;
			a = 2;
			F = 1;
			while (F < K and a < n){
				F += a;
				e3 += 2;
				++a;
			}
			while (F < K and a <= m){
				F += n;
				e3 += 2;
				++a;
			}
			if (F<K){
				e3 += K-F;
			}
		}
		cout << "Case #" << I+1 << ": " << min(min(e1,e2),e3) << endl;
	}


	return 0;
}
