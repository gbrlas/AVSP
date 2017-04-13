#include<iostream>
#include<string>
#include<vector>
using namespace std;

int Awin(int A, int B, int Aturn)
{
	if (A == B) {
		if (Aturn)
			return 0;
		else
			return 1;
	}
	if (A < B) swap(A,B);
	int r = A%B;
	if (r == 0) {
		if (Aturn)
			return 1;
		else
			return 0;
	} else {
		if (r+B == A) {
			return Awin(r, B, 1-Aturn);
		}
		int w1 = Awin(r+B, B, 1-Aturn);
		int w2 = Awin(r, B, 1-Aturn);
		if (Aturn) {
			if (w1 || w2)
				return 1;
			else
				return 0;
		} else {
			if (w1 && w2)
				return 1;
			else
				return 0;
		}
	}
}
int getit()
{
	int A1, A2, B1, B2;
	cin>>A1>>A2>>B1>>B2;

	int cnt = 0;
	for (int A=A1; A<=A2; A++)
	for (int B=B1; B<=B2; B++) {
		if (Awin(A, B, 1))
			cnt++;
	}
	return cnt;
}
int main(void)
{
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		int N;
		cout<<"Case #"<<i<<": "<<getit()<<endl;
	}
}
