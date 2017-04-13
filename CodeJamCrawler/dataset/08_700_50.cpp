#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class train {
    public:
	int depart;
	int arrive;

	train(int d, int a) : depart(d), arrive(a) {}
	bool operator<(const train& t) const {
	    if (depart < t.depart) return true;
	    else if (depart == t.depart) return arrive < t.arrive;
	    else return false;
	}
};

class event {
    public:
	int time;
	bool isAdd;

	event(int t, bool i) : time(t), isAdd(i) {}
	bool operator<(const event& t) const {
	    if (time < t.time) return true;
	    else if (time == t.time) return (isAdd == true);
	    else return false;
	}
};

int main() {
    int testN;
    scanf("%d", &testN);

    for (int t = 1; t <= testN; ++t) {
	int T, NA, NB;
	scanf("%d%d%d", &T, &NA, &NB);

	//vector<train> fromA, fromB;
	//fromA.reserve(NA);
	//fromB.reserve(NB);

	vector<event> A, B;
	A.reserve(NA + NB);
	B.reserve(NA + NB);

	// read data.
	int hh1, mm1, hh2, mm2;
	for (int i = 0; i < NA; ++i) { // from A to B.
	    scanf("%d:%d", &hh1, &mm1);
	    scanf("%d:%d", &hh2, &mm2);
	    //printf("%d:%d %d:%d\n", hh1, mm1, hh2, mm2);

	    //fromA.push_back(train(hh1 * 60 + mm1, hh2 * 60 + mm2));
	    A.push_back(event(hh1*60 + mm1, false));
	    B.push_back(event(hh2*60 + mm2 + T, true));
	}

	for (int i = 0; i < NB; ++i) {
	    scanf("%d:%d", &hh1, &mm1);
	    scanf("%d:%d", &hh2, &mm2);
	    //printf("%d:%d %d:%d\n", hh1, mm1, hh2, mm2);

	    //fromB.push_back(train(hh1 * 60 + mm1, hh2 * 60 + mm2));
	    B.push_back(event(hh1*60 + mm1, false));
	    A.push_back(event(hh2*60 + mm2 + T, true));
	}

	//sort(fromA.begin(), fromA.end());
	//sort(fromB.begin(), fromB.end());

#if 0
	// after sort.
	printf("\n");
	for (int i = 0; i < NA; ++i)
	    printf("%d:%d %d:%d\n", fromA[i].depart / 60, fromA[i].depart % 60, fromA[i].arrive / 60, fromA[i].arrive % 60);
	for (int i = 0; i < NB; ++i)
	    printf("%d:%d %d:%d\n", fromB[i].depart / 60, fromB[i].depart % 60, fromB[i].arrive / 60, fromB[i].arrive % 60);
#endif

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int Aneed = 0, Aremain = 0;
	for (int i = 0; i < NA + NB; ++i) {
	    if (A[i].isAdd == true) {
		Aremain++;
	    } else {
		if (Aremain > 0) Aremain--;
		else Aneed++;
	    }
	}

	int Bneed = 0, Bremain = 0;
	for (int i = 0; i < NA + NB; ++i) {
	    if (B[i].isAdd == true) {
		Bremain++;
	    } else {
		if (Bremain > 0) Bremain--;
		else Bneed++;
	    }
	}

	//Case #1: 2 2
	printf("Case #%d: %d %d\n", t, Aneed, Bneed);
    }

    return 0;
}

