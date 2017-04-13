#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#define CH(x) ((x)-'0')

using namespace std;

char * filename;

int conv(string str) {
	return (CH(str[0]) * 10 + CH(str[1])) * 60 + (CH(str[3]) * 10 + CH(str[4]));
}

vector<int> Arr, Arr2, Dep, Dep2;

void solve(int num) {
	int fir, sec, sz1, sz2, res;
	sort(Arr2.begin(), Arr2.end());
	sort(Dep.begin(), Dep.end());
	fir = sec = 0;
	sz1 = Arr2.size();
	sz2 = Dep.size();
	res = 0;
	while (1) {
		if (fir >= sz1 || sec >= sz2) break;
		if (Arr2[fir] <= Dep[sec]) {
			fir++;
			sec++;
			res++;
		} else {
			sec++;
		}
	}
	cout << "Case #" << num+1 << ": " << sz2 - res;

	sort(Arr.begin(), Arr.end());
	sort(Dep2.begin(), Dep2.end());
	fir = sec = 0;
	sz1 = Arr.size();
	sz2 = Dep2.size();
	res = 0;
	while (1) {
		if (fir >= sz1 || sec >= sz2) break;
		if (Arr[fir] <= Dep2[sec]) {
			fir++;
			sec++;
			res++;
		} else {
			sec++;
		}
	}
	cout << " " << sz2 - res << endl;
}

void readAndSolve() {
	int i, j, N, T, NA, NB;
	string dep, arr;
	ifstream inpf(filename, ios::in);
	inpf >> N;
	for (i=0 ; i<N ; i++) {
		inpf >> T;
		inpf >> NA >> NB;
		Dep.clear();
		Arr.clear();
		for (j=0 ; j<NA ; j++) {
			inpf >> dep >> arr;
			Dep.push_back(conv(dep));
			Arr.push_back(conv(arr) + T);
		}
		Dep2.clear();
		Arr2.clear();
		for (j=0 ; j<NB ; j++) {
			inpf >> dep >> arr;
			Dep2.push_back(conv(dep));
			Arr2.push_back(conv(arr) + T);
		}
		solve(i);
	}
	inpf.close();
}

int main(int argc, char *argv[]) {
	filename = argv[1];
	readAndSolve();
	return 0;
}

