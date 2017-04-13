#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int N,P,K,L;
int h;

using namespace std;
int main()
{
	cin >> N;
	for (int n=1;n<=N;++n) {

		cin >> P >> K >> L;

		vector<long long> l(L);
		for (int i=0; i<L; ++i) {
			cin >> l[i];
		}
		sort(l.begin(),l.end());
		reverse(l.begin(),l.end());


			int kp=0;
			int li=0;

			for (int p=1;p<=P;++p) {
				for (int k=1;k<=K;++k) {
				if (li < L) {
					kp+=l.at(li)*p;
					li++;
				}
				}
			}

			cout << "Case #" << n << ": " << kp << endl;

	}
}
