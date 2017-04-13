#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

char * filename;
int S, Q;
vector<string> engines;
vector<string> queries;

#define VOV 1000000

int findq(int x) {
	for (int i=0 ; i<S ; i++)
		if (queries[x] == engines[i]) return i;
}

void solve(int num) {
	int i, j, k, dyn[S][Q];
	if (Q == 0) {
		cout << "Case #" << num+1 << ": 0" << endl;
		return;
	}
	for (i=0 ; i<S ; i++)
		dyn[i][0] = 0;
	dyn[findq(0)][0] = VOV;
	for (i=1 ; i<Q ; i++) {
		for (j=0 ; j<S ; j++) {
			dyn[j][i] = VOV;
			for (k=0 ; k<S ; k++) {
				if (k==j && dyn[j][i-1] < dyn[j][i])
					dyn[j][i] = dyn[j][i-1];
				else if (dyn[k][i-1] + 1 < dyn[j][i])
					dyn[j][i] = dyn[k][i-1] + 1;
			}
		}
		dyn[findq(i)][i] = VOV;
	}

	/* for (i=0 ; i<Q ; i++) {
		for (j=0 ; j<S ; j++)
			if (dyn[j][i] == VOV)
				cout << "X ";
			else
				cout << dyn[j][i] << " ";
		cout << endl;
	} */

	int min = VOV;
	for (i=0 ; i<S ; i++) {
		if (dyn[i][Q-1] < min)
			min = dyn[i][Q-1];
	}
	cout << "Case #" << num+1 << ": " << min << endl;
}

void readInput() {
	ifstream inpf(filename, ios::in);
	int i, j, N;
	string tmpstr;
	stringstream ss(stringstream::in | stringstream::out);
	getline(inpf,tmpstr);
	ss << tmpstr;
	ss >> N;
	for (i=0 ; i<N ; i++) {
		getline(inpf,tmpstr);
		stringstream ss2(stringstream::in | stringstream::out);
		ss2 << tmpstr;
		ss2 >> S;
		engines.clear();
		for (j=0 ; j<S ; j++) {
			getline(inpf,tmpstr);
			engines.push_back(tmpstr);
			//cout << engines[j] << endl;
		}
		getline(inpf,tmpstr);
		stringstream ss3(stringstream::in | stringstream::out);
		ss3 << tmpstr;
		ss3 >> Q;
		queries.clear();
		for (j=0 ; j<Q ; j++) {
			getline(inpf,tmpstr);
			queries.push_back(tmpstr);
		}
		solve(i);
	}
	inpf.close();
}

int main(int argc, char * argv[]) {
	filename = argv[1];
	readInput();
}

