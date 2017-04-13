#include <iostream>
#include <vector>

typedef long long int in;

using namespace std;

void testcase() {
	vector<bool> pos = vector<bool>(17,true);
	in a,b;
	in act;
	cin >> a;
	for(in i=1; i<=4; i++) {
		for(in j=1; j<=4; j++) {
			cin >> act;
			if(i!=a) pos[act] = false;
		}
	}
	cin >> b;
	for(in i=1; i<=4; i++) {
		for(in j=1; j<=4; j++) {
			cin >> act;
			if(i!=b) pos[act] = false;
		}
	}
	in first=0, count=0;
	for(in i=1; i<=16; i++) {
		if(pos[i]) {
			count++;
			first=i;
		}
	}
	if(count==0) cout << "Volunteer cheated!";
	else if(count>1) cout << "Bad magician!";
	else cout << first;
}

int main() {
	in T;
	cin >> T;
	for(int t=0; t<T; t++) {
		cout << "Case #" << t+1 << ": ";
		testcase();
		cout << endl;
	}
}